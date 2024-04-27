#ifndef BRY900_H
#define BRY900_H
#include "bry_base.h"
#include "bym_base.h"
class bry900:public bry_base
{
    Q_OBJECT
public:
    explicit bry900(QString name,QObject *parent =nullptr);
    ~bry900(){
        for(int i=0;i<m_mis.size();i++)
        {
            delete m_mis[i];
        }
    };
    virtual void set_name(QString name) override;

    QStringList get_mi_cid_list();
    void add_mi(bym_base *bry); //挂载新的微逆
    void del_mi(QString name);  //删除微逆
private:
    QVector<bym_base *> m_mis;  //挂载的微逆

};

#endif // BRY900_H
