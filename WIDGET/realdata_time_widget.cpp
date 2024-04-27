#include "realdata_time_widget.h"
#include "ui_realdata_time_widget.h"

#include <QHash>
#include "add_device_dlg.h"
#include "err_analysis_dlg.h"
#include "control/dialog.h"
#include "control/dialog_emu.h"

#include "common.h"
#include <QMutex>
#include <QMutexLocker>

QMutex g_display_mutex;


realdata_time_widget::realdata_time_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::realdata_time_widget)
{
    ui->setupUi(this);

    m_field_list <<"对象" << "描述" << "状态(10分钟)" << "型号" << "路" << "额度功率(W)" << "实时温度(℃)" << "当前功率(W)"
                 << "发电量" << "电压"<< "并网电压" << "并网频率" << "原边故障" << "副边故障" << "原边版本"
                 << "副边版本" << "上报时间";
    //设置表头
    ui->treeWidget->setHeaderLabels(m_field_list);
    //设置表头格式
    QFont font;
    font.setPointSize(12);
    for(int i=0;i<m_field_list.size();i++)
    {
        //ui->treeWidget->headerItem()->setTextAlignment(i, Qt::AlignCenter);
        ui->treeWidget->headerItem()->setFont(i, font);
    }

    ui->treeWidget->setAlternatingRowColors(true);
    //设置不可编辑
    ui->treeWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //开启自定义菜单功能
    ui->treeWidget->setContextMenuPolicy(Qt::CustomContextMenu);
    //ui->treeWidget->header()->setSectionResizeMode(QHeaderView::ResizeToContents);

    ui->treeWidget->setColumnWidth(0,220);
    ui->treeWidget->setColumnWidth(4,50);

    add_emu_action = new QAction("添加网关",this);
    add_wifi_mi_action = new QAction("添加WiFi微逆",this);
    add_plc_mi_action = new QAction("添加PLC微逆",this);
    del_station_action = new QAction("删除电站",this);
    del_emu_action = new QAction("删除网关");
    del_mi_action = new QAction("删除微逆");

    ctl_emu_action = new QAction("网关控制");
    ctl_allmi_action = new QAction("全部微逆控制");
    ctl_plcmi_action = new QAction("微逆控制");
    ctl_wifimi_action = new QAction("微逆控制");

    connect(ui->treeWidget,&QTreeWidget::customContextMenuRequested,this,&realdata_time_widget::onm_show_menu);

    connect(add_emu_action,&QAction::triggered,this,&realdata_time_widget::onm_open_add_emu_dlg);
    connect(add_wifi_mi_action,&QAction::triggered,this,&realdata_time_widget::onm_open_add_wifimi_dlg);
    connect(add_plc_mi_action,&QAction::triggered,this,&realdata_time_widget::onm_open_add_plcmi_dlg);
    connect(del_station_action,&QAction::triggered,this,&realdata_time_widget::onm_del_station);
    connect(del_emu_action,&QAction::triggered,this,&realdata_time_widget::onm_del_emu);
    connect(del_mi_action,&QAction::triggered,this,&realdata_time_widget::onm_del_mi);
    connect(ctl_emu_action,&QAction::triggered,this,&realdata_time_widget::onm_ctl_emu);
    connect(ctl_allmi_action,&QAction::triggered,this,&realdata_time_widget::onm_ctl_all_mi);
    connect(ctl_plcmi_action,&QAction::triggered,this,&realdata_time_widget::onm_ctl_plc_mi);
    connect(ctl_wifimi_action,&QAction::triggered,this,&realdata_time_widget::onm_ctl_wifi_mi);
}

realdata_time_widget::~realdata_time_widget()
{
    delete ui;
}

void realdata_time_widget::onm_display_emu_ctl(QString path, QJsonObject data)
{
    //QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"
    if(path == "/r_one_emu_status")
    {
        if(data.value("datas").toArray().size() == 1)
        {
            QJsonObject obj = data.value("datas").toArray()[0].toObject();
            emit s_get_emu_status(obj["status"].toString(),obj["status_reserve"].toString(),obj["func"].toString(),
                                  obj["sign"].toString(),obj["run_mode"].toString(),obj["sys_time"].toString());
        }
    }
    else if(path == "/w_emu_func")
    {
        //emit s_write_log("写入功能码  下发到服务器成功");
    }
}

