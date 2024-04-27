#include "mi_detail_widget.h"
#include "ui_mi_detail_widget.h"

#include "bym_base.h"

mi_detail_widget::mi_detail_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mi_detail_widget)
{
    ui->setupUi(this);
    //日期选择控件设置  可以为空
    ui->startdate_edt->setCalendarPopup(true);
    ui->startdate_edt->setNullable(true);
    ui->startdate_edt->setNullDatetime();
    ui->stopdate_edt->setCalendarPopup(true);
    ui->stopdate_edt->setNullable(true);
    ui->stopdate_edt->setNullDatetime();

    ui->pv1_draw_widget->set_name("PV 1");
    ui->pv2_draw_widget->set_name("PV 2");
    ui->pv3_draw_widget->set_name("PV 3");
    ui->pv4_draw_widget->set_name("PV 4");

    ui->total_draw_widget->set_name("整 机");

    connect(ui->power_item_wd,&select_mi_power_widget::s_select_mi_power_data,
            this,&mi_detail_widget::s_select_power_data);

}

mi_detail_widget::~mi_detail_widget()
{
    delete ui;
}

void mi_detail_widget::init_by_name(QString name)
{
    m_name = name;

    bym_type tmp_bym = bym_base::analysis_type(name);

    if(tmp_bym == bym_type::bym_one_type)
    {
        ui->pv1_draw_widget->setVisible(false);
        ui->pv2_draw_widget->setVisible(false);
        ui->pv3_draw_widget->setVisible(false);
        ui->pv4_draw_widget->setVisible(false);

        ui->splitter->setVisible(false);
        ui->splitter_2->setVisible(false);
        ui->splitter_3->setVisible(false);

    }
    else if(tmp_bym == bym_type::bym_two_type)
    {
        ui->pv1_draw_widget->setVisible(true);
        ui->pv2_draw_widget->setVisible(true);
        ui->pv3_draw_widget->setVisible(false);
        ui->pv4_draw_widget->setVisible(false);
    }
    else if(tmp_bym == bym_type::bym_four_type)
    {
        ui->pv1_draw_widget->setVisible(true);
        ui->pv2_draw_widget->setVisible(true);
        ui->pv3_draw_widget->setVisible(true);
        ui->pv4_draw_widget->setVisible(true);
    }
    else
    {
        ui->pv1_draw_widget->setVisible(false);
        ui->pv2_draw_widget->setVisible(false);
        ui->pv3_draw_widget->setVisible(false);
        ui->pv4_draw_widget->setVisible(false);
    }
    //对发电数据项进行处理
    ui->power_item_wd->set_mi_cid_text(name);
    ui->power_item_wd->set_mi_cid_enable(false);
}


