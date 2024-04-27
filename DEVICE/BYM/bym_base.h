#ifndef BYM_BASE_H
#define BYM_BASE_H
#include <QObject>

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>



#define DEFAULT_VALUE_MIN (400000)
#define DEFAULT_VALUE_MAX (-400000)
#define DCOV_ERR_COUNT_MAX 2
#define DCOA_ERR_COUNT_MAX 2


typedef struct
{
    QString sel_desc;  //筛选描述
    bool emu_cid_field;
    bool emu_time_field;
    bool mi_cid_field;
    bool pv_id_field;
    bool mim_ver_field;
    bool mis_ver_field;
    bool pv_field;
    bool power_field;
    bool energy_field;
    bool temp_field;
    bool gridv_field;
    bool gridf_field;
    bool mim_err_field;
    bool mis_err_field;
    bool nominal_pw_field;
    bool reissue_data_field;
    bool sys_time_field;

    QStringList mi_cid;   //微逆编号
    QString mim_err;  //原边故障
    QString mis_err;  //副边故障
    QString start_date;
    QString stop_date;
    QString select_num;    //筛选数量
    QString select_start;  //筛选下标
    bool mi_cid_flag;
    bool mi_cid_dir_flag;
    bool mim_err_flag;
    bool mim_err_dir_flag;
    bool mis_err_flag;
    bool mis_err_dir_flag;
    bool date_flag;
    bool select_flag;
}power_select_stru;  //微逆发电数据筛选条件

typedef struct
{
    QString emu_cid;   //网关CID
    QString mi_cid;    //微逆CID
    QString date;      //上报日期
    uint8_t  pv_id;    //路号
    /*--------副边数据----------*/
    QString  mis_ver;
    float grid_volt;
    float grid_freq;
    QString mis_err;
    /*--------原边数据----------*/
    QString  mim_ver;
    float pv_volt;
    float power;
    float energy;
    float temp;
    QString mim_err;
    uint32_t nominal_power;  //标称功率
    QString reissue_data;  //补发数据
    /***************************/
    QString cur_date;
}mi_pv_data;
typedef struct
{
    QString room_name;
    QString rack_id;
    QString pos;
    QString mi_cid;
    uint8_t pv_id;

    uint16_t nominal_power; //额定功率

    QString start_time;    //起始时间
    QString stop_time;     //结束时间
    uint32_t nums;         //老化数据采集点数

    int start_power;     //起始功率（W）
    uint32_t rm40_spx_t90;    //环境40℃ 启动后的功率跌落到90%时长(S)
    uint32_t rm40_spx_t85;    //启动后的功率跌落到85%时长(S)
    uint32_t rm40_spx_t80;    //启动后的功率跌落到80%时长(S)
    uint32_t rm40_spx_t75;    //启动后的功率跌落到75%时长(S)
    uint32_t rm40_spx_t70;    //启动后的功率跌落到70%时长(S)

    uint32_t rm45_spx_t90;    //环境45℃ 启动后的功率跌落到90%时长(S)
    uint32_t rm45_spx_t85;    //启动后的功率跌落到85%时长(S)
    uint32_t rm45_spx_t80;    //启动后的功率跌落到80%时长(S)
    uint32_t rm45_spx_t75;    //启动后的功率跌落到75%时长(S)
    uint32_t rm45_spx_t70;    //启动后的功率跌落到70%时长(S)

    uint32_t rm50_spx_t90;    //环境50℃ 启动后的功率跌落到90%时长(S)
    uint32_t rm50_spx_t85;    //启动后的功率跌落到85%时长(S)
    uint32_t rm50_spx_t80;    //启动后的功率跌落到80%时长(S)
    uint32_t rm50_spx_t75;    //启动后的功率跌落到75%时长(S)
    uint32_t rm50_spx_t70;    //启动后的功率跌落到70%时长(S)

    uint32_t rm55_spx_t90;    //环境55℃ 启动后的功率跌落到90%时长(S)
    uint32_t rm55_spx_t85;    //启动后的功率跌落到85%时长(S)
    uint32_t rm55_spx_t80;    //启动后的功率跌落到80%时长(S)
    uint32_t rm55_spx_t75;    //启动后的功率跌落到75%时长(S)
    uint32_t rm55_spx_t70;    //启动后的功率跌落到70%时长(S)

    uint32_t rm60_spx_t90;    //环境60℃ 启动后的功率跌落到90%时长(S)
    uint32_t rm60_spx_t85;    //启动后的功率跌落到85%时长(S)
    uint32_t rm60_spx_t80;    //启动后的功率跌落到80%时长(S)
    uint32_t rm60_spx_t75;    //启动后的功率跌落到75%时长(S)
    uint32_t rm60_spx_t70;    //启动后的功率跌落到70%时长(S)

    QString mim_err;  //发生的原边故障列表
    QString mis_err;  //发生的原边故障列表
    uint16_t dcov_point;
    uint16_t dcoa_point;
    //不同环境温度下的功率 温度 极限值
    int rm40_pwmax;
    int rm40_pwmin;
    int rm40_tmax;
    int rm45_pwmax;
    int rm45_pwmin;
    int rm45_tmax;
    int rm50_pwmax;
    int rm50_pwmin;
    int rm50_tmax;
    int rm55_pwmax;
    int rm55_pwmin;
    int rm55_tmax;
    int rm60_pwmax;
    int rm60_pwmin;
    int rm60_tmax;
    //总计极限值
    int cm_pwmax;
    int cm_pwmin;
    int cm_tmax;

    int power_max;
    int power_min;
    int temp_max;
}aging_analysis_ret_strc;
enum aging_err_cause{
    pass_data,     //数据通过
    empty_data,    //无数据
    missing_time_data,  //老化时间不充分
    missing_point_data, //老化采集点数丢失
    nopower_data,  //无功率输出
    nonominal_power,  //功率没达到标称功率上
    lowpower_data, //功率低
    uptemp_data,   //温度过高
    errcode_data,  //错误代码
};


