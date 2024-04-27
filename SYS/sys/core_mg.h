#ifndef CORE_MG_H
#define CORE_MG_H

#include <QObject>

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#include "station.h"

typedef struct
{
    QString account;
    QString password;
    QString permission;
    QString algorithm;
    QString login_date;
}user;



class core_mg : public QObject
{
    Q_OBJECT
public:
    explicit core_mg(QObject *parent = nullptr);

    user get_user(){
        return m_user;
    };
    void set_user_alg(QString alg)
    {
        m_user.algorithm = alg;
    }

private:    
    user m_user;                       //当前用户名称
    QMap<QString,station *> m_station; //电站

    void clear_station();
public slots:
    void onm_deal_http_msg(QString path,QJsonObject msg);

    void onm_start();

signals:
    void s_update_alg_status(bool status);

    void s_new_account_data();

    void s_new_mapping(QMap<QString,station *> tmp_station);
    void s_new_current_power_data(QMap<QString,station *> tmp_station);

    void s_new_one_plot_mi_power_data(QString name,QJsonObject data);
    void s_new_mi_power_data(QString path,QJsonObject data);
    void s_new_emu_action_data(QJsonObject data);
    void s_new_emu_status_data(QJsonObject data);
    void s_new_room_temp_data(QJsonObject data);
    void s_new_user_act_data(QJsonObject data);

    void s_new_mi_ctl(QString path,QJsonObject data);
    void s_new_emu_ctl(QString path,QJsonObject data);

    void s_new_cloud_workorder(QJsonObject data);
    void s_write_cloud_workorder_response();

    void s_new_aging_report(QJsonObject data);
    void s_new_batch_list(QJsonObject data);
};

#endif // CORE_MG_H