void mi_detail_widget::onm_display_plot_data(QString name, QJsonObject data)
{
    if(name != m_name)
        return ;

    bym_type tmp_bym = bym_base::analysis_type(name);

    if(tmp_bym == bym_type::bym_one_type)
    {
        QVector<double> time_data,power_data,pvlot_data,temp_data,gridv_data,gridf_data;
        QJsonArray pw_data_array = data.value("datas").toArray();
        QString start_time = QDateTime::fromString(data.value("start_date").toString(),"yyyy-MM-dd hh:mm:ss").toString("yyyy-MM-dd") + " 00:00:00";
        QString stop_time = QDateTime::fromString(data.value("stop_date").toString(),"yyyy-MM-dd hh:mm:ss").toString("yyyy-MM-dd") + " 23:59:59";
        for(int i=0;i<pw_data_array.size();i++)
        {
            time_data.append(QDateTime::fromString(pw_data_array[i].toObject().value("sys_time").toString(),"yyyy-MM-dd hh:mm:ss").toTime_t());
            power_data.append(pw_data_array[i].toObject().value("power").toString().toDouble());
            pvlot_data.append(pw_data_array[i].toObject().value("pv").toString().toDouble());
            temp_data.append(pw_data_array[i].toObject().value("temperature").toString().toDouble());
            gridv_data.append(pw_data_array[i].toObject().value("gridv").toString().toDouble());
            gridf_data.append(pw_data_array[i].toObject().value("gridf").toString().toDouble());
        }

        //清空y坐标范围 绘图时会自动设定y轴
        ui->total_draw_widget->clear_y_range();


        //根据时间  设置x坐标范围
        ui->total_draw_widget->set_x_range(QDateTime::fromString(start_time,"yyyy-MM-dd hh:mm:ss").toTime_t(),
                                           QDateTime::fromString(stop_time,"yyyy-MM-dd hh:mm:ss").toTime_t());

        ui->total_draw_widget->plot_power_data(time_data,power_data);
        ui->total_draw_widget->plot_pvolt_data(time_data,pvlot_data);
        ui->total_draw_widget->plot_temp_data(time_data,temp_data);
        ui->total_draw_widget->plot_gridv_data(time_data,gridv_data);
        ui->total_draw_widget->plot_gridf_data(time_data,gridf_data);
        ui->total_draw_widget->plot();
    }
    else if(tmp_bym == bym_type::bym_two_type)
    {
        int pv_id = 0;
        QJsonArray pw_data_array = data.value("datas").toArray();
        QVector<double> total_time_data,total_power_data,total_pvlot_data,total_temp_data,total_gridv_data,total_gridf_data;
        QVector<double> time_data[2],power_data[2],pvlot_data[2],temp_data[2],gridv_data[2],gridf_data[2];
        QString start_time = QDateTime::fromString(data.value("start_date").toString(),"yyyy-MM-dd hh:mm:ss").toString("yyyy-MM-dd") + " 00:00:00";
        QString stop_time = QDateTime::fromString(data.value("stop_date").toString(),"yyyy-MM-dd hh:mm:ss").toString("yyyy-MM-dd") + " 23:59:59";

        for(int i=0;i<pw_data_array.size();i++)
        {
            pv_id = pw_data_array[i].toObject().value("pv_id").toInt();
            if(pv_id >0 && pv_id <=2)
            {
                time_data[pv_id-1].append(QDateTime::fromString(pw_data_array[i].toObject().value("sys_time").toString(),"yyyy-MM-dd hh:mm:ss").toTime_t());
                power_data[pv_id-1].append(pw_data_array[i].toObject().value("power").toString().toDouble());
                pvlot_data[pv_id-1].append(pw_data_array[i].toObject().value("pv").toString().toDouble());
                temp_data[pv_id-1].append(pw_data_array[i].toObject().value("temperature").toString().toDouble());
                gridv_data[pv_id-1].append(pw_data_array[i].toObject().value("gridv").toString().toDouble());
                gridf_data[pv_id-1].append(pw_data_array[i].toObject().value("gridf").toString().toDouble());
            }
        }

        if(time_data[0].size() != time_data[1].size())
        {
            return ;
        }

        for(int i=0;i<time_data[0].size();i++)
        {
            if(time_data[0][i] != time_data[1][i])
            {
                return ;
            }

            total_time_data.append(time_data[0][i]);
            total_power_data.append(power_data[0][i] + power_data[1][i]);
            //total_pvlot_data.append(pvlot_data[0][i] + pvlot_data[1][i] + pvlot_data[2][i] + pvlot_data[3][i]);
            total_temp_data.append((temp_data[0][i] + temp_data[1][i])/2);
            total_gridv_data.append(gridv_data[0][i]);
            total_gridf_data.append(gridf_data[0][i]);
        }

        //清空y坐标范围 绘图时会自动设定y轴
        ui->total_draw_widget->clear_y_range();
        //根据时间  设置x坐标范围
        ui->total_draw_widget->set_x_range(QDateTime::fromString(start_time,"yyyy-MM-dd hh:mm:ss").toTime_t(),
                                           QDateTime::fromString(stop_time,"yyyy-MM-dd hh:mm:ss").toTime_t());

        ui->total_draw_widget->plot_power_data(total_time_data,total_power_data);
        //ui->total_draw_widget->plot_pvolt_data(total_time_data,total_pvlot_data);
        ui->total_draw_widget->plot_temp_data(total_time_data,total_temp_data);
        ui->total_draw_widget->plot_gridv_data(total_time_data,total_gridv_data);
        ui->total_draw_widget->plot_gridf_data(total_time_data,total_gridf_data);
        ui->total_draw_widget->plot();

        //清空y坐标范围 绘图时会自动设定y轴
        ui->pv1_draw_widget->clear_y_range();
        //根据时间  设置x坐标范围
        ui->pv1_draw_widget->set_x_range(QDateTime::fromString(start_time,"yyyy-MM-dd hh:mm:ss").toTime_t(),
                                           QDateTime::fromString(stop_time,"yyyy-MM-dd hh:mm:ss").toTime_t());

        ui->pv1_draw_widget->plot_power_data(time_data[0],power_data[0]);
        ui->pv1_draw_widget->plot_pvolt_data(time_data[0],pvlot_data[0]);
        ui->pv1_draw_widget->plot_temp_data(time_data[0],temp_data[0]);
        ui->pv1_draw_widget->plot_gridv_data(time_data[0],gridv_data[0]);
        ui->pv1_draw_widget->plot_gridf_data(time_data[0],gridf_data[0]);
        ui->pv1_draw_widget->plot();

        //清空y坐标范围 绘图时会自动设定y轴
        ui->pv2_draw_widget->clear_y_range();
        //根据时间  设置x坐标范围
        ui->pv2_draw_widget->set_x_range(QDateTime::fromString(start_time,"yyyy-MM-dd hh:mm:ss").toTime_t(),
                                           QDateTime::fromString(stop_time,"yyyy-MM-dd hh:mm:ss").toTime_t());

        ui->pv2_draw_widget->plot_power_data(time_data[1],power_data[1]);
        ui->pv2_draw_widget->plot_pvolt_data(time_data[1],pvlot_data[1]);
        ui->pv2_draw_widget->plot_temp_data(time_data[1],temp_data[1]);
        ui->pv2_draw_widget->plot_gridv_data(time_data[1],gridv_data[1]);
        ui->pv2_draw_widget->plot_gridf_data(time_data[1],gridf_data[1]);
        ui->pv2_draw_widget->plot();

    }
    else if(tmp_bym == bym_type::bym_four_type)
    {
        int pv_id = 0;
        QJsonArray pw_data_array = data.value("datas").toArray();
        QVector<double> total_time_data,total_power_data,total_pvlot_data,total_temp_data,total_gridv_data,total_gridf_data;
        QVector<double> time_data[4],power_data[4],pvlot_data[4],temp_data[4],gridv_data[4],gridf_data[4];
        QString start_time = QDateTime::fromString(data.value("start_date").toString(),"yyyy-MM-dd hh:mm:ss").toString("yyyy-MM-dd") + " 00:00:00";
        QString stop_time = QDateTime::fromString(data.value("stop_date").toString(),"yyyy-MM-dd hh:mm:ss").toString("yyyy-MM-dd") + " 23:59:59";

        for(int i=0;i<pw_data_array.size();i++)
        {
            pv_id = pw_data_array[i].toObject().value("pv_id").toInt();
            if(pv_id >0 && pv_id <=4)
            {
                time_data[pv_id-1].append(QDateTime::fromString(pw_data_array[i].toObject().value("sys_time").toString(),"yyyy-MM-dd hh:mm:ss").toTime_t());
                power_data[pv_id-1].append(pw_data_array[i].toObject().value("power").toString().toDouble());
                pvlot_data[pv_id-1].append(pw_data_array[i].toObject().value("pv").toString().toDouble());
                temp_data[pv_id-1].append(pw_data_array[i].toObject().value("temperature").toString().toDouble());
                gridv_data[pv_id-1].append(pw_data_array[i].toObject().value("gridv").toString().toDouble());
                gridf_data[pv_id-1].append(pw_data_array[i].toObject().value("gridf").toString().toDouble());
            }
        }

        if(time_data[0].size() != time_data[1].size() ||
           time_data[0].size() != time_data[2].size() ||
           time_data[0].size() != time_data[3].size() ||
           time_data[1].size() != time_data[2].size() ||
           time_data[1].size() != time_data[3].size() ||
           time_data[2].size() != time_data[3].size())
        {
            return ;
        }

        for(int i=0;i<time_data[0].size();i++)
        {
            if(time_data[0][i] != time_data[1][i] ||
               time_data[0][i] != time_data[2][i] ||
               time_data[0][i] != time_data[3][i] ||
               time_data[1][i] != time_data[2][i] ||
               time_data[1][i] != time_data[3][i] ||
               time_data[2][i] != time_data[3][i])
            {
                return ;
            }

            total_time_data.append(time_data[0][i]);
            total_power_data.append(power_data[0][i] + power_data[1][i] + power_data[2][i] + power_data[3][i]);
            //total_pvlot_data.append(pvlot_data[0][i] + pvlot_data[1][i] + pvlot_data[2][i] + pvlot_data[3][i]);
            total_temp_data.append((temp_data[0][i] + temp_data[1][i] + temp_data[2][i] + temp_data[3][i])/4);
            total_gridv_data.append(gridv_data[0][i]);
            total_gridf_data.append(gridf_data[0][i]);
        }

        //清空y坐标范围 绘图时会自动设定y轴
        ui->total_draw_widget->clear_y_range();
        //根据时间  设置x坐标范围
        ui->total_draw_widget->set_x_range(QDateTime::fromString(start_time,"yyyy-MM-dd hh:mm:ss").toTime_t(),
                                           QDateTime::fromString(stop_time,"yyyy-MM-dd hh:mm:ss").toTime_t());

        ui->total_draw_widget->plot_power_data(total_time_data,total_power_data);
        //ui->total_draw_widget->plot_pvolt_data(total_time_data,total_pvlot_data);
        ui->total_draw_widget->plot_temp_data(total_time_data,total_temp_data);
        ui->total_draw_widget->plot_gridv_data(total_time_data,total_gridv_data);
        ui->total_draw_widget->plot_gridf_data(total_time_data,total_gridf_data);
        ui->total_draw_widget->plot();

        //清空y坐标范围 绘图时会自动设定y轴
        ui->pv1_draw_widget->clear_y_range();
        //根据时间  设置x坐标范围
        ui->pv1_draw_widget->set_x_range(QDateTime::fromString(start_time,"yyyy-MM-dd hh:mm:ss").toTime_t(),
                                           QDateTime::fromString(stop_time,"yyyy-MM-dd hh:mm:ss").toTime_t());

        ui->pv1_draw_widget->plot_power_data(time_data[0],power_data[0]);
        ui->pv1_draw_widget->plot_pvolt_data(time_data[0],pvlot_data[0]);
        ui->pv1_draw_widget->plot_temp_data(time_data[0],temp_data[0]);
        ui->pv1_draw_widget->plot_gridv_data(time_data[0],gridv_data[0]);
        ui->pv1_draw_widget->plot_gridf_data(time_data[0],gridf_data[0]);
        ui->pv1_draw_widget->plot();

        //清空y坐标范围 绘图时会自动设定y轴
        ui->pv2_draw_widget->clear_y_range();
        //根据时间  设置x坐标范围
        ui->pv2_draw_widget->set_x_range(QDateTime::fromString(start_time,"yyyy-MM-dd hh:mm:ss").toTime_t(),
                                           QDateTime::fromString(stop_time,"yyyy-MM-dd hh:mm:ss").toTime_t());

        ui->pv2_draw_widget->plot_power_data(time_data[1],power_data[1]);
        ui->pv2_draw_widget->plot_pvolt_data(time_data[1],pvlot_data[1]);
        ui->pv2_draw_widget->plot_temp_data(time_data[1],temp_data[1]);
        ui->pv2_draw_widget->plot_gridv_data(time_data[1],gridv_data[1]);
        ui->pv2_draw_widget->plot_gridf_data(time_data[1],gridf_data[1]);
        ui->pv2_draw_widget->plot();

        //清空y坐标范围 绘图时会自动设定y轴
        ui->pv3_draw_widget->clear_y_range();
        //根据时间  设置x坐标范围
        ui->pv3_draw_widget->set_x_range(QDateTime::fromString(start_time,"yyyy-MM-dd hh:mm:ss").toTime_t(),
                                           QDateTime::fromString(stop_time,"yyyy-MM-dd hh:mm:ss").toTime_t());

        ui->pv3_draw_widget->plot_power_data(time_data[2],power_data[2]);
        ui->pv3_draw_widget->plot_pvolt_data(time_data[2],pvlot_data[2]);
        ui->pv3_draw_widget->plot_temp_data(time_data[2],temp_data[2]);
        ui->pv3_draw_widget->plot_gridv_data(time_data[2],gridv_data[2]);
        ui->pv3_draw_widget->plot_gridf_data(time_data[2],gridf_data[2]);
        ui->pv3_draw_widget->plot();

        //清空y坐标范围 绘图时会自动设定y轴
        ui->pv4_draw_widget->clear_y_range();
        //根据时间  设置x坐标范围
        ui->pv4_draw_widget->set_x_range(QDateTime::fromString(start_time,"yyyy-MM-dd hh:mm:ss").toTime_t(),
                                           QDateTime::fromString(stop_time,"yyyy-MM-dd hh:mm:ss").toTime_t());

        ui->pv4_draw_widget->plot_power_data(time_data[3],power_data[3]);
        ui->pv4_draw_widget->plot_pvolt_data(time_data[3],pvlot_data[3]);
        ui->pv4_draw_widget->plot_temp_data(time_data[3],temp_data[3]);
        ui->pv4_draw_widget->plot_gridv_data(time_data[3],gridv_data[3]);
        ui->pv4_draw_widget->plot_gridf_data(time_data[3],gridf_data[3]);
        ui->pv4_draw_widget->plot();

    }
    else
    {
        ui->pv1_draw_widget->setVisible(false);
        ui->pv2_draw_widget->setVisible(false);
        ui->pv3_draw_widget->setVisible(false);
        ui->pv4_draw_widget->setVisible(false);
    }

}

