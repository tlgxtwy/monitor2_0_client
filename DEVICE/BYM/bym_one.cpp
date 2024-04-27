#include "bym_one.h"
//#include <QDateTime>


QStringList bym_one::power_mim_err_chinese(QString mim_err_code)
{
    bool ok = false;
    QStringList ret_str;
    uint16_t tmp_code = mim_err_code.toUInt(&ok,16);
    if(ok)
    {
        //最高位
        if(tmp_code &0x8000)
            ret_str << "光伏板过压";
        if(tmp_code &0x4000)
            ret_str << "光伏板欠压";
        if(tmp_code &0x2000)
            ret_str << "变压器过压";
        if(tmp_code &0x1000)
            ret_str << "变压器过流";
        if(tmp_code &0x0800)
            ret_str << "变压器过温";
        if(tmp_code &0x0400)
            ret_str << "逆变器孤岛";
        if(tmp_code &0x0200)
            ret_str << "MPPT 异常";
//          if(tmp_code &0x0100)  //保留
//              ret_str << "";
//          if(tmp_code &0x0080)
//              ret_str << "";
//          if(tmp_code &0x0040)
//              ret_str << "";
//          if(tmp_code &0x0020)
//              ret_str << "";
//          if(tmp_code &0x0010)
//              ret_str << "";
        if(tmp_code &0x0008)
            ret_str << "原副边同步异常";
        if(tmp_code &0x0004)
            ret_str << "安全链信号异常";
        if(tmp_code &0x0002)
            ret_str << "电网电压频率/异常";
        if(tmp_code &0x0001)
            ret_str << "遥控关机使能";
    }

    return ret_str;
}

QStringList bym_one::power_mis_err_chinese(QString mis_err_code)
{
    bool ok = false;
    QStringList ret_str;
    uint16_t tmp_code = mis_err_code.toUInt(&ok,16);
    if(ok)
    {
        //最高位
        if(tmp_code &0x8000)
            ret_str << "电网过压";
        if(tmp_code &0x4000)
            ret_str << "电网欠压";
        if(tmp_code &0x2000)
            ret_str << "电网过频";
        if(tmp_code &0x1000)
            ret_str << "电网欠频";
        if(tmp_code &0x0800)
            ret_str << "锁相异常";
        if(tmp_code &0x0400)
            ret_str << "电网浪涌";
        if(tmp_code &0x0200)
            ret_str << "副边 MCU 电压过低";
        if(tmp_code &0x0100)  //保留
            ret_str << "PV 电压过低";
        if(tmp_code &0x0080)
            ret_str << "H桥过流";
        if(tmp_code &0x0040)
            ret_str << "H桥过压";
//          if(tmp_code &0x0020)
//              ret_str << "";
//          if(tmp_code &0x0010)
//              ret_str << "";
//          if(tmp_code &0x0008)
//              ret_str << "";
        if(tmp_code &0x0004)
            ret_str << "原副边通讯异常";
        if(tmp_code &0x0002)
            ret_str << "电网频率未达恢复区间";
        if(tmp_code &0x0001)
            ret_str << "电网电压未达恢复区间";
    }

    return ret_str;
}


