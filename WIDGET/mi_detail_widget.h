#ifndef MI_DETAIL_WIDGET_H
#define MI_DETAIL_WIDGET_H

#include <QWidget>
#include <QJsonObject>

/*
    微逆设备详细界面
*/

namespace Ui {
class mi_detail_widget;
}

class mi_detail_widget : public QWidget
{
    Q_OBJECT

public:
    explicit mi_detail_widget(QWidget *parent = nullptr);
    ~mi_detail_widget();

    void init_by_name(QString name);
public slots:
    //显示绘图数据
    void onm_display_plot_data(QString name,QJsonObject data);
    void onm_display_power_data(QString path,QJsonObject data);

    //查询发电数据(用于绘图)
    void onm_set_select_param(QString name,QString start_time,QString stop_time);
private slots:
    //查询发电数据(用于显示发电数据项)
    void on_select1_pb_clicked();

signals:
    //HTTP请求:查询发电数据
    void s_select_power_data(quint32 timeout, QString path, QJsonObject param);

private:
    Ui::mi_detail_widget *ui;

    QString m_name = "";
};

#endif // MI_DETAIL_WIDGET_H
