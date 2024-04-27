#ifndef ARACK_ONE_H
#define ARACK_ONE_H

#include "arack_base.h"
//#include "bym_base.h"
typedef struct
{
    QString rack_room_name; //所属老化房名
    QString rack_id;        //所属老化架编号
    QString pos;            //在老化架位置编号 例1-1
    QString mi_cid;         //微逆编号
    QString cur_date;       //实时时间
}rack_mapping_data;


typedef struct
{
    QString rack_room_name; //所属老化房名
    QString rack_id;        //所属老化架编号
    QString leak_status;    //漏电开关状态

    QString pos;            //在老化架位置编号 例1-1
    QString mi_cid;         //微逆编号
    float dc_volt_in;       //直流输入电压
    float dc_current_in;    //直流输入电流
    float dc_power_in;      //直流输入功率
    float ac_volt_out;      //交流输出电压
    float ac_current_out;   //交流输出电流
    float ac_power_out;     //交流输出功率
    float efficiency;
    QString start_date;     //老化开始时间

    float volt_in_k;
    float volt_in_b;
    float volt_out_k;
    float volt_out_b;
    QString cur_date;       //实时时间
}rack_mi_data;//老化架实时数据

typedef struct
{
    QString rack_name;
    QString pos;
}rack_pos_stru;

typedef struct
{
    QString room_id;
    QString emu_id;
    QVector<rack_pos_stru> pos_list;
}emu_mapping_stru;

typedef struct
{
    QString pos;
    float volt_in_k;
    float volt_in_b;
    float volt_out_k;
    float volt_out_b;
}rack_eff_node_stru;

typedef struct
{
    QString rack_id;
    QVector<rack_eff_node_stru> node_data;
}rack_eff_stru;

typedef struct
{
    QString room_id;
    QVector<rack_eff_stru> racks;
}rack_eff_factor_stru;


typedef struct
{
    QString sel_desc;
    bool room_id_field;
    bool rack_id_field;
    bool leakage_field;
    bool mi_pos_field;
    bool mi_cid_field;
    bool dc_V_in_field;
    bool dc_A_in_field;
    bool dc_V_in_eff_k_field;
    bool dc_V_in_eff_b_field;
    bool dc_W_in_field;
    bool ac_V_out_field;
    bool ac_A_out_field;
    bool ac_V_out_eff_k_field;
    bool ac_V_out_eff_b_field;
    bool ac_W_out_field;
    bool eff_field;
    bool start_time_field;
    bool mi_curdate_field;

    QString room_id;
    bool room_id_flag;
    bool room_id_dir_flag;
    QString rack_id;
    bool rack_id_flag;
    bool rack_id_dir_flag;
    QString mi_pos;
    bool mi_pos_flag;
    bool mi_pos_dir_flag;
    QStringList mi_cid;
    bool mi_cid_flag;
    bool mi_cid_dir_flag;
    QString start_date;   //开始日期
    QString stop_date;    //结束日期
    bool date_flag;
    QString select_num;   //筛选数量
    QString select_start; //筛选下标
    bool select_flag;
}rack_data_select_stru;



typedef struct
{
    QString mi_cid;
    QVector<uint8_t> pv_list;
}mi_pv_map_struc;

class rack_pos:public QObject
{
public:
    explicit rack_pos(QObject *parent = nullptr)
        :QObject(parent){};
    ~rack_pos(){};

    void bind_mi_pv(QString mi_cid,uint8_t pv); //绑定 多路
    void unbind_mi_pv();  //解绑
    void update_pos_data(rack_mi_data pos_data);  //更新节点实时参数

    QVector<mi_pv_map_struc> get_mi_cid_map();  //获取绑定关系
    rack_mi_data get_cur_data();  //获取实时数据

    static void analysis_row_col(QString pos,uint8_t &row,uint8_t &col);  //解析出行和列
private:
    rack_mi_data m_pos_cur_data = {};   //老化架  该节点数据

    QVector<mi_pv_map_struc> m_mi_pv_map = {}; //当前绑定关系
};


class arack_one:public arack_base
{
   Q_OBJECT
public:
    explicit arack_one(QString name,QObject *parent = nullptr);
    ~arack_one(){
        for(int i=0;i<m_pos_matrix.size();i++)
        {
            for(int j=0;j<m_pos_matrix[i].size();j++)
            {
                delete m_pos_matrix[i][j];
            }
        }
    };

    uint8_t row_num() override;
    uint8_t col_num() override;
    void bind_mi_pv(uint8_t row,uint8_t col,QString mi_cid,uint8_t pv) override;
    void unbind_mi_pv(uint8_t row,uint8_t col) override;
    void unbind_all_mi_pv() override;

    void update_pos_data(uint8_t row,uint8_t col,rack_mi_data pos_data);
    void get_pos_dev(uint8_t row,uint8_t col,QVector<mi_pv_map_struc> &mi_pv_map);
    void get_pos_rack_data(uint8_t row,uint8_t col,rack_mi_data &rack_data);

    rack_pos* get_pos_obj(uint8_t row,uint8_t col);
private:
    uint8_t m_row_num = 8;  //行
    uint8_t m_col_num = 6;  //列
    QVector<QVector<rack_pos *>>  m_pos_matrix;  //位置矩阵

    bool is_row_col_valid(uint8_t row,uint8_t col);  //判断行和列是否在范围内
};

#endif // ARACK_ONE_H
