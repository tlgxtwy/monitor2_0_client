#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtCore/QCoreApplication>
#include "bym_base.h"

#include "realdata_time_widget.h"
#include "aging_mi_widget.h"
#include "select_emu_action_widget.h"
#include "select_mi_power_widget.h"
#include "select_room_temp_widget.h"
#include "select_user_act_widget.h"
#include "select_emu_status_widget.h"
#include "mi_detail_widget.h"
#include "bridge.h"
#include "err_analysis_dlg.h"

/*
    主界面
*/


static const hometree_field htree_field =
{
    .back_bt = "",
    .tree_head = "老化监控系统",
    .home = "首页",
    .monitor = "实时监控",
    .realtime_data = "实时数据",
    .mi_st = "微逆情况",
    .rack_st = "老化架情况",
    .sensor_st = "传感器情况",
    .data_select = "数据查询",
    .mi_aging_data = "微逆老化数据",
    .emu_aging_data = "网关老化数据",
    .emu_data = "网关数据",
    .emu_status = "网关状态",
    .mi_data = "微逆数据",
    .rack_data = "老化架数据",
    .sensor_data = "传感器数据",
    .room_temp_data = "房间温度",
    .user_act_data = "用户操作记录",
    .sys_set = "系统设置"
};



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->splitter->setStretchFactor(0,1);
    ui->splitter->setStretchFactor(1,3);

    m_maintree_model = new QStandardItemModel(this);
    m_maintree_select = new QItemSelectionModel(m_maintree_model);

    connect(m_maintree_select,&QItemSelectionModel::currentChanged,this,&MainWindow::onm_treeview_changed);

    //设置treeview
    //设置表头
    m_maintree_model->setHorizontalHeaderLabels(QStringList()<<htree_field.tree_head);

    ui->treeView->setModel(m_maintree_model);
    ui->treeView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->treeView->setSelectionModel(m_maintree_select);

    //首页
    QStandardItem *item;
    //实时监控
    item = new QStandardItem(htree_field.monitor);
    item->setIcon(QIcon(":/icon/icon/monitor.ico"));
    m_maintree_model->setItem(0,0,item);
    m_str_to_standitem.insert(htree_field.monitor,item);
    //总体情况
    item = new QStandardItem(htree_field.realtime_data);
    item->setIcon(QIcon(":/icon/icon/general_situation.ico"));
    m_maintree_model->item(0,0)->setChild(0,0,item);
    m_str_to_standitem.insert(htree_field.realtime_data,item);

    item = new QStandardItem(htree_field.mi_aging_data);
    item->setIcon(QIcon(":/icon/icon/inverter.ico"));
    m_maintree_model->item(0,0)->setChild(1,0,item);
    m_str_to_standitem.insert(htree_field.mi_aging_data,item);

    //
    item = new QStandardItem(htree_field.data_select);
    m_maintree_model->setItem(1,0,item);
    m_str_to_standitem.insert(htree_field.data_select,item);

    item = new QStandardItem(htree_field.emu_data);
    item->setIcon(QIcon(":/icon/icon/inverter.ico"));
    m_maintree_model->item(1,0)->setChild(0,0,item);
    m_str_to_standitem.insert(htree_field.emu_data,item);

    item = new QStandardItem(htree_field.emu_status);
    item->setIcon(QIcon(":/icon/icon/inverter.ico"));
    m_maintree_model->item(1,0)->setChild(1,0,item);
    m_str_to_standitem.insert(htree_field.emu_status,item);

    item = new QStandardItem(htree_field.mi_data);
    item->setIcon(QIcon(":/icon/icon/inverter.ico"));
    m_maintree_model->item(1,0)->setChild(2,0,item);
    m_str_to_standitem.insert(htree_field.mi_data,item);

    item = new QStandardItem(htree_field.room_temp_data);
    //item->setIcon(QIcon(":/icon/icon/inverter.ico"));
    m_maintree_model->item(1,0)->setChild(3,0,item);
    m_str_to_standitem.insert(htree_field.room_temp_data,item);

    item = new QStandardItem(htree_field.user_act_data);
    //item->setIcon(QIcon(":/icon/icon/inverter.ico"));
    m_maintree_model->item(1,0)->setChild(4,0,item);
    m_str_to_standitem.insert(htree_field.user_act_data,item);
