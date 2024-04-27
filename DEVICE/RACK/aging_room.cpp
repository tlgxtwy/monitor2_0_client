#include "aging_room.h"
#include <QMap>
//#include "sys_mg/data_mg.h"



aging_room::aging_room(QString name, QObject *parent)
    :QObject(parent)
{
    m_name = name;
    //m_temp.append(35); //默认正常温度
}

QString aging_room::name()
{
    return m_name;
}

QString aging_room::cn_name()
{
    QString cn_name = m_name;
    if(m_name.startsWith("room-"))
    {
        cn_name = "老化房-" + m_name.mid(5);
        return cn_name;
    }
    return m_name;
}

QHash<QString,arack_base *> aging_room::get_rack_list()
{
    return m_racks;
}

QHash<QString, bym_base *> aging_room::get_mi_map()
{
    return m_mis;
}

QStringList aging_room::get_mi_cid_list()
{
    return m_mis.keys();
}

QVector<mi_pv_data> aging_room::get_mi_pv_data(mi_pv_map_struc mi_pv_map)
{
    QVector<mi_pv_data> tmp_data = {};
    if(m_mis.contains(mi_pv_map.mi_cid))
    {
        bym_base *tmp_bym = m_mis[mi_pv_map.mi_cid];
        if(tmp_bym->type() == bym_type::bym_one_type)
        {
            bym_one* tmp_one = dynamic_cast<bym_one*>(tmp_bym);
            for(int i=0;i<tmp_data.size();i++)
            {
                tmp_data.append(tmp_one->get_mi_data(mi_pv_map.pv_list[i]));
            }
        }
    }

    return tmp_data;
}

QVector<aging_analysis_ret_strc> aging_room::get_mi_pv_aging_data(mi_pv_map_struc mi_pv_map)
{
    QVector<aging_analysis_ret_strc> tmp_aging_data = {};
    if(m_mis.contains(mi_pv_map.mi_cid))
    {
        bym_base *tmp_bym = m_mis[mi_pv_map.mi_cid];
        if(tmp_bym->type() == bym_type::bym_one_type)
        {
            bym_one* tmp_one = dynamic_cast<bym_one*>(tmp_bym);
            for(int i=0;i<tmp_aging_data.size();i++)
            {
                tmp_aging_data.append(tmp_one->get_aging_data(mi_pv_map.pv_list[i]));
            }
        }
    }
    return tmp_aging_data;
}

void aging_room::add_racks(arack_base *tmp_racks)
{
    if(tmp_racks == nullptr)
        return;

    m_racks.insert(tmp_racks->name(),tmp_racks);
}

void aging_room::del_racks(QString rack_name)
{
    if(m_racks[rack_name] != nullptr)
        delete m_racks[rack_name];

    m_racks.remove(rack_name);
}

void aging_room::add_emu(bry_base *bry)
{
    if(bry == nullptr)
        return;

    m_emus.insert(bry->name(),bry);
}

void aging_room::del_emu(QString name)
{
    if(m_emus[name] != nullptr)
        delete m_emus[name];

    m_emus.remove(name);
}

void aging_room::clear_emus()
{
    QStringList tmp_emu_list = m_emus.keys();
    for(int i=0;i<tmp_emu_list.size();i++)
    {
        del_emu(tmp_emu_list[i]);
    }
}

void aging_room::add_mi(bym_base *mi)
{
    if(mi == nullptr)
        return;

    m_mis.insert(mi->name(),mi);
}

void aging_room::del_mi(QString name)
{
    if(m_mis[name] != nullptr)
        delete m_mis[name];

    m_mis.remove(name);
}

void aging_room::clear_mis()
{
    QStringList tmp_mi_list = m_mis.keys();
    for(int i=0;i<tmp_mi_list.size();i++)
    {
        del_mi(tmp_mi_list[i]);
    }
}

void aging_room::unbind_all_rack_mi()
{
    QStringList tmp_rack_list = m_racks.keys();
    for(int i=0;i<tmp_rack_list.size();i++)
    {
        m_racks[tmp_rack_list[i]]->unbind_all_mi_pv();
    }
}

