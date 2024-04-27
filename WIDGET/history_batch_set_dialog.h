#ifndef HISTORY_BATCH_SET_DIALOG_H
#define HISTORY_BATCH_SET_DIALOG_H

#include <QDialog>
#include <QTableWidgetItem>
#include <QJsonObject>
//#include "devices/aging_room.h"

/*
    老化批次筛选界面
*/

namespace Ui {
class history_batch_set_dialog;
}

class history_batch_set_dialog : public QDialog
{
    Q_OBJECT
public:
    explicit history_batch_set_dialog(QWidget *parent = nullptr);
    ~history_batch_set_dialog();

    //显示 批次数据
    void display_batch_data(QJsonObject batch);

private slots:
    //界面:查询批次
    void on_select_pb_clicked();
    //界面:选中具体批次(用作查询该批次下的微逆数据)
    void on_batch_tablewidget_itemClicked(QTableWidgetItem *item);
    //界面:查询某批次下的数据
    void on_ok_pb_clicked();
    //关闭当前界面
    void on_cache_pb_clicked();
signals:
    //获取历史批次
    void s_get_batch_list(quint32 timeout, QString path, QJsonObject param);
    //上报某个批次的 微逆编号开始时间和停止时间
    void s_get_batch_param(QString start_time,QStringList mis);
private:
    Ui::history_batch_set_dialog *ui;
    //上次查询到的m_batch数据
    QJsonObject m_batch;
};

#endif // HISTORY_BATCH_SET_DIALOG_H
