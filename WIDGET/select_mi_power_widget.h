#ifndef SELECT_MI_POWER_WIDGET_H
#define SELECT_MI_POWER_WIDGET_H

#include <QWidget>

#include <QJsonObject>
#include <QJsonArray>
#include <QTableWidgetItem>

/*
    查询微逆数据窗口
*/


namespace Ui {
class select_mi_power_widget;
}

class select_mi_power_widget : public QWidget
{
    Q_OBJECT

public:
    explicit select_mi_power_widget(QWidget *parent = nullptr);
    ~select_mi_power_widget();

    void set_mi_cid_text(QString cid);
    void set_mi_cid_enable(bool flag);
private slots:
    //查询微逆数据
    void on_select_pb_clicked();
    //双击不同的字段  弹出下一级页面
    void on_tableWidget_itemDoubleClicked(QTableWidgetItem *item);
public slots:
    //显示微逆的发电数据
    void onm_display_power_data(QString path,QJsonObject data);
signals:
    //信号:打开微逆详细界面
    void s_open_midetail_data_widget(QString name,QString start_time,QString stop_time);
    //信号:发出HTTP请求  查询微逆发电数据
    void s_select_mi_power_data(quint32 timeout, QString path, QJsonObject param);
private:
    Ui::select_mi_power_widget *ui;
};

#endif // SELECT_MI_POWER_WIDGET_H