void realdata_time_widget::onm_update_power_data(QMap<QString, station *> t_station)
{
    QMutexLocker lock(&g_display_mutex);  //自动上锁  函数退出时自动解锁

    //清空界面
    ui->treeWidget->clear();

    QStringList keys = t_station.keys();
    //电站
    for(int i=0;i<keys.size();i++)
    {
        QTreeWidgetItem *item_station = new QTreeWidgetItem(QStringList() << t_station.value(keys[i])->name());
        QMap<QString,bry_base *> tmp_brys = t_station.value(keys[i])->get_bry();
        QStringList bry_keys = tmp_brys.keys();
        //ui->treeWidget->insertTopLevelItem(i,item_station);
        ui->treeWidget->addTopLevelItem(item_station);
        item_station->setData(0,Qt::UserRole,"电站");
        //网关
        for(int j=0;j<bry_keys.size();j++)
        {
            QTreeWidgetItem *item_bry = nullptr;
            QMap<QString,bym_base *> tmp_byms = tmp_brys.value(bry_keys[j])->get_mis();
            QStringList bym_keys = tmp_byms.keys();
            //如果网关是WiFi版   不是显示该项
            if(bry_base::is_wifiemu_cid_valid(tmp_brys.value(bry_keys[j])->name()))
            {
                //指向上一个层级
                item_bry = item_station;
            }
            else
            {
                item_bry = new QTreeWidgetItem();
                item_station->addChild(item_bry);
                item_bry->setData(0,Qt::UserRole,"网关");

                //处理 网关显示
                {
                    QString last_time = tmp_brys.value(bry_keys[j])->get_last_handshake_time();
                    item_bry->setText(0,tmp_brys.value(bry_keys[j])->name());
                    item_bry->setText(1,tmp_brys.value(bry_keys[j])->get_pos());
                    if(last_time == "" || common::cal_time_interval(last_time) > 10)
                    {
                        item_bry->setText(2,"离线");
                        item_bry->setBackground(2,QBrush(QColor(203,206,220)));
                    }
                    else
                    {
                        item_bry->setText(2,"在线");
                        item_bry->setBackground(2,QBrush(QColor(0,255,0)));
                    }
                    item_bry->setText(3,"运行模式:" + tmp_brys.value(bry_keys[j])->get_run_mode());
                    item_bry->setText(12,"状态码:" + tmp_brys.value(bry_keys[j])->get_status());
                    item_bry->setText(13,"状态码更新时间:" + tmp_brys.value(bry_keys[j])->get_status_time());
                    item_bry->setText(14,"硬件版本:" + tmp_brys.value(bry_keys[j])->get_hard_version());
                    item_bry->setText(15,"软件版本:" + tmp_brys.value(bry_keys[j])->get_soft_version());
                    item_bry->setText(16,"握手时间:" + last_time);
                }
            }

            for(int k=0;k<bym_keys.size();k++)
            {
                QHash<QString,QString>mi_pv_datas;
                QTreeWidgetItem *item_bym = new QTreeWidgetItem();
                item_bry->addChild(item_bym);
                item_bym->setData(0,Qt::UserRole,"微逆");
                mi_pv_datas = tmp_byms.value(bym_keys[k])->get_pv_data_str();

                //处理 微逆显示
                {
                    item_bym->setText(0,tmp_byms.value(bym_keys[k])->name());
                    item_bym->setText(1,tmp_byms.value(bym_keys[k])->get_pos());
                    //判断是否离线 十分钟

                    if(mi_pv_datas.value(bym_base::c_field_sys_time)=="" || common::cal_time_interval(mi_pv_datas.value(bym_base::c_field_sys_time)) > 10)
                    {
                        item_bym->setText(2,"离线");
                        item_bym->setBackground(2,QBrush(QColor(203,206,220)));
                    }
                    else
                    {
                        item_bym->setText(2,"在线");
                        item_bym->setBackground(2,QBrush(QColor(0,255,0)));
                    }

                    if(item_bry->data(0,Qt::UserRole) == "电站")
                    {
                        item_bym->setText(3,"WIFI版");
                    }
                    else if(item_bry->data(0,Qt::UserRole) == "网关")
                    {
                        item_bym->setText(3,"PLC版");
                    }

                    item_bym->setText(4,mi_pv_datas.value(bym_base::c_field_pv_id));
                    item_bym->setText(5,mi_pv_datas.value(bym_base::c_field_nominal_power));
                    item_bym->setText(6,mi_pv_datas.value(bym_base::c_field_temperature));
                    QStringList v_power_list = mi_pv_datas.value(bym_base::c_field_power).split("\r\n");

                    for(int i=0;i<v_power_list.size();i++)
                    {
                        if(v_power_list[i] == "0.00")
                        {
                            item_bym->setBackground(7,QBrush(QColor(255,79,82)));
                            break;
                        }
                    }
                    item_bym->setText(7,mi_pv_datas.value(bym_base::c_field_power));
                    item_bym->setText(8,mi_pv_datas.value(bym_base::c_field_energy));
                    item_bym->setText(9,mi_pv_datas.value(bym_base::c_field_pv));
                    item_bym->setText(10,mi_pv_datas.value(bym_base::c_field_gridv));
                    item_bym->setText(11,mi_pv_datas.value(bym_base::c_field_gridf));
                    item_bym->setText(12,mi_pv_datas.value(bym_base::c_field_mim_err));
                    item_bym->setText(13,mi_pv_datas.value(bym_base::c_field_mis_err));
                    item_bym->setText(14,mi_pv_datas.value(bym_base::c_field_mim_version));
                    item_bym->setText(15,mi_pv_datas.value(bym_base::c_field_mis_version));
                    item_bym->setText(16,mi_pv_datas.value(bym_base::c_field_sys_time));
                }
            }
        }
    }

    ui->treeWidget->expandAll();
}

