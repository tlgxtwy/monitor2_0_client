#include "bry900.h"

bry900::bry900(QString name, QObject *parent)
    :bry_base(name,gateway_bry900_type,parent)
{

}

void bry900::set_name(QString name)
{
    m_name = name;
}

QStringList bry900::get_mi_cid_list()
{
    QStringList tmp_list;
    for(int i=0;i<m_mis.size();i++)
    {
        tmp_list.append(m_mis[i]->name());
    }
    return tmp_list;
}

void bry900::add_mi(bym_base *bry)
{
    for(int i=0;i<m_mis.size();i++)
    {
        //如果存在相同名称的  直接替换
        if(bry->name() == m_mis[i]->name())
        {
            delete m_mis[i];
            m_mis[i] = bry;
            return ;
        }
    }

    m_mis.append(bry);
}

void bry900::del_mi(QString name)
{
    for(int i=0;i<m_mis.size();i++)
    {
        //存在该微逆则删除
        if(m_mis[i]->name() == name)
        {
            delete m_mis[i];
            m_mis.remove(i);
            return;
        }
    }
}
