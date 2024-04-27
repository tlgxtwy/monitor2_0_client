#ifndef SELECT_EMU_STATUS_WIDGET_H
#define SELECT_EMU_STATUS_WIDGET_H

#include <QWidget>
#include <QJsonObject>

/*
    网关状态界面
*/

namespace Ui {
class select_emu_status_widget;
}

class select_emu_status_widget : public QWidget
{
    Q_OBJECT

public:
    explicit select_emu_status_widget(QWidget *parent = nullptr);
    ~select_emu_status_widget();

private slots:
    //界面: 查询网关状态
    void on_select_pb_clicked();
public slots:
    //界面:显示网关状态
    void onm_display_emu_status(QJsonObject data);
signals:
    //HTTP请求:查询网关状态
    void s_select_emu_status(quint32 timeout, QString path, QJsonObject param);

private:
    Ui::select_emu_status_widget *ui;
};

#endif // SELECT_EMU_STATUS_WIDGET_H
