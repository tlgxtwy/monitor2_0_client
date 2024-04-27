#include "bry_base.h"


#include "basic_bym_factory.h"


void bry_base::onm_restart_bym(QJsonArray tmp_array)
{
    clear_mi();

    for(int i=0;i<tmp_array.size();i++)
    {
        QJsonObject tmp_mi = tmp_array[i].toObject();
        QString tmp_name = tmp_mi.value("mi_cid").toString();
        basic_bym_factory tmp_fact;

        bym_base *tmp_bym = nullptr;

        tmp_bym = tmp_fact.create_bym(tmp_name);

        if(tmp_bym != nullptr)
        {
            //设置设备属性
            tmp_bym->set_nominal_power(tmp_mi.value("nominal_power").toString().toInt());
            tmp_bym->set_soft_version(tmp_mi.value("mim_version").toString(),
                                      tmp_mi.value("mis_version").toString());
            tmp_bym->set_pos(tmp_mi.value("mi_desc").toString());
            m_bym.insert(tmp_name,tmp_bym);
        }
    }
}

bool bry_base::is_general_cid_valid(QString emu_cid)
{
    if(emu_cid =="")
    {
        return false;
    }

    //16进制数 8位
    QRegExp hexMatcher("^[0-9A-Fa-f]{8}$");
    if(hexMatcher.exactMatch(emu_cid) && (emu_cid[0] == '9'))
        return true;
    return false;
}

bool bry_base::is_wifiemu_cid_valid(QString wifiemu_cid)
{
    if(wifiemu_cid =="")
    {
        return false;
    }

    //16进制数 8位
    QRegExp hexMatcher("^[0-9A-Fa-f]{8}$");
    if(hexMatcher.exactMatch(wifiemu_cid) && (wifiemu_cid[0] == 'A' || wifiemu_cid[0] == 'B'
       || wifiemu_cid[0] == 'C' || wifiemu_cid[0] == 'a' || wifiemu_cid[0] == 'b' || wifiemu_cid[0] == 'c'))
        return true;
    return false;
}

QString bry_base::wifi_micid_to_emu_cid(QString mi_cid)
{
    if(bym_base::is_cid_valid(mi_cid))
    {
        if(mi_cid[0] == "1")
        {
            mi_cid[0] = 'A';
        }
        else if(mi_cid[0] == "2")
        {
            mi_cid[0] = 'B';
        }
        else if(mi_cid[0] == "4")
        {
            mi_cid[0] = 'C';
        }
        else
        {
            mi_cid = "";
        }
    }
    else
    {
        mi_cid = "";
    }
    return mi_cid;
}

QString bry_base::emu_cid_to_wifi_micid(QString wifiemu_cid)
{
    if(is_wifiemu_cid_valid(wifiemu_cid))
    {
        if(wifiemu_cid[0] == "A")
        {
            wifiemu_cid[0] = '1';
        }
        else if(wifiemu_cid[0] == "B")
        {
            wifiemu_cid[0] = '2';
        }
        else if(wifiemu_cid[0] == "C")
        {
            wifiemu_cid[0] = '4';
        }
    }
    else
    {
        wifiemu_cid = "";
    }
    return wifiemu_cid;
}

//bry_type bry_base::analysis_bry_type(QString name)
//{
//    if(name.startsWith("A") || name.startsWith("a"))
//    {
//        return bry_1000_type;
//    }
//    else if(name.startsWith("C") || name.startsWith("c"))
//    {
//        return bry_2000_type;
//    }

//    return bry_base_type;
//}
