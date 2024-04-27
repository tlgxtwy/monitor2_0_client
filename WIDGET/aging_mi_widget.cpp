#include "aging_mi_widget.h"
#include "ui_aging_mi_widget.h"

#include <QMessageBox>
#include <QTableWidgetItem>
#include <QFileDialog>
#include <QtXlsx>


#include "bym_base.h"
#include "bridge.h"
#include "judge_param_set_dlg.h"
#include "history_batch_set_dialog.h"
#include "err_analysis_dlg.h"


aging_mi_widget::aging_mi_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::aging_mi_widget)
{
    ui->setupUi(this);

    QStringList field;
    field <<  "微逆真实编号" << "默认网关编号"<< "老化位置" << "标称功率" << "最高功率(W)" << "最低功率(W)" << "最高温度(℃)" << "累计原边故障1" <<
        "累计原边故障2" << "累计副边故障"<< "数据点数" << "老化结果" <<"老化开始时间" << "老化结束时间" << "原边版本号"<< "副边版本号";

    ui->tableWidget->setColumnCount(field.size());
    ui->tableWidget->setHorizontalHeaderLabels(field);
    //设置最后一栏自适应长度
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    //交替背景色
    ui->tableWidget->setAlternatingRowColors(true);
    //不可编辑
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //关闭默认行号
    //ui->tableWidget->verticalHeader()->setHidden(true);
    //行选中
    ui->tableWidget->setSelectionBehavior(QTableWidget::SelectRows);

    ui->tableWidget->setItemDelegate(new NewlineDelegate());
    //初始化按 批次查询
    ui->select_way_cb->setCurrentIndex(2);

    //workorder初始化  信号
    connect(&m_workorder_dlg,&workorder_list_dlg::s_post_workorder_ctl,
            bridge::ins()->mesclient(),&mes_client::onm_post);
    connect(&m_workorder_dlg,&workorder_list_dlg::s_get_workorder_mi,
            bridge::ins()->mesclient(),&mes_client::onm_get);
    connect(bridge::ins()->mesclient(),&mes_client::s_cs_request_new_msg,
            &m_workorder_dlg,&workorder_list_dlg::onm_get_workorder_msg);
    /*云端系统数据处理*/
    connect(&m_workorder_dlg,&workorder_list_dlg::s_read_workorder,
            this,&aging_mi_widget::onm_read_cloud_workorder);
    connect(&m_workorder_dlg,&workorder_list_dlg::s_write_workorder,
            this,&aging_mi_widget::onm_write_cloud_wororder);

    /*下层  往上层传递的信号*/
    connect(&m_workorder_dlg,&workorder_list_dlg::s_get_workorder,
            this,&aging_mi_widget::onm_get_workorder_mis);
}

aging_mi_widget::~aging_mi_widget()
{
    delete ui;
}

void aging_mi_widget::onm_get_workorder_mis(QString workorder_id, QStringList mis)
{
    m_mis.clear();
    for(int i=0;i<mis.size();i++)
    {
        QString emu_cid = mis[i].toUpper();
        QString mi_cid = mis[i].toUpper();
        if(mi_cid.startsWith("00000000") && mi_cid.size() == 16)
        {
            emu_cid = emu_cid.mid(8,-1);
            mi_cid = mi_cid.mid(8,-1);
        }

        if(mi_cid.size() == 8)
        {
            if(mi_cid[0] == "A")
            {
                mi_cid[0] = '1';
            }
            else if(mi_cid[0] == "B")
            {
                mi_cid[0] = '2';
            }
            else if(mi_cid[0] == "C")
            {
                mi_cid[0] = '4';
            }
            else
            {
                emu_cid = "";
            }
        }
        m_mis.insert(mi_cid,emu_cid);
    }
    ui->msg_lb->setText("工单号: " + workorder_id + " 数量: " + QString::number(mis.size()));
}

void aging_mi_widget::onm_get_batch_mis(QString start_time, QStringList mis)
{
    ui->msg_lb->setText("批次开始时间: " + start_time + " 数量: " + QString::number(mis.size()));
    m_mis.clear();
    for(int i=0;i<mis.size();i++)
    {
        QString emu_cid = mis[i].toUpper();
        QString mi_cid = mis[i].toUpper();
        if(mi_cid.startsWith("00000000") && mi_cid.size() == 16)
        {
            emu_cid = emu_cid.mid(8,-1);
            mi_cid = mi_cid.mid(8,-1);
        }

        if(mi_cid.size() == 8)
        {
            if(mi_cid[0] == "A")
            {
                mi_cid[0] = '1';
            }
            else if(mi_cid[0] == "B")
            {
                mi_cid[0] = '2';
            }
            else if(mi_cid[0] == "C")
            {
                mi_cid[0] = '4';
            }
            else
            {
                emu_cid = "";
            }
        }
        m_mis.insert(mi_cid,emu_cid);
    }
    m_start_time = start_time;
}

void aging_mi_widget::onm_read_cloud_workorder(QString workorder_id)
{
    QJsonObject obj;

    obj.insert("workorder_id",workorder_id);

    emit s_select_workorder(1000,"/r_workorder",obj);
}