typedef struct{
    aging_err_cause b_result;      //老化最终结果

    bool b_aging_time;  //老化时间结果
    bool b_aging_point; //老化时间点数
    bool b_mim_errcode;
    bool b_mis_errcode;
    bool b_rm40_pwmax;
    bool b_rm40_pwmin;
    bool b_rm40_tmax;
    bool b_rm45_pwmax;
    bool b_rm45_pwmin;
    bool b_rm45_tmax;
    bool b_rm50_pwmax;
    bool b_rm50_pwmin;
    bool b_rm50_tmax;
    bool b_rm55_pwmax;
    bool b_rm55_pwmin;
    bool b_rm55_tmax;
    bool b_rm60_pwmax;
    bool b_rm60_pwmin;
    bool b_rm60_tmax;
}aging_judge_ret_stru;

typedef struct
{
    uint8_t pv_type;  //型号类型

    bool b_aging_time_min;
    uint32_t v_aging_time_min;
    bool b_aging_points;
    uint32_t v_aging_points;

    //某环境温度下 温升最大值
    bool b_rm40_tmax;
    uint32_t v_rm40_tmax;
    bool b_rm45_tmax;
    uint32_t v_rm45_tmax;
    bool b_rm50_tmax;
    uint32_t v_rm50_tmax;
    bool b_rm55_tmax;
    uint32_t v_rm55_tmax;
    bool b_rm60_tmax;
    uint32_t v_rm60_tmax;

    //某环境温度下  最低功率 %
    bool b_rm40_pwmin;
    uint32_t v_rm40_pwmin;
    bool b_rm45_pwmin;
    uint32_t v_rm45_pwmin;
    bool b_rm50_pwmin;
    uint32_t v_rm50_pwmin;
    bool b_rm55_pwmin;
    uint32_t v_rm55_pwmin;
    bool b_rm60_pwmin;
    uint32_t v_rm60_pwmin;

    //pv端某环境温度下 温升最大值
    bool b_pv_rm40_tmax;
    uint32_t v_pv_rm40_tmax;
    bool b_pv_rm45_tmax;
    uint32_t v_pv_rm45_tmax;
    bool b_pv_rm50_tmax;
    uint32_t v_pv_rm50_tmax;
    bool b_pv_rm55_tmax;
    uint32_t v_pv_rm55_tmax;
    bool b_pv_rm60_tmax;
    uint32_t v_pv_rm60_tmax;
    //pv端某环境温度下  最低功率 %
    bool b_pv_rm40_pwmin;
    uint32_t v_pv_rm40_pwmin;
    bool b_pv_rm45_pwmin;
    uint32_t v_pv_rm45_pwmin;
    bool b_pv_rm50_pwmin;
    uint32_t v_pv_rm50_pwmin;
    bool b_pv_rm55_pwmin;
    uint32_t v_pv_rm55_pwmin;
    bool b_pv_rm60_pwmin;
    uint32_t v_pv_rm60_pwmin;

    //阶段跌落设置
    int bs_rm40_spx_tmax;  // 1,2,3,4,5
    uint32_t v_rm_40_spx_tmax;
    int bs_rm45_spx_tmax;
    uint32_t v_rm_45_spx_tmax;
    int bs_rm50_spx_tmax;
    uint32_t v_rm_50_spx_tmax;
    int bs_rm55_spx_tmax;
    uint32_t v_rm_55_spx_tmax;
    int bs_rm60_spx_tmax;
    uint32_t v_rm_60_spx_tmax;

    //单路错误码屏蔽
    uint16_t mim_one_err_mask;
    uint16_t mis_one_err_mask;
    //四路错误码屏蔽
    uint16_t mim_four_pv12_err_mask;
    uint16_t mim_four_pv34_err_mask;
    uint16_t mis_four_err_mask;
}aging_judge_value;

