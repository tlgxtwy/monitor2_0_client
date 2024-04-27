#include "core_mg.h"

core_mg::core_mg(QObject *parent)
    : QObject{parent}
{

}

void core_mg::clear_station()
{
    QStringList station_list = m_station.keys();

    for(int i=0;i<station_list.size();i++)
    {
        delete m_station.value(station_list[i],nullptr);
    }
    m_station.clear();
}


void core_mg::onm_deal_http_msg(QString path, QJsonObject msg)
{
    if(path == "/r_user_property")
    {
        QJsonObject data = msg.value("datas").toObject();
        m_user.account = data.value("account").toString();
        m_user.password = data.value("password").toString();
        m_user.permission = data.value("permission").toString();
        m_user.algorithm = data.value("algorithm").toString();
        m_user.permission = data.value("login_date").toString();

    }//拿到了账户下的映射表
    else if(path == "/r_mapping")
    {

    }
    else if(path == "/r_emu_action")
    {
        emit s_new_emu_action_data(msg);
    }
    else if(path == "/r_rack_data")
    {

    }
    else if(path == "/r_mi_current_power")
    {
        //清空数据列表
        clear_station();

        //QJsonObject params = msg.value("params").toObject();
        QJsonArray mapping_datas = msg.value("mapping_datas").toArray();

        //QString emu_cid = params.value("emu_cid").toString();
        for(int i=0;i<mapping_datas.size();i++)
        {
            QJsonObject station_js = mapping_datas[i].toObject();
            QJsonArray emu_array = station_js.value("device").toArray();
            QString station_name = station_js.value("station").toString();

            station *tmp_station = nullptr;
            tmp_station = new station(station_name);
            if(tmp_station != nullptr)
            {
                //设置参数

                //设置关系
                m_station.insert(station_name,tmp_station);
                tmp_station->onm_restart_bry(emu_array);
            }
        }

        QJsonArray mi_power_array = msg.value("pw_datas").toArray();
        QMap<QString,QJsonObject> mi_power_hash;

        QString old_mi_cid = "";
        QString new_mi_cid = "";
        QJsonArray tmp_mis;
        QJsonObject tmp_mi;
        for(int i=0;i<mi_power_array.size();i++)
        {
            if(i !=0)
                new_mi_cid = mi_power_array[i].toObject().value("mi_cid").toString();

            if(new_mi_cid == old_mi_cid)
            {
                tmp_mis.append(mi_power_array[i].toObject());
            }
            else
            {
                tmp_mi.insert("datas",tmp_mis);
                mi_power_hash.insert(old_mi_cid,tmp_mi);
                tmp_mis = QJsonArray();
                tmp_mis.append(mi_power_array[i].toObject());
            }

            old_mi_cid = mi_power_array[i].toObject().value("mi_cid").toString();

            if(i == mi_power_array.size()-1)
            {
                tmp_mi.insert("datas",tmp_mis);
                mi_power_hash.insert(old_mi_cid,tmp_mi);
            }
        }

        QStringList station_list = m_station.keys();
        for(int i=0;i<station_list.size();i++)
        {
            m_station.value(station_list[i])->onm_update_bry(mi_power_hash);
        }

        emit s_new_current_power_data(m_station);
    }
    else if(path == "/add_station")
    {
        emit s_new_mapping(m_station);
    }
    else if(path == "/add_emu_cid")
    {
        emit s_new_mapping(m_station);
    }
    else if(path == "/add_plcmi_cid")
    {
        emit s_new_mapping(m_station);
    }
    else if(path == "/add_wifimi_cid")
    {
        emit s_new_mapping(m_station);
    }
    else if(path == "/del_station")
    {
        emit s_new_mapping(m_station);
    }
    else if(path == "/del_emu")
    {
        emit s_new_mapping(m_station);
    }
    else if(path == "/del_mi")
    {
        emit s_new_mapping(m_station);
    }
    else if(path == "/r_mi_power")
    {
        emit s_new_mi_power_data(path,msg);
    }
    else if(path == "/r_one_mi_power")
    {
        emit s_new_mi_power_data(path,msg);
    }
    else if(path == "/r_ag_room_temp")
    {
        emit s_new_room_temp_data(msg);
    }
    else if(path == "/r_workorder")
    {
        emit s_new_cloud_workorder(msg);
    }
    else if(path == "/w_workorder")
    {
        emit s_write_cloud_workorder_response();
    }
    else if(path == "/r_one_plot_mi_power")
    {
        emit s_new_one_plot_mi_power_data(msg.value("mi_cid").toString(),msg);
    }
    else if(path == "/aging_report")
    {
        emit s_new_aging_report(msg);
    }
    else if(path == "/update_alg")
    {
        emit s_update_alg_status(msg.value("ret").toBool(false));
    }
    else if(path == "/batch_list")
    {
        emit s_new_batch_list(msg);
    }
    else if(path == "/r_user_act")
    {
        emit s_new_user_act_data(msg);
    }
    else if(path == "/r_emu_status")
    {
        emit s_new_emu_status_data(msg);
    }
    else if(path == "/w_temporary_power" || path == "/r_temporary_power" || path == "/w_max_power"||
            path == "/r_max_power" || path == "/w_grid" || path == "/r_grid"||
            path == "/w_certification" || path == "/r_certification" || path == "/r_select_back"||
            path == "/w_more_temporary_power" || path == "/r_more_temporary_power" || path == "/w_more_max_power"||
            path == "/r_more_max_power")
    {
        emit s_new_mi_ctl(path,msg);
    }
    else if(path == "/w_emu_func" || path == "/r_one_emu_status")
    {
        emit s_new_emu_ctl(path,msg);
    }
    else
    {

    }

}



void core_mg::onm_start()
{

}



