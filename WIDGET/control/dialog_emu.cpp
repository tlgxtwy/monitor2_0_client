#include "dialog_emu.h"
#include "qjsonobject.h"
#include "ui_dialog_emu.h"
#include "QValidator"
#include <QMessageBox>

dialog_emu::dialog_emu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialog_emu)
{
    ui->setupUi(this);
    ui->lineEdit_emuCID->setReadOnly(true);
    ui->lineEdit_EMU_Mode->setReadOnly(true);
    ui->lineEdit_EMU_code->setReadOnly(true);
    ui->lineEdit_EMU_signal->setReadOnly(true);

    ui->textEdit_EMU_Info->setReadOnly(true);

    ui->radioButton_Reflux_OFF->setChecked(true);

    ui->status_edt->setReadOnly(true);
    QWidget * widget_Info = ui->widget_3;
    widget_Info->setObjectName("widget_Info");
    widget_Info->setStyleSheet("QWidget#widget_Info{border: 1px solid rgb(220,220,220);}");
}

dialog_emu::~dialog_emu()
{
    delete ui;
}

void dialog_emu::slot_getEMUCID(QString EMUCID, QString STATION)
{

    emu_CID = EMUCID;
    station = STATION;
    ui->lineEdit_emuCID->setText(emu_CID);
}

void dialog_emu::slot_get_EMU_status(QString status,QString reserve, QString func, QString sign, QString run_mode,QString time)
{
    bool ok;
    int EMU_status = status.toInt(&ok, 16);
    int EMU_Mode = run_mode.toInt(&ok, 16);
    int EMU_code = func.toInt(&ok, 16);

    int EMU_signal;

    ui->status_edt->setText(status+reserve+run_mode+sign+func+ "上报时间:" + time);

    if (sign.toInt(&ok, 16) > 127)
    {
        EMU_signal = -(256 - sign.toInt(&ok, 16));
    }
    else EMU_signal =  sign.toInt(&ok, 16);

    ui->lineEdit_EMU_signal->setText(QString::number(EMU_signal));


    if (EMU_status == 0)
        ui->textEdit_EMU_Info->append("正常");
    else
    {
        if ((EMU_status & 0x00000001) == 0x00000001)
            ui->textEdit_EMU_Info->append("SD卡损坏");
        if ((EMU_status & 0x00000002) == 0x00000002)
            ui->textEdit_EMU_Info->append("时间芯片故障");
        if ((EMU_status & 0x00000004) == 0x00000004)
            ui->textEdit_EMU_Info->append("通讯模组故障");
        if ((EMU_status & 0x00000008) == 0x00000008)
            ui->textEdit_EMU_Info->append("WIFI故障");
        if ((EMU_status & 0x00000010) == 0x00000010)
            ui->textEdit_EMU_Info->append("WIFI没有WIFI名");
        if ((EMU_status & 0x00000020) == 0x00000020)
            ui->textEdit_EMU_Info->append("WIFI搜寻超时故障");
        if ((EMU_status & 0x00000040) == 0x00000040)
            ui->textEdit_EMU_Info->append("WIFI加入超时故障");
        if ((EMU_status & 0x00000080) == 0x00000080)
            ui->textEdit_EMU_Info->append("WIFI没有连接故障");
        if ((EMU_status & 0x00000100) == 0x00000100)
            ui->textEdit_EMU_Info->append("WIFI没有获取到IPv4地址");
        if ((EMU_status & 0x00000200) == 0x00000200)
            ui->textEdit_EMU_Info->append("WIFI连接中故障");
        if ((EMU_status & 0x00000400) == 0x00000400)
            ui->textEdit_EMU_Info->append("WIFI断开故障");
        if ((EMU_status & 0x00000800) == 0x00000800)
            ui->textEdit_EMU_Info->append("WIFI状态查询超时故障");
        if ((EMU_status & 0x00001000) == 0x00001000)
            ui->textEdit_EMU_Info->append("WIFI没有获取到MAC地址");
        if ((EMU_status & 0x00002000) == 0x00002000)
            ui->textEdit_EMU_Info->append("断开WIFI连接故障");
//        if ((EMU_status & 0x00004000) == 0x00004000)
//            ui->textEdit_EMU_Info->append("");
//        if ((EMU_status & 0x00008000) == 0x00008000)
//            ui->textEdit_EMU_Info->append("");
        if ((EMU_status & 0x00010000) == 0x00010000)
            ui->textEdit_EMU_Info->append("RJ45连接故障");
        if ((EMU_status & 0x00100000) == 0x00100000)
            ui->textEdit_EMU_Info->append("RS485连接故障");
        if ((EMU_status & 0x01000000) == 0x01000000)
            ui->textEdit_EMU_Info->append("MI通讯故障");
        if ((EMU_status & 0x80000000) == 0x80000000)
            ui->textEdit_EMU_Info->append("通讯模组重新配置");
    }

    if ((EMU_Mode & 0x01) == 0x01)
    {
        ui->lineEdit_EMU_Mode->setText("PLCC通讯模式");
    }


    if ((EMU_code & 0x0001) == 0x0001)
    {
        ui->lineEdit_EMU_code->setText("打开");
        ui->radioButton_Reflux_ON->setChecked(true);
    }
    else
    {
        ui->lineEdit_EMU_code->setText("关闭");
        ui->radioButton_Reflux_OFF->setChecked(true);
    }
    ui->lineEdit_EMU_code->setText("");

}

void dialog_emu::on_pushButton_Reflux_set_clicked()
{
    QString emu_status_code;
    QJsonObject Js_emu_status;

    if (ui->radioButton_Reflux_ON->isChecked())
    {
        emu_status_code = "01";
    }
    else emu_status_code = "00";
    Js_emu_status["station"] = station;
    Js_emu_status["emu_cid"] = emu_CID;
    Js_emu_status["server_cmd"] = 112;
    Js_emu_status["func"] =  "00" + emu_status_code + "000000";
    Js_emu_status["data"] = "";

    emit signal_set_EMU_code(Js_emu_status);
}


void dialog_emu::on_pushButton_EMU_Info_get_clicked()
{
    QJsonObject data;
    data.insert("emu_cid",emu_CID);
    data.insert("start_date","2022-12-23 13:58:02");
    data.insert("stop_date",QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
    data.insert("nums","1");
    data.insert("start_num","0");
    emit signal_get_EMU_stauts(data);
}