//    item = new QStandardItem(htree_field.rack_data);
//    item->setIcon(QIcon(":/icon/icon/shelf.ico"));
//    m_maintree_model->item(1,0)->setChild(3,0,item);
//    m_str_to_standitem.insert(htree_field.rack_data,item);

//    item = new QStandardItem(htree_field.sys_set);
//    item->setIcon(QIcon(":/icon/icon/sysset.png"));
//    m_maintree_model->setItem(2,0,item);
//    m_str_to_standitem.insert(htree_field.sys_set,item);

    ui->treeView->expandAll();

    open_widget(htree_field.realtime_data);


    m_maintree_select->setCurrentIndex(m_maintree_model->indexFromItem(m_str_to_standitem.value(htree_field.mi_aging_data)),
                                       QItemSelectionModel::SelectCurrent);

    connect(ui->st_widget,&my_stacked_widget::s_widget_changed,this,&MainWindow::onm_stackedwidget_changed);


    connect(&m_timer,&QTimer::timeout,this,&MainWindow::onm_timer_callback);
    m_timer.start(1000);  //60秒处理一次

    connect(this,&MainWindow::s_client_test,bridge::ins()->csclient(),&cs_client::onm_send);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::open_widget(QString name)
{
    bool ret = false;
    bool close_bt = true; //是否显示关闭按钮  只有首页不显示
    //判断该界面是否已经被打开
    ret = ui->st_widget->is_widget_exist(name);
    //界面已经打开  直接跳转
    if(ret)
    {
        ui->st_widget->open_widget(name);
    }//创建新页
    else
    {
        QWidget *tmp_widget = nullptr;

        if(name == htree_field.home)
        {

        }
        else if(name == htree_field.realtime_data)
        {
            realdata_time_widget *tmp_real_widget = new realdata_time_widget();
            close_bt = false;
            tmp_widget = tmp_real_widget;

            connect(bridge::ins()->core(),&core_mg::s_new_current_power_data,tmp_real_widget,&realdata_time_widget::onm_update_power_data);
            connect(bridge::ins()->core(),&core_mg::s_new_mapping,tmp_real_widget,&realdata_time_widget::on_select_bt_clicked);
            connect(tmp_real_widget,&realdata_time_widget::s_select_power_data,bridge::ins()->csclient(),&cs_client::onm_send);

            connect(tmp_real_widget,&realdata_time_widget::s_ctl,bridge::ins()->csclient(),&cs_client::onm_send);
            connect(bridge::ins()->core(),&core_mg::s_new_mi_ctl,tmp_real_widget,&realdata_time_widget::onm_display_mi_ctl);
            connect(bridge::ins()->core(),&core_mg::s_new_emu_ctl,tmp_real_widget,&realdata_time_widget::onm_display_emu_ctl);


            //connect(tmp_real_widget,&realdata_time_widget::s_double_cid_clicked,this,&MainWindow::open_widget);
            connect(tmp_real_widget,&realdata_time_widget::s_double_cid_clicked,this,&MainWindow::onm_open_widget_from_aging_mi_widget);


            connect(tmp_real_widget,&realdata_time_widget::s_add_station,bridge::ins()->csclient(),&cs_client::onm_send);
            connect(tmp_real_widget,&realdata_time_widget::s_add_emu,bridge::ins()->csclient(),&cs_client::onm_send);
            connect(tmp_real_widget,&realdata_time_widget::s_add_plc_mi,bridge::ins()->csclient(),&cs_client::onm_send);
            connect(tmp_real_widget,&realdata_time_widget::s_add_wifi_mi,bridge::ins()->csclient(),&cs_client::onm_send);
            connect(tmp_real_widget,&realdata_time_widget::s_del_mi,bridge::ins()->csclient(),&cs_client::onm_send);
            connect(tmp_real_widget,&realdata_time_widget::s_del_emu,bridge::ins()->csclient(),&cs_client::onm_send);
            connect(tmp_real_widget,&realdata_time_widget::s_del_station,bridge::ins()->csclient(),&cs_client::onm_send);
        }
        else if(name == htree_field.mi_aging_data)
        {
            aging_mi_widget *tmp_aging_widget = new aging_mi_widget();
            close_bt = false;
            tmp_widget = tmp_aging_widget;

            connect(tmp_aging_widget,&aging_mi_widget::s_open_midetail_data_widget,this,&MainWindow::onm_open_widget_from_aging_mi_widget);
            //读取云端的工单
            connect(tmp_aging_widget,&aging_mi_widget::s_select_workorder,bridge::ins()->csclient(),&cs_client::onm_send);
            connect(bridge::ins()->core(),&core_mg::s_new_cloud_workorder,tmp_aging_widget,&aging_mi_widget::onm_read_cloud_workorder_success);
            //写入云端工单
            connect(tmp_aging_widget,&aging_mi_widget::s_write_workorder,bridge::ins()->csclient(),&cs_client::onm_send);
            connect(bridge::ins()->core(),&core_mg::s_write_cloud_workorder_response,tmp_aging_widget,&aging_mi_widget::onm_write_cloud_workorder_success);

            connect(tmp_aging_widget,&aging_mi_widget::s_read_aging_data,bridge::ins()->csclient(),&cs_client::onm_send);
            connect(bridge::ins()->core(),&core_mg::s_new_aging_report,tmp_aging_widget,&aging_mi_widget::onm_read_aging_data_success);

        }
        else if(name == htree_field.emu_data)
        {
            select_emu_action_widget *tmp_emu_act_widget = new select_emu_action_widget();
            //close_bt = false;
            tmp_widget = tmp_emu_act_widget;

            connect(tmp_emu_act_widget,&select_emu_action_widget::s_select_emu_data,bridge::ins()->csclient(),&cs_client::onm_send);
            connect(bridge::ins()->core(),&core_mg::s_new_emu_action_data,tmp_emu_act_widget,&select_emu_action_widget::onm_display_emu_data);
        }
        else if(name == htree_field.emu_status)
        {
            select_emu_status_widget *tmp_emu_status_widget = new select_emu_status_widget();
            //close_bt = false;
            tmp_widget = tmp_emu_status_widget;

            connect(tmp_emu_status_widget,&select_emu_status_widget::s_select_emu_status,bridge::ins()->csclient(),&cs_client::onm_send);
            connect(bridge::ins()->core(),&core_mg::s_new_emu_status_data,tmp_emu_status_widget,&select_emu_status_widget::onm_display_emu_status);



        }
        else if(name == htree_field.mi_data)
        {
            select_mi_power_widget *tmp_mi_pw_widget = new select_mi_power_widget();
            //close_bt = false;
            tmp_widget = tmp_mi_pw_widget;

            connect(tmp_mi_pw_widget,&select_mi_power_widget::s_select_mi_power_data,bridge::ins()->csclient(),&cs_client::onm_send);
            connect(bridge::ins()->core(),&core_mg::s_new_mi_power_data,tmp_mi_pw_widget,&select_mi_power_widget::onm_display_power_data);

            connect(tmp_mi_pw_widget,&select_mi_power_widget::s_open_midetail_data_widget,this,&MainWindow::onm_open_widget_from_aging_mi_widget);
        }
        else if(name == htree_field.rack_data)
        {

        }
        else if(name == htree_field.room_temp_data)
        {
            select_room_temp_widget *tmp_room_temp_widget = new select_room_temp_widget;
            tmp_widget = tmp_room_temp_widget;

            connect(tmp_room_temp_widget,&select_room_temp_widget::s_select_room_temp_data,bridge::ins()->csclient(),&cs_client::onm_send);
            connect(bridge::ins()->core(),&core_mg::s_new_room_temp_data,tmp_room_temp_widget,&select_room_temp_widget::onm_display_room_temp_data);
        }
        else if(name == htree_field.user_act_data)
        {
            select_user_act_widget *tmp_user_act_widget = new select_user_act_widget();
            tmp_widget = tmp_user_act_widget;

            connect(tmp_user_act_widget,&select_user_act_widget::s_select_user_act,bridge::ins()->csclient(),&cs_client::onm_send);
            connect(bridge::ins()->core(),&core_mg::s_new_user_act_data,tmp_user_act_widget,&select_user_act_widget::onm_display_user_act);
        }
        else
        {
            //符合微逆编号
            if(bym_base::is_cid_valid(name))
            {
                mi_detail_widget *tmp_mi_widget = new mi_detail_widget();
                tmp_mi_widget->init_by_name(name);

                tmp_widget = tmp_mi_widget;

                connect(tmp_mi_widget,&mi_detail_widget::s_select_power_data,bridge::ins()->csclient(),&cs_client::onm_send);
                connect(bridge::ins()->core(),&core_mg::s_new_one_plot_mi_power_data,tmp_mi_widget,&mi_detail_widget::onm_display_plot_data);

                connect(bridge::ins()->core(),&core_mg::s_new_mi_power_data,tmp_mi_widget,&mi_detail_widget::onm_display_power_data);
                connect(this,&MainWindow::s_select_time_mi_deatil_data,tmp_mi_widget,&mi_detail_widget::onm_set_select_param);
            }
        }


        if(tmp_widget !=nullptr)
        {
            // 新增\加入该页
            ui->st_widget->add_widget(name,tmp_widget,close_bt);
        }
        else {
            //QLOG_INFO() << QString("没有类型w为:%1的页面  无法创建或打开").arg(page_tp);
        }

    }
}

