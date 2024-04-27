#ifndef AGING_ROOM_H
#define AGING_ROOM_H

#include <QObject>
#include <QMap>
#include <QHash>

#include "arack_one.h"
#include "bym_one.h"
#include "bym_four.h"
//#include "bym_base.h"
#include "bry_base.h"

typedef struct
{
    QString mi_cid;
    QString stop_time;
}batch_strc;

typedef struct
{
    QString name;
    float value;
}temp_stru;

typedef struct
{
    uint16_t mi_ok_count;
    uint16_t mi_err_count;
    uint16_t mi_upower_count;  //功率低
    uint16_t mi_errpower_count;//功率异常
    uint16_t mi_nodata_count;  //无数据
}room_ret_stru;

class aging_room : public QObject
{
    Q_OBJECT
public:
    explicit aging_room(QString name,QObject *parent = nullptr);
    ~aging_room(){
        QStringList tmp_list;
        tmp_list = m_racks.keys();
        for(int i=0;i<tmp_list.size();i++)
        {
            delete m_racks[tmp_list[i]];
        }
        tmp_list =m_mis.keys();
        for(int i=0;i<tmp_list.size();i++)
        {
            delete m_mis[tmp_list[i]];
        }
        tmp_list = m_emus.keys();
        for(int i=0;i<tmp_list.size();i++)
        {
            delete m_emus[tmp_list[i]];
        }
    };

    QString name();
    QString cn_name();

    QHash<QString,arack_base *>  get_rack_list();
    QHash<QString,bym_base*> get_mi_map();

    QStringList get_mi_cid_list();   //获取当前room下的微逆

    QVector<mi_pv_data> get_mi_pv_data(mi_pv_map_struc mi_pv_map);
    QVector<aging_analysis_ret_strc> get_mi_pv_aging_data(mi_pv_map_struc mi_pv_map);

    void add_racks(arack_base *tmp_racks);  //添加老化架
    void del_racks(QString rack_name);      //删除老化架

    void add_emu(bry_base *bry);//添加网关
    void del_emu(QString name); //删除网关
    void clear_emus();

    void add_mi(bym_base *mi);  //挂载新的微逆
    void del_mi(QString name);  //删除微逆
    void clear_mis();

    void unbind_all_rack_mi();

    void update_rack_pos(QVector<rack_mapping_data> &map_data);      //更新架子位置绑定数据
    void update_rack_current_data(QVector<rack_mi_data> &rack_data); //更新架子位置工作数据
    void update_mis(QVector<mi_pv_data> &mi_data);     //更新微逆工作数据
    void update_aging_data(QMap<QString,QVector<aging_analysis_ret_strc>> &aging_data);//更新最新分析


    void get_aging_data(QString mi_cid,QMap<QString,QVector<aging_analysis_ret_strc>> &aging_data);
private:
    QString m_name;            //老化房名称
    QVector<temp_stru> m_temp; //老化房温度点

    QHash<QString,arack_base *> m_racks;//老化架列表
    QHash<QString,bym_base*> m_mis;     //微逆列表
    QHash<QString,bry_base *> m_emus;   //网关列表

    bym_base* bym_new(QString mi_cid);
signals:

};

#endif // AGING_ROOM_H