void realdata_time_widget::on_select_bt_clicked()
{
    QJsonObject body;
    emit s_select_power_data(60000,"/r_mi_current_power",body);
}


void realdata_time_widget::on_treeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column)
{
    //点击名称
    if(column == 0)
    {
        emit s_double_cid_clicked(item->text(column),QDateTime::currentDateTime().toString("yyyy-MM-dd") + " 00:00:00",
                                                     QDateTime::currentDateTime().toString("yyyy-MM-dd") + " 23:59:59");
    }
    else if(column == 12 || column == 13)
    {
        int mi_type = bym_base::analysis_type(item->text(0));
        if(mi_type == 1)
        {
            err_analysis_dlg *tmp_dlg = new err_analysis_dlg();
            tmp_dlg->setAttribute(Qt::WA_DeleteOnClose);
            tmp_dlg->set_combobox_enable(false);
            tmp_dlg->analysis_err_code(mi_type,item->text(12),"0000",item->text(13));
            tmp_dlg->exec();
        }
        else if(mi_type == 4)
        {
            err_analysis_dlg *tmp_dlg = new err_analysis_dlg();
            tmp_dlg->setAttribute(Qt::WA_DeleteOnClose);
            tmp_dlg->set_combobox_enable(false);
            tmp_dlg->analysis_err_code(mi_type,item->text(12).mid(6,4),item->text(12).mid(18,4),item->text(13));
            tmp_dlg->exec();
        }
    }
}

void realdata_time_widget::onm_show_menu(QPoint pos)
{
    QMutexLocker lock(&g_display_mutex);  //自动上锁  函数退出时自动解锁
    QTreeWidgetItem* selectedItem = ui->treeWidget->itemAt(pos); //获取右击的item
    if (nullptr == selectedItem)
    {
        return;
    }
    if(ui->treeWidget->currentColumn() == 0)
    {
        if(selectedItem->data(0,Qt::UserRole).toString() == "电站")
        {
            m_station_menu.clear();
            m_station_menu.addAction(add_emu_action);
            m_station_menu.addAction(add_wifi_mi_action);
            m_station_menu.addAction(del_station_action);


            m_station_menu.popup(ui->treeWidget->viewport()->mapToGlobal(pos));//将菜单显示到鼠标所在位置
        }
        else if(selectedItem->data(0,Qt::UserRole).toString() == "网关")
        {
            m_emu_menu.clear();
            m_emu_menu.addAction(ctl_emu_action);
            m_emu_menu.addAction(ctl_allmi_action);

            m_emu_menu.addAction(add_plc_mi_action);
            m_emu_menu.addAction(del_emu_action);

            m_emu_menu.popup(ui->treeWidget->viewport()->mapToGlobal(pos));//将菜单显示到鼠标所在位置

        }
        else if(selectedItem->data(0,Qt::UserRole).toString() == "微逆")
        {
            m_mi_menu.clear();

            if(ui->treeWidget->currentItem()->text(3) == "PLC版")
            {
                m_mi_menu.addAction(ctl_plcmi_action);
            }
            else if(ui->treeWidget->currentItem()->text(3) == "WIFI版")
            {
                m_mi_menu.addAction(ctl_wifimi_action);
            }
            m_mi_menu.addAction(del_mi_action);

            m_mi_menu.popup(ui->treeWidget->viewport()->mapToGlobal(pos));
        }
    }
}

void realdata_time_widget::onm_open_add_emu_dlg()
{
    add_device_dlg tp_dlg(add_emu_type);
    tp_dlg.set_add_emu_station_text(ui->treeWidget->currentItem()->text(0));

    connect(&tp_dlg,&add_device_dlg::s_add_emu,this,&realdata_time_widget::s_add_emu);
    tp_dlg.exec();
}

void realdata_time_widget::onm_open_add_wifimi_dlg()
{
    add_device_dlg tp_dlg(add_wifi_mi_type);
    tp_dlg.set_add_wifi_station_text(ui->treeWidget->currentItem()->text(0));

    connect(&tp_dlg,&add_device_dlg::s_add_wifi_mi,this,&realdata_time_widget::s_add_wifi_mi);

    tp_dlg.exec();
}

void realdata_time_widget::onm_open_add_plcmi_dlg()
{
    add_device_dlg tp_dlg(add_plc_mi_type);

    tp_dlg.set_add_plc_station_emu_text(ui->treeWidget->currentItem()->parent()->text(0),ui->treeWidget->currentItem()->text(0));

    connect(&tp_dlg,&add_device_dlg::s_add_plc_mi,this,&realdata_time_widget::s_add_plc_mi);
    tp_dlg.exec();
}



