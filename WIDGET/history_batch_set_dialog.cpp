#include "history_batch_set_dialog.h"
#include "ui_history_batch_set_dialog.h"

#include <QMessageBox>


history_batch_set_dialog::history_batch_set_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::history_batch_set_dialog)
{
    ui->setupUi(this);

    ui->start_dedt->setCalendarPopup(true);
    ui->start_dedt->setNullable(true);
    ui->start_dedt->setNullDatetime();

    ui->stop_dedt->setCalendarPopup(true);
    ui->stop_dedt->setNullable(true);
    ui->stop_dedt->setNullDatetime();

    ui->batch_tablewidget->setColumnCount(1);
    ui->batch_tablewidget->setHorizontalHeaderLabels(QStringList() << "批次开始老化时间");
    //开启交替行背景色,在设置style为交替颜色时必须开启
    ui->batch_tablewidget->setAlternatingRowColors(true);
    //设置不可编辑
    ui->batch_tablewidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->batch_tablewidget->setSelectionBehavior(QTableWidget::SelectRows);
    ui->batch_tablewidget->horizontalHeader()->setStretchLastSection(true);


    ui->mis_tablewidget->setColumnCount(1);
    ui->mis_tablewidget->setHorizontalHeaderLabels(QStringList() << "当前选中批次的微逆列表");
    //开启交替行背景色,在设置style为交替颜色时必须开启
    ui->mis_tablewidget->setAlternatingRowColors(true);
    //设置不可编辑
    ui->mis_tablewidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->mis_tablewidget->setSelectionBehavior(QTableWidget::SelectRows);
    ui->mis_tablewidget->horizontalHeader()->setStretchLastSection(true);
}

history_batch_set_dialog::~history_batch_set_dialog()
{
    delete ui;
}

void history_batch_set_dialog::display_batch_data(QJsonObject batch)
{
    QJsonArray batch_array = batch.value("batchs").toArray();


    m_batch = batch;
    if(batch_array.size() > 0)
    {
        QJsonArray mis;
        ui->batch_tablewidget->setRowCount(batch_array.size());
        for(int i=0;i<batch_array.size();i++)
        {
            ui->batch_tablewidget->setItem(i,0,new QTableWidgetItem(batch_array[i].toObject().value("start_time").toString()));
        }
        mis = batch_array[0].toObject().value("mis").toArray();
        ui->mis_tablewidget->setRowCount(mis.size());
        for(int i=0;i<mis.size();i++)
        {
            ui->mis_tablewidget->setItem(i,0,new QTableWidgetItem(mis[i].toString()));
        }
        ui->batch_tablewidget->selectRow(0);
    }
    else
    {
        QMessageBox::information(this,"提示","所选时间段并没有老化批次");
    }
}


void history_batch_set_dialog::on_select_pb_clicked()
{
    //要筛选的时间 范围
    QString start_date = ui->start_dedt->dateTime().toString("yyyy-MM-dd") + " 00:00:00";
    QString stop_date = ui->stop_dedt->dateTime().toString("yyyy-MM-dd") + " 23:59:59";

    //必须有筛选时间段 且时间要正常
    if(start_date == "" || stop_date == "")
    {
        QMessageBox::information(this,"提示","筛选时间不能为空,避免筛选数据量过大");
        return;
    }
    else if(start_date>stop_date)
    {
        QMessageBox::information(this,"提示","起始时间不能大于截至时间");
        return;
    }
    else if(ui->start_dedt->dateTime().daysTo(ui->stop_dedt->dateTime()) > 7)
    {
        QMessageBox::information(this,"提示","不要选取时间超过7天，避免筛选数据量过大");
        return;
    }
    //筛选前 清空旧数据
    ui->batch_tablewidget->clearContents();
    ui->mis_tablewidget->clearContents();
    //清空后重置数量
    ui->mis_tablewidget->setRowCount(0);
    ui->batch_tablewidget->setRowCount(0);
    //请求筛选 历史批次
    QJsonObject param;
    param.insert("start_time",start_date);
    param.insert("stop_time",stop_date);

    emit s_get_batch_list(60000,"/batch_list",param);

}


void history_batch_set_dialog::on_batch_tablewidget_itemClicked(QTableWidgetItem *item)
{
    QString cur_text = ui->batch_tablewidget->item(item->row(),0)->text();
    QJsonArray batch_array = m_batch.value("batchs").toArray();
    //重置mis_tablewidget
    ui->mis_tablewidget->clearContents();
    ui->mis_tablewidget->setRowCount(0);



    for(int i=0;i<batch_array.size();i++)
    {
        if(batch_array[i].toObject().value("start_time").toString() == cur_text)
        {
            int mis_count = 0;
            //拿到新数据后默认显示第一个批次 的 mis
            mis_count = batch_array[i].toObject().value("mis").toArray().size();
            ui->mis_tablewidget->setRowCount(mis_count);
            for(int j=0;j<mis_count;j++)
            {
                ui->mis_tablewidget->setItem(0,j,new QTableWidgetItem(batch_array[i].toObject().value("mis").toArray()[j].toString()));
            }
            break;
        }
    }

}


void history_batch_set_dialog::on_ok_pb_clicked()
{
    int cur_row = ui->batch_tablewidget->currentRow();

    if(cur_row ==-1)
    {
        QMessageBox::information(this,"提示","点击确定,必须选择一个批次");
        return;
    }
    QString cur_text = ui->batch_tablewidget->item(cur_row,0)->text();
    //获取选中批次的列表对象  //上层拿到去获取实际数据
    //emit s_get_batch_param(batch,m_batch[batch]);
    QJsonArray batch_array = m_batch.value("batchs").toArray();
    for(int i=0;i<batch_array.size();i++)
    {
        if(batch_array[i].toObject().value("start_time").toString() == cur_text)
        {
            QStringList mis;
            int mis_count = mis_count = batch_array[i].toObject().value("mis").toArray().size();
            for(int j=0;j<mis_count;j++)
            {
                mis.append(batch_array[i].toObject().value("mis").toArray()[j].toString());
            }

            emit s_get_batch_param(cur_text,mis);
            break;
        }
    }



    this->close();
}

void history_batch_set_dialog::on_cache_pb_clicked()
{
    this->close();
}

