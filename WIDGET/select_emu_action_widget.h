#ifndef SELECT_EMU_ACTION_WIDGET_H
#define SELECT_EMU_ACTION_WIDGET_H

#include <QWidget>
#include <QJsonObject>
#include <QJsonArray>

/*
    网关动作数据界面控件
*/

namespace Ui {
class select_emu_action_widget;
}

class select_emu_action_widget : public QWidget
{
    Q_OBJECT

public:
    explicit select_emu_action_widget(QWidget *parent = nullptr);
    ~select_emu_action_widget();

private slots:

    void on_select_pb_clicked();
public slots:
    void onm_display_emu_data(QJsonObject data);
signals:
    void s_select_emu_data(quint32 timeout, QString path, QJsonObject param);
private:
    Ui::select_emu_action_widget *ui;
};

#endif // SELECT_EMU_ACTION_WIDGET_H
