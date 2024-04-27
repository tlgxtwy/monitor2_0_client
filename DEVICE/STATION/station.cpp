#include "station.h"


#include "basic_bry_factory.h"


void station::onm_restart_bry(QJsonArray emu_array)
{
    clear_bry();

    for(int j=0;j<emu_array.size();j++)
    {
        QString emu_cid = emu_array[j].toObject().value("emu_cid").toString();
        QJsonArray mi_js = emu_array[j].toObject().value("mis").toArray();
        basic_bry_factory tmp_fact;
        bry_base *tmp_bry = nullptr;

        tmp_bry = tmp_fact.create_bry(emu_cid);
        //如果创建成功
        if(tmp_bry != nullptr)
        {
            //设置网关属性
            tmp_bry->set_last_handshake_time(emu_array[j].toObject().value("last_act_time").toString());
            tmp_bry->set_hard_version(emu_array[j].toObject().value("hard_version").toString());
            tmp_bry->set_soft_version(emu_array[j].toObject().value("soft_version").toString());
            tmp_bry->set_pos(emu_array[j].toObject().value("emu_desc").toString());
            tmp_bry->set_type(emu_array[j].toObject().value("type").toString());
            tmp_bry->set_status(emu_array[j].toObject().value("status").toString());
            tmp_bry->set_status_time(emu_array[j].toObject().value("status_time").toString());
            tmp_bry->set_run_mode(emu_array[j].toObject().value("run_mode").toString());
            //设置关系列表
            m_bry.insert(emu_cid,tmp_bry);
            tmp_bry->onm_restart_bym(mi_js);

        }
    }
}

void station::onm_update_bry(QMap<QString,QJsonObject> mi_power_hash)
{
    QStringList bry_keys = m_bry.keys();
    for(int i=0;i<bry_keys.size();i++)
    {
        //更新列表
        m_bry.value(bry_keys[i])->update_mi_pv_data(mi_power_hash);
    }
}