void aging_room::update_rack_pos(QVector<rack_mapping_data> &map_data)
{
    uint8_t tmp_row = 0;
    uint8_t tmp_col = 0;

    QStringList tmp_mis = m_mis.keys();

    for(int i=0;i<map_data.size();i++)
    {
        rack_mapping_data tmp_data = map_data[i];
        arack_base *tmp_rack = m_racks.value(tmp_data.rack_id,nullptr);

        if(tmp_data.mi_cid == "")
            continue;

        //当前不存在该微逆编号  加入微逆
        if((!m_mis.contains(map_data[i].mi_cid)))
        {
            bym_base *mi = bym_new(map_data[i].mi_cid);
            if(mi != nullptr)
            {
                add_mi(mi);
            }
        }

        if(tmp_rack != nullptr)
        {
//            if(bym_base::analysis_pv_from_cid(tmp_data.mi_cid) == 1)
//            {
                rack_pos::analysis_row_col(tmp_data.pos,tmp_row,tmp_col); //解析出行列
                tmp_rack->bind_mi_pv(tmp_row,tmp_col,tmp_data.mi_cid,1);
//            }
        }
    }
}

void aging_room::update_rack_current_data(QVector<rack_mi_data> &rack_data)
{
    uint8_t tmp_row = 0;
    uint8_t tmp_col = 0;

    for(int i=0;i<rack_data.size();i++)
    {
        rack_mi_data tmp_data = rack_data[i];
        rack_pos::analysis_row_col(tmp_data.pos,tmp_row,tmp_col); //解析出行列
        arack_base *tmp_rack = m_racks.value(tmp_data.rack_id,nullptr);
        if(tmp_rack != nullptr)
        {
            //单路处理 根据架子类型  调整网关绑定节点映射
            if(tmp_rack->type() == rack_type::ft_rack_type)
            {
                arack_one *tmp_rack_one =  dynamic_cast<arack_one*>(tmp_rack);
                tmp_rack_one->update_pos_data(tmp_row,tmp_col,tmp_data);
            }
        }
    }
}

void aging_room::update_mis(QVector<mi_pv_data> &mi_data)
{
    for(int i=0;i<mi_data.size();i++)
    {
        mi_pv_data tmp_data = mi_data[i];
        bym_base *tmp_bym = m_mis.value(tmp_data.mi_cid,nullptr);
        if(tmp_bym != nullptr)
        {
            tmp_bym->clear_mi_data();
        }
    }

    for(int i=0;i<mi_data.size();i++)
    {
        mi_pv_data tmp_data = mi_data[i];
        bym_base *tmp_bym = m_mis.value(tmp_data.mi_cid,nullptr);
        if(tmp_bym !=nullptr)
        {
           tmp_bym->update_mi_data(tmp_data);
        }
    }
}

void aging_room::update_aging_data(QMap<QString, QVector<aging_analysis_ret_strc> > &aging_data)
{
    QStringList mi_list = aging_data.keys();
    for(int i=0;i<mi_list.size();i++)
    {
        if(m_mis.contains(mi_list[i]))
        {
            bym_base *tmp_bym = m_mis[mi_list[i]];
            if(tmp_bym !=nullptr)
            {
                for(int j=0;j<aging_data[mi_list[i]].size();j++)
                {
                    //更新数据
                    m_mis[mi_list[i]]->update_mi_aging_data(aging_data[mi_list[i]][j]);
                }
            }
        }
    }
}

void aging_room::get_aging_data(QString mi_cid, QMap<QString, QVector<aging_analysis_ret_strc> > &aging_data)
{
    QVector<aging_analysis_ret_strc> tmp_aging_data;
    if(m_mis.contains(mi_cid))
    {
        bym_base *tmp_bym = m_mis[mi_cid];
        if(tmp_bym !=nullptr)
        {
            tmp_bym->get_all_aging_data(tmp_aging_data);
            aging_data.insert(mi_cid,tmp_aging_data);
        }
    }
}

bym_base *aging_room::bym_new(QString mi_cid)
{
    bym_base * tmp_bym = nullptr;

    uint8_t mi_type  = bym_base::analysis_pv_from_cid(mi_cid);

    if(mi_type == bym_one_type)
    {
        tmp_bym = new bym_one(mi_cid);
    }
    else if(mi_type == bym_two_type)
    {

    }
    else if(mi_type == bym_four_type)
    {
        tmp_bym = new bym_four(mi_cid);
    }
    else if(mi_type == bym_six_type)
    {

    }
    else if(mi_type == bym_eight_type)
    {

    }

    return tmp_bym;
}