void aging_mi_widget::onm_write_cloud_wororder(QString workorder_id, QString series_id, QString extra_id, QString vacant_id, QString update_record)
{
    QJsonObject obj;
    QJsonArray datas;
    QJsonObject one_data;
    one_data.insert("workorder_id",workorder_id);
    one_data.insert("mi_series_id",series_id);
    one_data.insert("extra_id",extra_id);
    one_data.insert("vacant_id",vacant_id);
    one_data.insert("update_record",update_record);
    datas.append(one_data);
    obj.insert("datas",datas);

    emit s_write_workorder(1000,"/w_workorder",obj);
}

void aging_mi_widget::onm_read_cloud_workorder_success(QJsonObject data)
{
    QJsonObject datas_obj = data.value("datas").toObject();
    m_workorder_dlg.read_workderorder_success(datas_obj.value("workorder_id").toString(),
                                              datas_obj.value("mi_series_id").toString(),
                                              datas_obj.value("extra_id").toString(),
                                              datas_obj.value("vacant_id").toString(),
                                              datas_obj.value("update_record").toString());
}

void aging_mi_widget::onm_write_cloud_workorder_success()
{
    m_workorder_dlg.write_workorder_success();
}

void aging_mi_widget::onm_read_aging_data_success(QJsonObject data)
{
    QVector<int> tmp_text_max(16);

    QFontMetrics fontMetrics(ui->tableWidget->font());
    tmp_text_max[0] = fontMetrics.horizontalAdvance(ui->tableWidget->horizontalHeaderItem(0)->text());
    tmp_text_max[1] = fontMetrics.horizontalAdvance(ui->tableWidget->horizontalHeaderItem(1)->text());
    tmp_text_max[2] = fontMetrics.horizontalAdvance(ui->tableWidget->horizontalHeaderItem(2)->text());
    tmp_text_max[3] = fontMetrics.horizontalAdvance(ui->tableWidget->horizontalHeaderItem(3)->text());
    tmp_text_max[4] = fontMetrics.horizontalAdvance(ui->tableWidget->horizontalHeaderItem(4)->text());
    tmp_text_max[5] = fontMetrics.horizontalAdvance(ui->tableWidget->horizontalHeaderItem(5)->text());
    tmp_text_max[6] = fontMetrics.horizontalAdvance(ui->tableWidget->horizontalHeaderItem(6)->text());
    tmp_text_max[7] = fontMetrics.horizontalAdvance(ui->tableWidget->horizontalHeaderItem(7)->text());
    tmp_text_max[8] = fontMetrics.horizontalAdvance(ui->tableWidget->horizontalHeaderItem(8)->text());
    tmp_text_max[9] = fontMetrics.horizontalAdvance(ui->tableWidget->horizontalHeaderItem(9)->text());
    tmp_text_max[10] = fontMetrics.horizontalAdvance(ui->tableWidget->horizontalHeaderItem(10)->text());
    tmp_text_max[11] = fontMetrics.horizontalAdvance(ui->tableWidget->horizontalHeaderItem(11)->text());
    tmp_text_max[12] = fontMetrics.horizontalAdvance(ui->tableWidget->horizontalHeaderItem(12)->text());
    tmp_text_max[13] = fontMetrics.horizontalAdvance(ui->tableWidget->horizontalHeaderItem(13)->text());

    //添加的版本号
    tmp_text_max[14] = fontMetrics.horizontalAdvance(ui->tableWidget->horizontalHeaderItem(14)->text());
    tmp_text_max[15] = fontMetrics.horizontalAdvance(ui->tableWidget->horizontalHeaderItem(15)->text());

    //保存老化报告
    m_report = data;

    QJsonArray report_datas = data.value("report_datas").toArray();

    ui->tableWidget->setRowCount(report_datas.size());

    for(int i=0;i<report_datas.size();i++)
    {
        QJsonObject mi_report_obj = report_datas[i].toObject();
        QJsonObject mi_total_obj = mi_report_obj.value("total_data").toObject();
        QJsonArray pv_datas_arr = mi_report_obj.value("pv_data").toArray();

        if(mi_report_obj.value("all_pv").toString() == "1" && pv_datas_arr.size() == 1)
        {
            //创建表格项并设置数据
            QTableWidgetItem *ret_item = new QTableWidgetItem();
            //微逆编号
            ui->tableWidget->setItem(i,0,new QTableWidgetItem(mi_report_obj.value("mi_cid").toString()));
            //默认网关编号
            ui->tableWidget->setItem(i,1,new QTableWidgetItem(m_mis.value(mi_report_obj.value("mi_cid").toString(),"")));
            //老化位置
            ui->tableWidget->setItem(i,2,new QTableWidgetItem(mi_report_obj.value("pos_desc").toString()));

            //标称功率
            if(mi_report_obj.value("total_nominal_power").toInt() == 1000000)
            {
                ui->tableWidget->setItem(i,3,new QTableWidgetItem());
            }
            else
            {
                ui->tableWidget->setItem(i,3,new QTableWidgetItem(QString::number(mi_report_obj.value("total_nominal_power").toInt())));
            }

            //最高功率
            if(mi_total_obj.value("pw_max").toInt() != DEFAULT_VALUE_MAX)
            {
                ui->tableWidget->setItem(i,4,new QTableWidgetItem(QString::number(((double)mi_total_obj.value("pw_max").toInt())/100,'f',2)));
            }
            else
            {
                ui->tableWidget->setItem(i,4,new QTableWidgetItem());
            }

            //最低功率
            if(mi_total_obj.value("pw_min").toInt() != DEFAULT_VALUE_MIN)
            {
                ui->tableWidget->setItem(i,5,new QTableWidgetItem(QString::number(((double)mi_total_obj.value("pw_min").toInt())/100,'f',2)));
            }
            else
            {
                ui->tableWidget->setItem(i,5,new QTableWidgetItem());
            }

            //最高温度
            if(mi_total_obj.value("tmax").toInt() != DEFAULT_VALUE_MAX)
            {
                ui->tableWidget->setItem(i,6,new QTableWidgetItem(QString::number(((double)mi_total_obj.value("tmax").toInt())/100,'f',2)));
            }
            else
            {
                ui->tableWidget->setItem(i,6,new QTableWidgetItem());
            }

            //累计原边故障1
            ui->tableWidget->setItem(i,7,new QTableWidgetItem(QString("%1").arg(pv_datas_arr[0].toObject().value("mim_err").toInt(),4,16,QLatin1Char('0'))));
            //累计原边故障2
            ui->tableWidget->setItem(i,8,new QTableWidgetItem(""));
            //累计副边故障
            ui->tableWidget->setItem(i,9,new QTableWidgetItem(QString("%1").arg(pv_datas_arr[0].toObject().value("mis_err").toInt(),4,16,QLatin1Char('0'))));
            //数据点数
            ui->tableWidget->setItem(i,10,new QTableWidgetItem(QString::number(mi_report_obj.value("aging_points").toInt())));

            //背景设置
            if(mi_report_obj.value("b_ret").toInt() == 2)
            {
                ret_item->setData(Qt::UserRole, 2);
            }
            else if(mi_report_obj.value("b_ret").toInt() == 1)
            {
                ret_item->setData(Qt::UserRole,1);
            }
            else if(mi_report_obj.value("b_ret").toInt() == 0)
            {
                ret_item->setData(Qt::UserRole,3);
            }
            ret_item->setText(pv_datas_arr[0].toObject().value("pv_ret").toString());

            //老化结果
            ui->tableWidget->setItem(i,11,ret_item);
            //老化开始时间
            ui->tableWidget->setItem(i,12,new QTableWidgetItem(mi_report_obj.value("start_time").toString()));
            //老化结束时间
            ui->tableWidget->setItem(i,13,new QTableWidgetItem(mi_report_obj.value("stop_time").toString()));

            //版本号
            ui->tableWidget->setItem(i,14,new QTableWidgetItem(mi_report_obj.value("mim_version").toString()));
            ui->tableWidget->setItem(i,15,new QTableWidgetItem(mi_report_obj.value("mis_version").toString()));

            //测量宽度
            for(int j=0;j<14;j++)
            {
                QFontMetrics fontMetrics(ui->tableWidget->item(i,j)->font());
                QStringList lines = ui->tableWidget->item(i,j)->text().split("\r");

                for(int k=0;k<lines.size();k++)
                {
                    int width = fontMetrics.horizontalAdvance(lines[k]);
                    if(tmp_text_max[j] <  width)
                    {
                        tmp_text_max[j] = width;
                    }
                }
            }


            if(mi_report_obj.value("b_ret").toInt() == 2)
            {
                ui->tableWidget->item(i,11)->setBackground(QBrush(QColor(255,79,82)));
            }
            else if(mi_report_obj.value("b_ret").toInt() == 1)
            {
                ui->tableWidget->item(i,11)->setBackground(QBrush(QColor(240,255,108)));
            }
            else if(mi_report_obj.value("b_ret").toInt() == 0)
            {
                ui->tableWidget->item(i,11)->setBackground(QBrush(QColor(138,255,165)));
            }
        }//多路情况
        else if(mi_report_obj.value("all_pv").toString() == QString::number(pv_datas_arr.size()) &&
                (pv_datas_arr.size() == 2 || pv_datas_arr.size() == 4))
        {
            QString max_power,min_power,max_temp,ret;


            if(mi_total_obj.value("pw_max").toInt() != DEFAULT_VALUE_MAX)
            {
                max_power += "整机:" + QString::number(((double)mi_total_obj.value("pw_max").toInt())/100,'f',2) + "\r";
            }

            if(mi_total_obj.value("pw_min").toInt() != DEFAULT_VALUE_MIN)
            {
                min_power.append("整机:" + QString::number(((double)mi_total_obj.value("pw_min").toInt())/100,'f',2) + "\r");
            }

            if(mi_total_obj.value("tmax").toInt() != DEFAULT_VALUE_MAX)
            {
                max_temp.append("整机:" + QString::number(((double)mi_total_obj.value("tmax").toInt())/100,'f',2) +"\r");
            }

            ret.append("整机:" + mi_total_obj.value("total_ret").toString() + "\r");

            //max_power += "\n";

            for(int j=0;j<pv_datas_arr.size();j++)
            {
                if(pv_datas_arr[j].toObject().value("pw_max").toInt() != DEFAULT_VALUE_MAX)
                {
                    max_power += "PV" + QString::number(j+1) + ":" + QString::number(((double)pv_datas_arr[j].toObject().value("pw_max").toInt())/100,'f',2) + "\r";
                }

                if(pv_datas_arr[j].toObject().value("pw_min").toInt() != DEFAULT_VALUE_MIN)
                {
                    min_power.append("PV" + QString::number(j+1) + ":" + QString::number(((double)pv_datas_arr[j].toObject().value("pw_min").toInt())/100,'f',2) + "\r" );
                }

                if(pv_datas_arr[j].toObject().value("tmax").toInt() != DEFAULT_VALUE_MAX)
                {
                    max_temp.append("PV" + QString::number(j+1)+ ":" + QString::number(((double)pv_datas_arr[j].toObject().value("tmax").toInt())/100,'f',2) +"\r");
                }

                //max_power += "\n";


                ret.append("PV" + QString::number(j+1)+ ":" + pv_datas_arr[j].toObject().value("pv_ret").toString() +"\r");
            }

            max_power.remove(-1,1);
            min_power.remove(-1,1);
            max_temp.remove(-1,1);
            ret.remove(-1,1);

            QTableWidgetItem *ret_item = new QTableWidgetItem();
            ui->tableWidget->setItem(i,0,new QTableWidgetItem(mi_report_obj.value("mi_cid").toString()));
            ui->tableWidget->setItem(i,1,new QTableWidgetItem(m_mis.value(mi_report_obj.value("mi_cid").toString(),"")));
            ui->tableWidget->setItem(i,2,new QTableWidgetItem(mi_report_obj.value("pos_desc").toString()));


            if(pv_datas_arr.size() == 2 && mi_report_obj.value("total_nominal_power").toInt() == 2000000)
            {
                ui->tableWidget->setItem(i,3,new QTableWidgetItem());
            }
            else if(pv_datas_arr.size() == 4 && mi_report_obj.value("total_nominal_power").toInt() == 4000000)
            {
                ui->tableWidget->setItem(i,3,new QTableWidgetItem());
            }
            else
            {
                ui->tableWidget->setItem(i,3,new QTableWidgetItem(QString::number(mi_report_obj.value("total_nominal_power").toInt())));
            }


            ui->tableWidget->setItem(i,4,new QTableWidgetItem(max_power));
            ui->tableWidget->setItem(i,5,new QTableWidgetItem(min_power));
            ui->tableWidget->setItem(i,6,new QTableWidgetItem(max_temp));
            ui->tableWidget->setItem(i,7,new QTableWidgetItem(QString("%1").arg(pv_datas_arr[0].toObject().value("mim_err").toInt(),4,16,QLatin1Char('0')).toUpper()));

            if(pv_datas_arr.size() == 2)
                ui->tableWidget->setItem(i,8,new QTableWidgetItem(""));
            else if(pv_datas_arr.size() == 4)
                ui->tableWidget->setItem(i,8,new QTableWidgetItem(QString("%1").arg(pv_datas_arr[2].toObject().value("mim_err").toInt(),4,16,QLatin1Char('0')).toUpper()));
            else
                ui->tableWidget->setItem(i,8,new QTableWidgetItem(""));

            ui->tableWidget->setItem(i,9,new QTableWidgetItem(QString("%1").arg(pv_datas_arr[0].toObject().value("mis_err").toInt(),4,16,QLatin1Char('0')).toUpper()));
            ui->tableWidget->setItem(i,10,new QTableWidgetItem(QString::number(mi_report_obj.value("aging_points").toInt())));

            if(mi_report_obj.value("b_ret").toInt() == 2)
            {
                ret_item->setData(Qt::UserRole, 2);
            }
            else if(mi_report_obj.value("b_ret").toInt() == 1)
            {
                ret_item->setData(Qt::UserRole,1);
            }
            else if(mi_report_obj.value("b_ret").toInt() == 0)
            {
                ret_item->setData(Qt::UserRole,3);
            }
            ret_item->setText(ret);

            ui->tableWidget->setItem(i,11,ret_item);
            ui->tableWidget->setItem(i,12,new QTableWidgetItem(mi_report_obj.value("start_time").toString()));
            ui->tableWidget->setItem(i,13,new QTableWidgetItem(mi_report_obj.value("stop_time").toString()));

            //版本号
            ui->tableWidget->setItem(i,14,new QTableWidgetItem(mi_report_obj.value("mim_version").toString()));
            ui->tableWidget->setItem(i,15,new QTableWidgetItem(mi_report_obj.value("mis_version").toString()));

            //测量宽度
            for(int j=0;j<14;j++)
            {
                QFontMetrics fontMetrics(ui->tableWidget->item(i,j)->font());
                QStringList lines = ui->tableWidget->item(i,j)->text().split("\r");

                for(int k=0;k<lines.size();k++)
                {
                    int width = fontMetrics.horizontalAdvance(lines[k]);
                    if(tmp_text_max[j] <  width)
                    {
                        tmp_text_max[j] = width;
                    }
                }
            }
        }
    }

    for(int i=0;i<14;i++)
    {
        ui->tableWidget->setColumnWidth(i,tmp_text_max[i]+30);
    }

//    ui->tableWidget->resizeColumnsToContents();
    ui->tableWidget->resizeRowsToContents();
}

