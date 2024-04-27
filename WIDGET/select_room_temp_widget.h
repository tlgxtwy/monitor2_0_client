#ifndef SELECT_ROOM_TEMP_WIDGET_H
#define SELECT_ROOM_TEMP_WIDGET_H

#include <QWidget>
#include <QJsonObject>

/*
    查询微逆老化温度窗口
*/

namespace Ui {
class select_room_temp_widget;
}

class select_room_temp_widget : public QWidget
{
    Q_OBJECT

public:
    explicit select_room_temp_widget(QWidget *parent = nullptr);
    ~select_room_temp_widget();

private slots:
    //界面: 查询温度
    void on_select_pb_clicked();
public slots:
    //界面: 显示温度
    void onm_display_room_temp_data(QJsonObject data);
signals:
    //HTTP请求: 查询温度
    void s_select_room_temp_data(quint32 timeout, QString path, QJsonObject param);
private:
    Ui::select_room_temp_widget *ui;
};

#endif // SELECT_ROOM_TEMP_WIDGET_H
