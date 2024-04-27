#ifndef ARACK_BASE_H
#define ARACK_BASE_H
#include <QObject>


typedef struct
{
    QString sel_desc;  //筛选描述
    QStringList mi_cid_list;
    QString start_time; //开始时间
    QString stop_time;  //结束时间
}aging_select_stru;


typedef struct
{
    QString sel_desc;
    QString start_cid;
    QString stop_cid;
    QString start_time;
    QString stop_time;
}aging_mis_stru;


enum rack_type
{
    rack_base_type,
    ft_rack_type   //老化架类型1
};

class arack_base:public QObject
{
    Q_OBJECT
public:
    arack_base(QString name,rack_type type,QObject *parent = nullptr)
    :QObject(parent)
    {
        m_type = type;  //基类类型
        m_name = name;
        m_cn_name = name;
    };
    //抽象基类
    //virtual ~arack_base() = 0;
    virtual ~arack_base();
    QString name() {return m_name;};
    QString cn_name(){return m_cn_name;};
    void set_cn_name(QString name){m_cn_name = name;};
    rack_type type() {return m_type;}; //获取类型
    virtual void bind_mi_pv(uint8_t row,uint8_t col,QString mi_cid,uint8_t pv) = 0;
    virtual void unbind_mi_pv(uint8_t row,uint8_t col) = 0;
    virtual void unbind_all_mi_pv() = 0;
    virtual uint8_t row_num() = 0;
    virtual uint8_t col_num() = 0;
private:
    QString m_name;
    QString m_cn_name;
    rack_type m_type;
};
#endif // ARACK_BASE_H