void aging_mi_widget::set_select_way(int id)
{
    if(id == 0)
    {
        //隐藏和显示控件
        ui->start_id_lb->setVisible(true);
        ui->start_id_edt->setVisible(true);
        ui->stop_id_lb->setVisible(true);
        ui->stop_id_edt->setVisible(true);
        ui->batch_pb->setVisible(false);

        ui->sel_workorder_pb->setVisible(false);

        ui->msg_lb->clear();
        ui->start_id_edt->clear();
        ui->stop_id_edt->clear();
        m_mis.clear();
    }//工单
    else if(id == 1)
    {
        //隐藏控件
        ui->start_id_lb->setVisible(false);
        ui->start_id_edt->setVisible(false);
        ui->stop_id_lb->setVisible(false);
        ui->stop_id_edt->setVisible(false);
        ui->batch_pb->setVisible(false);

        ui->sel_workorder_pb->setVisible(true);

        ui->msg_lb->clear();
        ui->start_id_edt->clear();
        ui->stop_id_edt->clear();
        m_mis.clear();
    }
    else if(id == 2)
    {
        //隐藏和显示控件
        ui->start_id_lb->setVisible(false);
        ui->start_id_edt->setVisible(false);
        ui->stop_id_lb->setVisible(false);
        ui->stop_id_edt->setVisible(false);
        ui->batch_pb->setVisible(true);

        ui->sel_workorder_pb->setVisible(false);

        ui->msg_lb->clear();
        ui->start_id_edt->clear();
        ui->stop_id_edt->clear();
        m_mis.clear();
    }

}