void MainWindow::onm_treeview_changed(const QModelIndex &current)
{
    QStandardItem *tmp_item = m_maintree_model->itemFromIndex(current);
    open_widget(tmp_item->text());
}

void MainWindow::onm_stackedwidget_changed(QString current_name)
{
    QModelIndex tmp_index = m_maintree_model->indexFromItem(m_str_to_standitem.value(current_name));
    if(current_name == htree_field.realtime_data || current_name == htree_field.mi_aging_data ||
       current_name == htree_field.emu_aging_data || current_name == htree_field.mi_data ||
       current_name == htree_field.rack_data || current_name == htree_field.emu_data ||
       current_name == htree_field.emu_status||
       current_name == htree_field.room_temp_data || current_name == htree_field.user_act_data)
    {
        m_maintree_select->setCurrentIndex(tmp_index,QItemSelectionModel::SelectCurrent);
    }
}

//void MainWindow::onm_open_mi_detail_widget(QString mi_cid)
//{
//    open_widget(mi_cid);
//}

void MainWindow::onm_timer_callback()
{
    static int s_count = 0;

    if(!bridge::ins()->csclient()->is_busy())
    {
        s_count ++;
        if(s_count == 1)
        {

//            QJsonObject data;
//            QJsonObject param;

//            param.insert("account","jack_lin");

//            data.insert("params",param);



//            emit s_client_test(20000,"/r_mapping",data);

        }
        else if(s_count == 2)
        {
//            QJsonObject pw_data;
//            QJsonObject pw_param;
//            QJsonArray pw_mi_array;

//            pw_mi_array.append("10000001");
//            pw_mi_array.append("10000002");
//            pw_mi_array.append("40000001");

//            pw_param.insert("mi_cid",pw_mi_array);
//            pw_data.insert("params",pw_param);

//            emit s_client_test(20000,"/r_mi_current_power",pw_data);

        }
        else
        {
            s_count = 3;
        }

    }

}

void MainWindow::onm_open_widget_from_aging_mi_widget(QString name, QString start_time, QString stop_time)
{
    open_widget(name);

    emit s_select_time_mi_deatil_data(name,start_time,stop_time);
}

void MainWindow::on_account_switches_triggered()
{
    qApp->exit(2);
}


void MainWindow::on_treeView_clicked(const QModelIndex &index)
{
    QStandardItem *tmp_item = m_maintree_model->itemFromIndex(index);
    open_widget(tmp_item->text());
}


void MainWindow::on_action_triggered()
{
    err_analysis_dlg *tmp_dlg = new err_analysis_dlg();
    tmp_dlg->setAttribute(Qt::WA_DeleteOnClose);

    tmp_dlg->exec();
}

