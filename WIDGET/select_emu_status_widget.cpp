#include "select_emu_status_widget.h"
#include "ui_select_emu_status_widget.h"



select_emu_status_widget::select_emu_status_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::select_emu_status_widget)
{
    ui->setupUi(this);

    //日期选择控件设置  可以为空
    ui->date_edt->setCalendarPopup(true);
    ui->date_edt->setNullable(true);
    ui->date_edt->setNullDatetime();
    ui->date_edt->setDateTime(QDateTime::currentDateTime());

    ui->tableWidget->setColumnCount(7);
    ui->tableWidget->setHorizontalHeaderLabels(
        QStringList() << "网关" << "网关状态" << "运行模式" << "信号强度" << "功能码" << "网关版本"<< "更新时间");


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
    connect(ui->flipover_wd,&flipover_widget::s_new_page_select,this,&select_emu_status_widget::on_select_pb_clicked);

}

select_emu_status_widget::~select_emu_status_widget()
{
    delete ui;
}

void select_emu_status_widget::on_select_pb_clicked()
{
    QJsonObject body_obj;

    QString date = ui->date_edt->dateTime().toString("yyyy-MM-dd");
    if(date != "")
    {
        body_obj.insert("start_date",date + " 00:00:00");
        body_obj.insert("stop_date",date + " 23:59:59");
    }


    body_obj.insert("nums",QString::number(ui->flipover_wd->get_one_page_num()));
    body_obj.insert("start_num",QString::number(ui->flipover_wd->get_page_index()));
    body_obj.insert("emu_cid",ui->emu_cid_edt->text());

    emit s_select_emu_status(5000,"/r_emu_status",body_obj);
}

void select_emu_status_widget::onm_display_emu_status(QJsonObject data)
{
    QJsonArray datas_array = data.value("datas").toArray();
    //根据总数 设置翻页控件
    ui->flipover_wd->set_page_num(data.value("all_size").toString().toInt());
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(datas_array.size());
    for(int i=0;i<datas_array.size();i++)
    {
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(datas_array[i].toObject().value("emu_cid").toString()));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(datas_array[i].toObject().value("status").toString()));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(datas_array[i].toObject().value("run_mode").toString()));


        bool ok = false;
        int v_sign = 0;

        v_sign = datas_array[i].toObject().value("sign").toString().toInt(&ok,16);

        if(ok)
        {
            if(v_sign > 127)
            {
                v_sign = v_sign -256;
            }

            ui->tableWidget->setItem(i,3,new QTableWidgetItem(QString::number(v_sign)));
        }
        else
        {
            ui->tableWidget->setItem(i,3,new QTableWidgetItem("数据异常"));
        }
        ui->tableWidget->setItem(i,4,new QTableWidgetItem(datas_array[i].toObject().value("func").toString()));

        //网关版本
        ui->tableWidget->setItem(i,5,new QTableWidgetItem(datas_array[i].toObject().value("hard_version").toString()));

        ui->tableWidget->setItem(i,6,new QTableWidgetItem(datas_array[i].toObject().value("sys_time").toString()));

        for(int j=0;j<7;j++)
        {
            //设置每项居中
            ui->tableWidget->item(i,j)->setTextAlignment(Qt::AlignCenter);
        }
    }


}