void aging_mi_widget::export_aging_report(QString file_path)
{
#define EXCEL_FIELD_SIZE  17
    QJsonArray report_datas_arr = m_report.value("report_datas").toArray();
    QXlsx::Document xlsx;
    QXlsx::Worksheet *sheet1 = xlsx.currentWorksheet();
    QXlsx::Format float_format,format;
    int cur_index = 0;
    int ok_size = 0,again_size = 0,err_size = 0;
    /*老化记录头部*/
    //合并头
    sheet1->mergeCells(QXlsx::CellRange(1,1,1,EXCEL_FIELD_SIZE));
    format.setBorderStyle(QXlsx::Format::BorderThin);
    format.setHorizontalAlignment(QXlsx::Format::AlignHCenter);
    format.setVerticalAlignment(QXlsx::Format::AlignVCenter);
    format.setTextWarp(true);

    float_format.setNumberFormat("0.00");
    float_format.setBorderStyle(QXlsx::Format::BorderThin);
    float_format.setHorizontalAlignment(QXlsx::Format::AlignHCenter);
    float_format.setVerticalAlignment(QXlsx::Format::AlignVCenter);
    //合并第一行
    for (int row = 1; row <= 1; ++row) {
        for (int col = 1; col <= EXCEL_FIELD_SIZE; ++col) {
            sheet1->write(row, col, "", format);
        }
    }
    //第一行写入
    sheet1->write(1,1, "浙江奔一新能源有限公司");
    //合并第2行
    sheet1->mergeCells(QXlsx::CellRange(2,1,2,EXCEL_FIELD_SIZE));
    for (int row = 2; row <= 2; ++row) {
        for (int col = 1; col <= EXCEL_FIELD_SIZE; ++col) {
            sheet1->write(row, col, "", format);
        }
    }
    sheet1->write(2,1,"微逆老化记录");
    /* 定义各个字段名 */
    sheet1->write(3,1,"微逆编号",format);
    sheet1->setColumnWidth(1,1,12);

    sheet1->write(3,2,"额定功率",format);
    sheet1->setColumnWidth(2,2,12);

    sheet1->write(3,3,"老化位置",format);
    sheet1->setColumnWidth(3,3,12);

    sheet1->write(3,4,"标称功率",format);
    sheet1->setColumnWidth(4,4,12);

    sheet1->write(3,5,"最高功率",format);
    sheet1->setColumnWidth(5,5,12);

    sheet1->write(3,6,"最低功率",format);
    sheet1->setColumnWidth(6,6,21);

    sheet1->write(3,7,"最高温度",format);
    sheet1->setColumnWidth(7,7,21);

    sheet1->write(3,8,"累计原边故障1",format);
    sheet1->setColumnWidth(8,8,21);

    sheet1->write(3,9,"累计原边故障2",format);
    sheet1->setColumnWidth(9,9,18);

    sheet1->write(3,10,"累计副边故障",format);
    sheet1->setColumnWidth(10,10,18);

    sheet1->write(3,11,"数据点数",format);
    sheet1->setColumnWidth(11,11,21);

    sheet1->write(3,12,"老化结果",format);
    sheet1->setColumnWidth(12,12,21);

    sheet1->write(3,13,"老化开始时间",format);
    sheet1->setColumnWidth(13,13,21);

    sheet1->write(3,14,"老化结束时间",format);
    sheet1->setColumnWidth(14,14,21);

    sheet1->write(3,15,"原边版本号",format);
    sheet1->setColumnWidth(15,15,21);

    sheet1->write(3,16,"副边版本号",format);
    sheet1->setColumnWidth(16,16,21);

    sheet1->write(3,17,"备注说明",format);
    sheet1->setColumnWidth(17,17,21);


    /* 老化记录 微逆具体数据*/
    //微逆数量
    cur_index = 4;  //从第4行计数
    for(int i=0;i<report_datas_arr.size();i++)
    {
        QJsonObject mi_report = report_datas_arr[i].toObject();
        QJsonArray pv_data_array = mi_report.value("pv_data").toArray();
        int pv_data_size = pv_data_array.size();
        //如果是单路微逆
        if(mi_report.value("all_pv").toString() == QString::number(pv_data_size) && pv_data_size == 1)
        {
            QJsonObject pv0_report = mi_report.value("pv_data").toArray()[0].toObject();

            if(m_mis.value(mi_report.value("mi_cid").toString(),"") == "")
            {
                sheet1->write(cur_index,1,mi_report.value("mi_cid").toString(),format);
            }
            else
            {
                sheet1->write(cur_index,1,m_mis[mi_report.value("mi_cid").toString()],format);
            }


            if(mi_report.value("total_nominal_power").toInt() != 1000000)
            {
                sheet1->write(cur_index,2,mi_report.value("total_nominal_power").toInt(),format);
            }

            //老化位置
            if(m_mis.value(mi_report.value("pos_desc").toString(),"") == "")
            {
                sheet1->write(cur_index,3,mi_report.value("pos_desc").toString(),format);
            }
            else
            {
                sheet1->write(cur_index,3,m_mis[mi_report.value("pos_desc").toString()],format);
            }

            //标称功率
            if(mi_report.value("total_nominal_power").toInt() != 1000000)
            {
                sheet1->write(cur_index,4,mi_report.value("total_nominal_power").toInt(),format);
            }

            //最大功率
            if(pv0_report.value("pw_max").toInt() != DEFAULT_VALUE_MAX)
            {
                sheet1->write(cur_index,5,(float)pv0_report.value("pw_max").toInt()/100,float_format);
            }
            //最小功率
            if(pv0_report.value("pw_min").toInt() != DEFAULT_VALUE_MIN)
            {
                sheet1->write(cur_index,6,(float)pv0_report.value("pw_min").toInt()/100,float_format);
            }
            //最高温度
            if(pv0_report.value("tmax").toInt() != DEFAULT_VALUE_MAX)
            {
                sheet1->write(cur_index,7,(float)pv0_report.value("tmax").toInt()/100,float_format);
            }

            //累计原边故障1
            sheet1->write(cur_index,8,QString("%1").arg(pv0_report.value("mim_err").toInt(),4,16,QLatin1Char('0')).toUpper(),format);
            //累计原边故障2
            sheet1->write(cur_index,9,"",format);
            //累计副边故障
            sheet1->write(cur_index,10,QString("%1").arg(pv0_report.value("mis_err").toInt(),4,16,QLatin1Char('0')).toUpper(),format);
            //采集数据点数
            sheet1->write(cur_index,11,mi_report.value("aging_points").toInt(0),format);
            //老化开始时间
            sheet1->write(cur_index,12,mi_report.value("start_time").toString(),format);
            //老化结束时间
            sheet1->write(cur_index,13,mi_report.value("stop_time").toString(),format);

            //原边版本号
            if(m_mis.value(mi_report.value("mim_version").toString(),"") == "")
            {
                sheet1->write(cur_index,14,mi_report.value("mim_version").toString(),format);
            }
            else
            {
                sheet1->write(cur_index,14,m_mis[mi_report.value("mim_version").toString()],format);
            }

            //副边版本号
            if(m_mis.value(mi_report.value("mis_version").toString(),"") == "")
            {
                sheet1->write(cur_index,15,mi_report.value("mis_version").toString(),format);
            }
            else
            {
                sheet1->write(cur_index,15,m_mis[mi_report.value("mis_version").toString()],format);
            }

            //调整结果背景色格式
            if(mi_report.value("b_ret").toInt() == 0)
            {
                ok_size++;
                sheet1->write(cur_index,11,pv0_report.value("pv_ret").toString(),format);
            }
            else if(mi_report.value("b_ret").toInt() == 1)
            {
                format.setPatternBackgroundColor(QColor(240,255,108));
                sheet1->write(cur_index,11,pv0_report.value("pv_ret").toString(),format);
                again_size++;
            }
            else if(mi_report.value("b_ret").toInt() == 2)
            {
                err_size ++;
                format.setPatternBackgroundColor(QColor(255,0,0));
                sheet1->write(cur_index,11,pv0_report.value("pv_ret").toString(),format);
            }
            //恢复背景色格式
            QColor tmp_color = QColor(255,255,255);
            tmp_color.setAlpha(0);
            format.setPatternBackgroundColor(tmp_color);

            sheet1->write(cur_index,12,"",format);

        }//如果是多路
        else if(mi_report.value("all_pv").toString() == QString::number(pv_data_size) &&
                (pv_data_size== 2 || pv_data_size == 4))
        {
            QXlsx::RichString max_pw_str,min_pw_str,max_temp_str,ret_str;
            QString mim_err1,mim_err2,mis_err;
            QJsonObject total_data = mi_report.value("total_data").toObject();


            if(total_data.value("pw_max").toInt() != DEFAULT_VALUE_MAX)
            {
                max_pw_str.addFragment("整机:" + QString::number(((double)total_data.value("pw_max").toInt())/100,'f',2),format);
            }
            if(total_data.value("pw_min").toInt() != DEFAULT_VALUE_MIN)
            {
                min_pw_str.addFragment("整机:" + QString::number(((double)total_data.value("pw_min").toInt())/100,'f',2),format);
            }
            if(total_data.value("tmax").toInt() != DEFAULT_VALUE_MAX)
            {
                max_temp_str.addFragment("整机:" + QString::number(((double)total_data.value("tmax").toInt())/100,'f',2),format);
            }

            ret_str.addFragment("整机:"  + total_data.value("total_ret").toString(),format);
            for(int j=0;j<pv_data_size;j++)
            {
                QJsonObject one_pv_data = pv_data_array[j].toObject();
                if(one_pv_data.value("pw_max").toInt() != DEFAULT_VALUE_MAX)
                {
                    max_pw_str.addFragment("\nPV" + QString::number(j+1) + ":" + QString::number(((double)one_pv_data.value("pw_max").toInt())/100,'f',2),format);
                }
                if(one_pv_data.value("pw_min").toInt() != DEFAULT_VALUE_MIN)
                {
                    min_pw_str.addFragment("\nPV" + QString::number(j+1) + ":" + QString::number(((double)one_pv_data.value("pw_min").toInt())/100,'f',2),format);
                }
                if(one_pv_data.value("tmax").toInt() != DEFAULT_VALUE_MAX)
                {
                    max_temp_str.addFragment("\nPV" + QString::number(j+1) + ":" + QString::number(((double)one_pv_data.value("tmax").toInt())/100,'f',2),format);
                }

                ret_str.addFragment("\nPV"  + QString::number(j+1) + ":" + one_pv_data.value("pv_ret").toString(),format);

                if(j== 0)
                {
                    mim_err1 = QString("%1").arg(one_pv_data.value("mim_err").toInt(),4,16,QLatin1Char('0')).toUpper();
                    mis_err = QString("%1").arg(one_pv_data.value("mis_err").toInt(),4,16,QLatin1Char('0')).toUpper();
                }
                else if(j==3)
                {
                    mim_err2 = QString("%1").arg(one_pv_data.value("mim_err").toInt(),4,16,QLatin1Char('0')).toUpper();
                }
            }


            if(m_mis.value(mi_report.value("mi_cid").toString(),"") == "")
            {
                sheet1->write(cur_index,1,mi_report.value("mi_cid").toString(),format);
            }
            else
            {
                sheet1->write(cur_index,1,m_mis[mi_report.value("mi_cid").toString()],format);
            }


            if(pv_data_size == 2 && mi_report.value("total_nominal_power").toInt() != 2000000)
            {
               sheet1->write(cur_index,2,mi_report.value("total_nominal_power").toInt(),format);
            }
            else if(pv_data_size == 4 && mi_report.value("total_nominal_power").toInt() != 4000000)
            {
                sheet1->write(cur_index,2,mi_report.value("total_nominal_power").toInt(),format);
            }

            sheet1->write(cur_index,3,max_pw_str,format);
            sheet1->write(cur_index,4,min_pw_str,format);
            sheet1->write(cur_index,5,max_temp_str,format);
            sheet1->write(cur_index,6,mim_err1,format);
            sheet1->write(cur_index,7,mim_err2,format);
            sheet1->write(cur_index,8,mis_err,format);
            sheet1->write(cur_index,9,mi_report.value("aging_points").toInt(0),format);
            sheet1->write(cur_index,10,mi_report.value("start_time").toString(),format);
            sheet1->write(cur_index,11,mi_report.value("stop_time").toString(),format);


            //调整结果背景色格式
            if(mi_report.value("b_ret").toInt() == 0)
            {
                ok_size++;
                format.setPatternBackgroundColor(QColor(138,255,165));
                sheet1->write(cur_index,11,ret_str,format);
            }
            else if(mi_report.value("b_ret").toInt() == 1)
            {
                format.setPatternBackgroundColor(QColor(240,255,108));
                sheet1->write(cur_index,11,ret_str,format);
                again_size++;
            }
            else if(mi_report.value("b_ret").toInt() == 2)
            {
                err_size ++;
                format.setPatternBackgroundColor(QColor(255,0,0));
                sheet1->write(cur_index,11,ret_str,format);
            }
            //恢复背景色格式
            QColor tmp_color = QColor(255,255,255);
            tmp_color.setAlpha(0);
            format.setPatternBackgroundColor(tmp_color);

            sheet1->write(cur_index,12,"",format);
        }

        cur_index ++;
    }//i

    sheet1->write(cur_index,11,"通过率:" + QString::number((float)ok_size/(ok_size + err_size)*100)+ "%",format);

    //保存
    xlsx.saveAs(file_path);
}

