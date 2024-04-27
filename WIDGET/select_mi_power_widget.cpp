#include "select_mi_power_widget.h"
#include "ui_select_mi_power_widget.h"

#include "err_analysis_dlg.h"
#include "bym_base.h"
#include <QJsonObject>
#include <QJsonArray>




select_mi_power_widget::select_mi_power_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::select_mi_power_widget)
{
    ui->setupUi(this);
    //日期选择控件设置  可以为空
    ui->date_edt->setCalendarPopup(true);
    ui->date_edt->setNullable(true);
    ui->date_edt->setNullDatetime();
    ui->date_edt->setDateTime(QDateTime::currentDateTime());


    ui->tableWidget->setColumnCount(16);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()
                                             << "网关" << "微逆" << "更新时间" << "标称功率" << "路" << "功率" << "发电量" << "电压"
                                             << "温度" << "并网电压" << "并网频率" << "原边故障代码"  << "副边故障代码" << "原边版本"
                                             << "副边版本" << "补发数据");
    //设置最后一栏自适应长度
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    //开启交替行背景色,在设置style为交替颜色时必须开启
    ui->tableWidget->setAlternatingRowColors(true);
    //设置不可编辑
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //关闭默认行号
    ui->tableWidget->verticalHeader()->setHidden(true);
    ui->tableWidget->setSelectionBehavior(QTableWidget::SelectRows);

    //翻页的时候 重新筛选
    connect(ui->flipover_wd,&flipover_widget::s_new_page_select,this,&select_mi_power_widget::on_select_pb_clicked);
}

select_mi_power_widget::~select_mi_power_widget()
{
    delete ui;
}

void select_mi_power_widget::set_mi_cid_text(QString cid)
{
    ui->mi_edt->setText(cid);
}
void select_mi_power_widget::set_mi_cid_enable(bool flag)
{
    ui->mi_edt->setEnabled(flag);
}


void select_mi_power_widget::on_select_pb_clicked()
{
    QJsonObject body_obj;
    QJsonArray mi_cid_array;

    QString date = ui->date_edt->dateTime().toString("yyyy-MM-dd");

    if(ui->mi_edt->text() != "")
        mi_cid_array.append(ui->mi_edt->text());

    if(ui->mim_err_edt->text()!= "")
        body_obj.insert("mim_err",ui->mim_err_edt->text());

    if(ui->mis_err_edt->text() != "")
        body_obj.insert("mis_err",ui->mis_err_edt->text());

    if(date != "")
    {
        body_obj.insert("start_date",date + " 00:00:00");
        body_obj.insert("stop_date",date + " 23:59:59");
    }
    else
    {
        body_obj.insert("start_date","2021-7-23 13:58:02");
        body_obj.insert("stop_date","2025-7-23 13:58:02");
    }

    body_obj.insert("nums",QString::number(ui->flipover_wd->get_one_page_num()));
    body_obj.insert("start_num",QString::number(ui->flipover_wd->get_page_index()));
    body_obj.insert("mi_cid",mi_cid_array);

    //用不同的url  区分回来时数据的显示界面  因为mi_detail_widget  和 当前界面都用的这个控件
    if(ui->mi_edt->isEnabled())
    {
        emit s_select_mi_power_data(5000,"/r_mi_power",body_obj);
    }
    else
    {
        emit s_select_mi_power_data(5000,"/r_one_mi_power",body_obj);
    }
}

