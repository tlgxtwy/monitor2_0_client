#include "my_stacked_widget.h"
#include "ui_my_stacked_widget.h"

#include "Qslog.h"

my_stacked_widget::my_stacked_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::my_stacked_widget)
{
    ui->setupUi(this);

    setStyleSheet(QString::fromUtf8("#stackedWidget{border:1px solid gray}"));

    //信号: 当前页面修改  槽：切换focus按钮  并发送信号
    connect(ui->stackedWidget,&QStackedWidget::currentChanged,this,&my_stacked_widget::onm_current_widget_changed);
}

my_stacked_widget::~my_stacked_widget()
{
    delete ui;
}

void my_stacked_widget::add_widget(QString name, QWidget *w,bool button)
{
    if(m_name_to_csbt.contains(name))
    {
        QLOG_INFO() << QString("stackedwidget 的名称 %1 已存在 新建失败 ").arg(name);
        return;
    }
    //创建新按钮
    close_button *tmp_close_button = new close_button(name);
    //tmp_close_button->setStyleSheet("QPushButton{font-size:50px;}");
    m_name_to_csbt.insert(name,tmp_close_button);
    //加入新界面到stackedwidget
    m_name_to_widget.insert(name,w);
    ui->stackedWidget->addWidget(w);
    ui->stackedWidget->setCurrentWidget(w);
    //将按钮加入新界面
    ui->horizontalLayout->insertWidget(ui->horizontalLayout->count()-1,tmp_close_button);
    //ui->horizontalLayout->addWidget(tmp_close_button);

    //显示 close_button
    if(button)
        tmp_close_button->show_button();
    else
        tmp_close_button->hide_button();
    set_cs_button_foucs(name);

    connect(tmp_close_button,&close_button::s_clicked_label,this,&my_stacked_widget::onm_select_widget);
    connect(tmp_close_button,&close_button::s_clicked_close_button,this,&my_stacked_widget::onm_close_widget);
}

void my_stacked_widget::open_widget(QString name)
{
    if(!m_name_to_csbt.contains(name))
    {
        QLOG_INFO() << QString("打开 stackedwidget 名称为：%1的页面失败(不存在)").arg(name);
    }
    QWidget *tmp_wd = m_name_to_widget.value(name);
    //设置当前界面
    ui->stackedWidget->setCurrentWidget(tmp_wd);

    //设置当前按钮高亮同步
    set_cs_button_foucs(name);
}

void my_stacked_widget::close_widget(QString name)
{
    //不存在该页面
    if(!m_name_to_csbt.contains(name))
    {
        QLOG_INFO() << QString("关闭 stackedwidget 名称为：%1的页面失败(不存在)").arg(name);
        return;
    }
    close_button *tmp_bt = m_name_to_csbt.value(name);
    QWidget *tmp_wd = m_name_to_widget.value(name);
    //移除按钮
    ui->horizontalLayout->removeWidget(tmp_bt);
    m_name_to_csbt.remove(name);
    delete tmp_bt;
    //移除界面
    m_name_to_widget.remove(name);
    ui->stackedWidget->removeWidget(tmp_wd);
    delete tmp_wd;
}

bool my_stacked_widget::is_widget_exist(QString name)
{
    if(m_name_to_csbt.contains(name))
        return true;
    else
        return false;
}

void my_stacked_widget::set_cs_button_foucs(QString name)
{
    QMapIterator<QString,close_button*> itr(m_name_to_csbt);
    while (itr.hasNext()) {
        QString tmp_name = itr.next().key();
        close_button *tmp_bt = m_name_to_csbt.value(tmp_name);
        if(tmp_name == name)
        {
            tmp_bt->set_focus(true);
        }
        else
        {
            tmp_bt->set_focus(false);
        }
    }
}

void my_stacked_widget::onm_current_widget_changed()
{
    QWidget *current_widget = ui->stackedWidget->currentWidget();
    QString name = m_name_to_widget.key(current_widget);
    set_cs_button_foucs(name);

    emit s_widget_changed(name);
}

void my_stacked_widget::onm_close_widget(QString name)
{
    close_widget(name);
}

void my_stacked_widget::onm_select_widget(QString name)
{
    open_widget(name);
}