void aging_mi_widget::on_select_way_cb_currentIndexChanged(int index)
{

    set_select_way(index);
}

void aging_mi_widget::on_sel_workorder_pb_clicked()
{
    m_workorder_dlg.exec();
}


void aging_mi_widget::on_select_pb_clicked()
{
    ui->tableWidget->clearContents();

    //按编号
    if(ui->select_way_cb->currentIndex() == 0)
    {
        if(!bym_base::is_cid_valid(ui->start_id_edt->text()))
        {
            QMessageBox::information(this,"提示","起始编号不符合微逆编号");
            return;
        }
        else if(!bym_base::is_cid_valid(ui->stop_id_edt->text()))
        {
            QMessageBox::information(this,"提示","结束编号不符合微逆编号");
            return;
        }
        else if(ui->start_id_edt->text() > ui->stop_id_edt->text())
        {
            QMessageBox::information(this,"提示","起始编号不可以大于结束编号");
            return;
        }


        QJsonObject sel_param_obj;
        QJsonArray mis;

        for(uint i= ui->start_id_edt->text().toUInt();i<=ui->stop_id_edt->text().toUInt();i++)
        {
            mis.append(QString::number(i));
        }

        sel_param_obj.insert("mode",0);
        sel_param_obj.insert("mis",mis);
        QJsonObject data;
        data.insert("select_param",sel_param_obj);
        emit s_read_aging_data(20000,"/aging_report",data);


    }//按工单
    else if(ui->select_way_cb->currentIndex() == 1)
    {
        QStringList tmp_mis = m_mis.keys();
        QJsonObject sel_param_obj;
        QJsonArray mis;

        for(int i=0;i<tmp_mis.size();i++)
        {
            mis.append(tmp_mis[i]);
        }
        sel_param_obj.insert("mode",0);
        sel_param_obj.insert("mis",mis);

        QJsonObject data;
        data.insert("select_param",sel_param_obj);
        emit s_read_aging_data(60000,"/aging_report",data);
    }
    else if(ui->select_way_cb->currentIndex() == 2)
    {
        QStringList tmp_mis = m_mis.keys();
        QJsonObject sel_param_obj;
        QJsonArray mis;

        for(int i=0;i<tmp_mis.size();i++)
        {
            mis.append(tmp_mis[i]);
        }
        sel_param_obj.insert("mode",1);
        sel_param_obj.insert("mis",mis);
        sel_param_obj.insert("start_time",m_start_time);
        QJsonObject data;
        data.insert("select_param",sel_param_obj);
        emit s_read_aging_data(60000,"/aging_report",data);
    }
}


