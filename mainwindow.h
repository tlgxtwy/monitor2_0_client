#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QStandardItemModel>
#include <QItemSelectionModel>

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QTimer>

typedef struct
{
    QString back_bt;
    QString tree_head;
    QString home;
    QString monitor;
    QString realtime_data;
    QString mi_st;
    QString rack_st;
    QString sensor_st;
    QString data_select;
    QString mi_aging_data;
    QString emu_aging_data;
    QString emu_data;
    QString emu_status;
    QString mi_data;
    QString rack_data;
    QString sensor_data;
    QString room_temp_data;
    QString user_act_data;
    QString sys_set;
}hometree_field;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QTimer m_timer;
    QStandardItemModel  *m_maintree_model;   //主界面树状模型
    QItemSelectionModel *m_maintree_select;  //选择模型
    QMap<QString,QStandardItem*> m_str_to_standitem;  //名称 -> standard_item

    void open_widget(QString name); //打开界面

signals:
    void s_client_test(quint32 timeout, QString url, QJsonObject param);

    void s_select_time_mi_deatil_data(QString name,QString start_time,QString stop_time);
public slots:
    void onm_treeview_changed(const QModelIndex &current);
    void onm_stackedwidget_changed(QString current_name); //界面发生跳转

    //void onm_open_mi_detail_widget(QString mi_cid);
    void onm_timer_callback();

    void onm_open_widget_from_aging_mi_widget(QString name,QString start_time,QString stop_time);

private slots:
    void on_account_switches_triggered();
    void on_treeView_clicked(const QModelIndex &index);
    void on_action_triggered();
};
#endif // MAINWINDOW_H