typedef struct
{
    QString ret;
}aging_ret;



enum bym_type
{
    bym_empty_type = 0,
    bym_one_type = 1,    //1路微逆
    bym_two_type = 2,    //2路微逆
    bym_four_type = 4,   //4路微逆
    bym_six_type = 6,    //6路微逆
    bym_eight_type = 8   //8路微逆
};

class bym_base:public QObject
{
    Q_OBJECT
public:
    bym_base(QString name,bym_type type,QObject *parent = nullptr)
    :QObject(parent)
    {
        m_type = type;
        m_name = name;
    };
    //设计为抽象类
    //virtual ~bym_base() = 0;  //即使是纯虚析构  基类也要有该定义 析构时子类会调用  不然编译会出错
    virtual ~bym_base()
    {

    };

    static const QString c_field_emu_cid;
    static const QString c_field_emu_time;
    static const QString c_field_mi_cid;
    static const QString c_field_mim_version;
    static const QString c_field_mis_version;
    static const QString c_field_pv;
    static const QString c_field_power;
    static const QString c_field_energy;
    static const QString c_field_temperature;
    static const QString c_field_gridv;
    static const QString c_field_gridf;
    static const QString c_field_mim_err;
    static const QString c_field_mis_err;
    static const QString c_field_pv_id;
    static const QString c_field_nominal_power;
    static const QString c_field_reissue_data;
    static const QString c_field_sys_time;


    virtual bym_type get_type(){
        return m_type;
    };
//    virtual void set_type(bym_type type)
//    {
//        m_type = type;
//    }

    virtual QString name(){
        return m_name;
    };

    //设置标称功率
    virtual void set_nominal_power(uint16_t nominal_power){
        m_nominal_power = nominal_power;
    };
    virtual uint16_t get_nominal_power(){
        return m_nominal_power;
    };

    //设置软件版本
    virtual void set_soft_version(QString mim,QString mis){
        m_mim_ver = mim;
        m_mis_ver = mis;
    };

    virtual void set_pos(QString pos)
    {
        m_pos = pos;
    };
    virtual QString get_pos()
    {
        return m_pos;
    };

    //设置pv数据
    virtual void set_pv_data(QJsonObject data){
        m_pv_data = data;
    };

    virtual QJsonObject get_pv_data(){
        return m_pv_data;
    };



    virtual void clear_pv_data(){
        QJsonObject tmp_data;
        m_pv_data = tmp_data;
    };

    virtual void set_aging_ret(QJsonObject aging_ret){
        m_aging_ret = aging_ret;
    };
    virtual QJsonObject get_aging_ret(){
        return m_aging_ret;
    };
    virtual void clear_aging_ret(){
        QJsonObject tmp_data;
        m_aging_ret = tmp_data;
    };
    //获取发电数据的字符解析 区分单路和多路
    virtual QHash<QString,QString> get_pv_data_str();

//    virtual void analysis_mim(quint8 pv_id,QString mim_err) = 0;
//    virtual void analysis_mis(quint8 pv_id,QString mis_err) = 0;

    static bym_type analysis_type(QString name);
    static bool is_cid_valid(QString cid);
    static bool is_plcmi_valid(QString cid);
    static bool is_wifimi_valid(QString cid);
private:
    QString m_name;
    bym_type m_type;

    uint16_t m_nominal_power = 0;
    QString m_mim_ver = "0.0";
    QString m_mis_ver = "0.0";
    QString m_pos = "";

    QJsonObject m_pv_data;     //power data
    QJsonObject m_aging_ret;   //aging data


};

#endif // BYM_BASE_H
