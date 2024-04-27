#include "close_button.h"
#include "ui_close_button.h"

#include <QPainter>
#include <QStyleOption>
#include <QMouseEvent>

close_button::close_button(QString bt_name,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::close_button)
{
    ui->setupUi(this);

    ui->toolButton->setIcon(QIcon(":/icon/icon/close_bt.ico"));
    ui->label->setText(bt_name);

    ui->label->installEventFilter(this);
    ui->toolButton->installEventFilter(this);
    ui->toolButton->setFixedHeight(this->height());
}

close_button::~close_button()
{
    delete ui;
}

void close_button::set_focus(bool status)
{
    if(status)
    {
        this->setStyleSheet("background-color:rgb(181,217,255)");  //天蓝色
    }
    else {
        this->setStyleSheet(0);
    }

}

//void close_button::set_index(uint32_t widget_index)
//{
//    this->widget_index = widget_index;
//}

//void close_button::set_name(QString name)
//{
//    ui->label->setText(name);
//}

//uint32_t close_button::get_index()
//{
//    return widget_index;
//}

void close_button::hide_button()
{
    ui->toolButton->hide();
}

void close_button::show_button()
{
    ui->toolButton->show();
}

//void close_button::minus_index_one()
//{
//    widget_index --;
//}


void close_button::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.setPen(QPen(QColor(181,217,255),2)); //设置画笔记颜色
    p.drawRect(0, 0, width()-1, height()-1);
}
//事件过滤器   鼠标点击label事件
bool close_button::eventFilter(QObject *watched, QEvent *event)
{
    //判断对象是否为label_
    if (watched == ui->label)
    {
        //判断事件类型是否为鼠标事件
        if (event->type() == QEvent::MouseButtonPress)
        {
            //转换为鼠标事件
            QMouseEvent* mouseenevt = static_cast<QMouseEvent*>(event);
            //判断鼠标左键点击
            if (mouseenevt->button() == Qt::LeftButton)
            {
                QString name = ui->label->text();
                emit s_clicked_label(name);
                return true;
            }
        }
    }
    else if(watched == ui->toolButton){
        if (event->type() == QEvent::MouseButtonPress)
        {
            //转换为鼠标事件
            QMouseEvent* mouseenevt = static_cast<QMouseEvent*>(event);
            //判断鼠标左键点击
            if (mouseenevt->button() == Qt::LeftButton)
            {
                QString name = ui->label->text();
                emit s_clicked_close_button(name);
                return true;
            }
        }
    }

    return QWidget::eventFilter(watched, event);
}