void realdata_time_widget::onm_ctl_emu()
{
    dialog_emu *tmp_emu_dlg = new dialog_emu();
    tmp_emu_dlg->slot_getEMUCID(ui->treeWidget->currentItem()->text(0),
                                ui->treeWidget->currentItem()->parent()->text(0));

    tmp_emu_dlg->setAttribute(Qt::WA_DeleteOnClose);

    connect(tmp_emu_dlg,&dialog_emu::signal_set_EMU_code,this,&realdata_time_widget::onm_set_emu_func);
    connect(tmp_emu_dlg,&dialog_emu::signal_get_EMU_stauts,this,&realdata_time_widget::onm_get_emu_status);
    connect(this,&realdata_time_widget::s_get_emu_status,tmp_emu_dlg,&dialog_emu::slot_get_EMU_status);
    tmp_emu_dlg->exec();
}

void realdata_time_widget::onm_ctl_all_mi()
{
    Dialog *tmp_mi_dlg = nullptr;
    QTreeWidgetItem *currentitem = ui->treeWidget->currentItem();
    QStringList str;
    if(currentitem == nullptr)
        return ;
    int child_count = currentitem->childCount();
    tmp_mi_dlg = new Dialog();

    for(int i=0;i<child_count;i++)
    {
        str << currentitem->child(i)->text(0); // 获取子节点
    }


    tmp_mi_dlg->slot_setCID(str,ui->treeWidget->currentItem()->text(0),
                            ui->treeWidget->currentItem()->parent()->text(0));

    tmp_mi_dlg->setAttribute(Qt::WA_DeleteOnClose);

    connect(tmp_mi_dlg,&Dialog::signal_COP_set,this,&realdata_time_widget::onm_set_cop);
    connect(tmp_mi_dlg,&Dialog::signal_COP_read,this,&realdata_time_widget::onm_get_cop);
    connect(tmp_mi_dlg,&Dialog::signal_MaxOP_set,this,&realdata_time_widget::onm_set_max_op);
    connect(tmp_mi_dlg,&Dialog::signal_MaxOP_read,this,&realdata_time_widget::onm_get_max_op);
    connect(tmp_mi_dlg,&Dialog::signal_Grid_set,this,&realdata_time_widget::onm_set_grid);
    connect(tmp_mi_dlg,&Dialog::signal_Grid_read,this,&realdata_time_widget::onm_get_grid);
    connect(tmp_mi_dlg,&Dialog::signal_Cer_set,this,&realdata_time_widget::onm_set_cer);
    connect(tmp_mi_dlg,&Dialog::signal_Cer_read,this,&realdata_time_widget::onm_get_cer);
    connect(tmp_mi_dlg,&Dialog::signal_select_back,this,&realdata_time_widget::onm_select_back);

    connect(this,&realdata_time_widget::s_write_log,tmp_mi_dlg,&Dialog::log_receiveData);
    connect(this,&realdata_time_widget::s_get_cop,tmp_mi_dlg,&Dialog::slot_receiveCOP);
    connect(this,&realdata_time_widget::s_get_max_op,tmp_mi_dlg,&Dialog::slot_receiveMaxOP);
    connect(this,&realdata_time_widget::s_get_grid,tmp_mi_dlg,&Dialog::slot_receiveGrid);
    connect(this,&realdata_time_widget::s_get_cer,tmp_mi_dlg,&Dialog::slot_receiveCer);
    connect(this,&realdata_time_widget::s_set_maxop_read_back_flag,tmp_mi_dlg,&Dialog::slot_set_maxop_read_back_flag);
    connect(this,&realdata_time_widget::s_set_cop_read_back_flag,tmp_mi_dlg,&Dialog::slot_set_cop_read_back_flag);
    connect(this,&realdata_time_widget::s_set_grid_read_back_flag,tmp_mi_dlg,&Dialog::slot_set_grid_read_back_flag);
    connect(this,&realdata_time_widget::s_set_cer_read_back_flag,tmp_mi_dlg,&Dialog::slot_set_cer_read_back_flag);
    connect(this,&realdata_time_widget::s_set_r_maxop_read_back_flag,tmp_mi_dlg,&Dialog::slot_set_r_maxop_read_back_flag);
    connect(this,&realdata_time_widget::s_set_r_cop_read_back_flag,tmp_mi_dlg,&Dialog::slot_set_r_cop_read_back_flag);
    connect(this,&realdata_time_widget::s_set_r_grid_read_back_flag,tmp_mi_dlg,&Dialog::slot_set_r_grid_read_back_flag);
    connect(this,&realdata_time_widget::s_set_r_cer_read_back_flag,tmp_mi_dlg,&Dialog::slot_set_r_cer_read_back_flag);
    tmp_mi_dlg->exec();
}

