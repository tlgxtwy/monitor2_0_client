#ifndef BRY_BASE_H
#define BRY_BASE_H
#include <QObject>

#include "bym_base.h"
#include <QJsonArray>

typedef struct
{
    QString m_cid;
    QString m_version;
    QString m_type;
    QString m_sys_time;
}gateway_data_strc;

typedef struct
{
    QString sel_desc; //筛选描述  可能存在不同的筛选(主要是字段不同) 由客户端自主控制
    bool emu_cid_field;
    bool action_field;
    bool version_field;
    bool sys_time_field;

    QString emu_cid;      //网关编号
    QString action;       //网关动作类型
    QString start_date;   //开始日期
    QString stop_date;    //结束日期
    QString select_num;   //筛选数量
    QString select_start; //筛选下标

    bool emu_cid_flag;
    bool emu_cid_dir_flag;
    bool action_flag;
    bool action_dir_flag;
    bool date_flag;
    bool select_flag;
}emu_select_stru;


enum bry_type
{
    bry_base_type,
    bry_general_type,
    bry_1000_type,
    bry_2000_type
};

class bry_base:public QObject
{
    Q_OBJECT
public:
    bry_base(QString name,bry_type type,QObject *parent = nullptr)
    :QObject(parent)
    {
        m_type = type;
        m_name = name;
    };
    //纯虚类
    //virtual ~bry_base() = 0;
    virtual ~bry_base(){
        for (QMap<QString,bym_base *>::const_iterator it = m_bym.cbegin(), end = m_bym.cend(); it != end; ++it)
        {
            if(it.value() != nullptr)
            {
                delete it.value();
            }
        }
    };


    virtual bry_type get_type(){
        return m_type;
    };

    virtual void set_type(QString type)
    {
        if(type  == "0001")
        {
            m_type = bry_1000_type;
        }
        else if(type == "0002")
        {
            m_type = bry_2000_type;
        }
        else
        {
            m_type = bry_general_type;
        }
    }
    virtual void set_type(bry_type type)
    {
        m_type = type;
    }

    virtual QString name(){
        return m_name;
    };

    virtual void set_pos(QString pos)
    {
        m_pos = pos;
    };
    virtual QString get_pos(){
        return m_pos;
    };

    virtual void set_hard_version(QString ver){
        m_hard_version = ver;
    };

    virtual QString get_hard_version(){
        return m_hard_version;
    };

    virtual void set_soft_version(QString ver)
    {
        m_soft_version =  ver;
    };

    virtual QString get_soft_version(){
        return m_soft_version;
    };

    virtual void set_status(QString status)
    {
        m_status = status;
    };
    virtual QString get_status()
    {
        return m_status;
    };

    virtual void set_run_mode(QString run_mode)
    {
        m_run_mode = run_mode;
    };
    virtual QString get_run_mode()
    {
        return m_run_mode;
    };
    virtual void set_status_time(QString time)
    {
        m_status_time = time;
    };
    virtual QString get_status_time()
    {
        return m_status_time;
    };
    virtual void set_last_handshake_time(QString last_time)
    {
        m_last_handshake_time = last_time;
    };
    virtual QString get_last_handshake_time()
    {
        return m_last_handshake_time;
    };


    virtual QMap<QString,bym_base *> get_mis()
    {
        return m_bym;
    };

    virtual void insert_mi(bym_base * bym){
        if(m_bym.contains(bym->name()))
            delete m_bym.value(bym->name());

        m_bym.insert(bym->name(),bym);
    };
    virtual void clear_mi(){
        for (QMap<QString,bym_base *>::const_iterator it = m_bym.cbegin(), end = m_bym.cend(); it != end; ++it)
        {
            if(it.value() != nullptr)
            {
                delete it.value();
            }
        }
        m_bym.clear();
    };

    virtual void update_mi_pv_data(QMap<QString,QJsonObject> &mi_data)
    {
        QStringList mi_cid_list = mi_data.keys();
        for(int i=0;i<mi_cid_list.size();i++)
        {
            if(m_bym.contains(mi_cid_list[i]))
            {
                m_bym.value(mi_cid_list[i])->set_pv_data(mi_data.value(mi_cid_list[i]));
            }
        }
    };

    void onm_restart_bym(QJsonArray tmp_array);


    static bool is_general_cid_valid(QString emu_cid);
    static bool is_wifiemu_cid_valid(QString wifiemu_cid);
    static QString wifi_micid_to_emu_cid(QString mi_cid);
    static QString emu_cid_to_wifi_micid(QString wifiemu_cid);
    //static bry_type analysis_bry_type(QString name);
private:
    bry_type m_type;
    QString m_name;
    QString m_hard_version;
    QString m_soft_version;
    QString m_pos;
    QString m_last_handshake_time;  //最后心跳上报时间

    QString m_status;
    QString m_run_mode;     //异常
    QString m_status_time;  //异常上报时间
    QMap<QString,bym_base *> m_bym;  //绑定的微逆
};

#endif // BRY_BASE_H