void select_mi_power_widget::onm_display_power_data(QString path,QJsonObject data)
{
    if(path == "/r_one_mi_power")
    {
        if(ui->mi_edt->isEnabled())
            return ;

        if(data.value("mi_cid").toString() != ui->mi_edt->text())
            return;
    }
    else if(path == "/r_mi_power")
    {
        if(!ui->mi_edt->isEnabled())
            return ;
    }

    QJsonArray datas_array;

    datas_array = data.value("datas").toArray();
    //根据总数 设置翻页控件
    ui->flipover_wd->set_page_num(data.value("all_size").toString().toInt());

    //清空数据内容
    ui->tableWidget->clearContents();
    //设置行数
    ui->tableWidget->setRowCount(datas_array.size());

    for(int i=0;i<datas_array.size();i++)
    {
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(datas_array[i].toObject().value("emu_cid").toString()));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(datas_array[i].toObject().value("mi_cid").toString()));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(datas_array[i].toObject().value("sys_time").toString()));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(QString::number(datas_array[i].toObject().value("nominal_power").toInt())));
        ui->tableWidget->setItem(i,4,new QTableWidgetItem(QString::number(datas_array[i].toObject().value("pv_id").toInt())));
        ui->tableWidget->setItem(i,5,new QTableWidgetItem(datas_array[i].toObject().value("power").toString()));
        ui->tableWidget->setItem(i,6,new QTableWidgetItem(datas_array[i].toObject().value("energy").toString()));
        ui->tableWidget->setItem(i,7,new QTableWidgetItem(datas_array[i].toObject().value("pv").toString()));
        ui->tableWidget->setItem(i,8,new QTableWidgetItem(datas_array[i].toObject().value("temperature").toString()));
        ui->tableWidget->setItem(i,9,new QTableWidgetItem(datas_array[i].toObject().value("gridv").toString()));
        ui->tableWidget->setItem(i,10,new QTableWidgetItem(datas_array[i].toObject().value("gridf").toString()));
        ui->tableWidget->setItem(i,11,new QTableWidgetItem(datas_array[i].toObject().value("mim_err").toString()));
        ui->tableWidget->setItem(i,12,new QTableWidgetItem(datas_array[i].toObject().value("mis_err").toString()));
        ui->tableWidget->setItem(i,13,new QTableWidgetItem(datas_array[i].toObject().value("mim_version").toString()));
        ui->tableWidget->setItem(i,14,new QTableWidgetItem(datas_array[i].toObject().value("mis_version").toString()));
        ui->tableWidget->setItem(i,15,new QTableWidgetItem(datas_array[i].toObject().value("reissue_data").toString()));

        for(int j=0;j<16;j++)
        {
            //设置每项居中
            ui->tableWidget->item(i,j)->setTextAlignment(Qt::AlignCenter);
        }
    }
}

void select_mi_power_widget::on_tableWidget_itemDoubleClicked(QTableWidgetItem *item)
{
    //ID  跳转到微逆详细界面
    if(item->column() == 1)
    {
        if(bym_base::is_cid_valid(item->text()))
        {
            emit s_open_midetail_data_widget(item->text(),"","");
        }
    }

    //ERR 弹出微逆故障码的解析界面
    if(item->column() == 11 || item->column() == 12)
    {
        QString mi;
        int mi_type;
        err_analysis_dlg *tmp_dlg = nullptr;

        mi = ui->tableWidget->item(item->row(),1)->text();
        mi_type = bym_base::analysis_type(mi);
        tmp_dlg = new err_analysis_dlg();

        if(tmp_dlg == nullptr)
            return;

        tmp_dlg->setAttribute(Qt::WA_DeleteOnClose);
        //设置 主动选取失效
        tmp_dlg->set_combobox_enable(false);
        if(mi_type == 1)
        {
            tmp_dlg->analysis_err_code(mi_type,
                                   ui->tableWidget->item(item->row(),11)->text(),
                                   "",
                                   ui->tableWidget->item(item->row(),12)->text());
        }
        else if(mi_type == 2)
        {
            tmp_dlg->analysis_err_code(mi_type,
                               ui->tableWidget->item(item->row(),11)->text(),
                               "",
                               ui->tableWidget->item(item->row(),12)->text());
        }
        else if(mi_type == 4)
        {
            if(ui->tableWidget->item(item->row(),4)->text() == "1" ||
               ui->tableWidget->item(item->row(),4)->text() == "2")
            {
                tmp_dlg->analysis_err_code(mi_type,
                                   ui->tableWidget->item(item->row(),11)->text(),
                                   "",
                                   ui->tableWidget->item(item->row(),12)->text());
            }
            else if(ui->tableWidget->item(item->row(),4)->text() == "3" ||
                    ui->tableWidget->item(item->row(),4)->text() == "4")
            {
                tmp_dlg->analysis_err_code(mi_type,
                                   "",
                                   ui->tableWidget->item(item->row(),11)->text(),
                                   ui->tableWidget->item(item->row(),12)->text());
            }
        }
        tmp_dlg->exec();
    }
}