void aging_mi_widget::on_export_pb_clicked()
{

    QString folderPath = QFileDialog::getSaveFileName(nullptr, "选择存放的文件夹", QCoreApplication::applicationDirPath()) + ".xlsx";
    QFileInfo fileInfo(folderPath);
    QDir dir(fileInfo.absolutePath());
    QFile file(fileInfo.filePath());
    bool b_export = false;
    if(dir.exists())
    {
        if(file.exists())
        {
            QMessageBox::StandardButton reply;
            reply = QMessageBox::question(this,"提示","存在相同的文件名,是否覆盖",QMessageBox::Yes|QMessageBox::No);
            if(reply == QMessageBox::Yes)
            {
                b_export = true;
            }
        }
        else
        {
           b_export = true;
        }
    }
    else {
        QMessageBox::warning(this,"警告","文件夹已经不存在,请重新选择");
    }
    //文件路径合法
    if(b_export)
    {
        //导出内容
        export_aging_report(folderPath);
        QMessageBox::information(this,"通知","导出老化报告成功");
        //QMessageBox::warning(this,"提示","准备导出");
    }
}


void aging_mi_widget::on_pushButton_clicked()
{
    QJsonDocument js_doc = QJsonDocument::fromJson(bridge::ins()->core()->get_user().algorithm.toUtf8());
    judge_param_set_dlg dlg(js_doc.object());

    dlg.exec();
}


