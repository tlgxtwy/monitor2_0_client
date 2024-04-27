#ifndef MY_STACKED_WIDGET_H
#define MY_STACKED_WIDGET_H

#include <QWidget>
#include <QMap>
#include <QStack>
#include "close_button.h"

namespace Ui {
class my_stacked_widget;
}

class my_stacked_widget : public QWidget
{
    Q_OBJECT

public:
    explicit my_stacked_widget(QWidget *parent = nullptr);
    ~my_stacked_widget();

    QMap<QString,close_button*> m_name_to_csbt;  //名称_关闭按键 close_button自身控制删除
    QMap<QString,QWidget *> m_name_to_widget;    //名称_窗口mapping表

    void add_widget(QString name,QWidget *w,bool button = true);   //新增一个界面 名称唯一  //默认显示关闭按钮
    void open_widget(QString name);    //打开某页面
    void close_widget(QString name);   //关闭某页面

    bool is_widget_exist(QString name);//判断名称为name的界面是否存在 存在:true 不存在:false
private:
    Ui::my_stacked_widget *ui;
    void set_cs_button_foucs(QString name);  //设置某个按键高亮  高亮是唯一的
private slots:
    void onm_current_widget_changed(); //信号：当前widget改变  槽：按钮 focus变化

    void onm_close_widget(QString name);
    void onm_select_widget(QString name);
signals:
    void s_widget_changed(QString current_name);  //当前widget改变
};

#endif // MY_STACKED_WIDGET_H
