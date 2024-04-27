#include "select_user_act_widget.h"
#include "ui_select_user_act_widget.h"
#include <QJsonArray>
#include <QToolTip>
select_user_act_widget::select_user_act_widget(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::select_user_act_widget)
{
    ui->setupUi(this);
    //日期选择控件设置  可以为空
    ui->date_edt->setCalendarPopup(true);
    ui->date_edt->setNullable(true);
    ui->date_edt->setNullDatetime();
    ui->date_edt->setDateTime(QDateTime::currentDateTime());

    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setHorizontalHeaderLabels(
                QStringList() << "用户" << "操作时间" << "操作类型" << "操作内容");

    //设置最后一栏自适应长度
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    //开启交替行背景色,在设置style为交替颜色时必须开启
    ui->tableWidget->setAlternatingRowColors(true);
    //设置不可编辑
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //关闭默认行号
    ui->tableWidget->verticalHeader()->setHidden(true);
    ui->tableWidget->setSelectionBehavior(QTableWidget::SelectRows);

    //开启tips
//    ui->tableWidget->setMouseTracking(true);
//    connect(ui->tableWidget,&QTableWidget::cellEntered,this,&select_user_act_widget::onm_show_tips);
    connect(ui->flipover_wd,&flipover_widget::s_new_page_select,this,&select_user_act_widget::on_select_pb_clicked);
}

select_user_act_widget::~select_user_act_widget()
{
    delete ui;
}

void select_user_act_widget::on_select_pb_clicked()
{
    QJsonObject param;

    QString date = ui->date_edt->dateTime().toString("yyyy-MM-dd");

    param.insert("user",ui->user_edt->text());
    if(ui->act_cb->currentIndex() == 1)
    {
        param.insert("act",1);
    }
    else if(ui->act_cb->currentIndex() == 2)
    {
        param.insert("act",2);
    }
    else if(ui->act_cb->currentIndex() == 3)
    {
        param.insert("act",3);
    }
    else
    {
        param.insert("act",-1);
    }

    if(date != "")
    {
        param.insert("start_date",date + " 00:00:00");
        param.insert("stop_date",date + " 23:59:59");
    }
    else
    {
        param.insert("start_date","2021-7-23 13:58:02");
        param.insert("stop_date","2025-7-23 13:58:02");
    }

    param.insert("nums",QString::number(ui->flipover_wd->get_one_page_num()));
    param.insert("start_num",QString::number(ui->flipover_wd->get_page_index()));

    emit s_select_user_act(5000,"/r_user_act",param);
}


//void select_user_act_widget::onm_show_tips(int row, int column)
//{
//    QTableWidgetItem *item = ui->tableWidget->item(row,column);
//    if(item == nullptr)
//    {
//        return;
//    }

//    if(column == 3)
//    {
//        //QPoint globalPos = mapToGlobal(rect().topLeft()) + visualRect(item->index().sibling(row, 0)).topLeft();
//        m_tips.showTooltip(item->text(),QCursor::pos());
//    }
//}

//void select_user_act_widget::onm_hide_tips()
//{
//    m_tips.hide();
//}

//void select_user_act_widget::leaveEvent(QEvent *event)
//{
//    Q_UNUSED(event);
//    onm_hide_tips();
//}



void select_user_act_widget::onm_display_user_act(QJsonObject data)
{
    QJsonArray datas_array = data.value("datas").toArray();
    ui->flipover_wd->set_page_num(data.value("all_size").toString().toInt());

    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(datas_array.size());

    for(int i=0;i<datas_array.size();i++)
    {
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(datas_array[i].toObject().value("user").toString()));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(datas_array[i].toObject().value("act_time").toString()));
        if(datas_array[i].toObject().value("act").toInt() == 1)
        {
            ui->tableWidget->setItem(i,2,new QTableWidgetItem("删除"));
        }
        else if(datas_array[i].toObject().value("act").toInt() == 2)
        {
            ui->tableWidget->setItem(i,2,new QTableWidgetItem("添加"));
        }
        else if(datas_array[i].toObject().value("act").toInt() == 3)
        {
            ui->tableWidget->setItem(i,2,new QTableWidgetItem("控制"));
        }
        else
        {
            ui->tableWidget->setItem(i,2,new QTableWidgetItem(""));
        }
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(datas_array[i].toObject().value("act_desc").toString()));
        for(int j=0;j<4;j++)
        {
            //设置每项居中
            ui->tableWidget->item(i,j)->setTextAlignment(Qt::AlignCenter);
        }
    }

}