void aging_mi_widget::on_tableWidget_itemDoubleClicked(QTableWidgetItem *item)
{
    QString start_time = ui->tableWidget->item(item->row(),12)->text();
    QString stop_time = ui->tableWidget->item(item->row(),13)->text();

    if(item->column() == 0)
    {
        if(bym_base::is_cid_valid(item->text()))
        {
            emit s_open_midetail_data_widget(item->text(),start_time,stop_time);
        }
        else
        {
            QMessageBox::information(this,"警告","编号不符合要求");
        }
    }
    else if(item->column() == 6 || item->column() == 7 ||item->column() == 8)
    {
        QString mi = ui->tableWidget->item(item->row(),0)->text();
        err_analysis_dlg *tmp_dlg = new err_analysis_dlg();
        tmp_dlg->setAttribute(Qt::WA_DeleteOnClose);
        tmp_dlg->set_combobox_enable(false);
        tmp_dlg->analysis_err_code(bym_base::analysis_type(mi),
                                   ui->tableWidget->item(item->row(),6)->text(),
                                   ui->tableWidget->item(item->row(),7)->text(),
                                   ui->tableWidget->item(item->row(),8)->text());
        tmp_dlg->exec();
    }


}


void aging_mi_widget::on_batch_pb_clicked()
{
    history_batch_set_dialog *batch_dlg = new history_batch_set_dialog;
    batch_dlg->setAttribute(Qt::WA_DeleteOnClose);

    connect(batch_dlg,&history_batch_set_dialog::s_get_batch_param,this,&aging_mi_widget::onm_get_batch_mis);

    connect(batch_dlg,&history_batch_set_dialog::s_get_batch_list,bridge::ins()->csclient(),&cs_client::onm_send);
    connect(bridge::ins()->core(),&core_mg::s_new_batch_list,batch_dlg,&history_batch_set_dialog::display_batch_data);
    batch_dlg->exec();
}

