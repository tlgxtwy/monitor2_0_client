#include "bym_base.h"

#include <QDateTime>

const QString bym_base::c_field_emu_cid = "emu_cid";
const QString bym_base::c_field_emu_time = "emu_time";
const QString bym_base::c_field_mi_cid = "mi_cid";
const QString bym_base::c_field_mim_version = "mim_version";
const QString bym_base::c_field_mis_version = "mis_version";
const QString bym_base::c_field_pv = "pv";
const QString bym_base::c_field_power = "power";
const QString bym_base::c_field_energy = "energy";
const QString bym_base::c_field_temperature = "temperature";
const QString bym_base::c_field_gridv = "gridv";
const QString bym_base::c_field_gridf = "gridf";
const QString bym_base::c_field_mim_err = "mim_err";
const QString bym_base::c_field_mis_err = "mis_err";
const QString bym_base::c_field_pv_id = "pv_id";
const QString bym_base::c_field_nominal_power = "nominal_power";
const QString bym_base::c_field_reissue_data = "reissue_data";
const QString bym_base::c_field_sys_time = "sys_time";

QHash<QString, QString> bym_base::get_pv_data_str()
{
    QHash<QString,QString> tmp_hash;
    QJsonArray tmp_datas = m_pv_data.value("datas").toArray();
    if(m_type == bym_type::bym_one_type)
    {
        if(tmp_datas.size() == 1)
        {

            tmp_hash.insert(c_field_emu_cid,tmp_datas[0].toObject().value(c_field_emu_cid).toString(""));
            tmp_hash.insert(c_field_mi_cid,tmp_datas[0].toObject().value(c_field_mi_cid).toString(""));
            tmp_hash.insert(c_field_mim_version,tmp_datas[0].toObject().value(c_field_mim_version).toString(""));
            tmp_hash.insert(c_field_mis_version,tmp_datas[0].toObject().value(c_field_mis_version).toString(""));
            tmp_hash.insert(c_field_pv,tmp_datas[0].toObject().value(c_field_pv).toString(""));
            tmp_hash.insert(c_field_power,tmp_datas[0].toObject().value(c_field_power).toString(""));
            tmp_hash.insert(c_field_energy,tmp_datas[0].toObject().value(c_field_energy).toString(""));
            tmp_hash.insert(c_field_temperature,tmp_datas[0].toObject().value(c_field_temperature).toString(""));
            tmp_hash.insert(c_field_gridv,tmp_datas[0].toObject().value(c_field_gridv).toString(""));
            tmp_hash.insert(c_field_gridf,tmp_datas[0].toObject().value(c_field_gridf).toString(""));
            tmp_hash.insert(c_field_mim_err,tmp_datas[0].toObject().value(c_field_mim_err).toString("").toUpper());
            tmp_hash.insert(c_field_mis_err,tmp_datas[0].toObject().value(c_field_mis_err).toString("").toUpper());
            tmp_hash.insert(c_field_pv_id,QString::number(tmp_datas[0].toObject().value(c_field_pv_id).toInt()));
            tmp_hash.insert(c_field_nominal_power,QString::number(tmp_datas[0].toObject().value(c_field_nominal_power).toInt()));
            tmp_hash.insert(c_field_reissue_data,tmp_datas[0].toObject().value(c_field_reissue_data).toString(""));
            tmp_hash.insert(c_field_sys_time,tmp_datas[0].toObject().value(c_field_sys_time).toString(""));
        }
    }
    else if(m_type == bym_type::bym_two_type)
    {
        QString pv_str,power_str,energy_str,temp_str,pv_id_str
//                gridv_str,
                //emu_cid_str,mi_cid_str,mim_version_str,mis_version_str,
                //gridf_str,mimerr_str,mis_err_str,nominal_str,reissue_str,
//                ,systime_str
                ;

        if(tmp_datas.size() == 2)
        {
            for(int i=0;i<tmp_datas.size();i++)
            {
                pv_str += tmp_datas[i].toObject().value(c_field_pv).toString("");
                power_str += tmp_datas[i].toObject().value(c_field_power).toString("");
                energy_str += tmp_datas[i].toObject().value(c_field_energy).toString("");
                temp_str += tmp_datas[i].toObject().value(c_field_temperature).toString("");
//                gridv_str += tmp_datas[i].toObject().value(c_field_gridv).toString("");
//                systime_str += tmp_datas[i].toObject().value(c_field_sys_time).toString("");
                pv_id_str += QString::number(tmp_datas[i].toObject().value(c_field_pv_id).toInt());
                if(i != tmp_datas.size() -1)
                {
//                    emu_cid_str += "\r\n";
//                    mi_cid_str += "\r\n";
//                    mim_version_str += "\r\n";
//                    mis_version_str += "\r\n";
                    pv_str += "\r\n";
                    power_str += "\r\n";
                    energy_str += "\r\n";
                    temp_str += "\r\n";
//                    gridv_str += "\r\n";
//                    gridf_str += "\r\n";
//                    mimerr_str += "\r\n";
//                    mis_err_str += "\r\n";
                    pv_id_str += "\r\n";
//                    nominal_str += "\r\n";
//                    reissue_str += "\r\n";
//                    systime_str += "\r\n";
                }
            }

            if(tmp_datas[0].toObject().value(c_field_sys_time).toString("") != tmp_datas[1].toObject().value(c_field_sys_time).toString(""))
            {
                //时间不对时  跳出
                return tmp_hash;
            }
            tmp_hash.insert(c_field_emu_cid,tmp_datas[0].toObject().value(c_field_emu_cid).toString(""));
            tmp_hash.insert(c_field_mi_cid,tmp_datas[0].toObject().value(c_field_mi_cid).toString(""));
            tmp_hash.insert(c_field_mim_version,tmp_datas[0].toObject().value(c_field_mim_version).toString(""));
            tmp_hash.insert(c_field_mis_version,tmp_datas[0].toObject().value(c_field_mis_version).toString(""));
            tmp_hash.insert(c_field_pv,pv_str);
            tmp_hash.insert(c_field_power,power_str);
            tmp_hash.insert(c_field_energy,energy_str);
            tmp_hash.insert(c_field_temperature,temp_str);
            tmp_hash.insert(c_field_gridv,tmp_datas[0].toObject().value(c_field_gridv).toString(""));
            tmp_hash.insert(c_field_gridf,tmp_datas[0].toObject().value(c_field_gridf).toString(""));
            tmp_hash.insert(c_field_mim_err,"PV1-2:" + tmp_datas[0].toObject().value(c_field_mim_err).toString("").toUpper());
            tmp_hash.insert(c_field_mis_err,tmp_datas[0].toObject().value(c_field_mis_err).toString("").toUpper());
            tmp_hash.insert(c_field_pv_id,pv_id_str);
            tmp_hash.insert(c_field_nominal_power,QString::number(tmp_datas[0].toObject().value(c_field_nominal_power).toInt() *2));
            tmp_hash.insert(c_field_reissue_data,tmp_datas[0].toObject().value(c_field_reissue_data).toString(""));
            tmp_hash.insert(c_field_sys_time,tmp_datas[0].toObject().value(c_field_sys_time).toString(""));
        }
    }
    else if(m_type == bym_type::bym_four_type)
    {
        QString pv_str,power_str,energy_str,temp_str,pv_id_str
//                gridv_str,
                //emu_cid_str,mi_cid_str,mim_version_str,mis_version_str,
                //gridf_str,mimerr_str,mis_err_str,nominal_str,reissue_str,
//                ,systime_str
                ;

        if(tmp_datas.size() == 4)
        {
            for(int i=0;i<tmp_datas.size();i++)
            {
                pv_str += tmp_datas[i].toObject().value(c_field_pv).toString("");
                power_str += tmp_datas[i].toObject().value(c_field_power).toString("");
                energy_str += tmp_datas[i].toObject().value(c_field_energy).toString("");
                temp_str += tmp_datas[i].toObject().value(c_field_temperature).toString("");
//                gridv_str += tmp_datas[i].toObject().value(c_field_gridv).toString("");
//                systime_str += tmp_datas[i].toObject().value(c_field_sys_time).toString("");
                pv_id_str += QString::number(tmp_datas[i].toObject().value(c_field_pv_id).toInt());
                if(i != tmp_datas.size() -1)
                {
//                    emu_cid_str += "\r\n";
//                    mi_cid_str += "\r\n";
//                    mim_version_str += "\r\n";
//                    mis_version_str += "\r\n";
                    pv_str += "\r\n";
                    power_str += "\r\n";
                    energy_str += "\r\n";
                    temp_str += "\r\n";
//                    gridv_str += "\r\n";
//                    gridf_str += "\r\n";
//                    mimerr_str += "\r\n";
//                    mis_err_str += "\r\n";
                    pv_id_str += "\r\n";
//                    nominal_str += "\r\n";
//                    reissue_str += "\r\n";
//                    systime_str += "\r\n";
                }
            }

            if(tmp_datas[0].toObject().value(c_field_sys_time).toString("") != tmp_datas[1].toObject().value(c_field_sys_time).toString("") ||
               tmp_datas[0].toObject().value(c_field_sys_time).toString("") != tmp_datas[2].toObject().value(c_field_sys_time).toString("") ||
               tmp_datas[0].toObject().value(c_field_sys_time).toString("") != tmp_datas[3].toObject().value(c_field_sys_time).toString(""))
            {
                //时间不对时  跳出
                return tmp_hash;
            }
            tmp_hash.insert(c_field_emu_cid,tmp_datas[0].toObject().value(c_field_emu_cid).toString(""));
            tmp_hash.insert(c_field_mi_cid,tmp_datas[0].toObject().value(c_field_mi_cid).toString(""));
            tmp_hash.insert(c_field_mim_version,tmp_datas[0].toObject().value(c_field_mim_version).toString(""));
            tmp_hash.insert(c_field_mis_version,tmp_datas[0].toObject().value(c_field_mis_version).toString(""));
            tmp_hash.insert(c_field_pv,pv_str);
            tmp_hash.insert(c_field_power,power_str);
            tmp_hash.insert(c_field_energy,energy_str);
            tmp_hash.insert(c_field_temperature,temp_str);
            tmp_hash.insert(c_field_gridv,tmp_datas[0].toObject().value(c_field_gridv).toString(""));
            tmp_hash.insert(c_field_gridf,tmp_datas[0].toObject().value(c_field_gridf).toString(""));
            tmp_hash.insert(c_field_mim_err,"PV1-2:" + tmp_datas[0].toObject().value(c_field_mim_err).toString("").toUpper() + "\r\n" +
                            "PV3-4:" + tmp_datas[2].toObject().value(c_field_mim_err).toString("").toUpper());
            tmp_hash.insert(c_field_mis_err,tmp_datas[0].toObject().value(c_field_mis_err).toString("").toUpper());
            tmp_hash.insert(c_field_pv_id,pv_id_str);
            tmp_hash.insert(c_field_nominal_power,QString::number(tmp_datas[0].toObject().value(c_field_nominal_power).toInt() *4));
            tmp_hash.insert(c_field_reissue_data,tmp_datas[0].toObject().value(c_field_reissue_data).toString(""));
            tmp_hash.insert(c_field_sys_time,tmp_datas[0].toObject().value(c_field_sys_time).toString(""));
        }
    }
    else
    {
        //for(int i=0;i<;i++)



    }

    return tmp_hash;
}

bym_type bym_base::analysis_type(QString name)
{
    if(is_cid_valid(name))
    {
        if(name.startsWith("1"))
        {
            return bym_one_type;
        }
        else if(name.startsWith("2"))
        {
            return bym_two_type;
        }
        else if(name.startsWith("4"))
        {
            return bym_four_type;
        }
        else if(name.startsWith("8"))
        {
            return bym_eight_type;
        }
    }

    return bym_empty_type;
}

bool bym_base::is_cid_valid(QString mi_cid)
{
    if(mi_cid =="")
    {
        return false;
    }

    //16进制数 8位
    QRegExp hexMatcher("^[0-9A-F]{8}$");
    if(hexMatcher.exactMatch(mi_cid) && (mi_cid[0] == '1' || mi_cid[0] == '2' ||
            mi_cid[0] == '4' || mi_cid[0] == '8' ))
        return true;
    return false;
}