void realdata_time_widget::onm_ctl_plc_mi()
{
    Dialog *tmp_mi_dlg = new Dialog();
    tmp_mi_dlg->slot_setCID(QStringList() << ui->treeWidget->currentItem()->text(0),
                            ui->treeWidget->currentItem()->parent()->text(0),
                            ui->treeWidget->currentItem()->parent()->parent()->text(0));

    tmp_mi_dlg->setAttribute(Qt::WA_DeleteOnClose);

    connect(tmp_mi_dlg,&Dialog::signal_COP_set,this,&realdata_time_widget::onm_set_cop);
    connect(tmp_mi_dlg,&Dialog::signal_COP_read,this,&realdata_time_widget::onm_get_cop);
    connect(tmp_mi_dlg,&Dialog::signal_MaxOP_set,this,&realdata_time_widget::onm_set_max_op);
    connect(tmp_mi_dlg,&Dialog::signal_MaxOP_read,this,&realdata_time_widget::onm_get_max_op);
    connect(tmp_mi_dlg,&Dialog::signal_Grid_set,this,&realdata_time_widget::onm_set_grid);
    connect(tmp_mi_dlg,&Dialog::signal_Grid_read,this,&realdata_time_widget::onm_get_grid);
    connect(tmp_mi_dlg,&Dialog::signal_Cer_set,this,&realdata_time_widget::onm_set_cer);
    connect(tmp_mi_dlg,&Dialog::signal_Cer_read,this,&realdata_time_widget::onm_get_cer);
    connect(tmp_mi_dlg,&Dialog::signal_select_back,this,&realdata_time_widget::onm_select_back);

    connect(this,&realdata_time_widget::s_write_log,tmp_mi_dlg,&Dialog::log_receiveData);
    connect(this,&realdata_time_widget::s_get_cop,tmp_mi_dlg,&Dialog::slot_receiveCOP);
    connect(this,&realdata_time_widget::s_get_max_op,tmp_mi_dlg,&Dialog::slot_receiveMaxOP);
    connect(this,&realdata_time_widget::s_get_grid,tmp_mi_dlg,&Dialog::slot_receiveGrid);
    connect(this,&realdata_time_widget::s_get_cer,tmp_mi_dlg,&Dialog::slot_receiveCer);
    connect(this,&realdata_time_widget::s_set_maxop_read_back_flag,tmp_mi_dlg,&Dialog::slot_set_maxop_read_back_flag);
    connect(this,&realdata_time_widget::s_set_cop_read_back_flag,tmp_mi_dlg,&Dialog::slot_set_cop_read_back_flag);
    connect(this,&realdata_time_widget::s_set_grid_read_back_flag,tmp_mi_dlg,&Dialog::slot_set_grid_read_back_flag);
    connect(this,&realdata_time_widget::s_set_cer_read_back_flag,tmp_mi_dlg,&Dialog::slot_set_cer_read_back_flag);
    connect(this,&realdata_time_widget::s_set_r_maxop_read_back_flag,tmp_mi_dlg,&Dialog::slot_set_r_maxop_read_back_flag);
    connect(this,&realdata_time_widget::s_set_r_cop_read_back_flag,tmp_mi_dlg,&Dialog::slot_set_r_cop_read_back_flag);
    connect(this,&realdata_time_widget::s_set_r_grid_read_back_flag,tmp_mi_dlg,&Dialog::slot_set_r_grid_read_back_flag);
    connect(this,&realdata_time_widget::s_set_r_cer_read_back_flag,tmp_mi_dlg,&Dialog::slot_set_r_cer_read_back_flag);
    tmp_mi_dlg->exec();

}


