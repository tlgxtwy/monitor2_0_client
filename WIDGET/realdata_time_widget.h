#ifndef REALDATA_TIME_WIDGET_H
#define REALDATA_TIME_WIDGET_H

#include <QWidget>
#include <QTreeWidgetItem>

#include <QMenu>
#include <QPoint>
#include <QFont>
#include <QMap>
#include "station.h"

/*
    关系列表及运行状态主界面
*/

namespace Ui {
class realdata_time_widget;
}

class realdata_time_widget : public QWidget
{
    Q_OBJECT

public:
    explicit realdata_time_widget(QWidget *parent = nullptr);
    ~realdata_time_widget();

public slots:
    //显示远程控制网关的回读
    void onm_display_emu_ctl(QString path,QJsonObject data);
    //显示远程控制微逆的回读
    void onm_display_mi_ctl(QString path,QJsonObject data);
    //更新账号下设备的实时数据（一般是最后一条的上报数据）
    void onm_update_power_data(QMap<QString,station *> t_station);
    //HTTP请求: 查询账号下设备的实时数据
    void on_select_bt_clicked();
private slots:
    //双击 子界面跳转
    void on_treeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column);

    //界面操作
    //右键显示菜单
    void onm_show_menu(QPoint pos);
    //打开添加网关界面
    void onm_open_add_emu_dlg();
    //打开添加WiFi版微逆界面
    void onm_open_add_wifimi_dlg();
    //打开添加PLC版微逆界面
    void onm_open_add_plcmi_dlg();

    //界面: 弹出网关控制界面
    void onm_ctl_emu();
    //界面: 弹出全部微逆控制界面
    void onm_ctl_all_mi();
    //界面：弹出plc微逆控制界面
    void onm_ctl_plc_mi();
    //界面：弹出wifi微逆控制界面
    void onm_ctl_wifi_mi();
    //界面:添加微逆
    void on_add_station_clicked();

    //HTTP请求:删除电站
    void onm_del_station();
    //HTTP请求:删除网关
    void onm_del_emu();
    //HTTP请求:删除微逆
    void onm_del_mi();

    //HTTP请求 发起控制
    void onm_set_cop(QJsonObject data);
    void onm_get_cop(QJsonObject data);
    void onm_set_max_op(QJsonObject data);
    void onm_get_max_op(QJsonObject data);
    void onm_set_grid(QJsonObject data);
    void onm_get_grid(QJsonObject data);
    void onm_set_cer(QJsonObject data);
    void onm_get_cer(QJsonObject data);

    //请求回读数据
    void onm_select_back(QJsonObject data);
    //HTTP请求:获取网关
    void onm_set_emu_func(QJsonObject data);
    //HTTP请求:获取网关状态
    void onm_get_emu_status(QJsonObject data);
signals:
    //HTTP请求: 获取当前设备的 运行数据（最后一次上报的数据）
    void s_select_power_data(quint32 timeout, QString path, QJsonObject param);
    //HTTP请求发起 设备控制
    void s_ctl(quint32 timeout, QString path, QJsonObject param);

    //向网关和微逆控制界面(是一个下级界面)  设置控制参数
    //void s_set_cop(QString mi_cid,QString data);
    void s_get_cop(QHash<QString,QString> data);
    //void s_set_max_op(QString mi_cid,QString data);
    void s_get_max_op(QHash<QString,QString> data);
    //void s_set_grid(QString mi_cid,QString data);
    void s_get_grid(QHash<QString,QString> data);
    //void s_set_cer(QString mi_cid,QString data);
    void s_get_cer(QHash<QString,QString> data);

    //向网关和微逆控制界面(是一个下级界面) 设置回读的时间
    void s_set_maxop_read_back_flag(QString old_status,QString status);
    void s_set_cop_read_back_flag(QString old_status,QString status);
    void s_set_grid_read_back_flag(QString old_status,QString status);
    void s_set_cer_read_back_flag(QString old_status,QString status);
    void s_set_r_maxop_read_back_flag(QString old_status,QString status);
    void s_set_r_cop_read_back_flag(QString old_status,QString status);
    void s_set_r_grid_read_back_flag(QString old_status,QString status);
    void s_set_r_cer_read_back_flag(QString old_status,QString status);

    //向网关和微逆控制界面(是一个下级界面)  显示日志记录
    void s_write_log(QString data);
    //HTTP相关:  查询该网关的网关状态
    void s_get_emu_status(QString status,QString reserve, QString func, QString sign, QString run_mode,QString time);

    //HTTP相关: 查询该微逆当天的发电数据 并进入详细界面
    void s_double_cid_clicked(QString cid,QString start_time,QString stop_time);

    //HTTP相关  为发起HTTP请求向上层传递参数
    void s_add_station(quint32 timeout, QString path, QJsonObject param);
    void s_add_emu(quint32 timeout, QString path, QJsonObject param);
    void s_add_plc_mi(quint32 timeout, QString path, QJsonObject param);
    void s_add_wifi_mi(quint32 timeout, QString path, QJsonObject param);
    void s_del_station(quint32 timeout, QString path, QJsonObject param);
    void s_del_emu(quint32 timeout, QString path, QJsonObject param);
    void s_del_mi(quint32 timeout, QString path, QJsonObject param);
private:
    Ui::realdata_time_widget *ui;
    //右键弹出的菜单
    QAction* add_emu_action = nullptr;
    QAction* add_wifi_mi_action = nullptr;
    QAction* add_plc_mi_action = nullptr;

    QAction* del_station_action = nullptr;
    QAction* del_emu_action = nullptr;
    QAction* del_mi_action = nullptr;

    QAction* ctl_allmi_action = nullptr;
    QAction* ctl_plcmi_action = nullptr;
    QAction* ctl_wifimi_action = nullptr;
    QAction* ctl_emu_action = nullptr;

    QMenu m_station_menu;
    QMenu m_emu_menu;
    QMenu m_mi_menu;
    //表头高度属性
    QFont m_font;
    //字段列表
    QStringList m_field_list;
};

#endif // REALDATA_TIME_WIDGET_H