void mi_detail_widget::onm_display_power_data(QString path,QJsonObject data)
{
    ui->power_item_wd->onm_display_power_data(path,data);
}

void mi_detail_widget::onm_set_select_param(QString name, QString start_time, QString stop_time)
{
    if(m_name == name)
    {
        ui->startdate_edt->setDateTime(QDateTime::fromString(start_time,"yyyy-MM-dd hh:mm:ss"));
        ui->stopdate_edt->setDateTime(QDateTime::fromString(stop_time,"yyyy-MM-dd hh:mm:ss"));
        on_select1_pb_clicked();
    }
}




void mi_detail_widget::on_select1_pb_clicked()
{
    QJsonObject data_obj;
    QJsonArray mi_cid;

    mi_cid.append(m_name);
    data_obj.insert("mi_cid",mi_cid);
    data_obj.insert("nums","-1");
    data_obj.insert("start_num","0");

    if(ui->startdate_edt->dateTime().toString("yyyy-MM-dd") != "" &&
       ui->stopdate_edt->dateTime().toString("yyyy-MM-dd") != "")
    {
        data_obj.insert("start_date",ui->startdate_edt->dateTime().toString("yyyy-MM-dd") + " 00:00:00");
        data_obj.insert("stop_date",ui->stopdate_edt->dateTime().toString("yyyy-MM-dd") + " 23:59:59");
    }
    else
    {
        data_obj.insert("start_date",QDateTime::currentDateTime().toString("yyyy-MM-dd") + " 00:00:00");
        data_obj.insert("stop_date",QDateTime::currentDateTime().toString("yyyy-MM-dd") + " 23:59:59");
    }

    emit s_select_power_data(15000,"/r_one_plot_mi_power",data_obj);
}