void realdata_time_widget::onm_ctl_wifi_mi()
{
    Dialog *tmp_mi_dlg = new Dialog();
    tmp_mi_dlg->slot_setCID(QStringList() << ui->treeWidget->currentItem()->text(0),
                            bry_base::wifi_micid_to_emu_cid(ui->treeWidget->currentItem()->text(0)),
                            ui->treeWidget->currentItem()->parent()->text(0));
    connect(tmp_mi_dlg,&Dialog::signal_COP_set,this,&realdata_time_widget::onm_set_cop);
    connect(tmp_mi_dlg,&Dialog::signal_COP_read,this,&realdata_time_widget::onm_get_cop);
    connect(tmp_mi_dlg,&Dialog::signal_MaxOP_set,this,&realdata_time_widget::onm_set_max_op);
    connect(tmp_mi_dlg,&Dialog::signal_MaxOP_read,this,&realdata_time_widget::onm_get_max_op);
    connect(tmp_mi_dlg,&Dialog::signal_Grid_set,this,&realdata_time_widget::onm_set_grid);
    connect(tmp_mi_dlg,&Dialog::signal_Grid_read,this,&realdata_time_widget::onm_get_grid);
    connect(tmp_mi_dlg,&Dialog::signal_Cer_set,this,&realdata_time_widget::onm_set_cer);
    connect(tmp_mi_dlg,&Dialog::signal_Cer_read,this,&realdata_time_widget::onm_get_cer);
    connect(tmp_mi_dlg,&Dialog::signal_select_back,this,&realdata_time_widget::onm_select_back);


    connect(this,&realdata_time_widget::s_write_log,tmp_mi_dlg,&Dialog::log_receiveData);
    connect(this,&realdata_time_widget::s_get_cop,tmp_mi_dlg,&Dialog::slot_receiveCOP);
    connect(this,&realdata_time_widget::s_get_max_op,tmp_mi_dlg,&Dialog::slot_receiveMaxOP);
    connect(this,&realdata_time_widget::s_get_grid,tmp_mi_dlg,&Dialog::slot_receiveGrid);
    connect(this,&realdata_time_widget::s_get_cer,tmp_mi_dlg,&Dialog::slot_receiveCer);
    connect(this,&realdata_time_widget::s_set_maxop_read_back_flag,tmp_mi_dlg,&Dialog::slot_set_maxop_read_back_flag);
    connect(this,&realdata_time_widget::s_set_cop_read_back_flag,tmp_mi_dlg,&Dialog::slot_set_cop_read_back_flag);
    connect(this,&realdata_time_widget::s_set_grid_read_back_flag,tmp_mi_dlg,&Dialog::slot_set_grid_read_back_flag);
    connect(this,&realdata_time_widget::s_set_cer_read_back_flag,tmp_mi_dlg,&Dialog::slot_set_cer_read_back_flag);
    connect(this,&realdata_time_widget::s_set_r_maxop_read_back_flag,tmp_mi_dlg,&Dialog::slot_set_r_maxop_read_back_flag);
    connect(this,&realdata_time_widget::s_set_r_cop_read_back_flag,tmp_mi_dlg,&Dialog::slot_set_r_cop_read_back_flag);
    connect(this,&realdata_time_widget::s_set_r_grid_read_back_flag,tmp_mi_dlg,&Dialog::slot_set_r_grid_read_back_flag);
    connect(this,&realdata_time_widget::s_set_r_cer_read_back_flag,tmp_mi_dlg,&Dialog::slot_set_r_cer_read_back_flag);
    tmp_mi_dlg->setAttribute(Qt::WA_DeleteOnClose);
    tmp_mi_dlg->exec();
}


void realdata_time_widget::on_add_station_clicked()
{
    add_device_dlg tp_dlg(add_station_type);

    connect(&tp_dlg,&add_device_dlg::s_add_station,this,&realdata_time_widget::s_add_station);
    tp_dlg.exec();
}
void realdata_time_widget::onm_del_station()
{
    QJsonObject data;
    data.insert("station",ui->treeWidget->currentItem()->text(0));

    emit s_del_station(15000,"/del_station",data);
}

void realdata_time_widget::onm_del_emu()
{
    QJsonObject data;

    data.insert("emu_cid",ui->treeWidget->currentItem()->text(0));
    data.insert("station",ui->treeWidget->currentItem()->parent()->text(0));

    emit s_del_emu(15000,"/del_emu",data);
}


void realdata_time_widget::onm_del_mi()
{
    QJsonObject data;

    if(ui->treeWidget->currentItem()->text(3) == "PLC版")
    {
        data.insert("mi_cid",ui->treeWidget->currentItem()->text(0));
        data.insert("emu_cid",ui->treeWidget->currentItem()->parent()->text(0));
        data.insert("station",ui->treeWidget->currentItem()->parent()->parent()->text(0));
    }
    else if(ui->treeWidget->currentItem()->text(3) == "WIFI版")
    {
        data.insert("mi_cid",ui->treeWidget->currentItem()->text(0));
        data.insert("emu_cid",bry_base::wifi_micid_to_emu_cid(ui->treeWidget->currentItem()->text(0)));
        data.insert("station",ui->treeWidget->currentItem()->parent()->text(0));
    }
    emit s_del_mi(15000,"/del_mi",data);
}
void realdata_time_widget::onm_set_cop(QJsonObject data)
{
    if(data.contains("mis"))
        emit s_ctl(5000,"/w_more_temporary_power",data);
    else
        emit s_ctl(5000,"/w_temporary_power",data);
}

void realdata_time_widget::onm_get_cop(QJsonObject data)
{
    if(data.contains("mis"))
        emit s_ctl(5000,"/r_more_temporary_power",data);
    else
        emit s_ctl(5000,"/r_temporary_power",data);
}

void realdata_time_widget::onm_set_max_op(QJsonObject data)
{
    if(data.contains("mis"))
        emit s_ctl(5000,"/w_more_max_power",data);
    else
        emit s_ctl(5000,"/w_max_power",data);
}

void realdata_time_widget::onm_get_max_op(QJsonObject data)
{
    if(data.contains("mis"))
        emit s_ctl(5000,"/r_more_max_power",data);
    else
        emit s_ctl(5000,"/r_max_power",data);
}

void realdata_time_widget::onm_set_grid(QJsonObject data)
{
    emit s_ctl(5000,"/w_grid",data);
}

void realdata_time_widget::onm_get_grid(QJsonObject data)
{
    emit s_ctl(5000,"/r_grid",data);
}

void realdata_time_widget::onm_set_cer(QJsonObject data)
{
    emit s_ctl(5000,"/w_certification",data);
}

void realdata_time_widget::onm_get_cer(QJsonObject data)
{
    emit s_ctl(5000,"/r_certification",data);
}

void realdata_time_widget::onm_select_back(QJsonObject data)
{
    emit s_ctl(5000,"/r_select_back",data);
}

void realdata_time_widget::onm_set_emu_func(QJsonObject data)
{
    emit s_ctl(5000,"/w_emu_func",data);
}

void realdata_time_widget::onm_get_emu_status(QJsonObject data)
{
    emit s_ctl(5000,"/r_one_emu_status",data);
}

void realdata_time_widget::onm_display_mi_ctl(QString path, QJsonObject data)
{
    if(path == "/w_temporary_power" || path == "/w_more_temporary_power")
    {
        emit s_write_log("下发临时功率成功  注意:实际设置成功会有延时 ");
    }
    else if(path == "/r_temporary_power" )
    {
        QHash<QString,QString> tmp_data;
        tmp_data.insert(data.value("mi_cid").toString(),data.value("temporary_power").toString());

        emit s_get_cop(tmp_data);
        emit s_write_log("获取临时功率成功  注意:当前为旧数据 等待最新数据中");
    }
    else if(path == "/r_more_temporary_power")
    {
        QHash<QString,QString> tmp_data;
        QJsonArray mis = data.value("mis").toArray();
        for(int i=0;i<mis.size();i++)
        {
            tmp_data.insert(mis[i].toObject().value("mi_cid").toString(),
                            mis[i].toObject().value("temporary_power").toString());
        }


        emit s_get_cop(tmp_data);
        emit s_write_log("获取批量临时功率成功  注意:当前为旧数据 等待最新数据中");
    }
    else if(path == "/w_max_power" || path == "/w_more_max_power")
    {
        emit s_write_log("下发最大功率成功  注意:实际设置成功会有延时 ");
    }
    else if(path == "/r_max_power")
    {
        QHash<QString,QString> tmp_data;
        tmp_data.insert(data.value("mi_cid").toString(),data.value("max_power").toString());
        emit s_get_max_op(tmp_data);
        emit s_write_log("获取最大功率参数  注意:当前为旧数据 等待最新数据中");
    }
    else if(path == "/r_more_max_power")
    {
        QHash<QString,QString> tmp_data;
        QJsonArray mis = data.value("mis").toArray();
        for(int i=0;i<mis.size();i++)
        {
            tmp_data.insert(mis[i].toObject().value("mi_cid").toString(),
                            mis[i].toObject().value("max_power").toString());
        }
        emit s_get_max_op(tmp_data);
        emit s_write_log("获取批量最大功率参数  注意:当前为旧数据 等待最新数据中");
    }
    else if(path == "/w_grid")
    {
        emit s_write_log("下发并网参数成功  注意:实际设置成功会有延时 ");
    }
    else if(path == "/r_grid")
    {
        QHash<QString,QString> tmp_data;
        tmp_data.insert(data.value("mi_cid").toString(),data.value("grid").toString());
        emit s_get_grid(tmp_data);
        emit s_write_log("获取并网参数成功  注意:当前为旧数据 等待最新数据中");
    }
    else if(path == "/w_certification")
    {
        emit s_write_log("下发认证参数成功  注意:实际设置成功会有延时 ");
    }
    else if(path == "/r_certification")
    {
        QHash<QString,QString> tmp_data;
        tmp_data.insert(data.value("mi_cid").toString(),data.value("certification").toString());
        emit s_get_cer(tmp_data);
        emit s_write_log("获取认证参数成功  注意:当前为旧数据 等待最新数据中");
    }
    else if(path == "/r_select_back")
    {
        if(data.contains("r_maxop"))
        {
            QHash<QString,QString> tmp_data;
            QJsonArray maxop_arr = data.value("r_maxop").toObject().value("mis_maxop").toArray();
            QString log = "读取最新 最大功率参数成功 读取时间: " + data.value("r_maxop").toObject().value("r_maxop_time").toString();
            for(int i=0;i<maxop_arr.size();i++)
            {
                tmp_data.insert(maxop_arr[i].toObject().value("mi_cid").toString(),
                                maxop_arr[i].toObject().value("v_max_power").toString());
            }

            emit s_get_max_op(tmp_data);

            emit s_write_log(log);
            emit s_set_r_maxop_read_back_flag(data.value("r_maxop").toObject().value("r_maxop_time").toString(),"");
        }

        if(data.contains("r_cop"))
        {
            QHash<QString,QString> tmp_data;
            QJsonArray cop_arr = data.value("r_cop").toObject().value("mis_cop").toArray();
            QString log = "读取最新 临时功率参数成功 读取时间: " + data.value("r_cop").toObject().value("r_cop_time").toString();
            for(int i=0;i<cop_arr.size();i++)
            {
                tmp_data.insert(cop_arr[i].toObject().value("mi_cid").toString(),
                                cop_arr[i].toObject().value("v_cop").toString());
            }
            emit s_get_cop(tmp_data);
            emit s_write_log(log);
            emit s_set_r_cop_read_back_flag(data.value("r_cop").toObject().value("r_cop_time").toString(),"");
        }

        if(data.contains("r_grid"))
        {
            QHash<QString,QString> tmp_data;

            QJsonArray arr = data.value("r_grid").toObject().value("mis_grid").toArray();
            QString log = "读取最新 并网参数成功 读取时间: " + data.value("r_grid").toObject().value("r_grid_time").toString();
            for(int i=0;i<arr.size();i++)
            {
                tmp_data.insert(arr[i].toObject().value("mi_cid").toString(),
                                arr[i].toObject().value("v_grid").toString());
            }
            emit s_get_grid(tmp_data);
            emit s_write_log(log);
            emit s_set_r_grid_read_back_flag(data.value("r_grid").toObject().value("r_grid_time").toString(),"");
        }

        if(data.contains("r_cer"))
        {
            QHash<QString,QString> tmp_data;
            QJsonArray arr = data.value("r_cer").toObject().value("mis_cer").toArray();
            QString log = "读取最新 认证参数成功 读取时间: " + data.value("r_cer").toObject().value("r_cer_time").toString();
            for(int i=0;i<arr.size();i++)
            {
                tmp_data.insert(arr[i].toObject().value("mi_cid").toString(),
                                arr[i].toObject().value("v_cer").toString());
            }

            emit s_get_cer(tmp_data);
            emit s_write_log(log);

            emit s_set_r_cer_read_back_flag(data.value("r_cer").toObject().value("r_cer_time").toString(),"");

        }

        if(data.contains("w_maxop"))
        {
            QHash<QString,QString> tmp_data;
            QJsonArray maxop_arr = data.value("w_maxop").toObject().value("mis_maxop").toArray();
            QString log = "最大功率参数设置后 回读成功 设置时间: " + data.value("w_maxop").toObject().value("w_maxop_time").toString();
            for(int i=0;i<maxop_arr.size();i++)
            {
                tmp_data.insert(maxop_arr[i].toObject().value("mi_cid").toString(),
                                maxop_arr[i].toObject().value("v_max_power").toString());
            }

            emit s_get_max_op(tmp_data);

            emit s_write_log(log);
            emit s_set_maxop_read_back_flag(data.value("w_maxop").toObject().value("w_maxop_time").toString(),"");
        }

        if(data.contains("w_cop"))
        {
            QHash<QString,QString> tmp_data;
            QJsonArray cop_arr = data.value("w_cop").toObject().value("mis_cop").toArray();
            QString log = "临时功率参数设置后 回读成功 设置时间: " + data.value("w_cop").toObject().value("w_cop_time").toString();
            for(int i=0;i<cop_arr.size();i++)
            {
                tmp_data.insert(cop_arr[i].toObject().value("mi_cid").toString(),
                                cop_arr[i].toObject().value("v_cop").toString());
                //log += "\r\n" + cop_arr[i].toObject().value("mi_cid").toString();

            }

            emit s_get_cop(tmp_data);
            emit s_write_log(log);
            emit s_set_cop_read_back_flag(data.value("w_cop").toObject().value("w_cop_time").toString(),"");

        }

        if(data.contains("w_grid"))
        {
            QHash<QString,QString> tmp_data;
            QJsonArray cop_arr = data.value("w_grid").toObject().value("mis_grid").toArray();
            QString log = "并网参数设置后 回读成功 设置时间: " + data.value("w_grid").toObject().value("w_grid_time").toString();
            for(int i=0;i<cop_arr.size();i++)
            {
                tmp_data.insert(cop_arr[i].toObject().value("mi_cid").toString(),
                                cop_arr[i].toObject().value("v_grid").toString());

            }

            emit s_get_grid(tmp_data);
            emit s_write_log(log);
            emit s_set_grid_read_back_flag(data.value("w_grid").toObject().value("w_grid_time").toString(),"");
        }

        if(data.contains("w_cer"))
        {
            QHash<QString,QString> tmp_data;

            QJsonArray arr = data.value("w_cer").toObject().value("mis_cer").toArray();
            QString log = "认证参数设置后 回读成功 设置时间: " + data.value("w_cer").toObject().value("w_cer_time").toString();
            for(int i=0;i<arr.size();i++)
            {
                tmp_data.insert(arr[i].toObject().value("mi_cid").toString(),
                                arr[i].toObject().value("v_cer").toString());
            }

            emit s_get_cer(tmp_data);
            emit s_write_log(log);
            emit s_set_cer_read_back_flag(data.value("w_cer").toObject().value("w_cer_time").toString(),"");

        }
    }

}






