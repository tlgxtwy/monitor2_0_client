#include "dialog.h"
#include "ui_dialog.h"
#include "qdebug.h"
#include <QCheckBox>
#include <math.h>
#include "dialog_file.h"
#include <QMessageBox>
#include <QDesktopServices>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    //界面画框

    QWidget *widget_QUMODE = ui->widget_QUMode;
    widget_QUMODE->setObjectName("widget_QUMODE");
    widget_QUMODE->setStyleSheet("QWidget#widget_QUMODE{border: 1px solid rgb(192,192,192);}");

    QWidget *widget_PUMODE = ui->widget_PU;
    widget_PUMODE->setObjectName("widget_PUMODE");
    widget_PUMODE->setStyleSheet("QWidget#widget_PUMODE{border: 1px solid rgb(192,192,192);}");

    QWidget *widget_LFSMMODE = ui->widget_LFSMMode;
    widget_LFSMMODE->setObjectName("widget_LFSMMODE");
    widget_LFSMMODE->setStyleSheet("QWidget#widget_LFSMMODE{border: 1px solid rgb(192,192,192);}");

    QWidget *widget_3 = ui->widget_3;
    widget_3->setObjectName("widget_3");
    widget_3->setStyleSheet("QWidget#widget_3{border: 1px solid rgb(192,192,192);}");

    QWidget *widget_FVRT = ui->widget_FVRT;
    widget_FVRT->setObjectName("widget_FVRT");
    widget_FVRT->setStyleSheet("QWidget#widget_FVRT{border: 1px solid rgb(192,192,192);}");

    QWidget *widget_OV10 = ui->widget_OV10;
    widget_OV10->setObjectName("widget_OV10");
    widget_OV10->setStyleSheet("QWidget#widget_OV10{border: 1px solid rgb(192,192,192);}");


    QWidget *widget_21 = ui->widget_21;
    widget_21->setObjectName("widget_21");
    widget_21->setStyleSheet("QWidget#widget_21{border: 1px solid rgb(192,192,192);}");

    QWidget *widget = ui->widget;
    widget->setObjectName("widget");
    widget->setStyleSheet("QWidget#widget{border-right: 1px solid rgb(192,192,192);border-left: 1px solid rgb(192,192,192);border-top: 1px solid rgb(192,192,192)}");




    getFilePath();
    sacnDataFile();

    //tablewidget初始化
    ui->tableWidget_CID->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    appendTimes = 0;
    MaxOP_ctl_time = "";   //最新一次控制时间  用于定时查询数据 查询成功后清空
    COP_ctl_time = "";
    Grid_ctl_time = "";
    Cer_ctl_time = "";
    r_MaxOP_ctl_time = "";   //最新一次控制时间  用于定时查询数据 查询成功后清空
    r_COP_ctl_time = "";
    r_Grid_ctl_time = "";
    r_Cer_ctl_time = "";
    connect(&m_timer,&QTimer::timeout,this,&Dialog::onm_timer_callback);
    m_timer.start(20000);  //20秒处理一次
}

Dialog::~Dialog()
{
    delete ui;
}

//显示传送过来的CID
void Dialog::slot_setCID(QStringList CID, QString EMUCID, QString STATION)
{
    MICID_List = CID;
    emu_CID = EMUCID;
    station = STATION;
    ui->comboBox_CID->addItems(MICID_List);

    for (int i = 0; i < CID.size(); ++i)
    {
        ui->tableWidget_CID->insertRow(i);
        creat_item_checkBox(i, MICID_List[i]);
    }
    ui->checkBox_all->setCheckState(Qt::Checked);
}


void Dialog::creat_item_checkBox(int row, QString name)
{
    QCheckBox* pCheckBox = new QCheckBox();
    ui->tableWidget_CID->setCellWidget(row, 0, pCheckBox);
    pCheckBox->setText(name);

}

void Dialog::set_item_checked(bool checked, int row)
{
    QWidget *widget = ui->tableWidget_CID->cellWidget(row, 0);
    QCheckBox *checkBox = dynamic_cast<QCheckBox*>(widget);
    checkBox->setChecked(checked);
}

void Dialog::get_CID_list()
{
    MICID_list_checked.clear();
    for (int row = 0; row < ui->tableWidget_CID->rowCount(); ++row)
    {
        QWidget *widget = ui->tableWidget_CID->cellWidget(row, 0);
        QCheckBox *checkBox = dynamic_cast<QCheckBox*>(widget);
        if (checkBox->isChecked())
        {
            MICID_list_checked.append(checkBox->text());
        }
    }
}


void Dialog::log_receiveData1(QHash <QString, QString> data)
{
    appendTimes +=data.size()+1;
    ui->textEdit->setTextColor(QColor(0, 0, 0));
    QHash<QString, QString>::iterator i;
    for (i = data.begin(); i != data.end(); ++i)
    {
        ui->textEdit->append("Re:" + i.key() + ":"+i.value());
    }

    ui->textEdit->append("");
    limitTextLines();
}

void Dialog::log_sendData(const QString data)
{
    appendTimes ++;
    ui->textEdit->setTextColor(QColor(0, 0, 0));
    ui->textEdit->append("Send:" + data);
    limitTextLines();
}

void Dialog::log_green(const QString msg)
{
    appendTimes ++;
    ui->textEdit->setTextColor(QColor(50, 205, 50));
    ui->textEdit->append(msg);
    limitTextLines();
}

void Dialog::log_red(const QString msg)
{
    appendTimes ++;
    ui->textEdit->setTextColor(QColor(227, 23, 13));
    ui->textEdit->append(msg);
    limitTextLines();
}

void Dialog::limitTextLines()
{
    while (appendTimes > 150)
    {
        QTextCursor cursor(ui->textEdit->document());
        cursor.movePosition(QTextCursor::Start);
        cursor.movePosition(QTextCursor::NextBlock, QTextCursor::KeepAnchor);
        cursor.removeSelectedText();
        appendTimes--;
    }
}

void Dialog::log_receiveData(QString data)
{
//    if (mi_cid != ui->lineEdit_CID->text())
//    {
//        log_red("微逆CID不匹配");
//        return;
//    }

    appendTimes +=2;
    ui->textEdit->setTextColor(QColor(0, 0, 0));
    ui->textEdit->append("Re:" + data);
    ui->textEdit->append("");
    limitTextLines();
}

void Dialog::slot_set_maxop_read_back_flag(QString old_status,QString status)
{
    if(old_status == MaxOP_ctl_time)
    {
        MaxOP_ctl_time = status;
    }
}
void Dialog::slot_set_cop_read_back_flag(QString old_status,QString status)
{
    if(old_status == COP_ctl_time)
    {
        COP_ctl_time = status;

    }
}
void Dialog::slot_set_grid_read_back_flag(QString old_status,QString status)
{
    if(old_status == Grid_ctl_time)
    {
        Grid_ctl_time = status;

    }
}
void Dialog::slot_set_cer_read_back_flag(QString old_status,QString status)
{
    if(old_status == Cer_ctl_time)
    {

        Cer_ctl_time = status;
    }
}

void Dialog::slot_set_r_maxop_read_back_flag(QString old_status, QString status)
{
    if(old_status == r_MaxOP_ctl_time)
    {
        r_MaxOP_ctl_time = status;

    }
}
void Dialog::slot_set_r_cop_read_back_flag(QString old_status, QString status)
{
    if(old_status == r_COP_ctl_time)
    {
        r_COP_ctl_time = status;

    }
}
void Dialog::slot_set_r_grid_read_back_flag(QString old_status, QString status)
{
    if(old_status == r_Grid_ctl_time)
    {

        r_Grid_ctl_time = status;

    }
}

void Dialog::slot_set_r_cer_read_back_flag(QString old_status, QString status)
{
    if(old_status == r_Cer_ctl_time)
    {
        r_Cer_ctl_time = status;

    }
}

//从界面获取并网参数
void Dialog::getGrid()
{
    s_Grid.CID = ui->comboBox_CID->currentText();
    s_Grid.uOV1 = ui->lineEdit_uOV1->text().toFloat();
    s_Grid.tOV1 = ui->lineEdit_tOV1->text().toFloat();
    s_Grid.uUV1 = ui->lineEdit_uUV1->text().toFloat();
    s_Grid.tUV1 = ui->lineEdit_tUV1->text().toFloat();
    s_Grid.uOF1 = ui->lineEdit_uOF1->text().toFloat();
    s_Grid.tOF1 = ui->lineEdit_tOF1->text().toFloat();
    s_Grid.uUF1 = ui->lineEdit_uUF1->text().toFloat();
    s_Grid.tUF1 = ui->lineEdit_tUF1->text().toFloat();
    s_Grid.uOV2 = ui->lineEdit_uOV2->text().toFloat();
    s_Grid.tOV2 = ui->lineEdit_tOV2->text().toFloat();
    s_Grid.uUV2 = ui->lineEdit_uUV2->text().toFloat();
    s_Grid.tUV2 = ui->lineEdit_tUV2->text().toFloat();
    s_Grid.uOF2 = ui->lineEdit_uOF2->text().toFloat();
    s_Grid.tOF2 = ui->lineEdit_tOF2->text().toFloat();
    s_Grid.uUF2 = ui->lineEdit_uUF2->text().toFloat();
    s_Grid.tUF2 = ui->lineEdit_tUF2->text().toFloat();
    s_Grid.GT = ui->lineEdit_GT->text().toInt();
    s_Grid.URov = ui->lineEdit_UROV->text().toFloat();
    s_Grid.URuv = ui->lineEdit_URuV->text().toFloat();
    s_Grid.FRof = ui->lineEdit_FROF->text().toFloat();
    s_Grid.FRuf = ui->lineEdit_FRuF->text().toFloat();
    s_Grid.superPF = ui->comboBox_SuperPF->currentIndex();
    s_Grid.ASPQU = ui->comboBox_ASPQU->currentIndex();
    s_Grid.CEIDFU = ui->comboBox_CEIDFU->currentIndex();
    s_Grid.Var = ui->comboBox_VAR->currentIndex();
    s_Grid.HVRT = ui->lineEdit_HVRT->text().toFloat();
    s_Grid.LVRT = ui->lineEdit_LVRT->text().toFloat();
    ui->comboBox_RatedFreq->currentIndex() == 0 ? s_Grid.RatedFreq = 125:s_Grid.RatedFreq = 150;
    ui->comboBox_RatedFreq->currentIndex() == 0 ? s_Grid.t_RatedFreq = 20:s_Grid.t_RatedFreq = 16.67;
}

//从界面获取认证参数
void Dialog::getCer()
{
    s_Cer.Fixed_non_P = ui->comboBox_Fixed_non_P->currentIndex();
    s_Cer.Fixed_non_P_Para = ui->lineEdit_FixedPF_Para->text().toFloat();

    switch (ui->comboBox_MaxPF_Value->currentIndex())
    {
    case 0: s_Cer.Max_non_P = 5; break;
    case 1: s_Cer.Max_non_P = 10; break;
    case 2: s_Cer.Max_non_P = 20; break;
    default: break;
    }
    s_Cer.Remote_P_slope = ui->comboBox_Remote_P_slope->currentIndex();
    s_Cer.Remote_P_slopePara = ui->lineEdit_Remote_P_slope->text().toFloat();
    s_Cer.Reconnect_P_slope = ui->lineEdit_Reconnect_P->text().toFloat();
    s_Cer.OverVol_10 = ui->comboBox_OV10min->currentIndex();
    s_Cer.OverVol_10_Para = ui->lineEdit_OverVol->text().toFloat();
    s_Cer.UF_hyst = ui->comboBox_UF_hyst->currentIndex();
    s_Cer.UF_hyst_powerOn = ui->comboBox_UF_hyst_powerOn->currentIndex();
    s_Cer.LFSM_Mode = ui->comboBox_LFSMMode->currentIndex();
    s_Cer.LFSMO_fact = ui->lineEdit_LFSMO_fact->text().toFloat();
    s_Cer.LFSMO_fdeact = ui->lineEdit_LFSMO_fdeact->text().toFloat();
    s_Cer.LFSMO_Droop = ui->lineEdit_LFSMO_Droop->text().toFloat();
    s_Cer.LFSMO_Trec = ui->lineEdit_LFSMO_Trec->text().toInt();
    s_Cer.LFSMO_P_slope = ui->lineEdit_LFSMO_P_slope->text().toFloat();
    s_Cer.LFSMO_Pn = ui->comboBox_LFSMO_Pn->currentIndex();
    s_Cer.LFSMU_fact = ui->lineEdit_LFSMU_fact->text().toFloat();
    s_Cer.LFSMU_fdeact = ui->lineEdit_LFSMU_fdeact->text().toFloat();
    s_Cer.LFSMU_Droop = ui->lineEdit_LFSMU_Droop->text().toFloat();
    s_Cer.Island = ui->comboBox_Island->currentIndex();
    s_Cer.DF1 = ui->comboBox_DF1->currentIndex();
    s_Cer.DF2 = ui->comboBox_DF2->currentIndex();
    s_Cer.FVRT = ui->comboBox_FVRT->currentIndex();
    s_Cer.ratedVol = ui->lineEdit_RatedVol->text().toInt();
    s_Cer.PU_mode = ui->comboBox_PUMode->currentIndex();
    s_Cer.PU_InitialVol = ui->lineEdit_PU_InitialVol->text().toFloat();
    s_Cer.PU_EndVol = ui->lineEdit_PU_EndVol->text().toFloat();
    s_Cer.PU_Droop = ui->lineEdit_PU_Droop->text().toFloat();
    s_Cer.PU_DroopSpd = ui->lineEdit_PU_DroopSpd->text().toFloat();
    s_Cer.QU_mode = ui->comboBox_QUMode->currentIndex();
    s_Cer.QU_UVstart = ui->lineEdit_UV_start->text().toFloat();
    s_Cer.QU_UVstop = ui->lineEdit_UV_stop->text().toFloat();
    s_Cer.QU_OVstart = ui->lineEdit_OV_start->text().toFloat();
    s_Cer.QU_OVstop = ui->lineEdit_OV_stop->text().toFloat();
    s_Cer.QU_Plockin = ui->lineEdit_Plock_in->text().toFloat();
    s_Cer.QU_PlockOut = ui->lineEdit_Plock_out->text().toFloat();
    s_Cer.tao = ui->comboBox_Tau->currentIndex();
    s_Cer.certification_En = ui->comboBox_cetificationMode->currentIndex();
    s_Cer.CID = ui->comboBox_CID->currentText();
    s_Cer.SWH_MaxPF = ui->comboBox_MaxPF_Value->currentIndex();
    s_Cer.SWH_Tao = ui->comboBox_Tau->currentIndex();
}

void Dialog::Re_getGridNum(QString Grid)
{
    bool ok;
    s_Re_Grid.uOV1 = Grid.mid(0, 4).toInt(&ok, 16)/sqrt(2)/64.0;
    s_Re_Grid.tOV1 = Grid.mid(4, 4).toInt(&ok, 16);
    s_Re_Grid.uUV1 = Grid.mid(8, 4).toInt(&ok, 16)/sqrt(2)/(double)64;
    s_Re_Grid.tUV1 = Grid.mid(12, 4).toInt(&ok, 16);
    if (Grid.mid(16, 4).toInt(&ok, 16))
    {
        s_Re_Grid.uOF1 = 50000000/(Grid.mid(16, 4).toInt(&ok, 16)*(double)64);
        s_Re_Grid.tOF1 = Grid.mid(20, 4).toInt(&ok, 16);
    }
    else
    {
        s_Re_Grid.uOF1 =0;
        s_Re_Grid.tOF1 =0;
    }

    if (Grid.mid(24, 4).toInt(&ok, 16))
    {
        s_Re_Grid.uUF1 = 50000000/(Grid.mid(24, 4).toInt(&ok, 16)*(double)64);
        s_Re_Grid.tUF1 = Grid.mid(28, 4).toInt(&ok, 16);
    }
    else
    {
        s_Re_Grid.uUF1 = 0;
        s_Re_Grid.tUF1 = 0;
    }

    s_Re_Grid.uOV2 = Grid.mid(32, 4).toInt(&ok, 16)/sqrt(2)/(double)64;
    s_Re_Grid.tOV2 = Grid.mid(36, 4).toInt(&ok, 16);
    s_Re_Grid.uUV2 = Grid.mid(40, 4).toInt(&ok, 16)/sqrt(2)/(double)64;
    s_Re_Grid.tUV2 = Grid.mid(44, 4).toInt(&ok, 16);
    if (Grid.mid(48, 4).toInt(&ok, 16))
    {
        s_Re_Grid.uOF2 = 50000000/(Grid.mid(48, 4).toInt(&ok, 16)*(double)64);
        s_Re_Grid.tOF2 = Grid.mid(52, 4).toInt(&ok, 16);
    }
    else
    {
        s_Re_Grid.uOF2 = 0;
        s_Re_Grid.tOF2 = 0;
    }


    if (Grid.mid(56, 4).toInt(&ok, 16))
    {
        s_Re_Grid.uUF2 = 50000000/(Grid.mid(56, 4).toInt(&ok, 16)*(double)64);
        s_Re_Grid.tUF2 = Grid.mid(60, 4).toInt(&ok, 16);
    }
    else
    {
        s_Re_Grid.uUF2 = 0;
        s_Re_Grid.tUF2 = 0;
    }

    s_Re_Grid.GT = Grid.mid(64, 4).toInt(&ok, 16);
    s_Re_Grid.URov = Grid.mid(68, 4).toInt(&ok, 16)/sqrt(2)/(double)64;
    s_Re_Grid.URuv = Grid.mid(72, 4).toInt(&ok, 16)/sqrt(2)/(double)64;
    if (Grid.mid(76, 4).toInt(&ok, 16))
    {
        s_Re_Grid.FRof = 50000000/(Grid.mid(76, 4).toInt(&ok, 16)*(double)64);
    }
    else s_Re_Grid.FRof = 0;
    if (Grid.mid(80, 4).toInt(&ok, 16))
    {
        s_Re_Grid.FRuf = 50000000/(Grid.mid(80, 4).toInt(&ok, 16)*(double)64);
    }
    else s_Re_Grid.FRuf = 0;
    s_Re_Grid.superPF = Grid.mid(84, 2).toInt();
    s_Re_Grid.ASPQU = Grid.mid(86, 2).toInt();
    s_Re_Grid.CEIDFU = Grid.mid(88, 2).toInt();
    s_Re_Grid.Var = Grid.mid(90, 2).toInt();
    s_Re_Grid.HVRT = Grid.mid(92, 2).toInt(&ok, 16)+100;
    s_Re_Grid.LVRT = Grid.mid(94, 2).toInt(&ok, 16);

}

void Dialog::Re_getCerNum(QString Cer)
{
    bool ok;

    s_Re_Cer.Fixed_non_P = Cer.mid(0, 2).toInt(&ok, 16);

    if(Cer.mid(2, 4).toInt(&ok, 16))
    {
        s_Re_Cer.Fixed_non_P_Para = Cer.mid(2, 4).toInt(&ok, 16)/(double)200.0-2;
    }
    else s_Re_Cer.Fixed_non_P_Para = 0;
    s_Re_Cer.Remote_P_slope = Cer.mid(6, 2).toInt(&ok, 16);
    s_Re_Cer.Remote_P_slopePara = Cer.mid(8, 4).toInt(&ok, 16)/(double)163.84;
    s_Re_Cer.OverVol_10 = Cer.mid(12, 2).toInt(&ok, 16);
    s_Re_Cer.UF_hyst = Cer.mid(14, 2).toInt(&ok, 16);
    s_Re_Cer.LFSM_Mode = Cer.mid(16, 2).toInt(&ok, 16);

    if (Cer.mid(18, 4).toInt(&ok, 16))
    {
        s_Re_Cer.LFSMO_fact = 50000000/((double)64*Cer.mid(18, 4).toInt(&ok, 16));
    }
    else s_Re_Cer.LFSMO_fact = 0;

    if (Cer.mid(22, 4).toInt(&ok, 16))
    {
        s_Re_Cer.LFSMO_fdeact = 50000000/((double)64*Cer.mid(22, 4).toInt(&ok, 16));
    }
    else s_Re_Cer.LFSMO_fdeact = 0;

    s_Re_Cer.LFSMO_Droop = Cer.mid(26, 2).toInt(&ok, 16)/10.0;

    if (Cer.mid(28, 4).toInt(&ok, 16))
    {
        s_Re_Cer.LFSMU_fact = 50000000/((double)64*Cer.mid(28, 4).toInt(&ok, 16));
    }
    else s_Re_Cer.LFSMU_fact = 0;

    if (Cer.mid(32, 4).toInt(&ok, 16))
    {
        s_Re_Cer.LFSMU_fdeact = 50000000/((double)64*Cer.mid(32, 4).toInt(&ok, 16));
    }
    else s_Re_Cer.LFSMU_fdeact = 0;

    s_Re_Cer.LFSMU_Droop = Cer.mid(36, 2).toInt(&ok, 16)/(double)10.0;
    s_Re_Cer.LFSMO_Trec = Cer.mid(38, 4).toInt(&ok, 16);
    s_Re_Cer.LFSMO_P_slope = Cer.mid(42, 4).toInt(&ok, 16)/(double)163.84;
    s_Re_Cer.Reconnect_P_slope = Cer.mid(46, 4).toInt(&ok, 16)/(double)163.84;
    s_Re_Cer.Island = Cer.mid(50, 2).toInt(&ok, 16);
    s_Re_Cer.DF1 = Cer.mid(52, 2).toInt(&ok, 16);
    s_Re_Cer.DF2 = Cer.mid(54, 2).toInt(&ok, 16);
    s_Re_Cer.FVRT = Cer.mid(56, 2).toInt(&ok, 16);
    s_Re_Cer.UF_hyst_powerOn = Cer.mid(58, 2).toInt(&ok, 16);
    s_Re_Cer.QU_mode = Cer.mid(60, 2).toInt(&ok, 16);
    s_Re_Cer.PU_mode = Cer.mid(62, 2).toInt(&ok, 16);
    s_Re_Cer.LFSMO_Pn = Cer.mid(64, 2).toInt(&ok, 16);
    s_Re_Cer.ratedVol = Cer.mid(66, 2).toInt(&ok, 16);
    s_Re_Cer.PU_InitialVol = Cer.mid(68, 2).toInt(&ok, 16);
    s_Re_Cer.PU_EndVol = Cer.mid(70, 2).toInt(&ok, 16);
    s_Re_Cer.PU_Droop = Cer.mid(72, 2).toInt(&ok, 16);
    s_Re_Cer.PU_DroopSpd = Cer.mid(74, 2).toInt(&ok, 16);
    s_Re_Cer.QU_UVstart = Cer.mid(76, 2).toInt(&ok, 16);
    s_Re_Cer.QU_UVstop = Cer.mid(78, 2).toInt(&ok, 16);
    s_Re_Cer.QU_OVstart = Cer.mid(80, 2).toInt(&ok, 16);
    s_Re_Cer.QU_OVstop = Cer.mid(82, 2).toInt(&ok, 16);
    s_Re_Cer.QU_Plockin = Cer.mid(84, 2).toInt(&ok, 16);
    s_Re_Cer.QU_PlockOut = Cer.mid(86, 2).toInt(&ok, 16);
    s_Re_Cer.OverVol_10_Para = Cer.mid(88, 2).toInt(&ok, 16)/(double)4.0+230;
    s_Re_Cer.Max_non_P = Cer.mid(90, 2).toInt(&ok, 16);
    s_Re_Cer.tao = Cer.mid(92, 2).toInt(&ok, 16);
    s_Re_Cer.certification_En = Cer.mid(94, 2).toInt(&ok, 16);
}



void Dialog::slot_receiveCOP(QHash<QString, QString> Re_COP)
{
    bool ok;
    QString COP, COP_Ack;
    double COP_num;

    save_Re_COP = Re_COP;

    if (Re_COP.keys().contains(ui->comboBox_CID->currentText()))
    {
        COP_num = Re_COP[ui->comboBox_CID->currentText()].mid(0, 4).toInt(&ok, 16)/16384.0*100;
        COP = QString::number((int)(COP_num*10 + 0.5)/10.0);
    }
    else COP = "";

    ui->lineEdit_COP->setText(COP);

    log_green("COP读取成功");
    log_receiveData1(Re_COP);
    //    COP_Ack = "8705"+MICID+"01";
    //    emit signal_COP_Ack(COP_Ack);
}

void Dialog::slot_receiveMaxOP(QHash<QString, QString> Re_MaxOP)
{
    bool ok;
    QString MaxOP, MaxOP_Ack;

    save_Re_MaxOP = Re_MaxOP;

    if (Re_MaxOP.keys().contains(ui->comboBox_CID->currentText()))
    {
        MaxOP = QString::number(Re_MaxOP[ui->comboBox_CID->currentText()].mid(0, 2).toInt(&ok, 16)*10);
    }
    else MaxOP = "";

    ui->lineEdit_MaxOP->setText(MaxOP);

    log_green("MaxOP读取成功");
    log_receiveData1(Re_MaxOP);
//    MaxOP_Ack = "8905"+MICID+"01";
//    emit signal_MaxOP_Ack(MaxOP_Ack);
}





void Dialog::slot_receiveGrid(QHash<QString, QString> Re_Grid)
{
    QString Grid_Ack;
    save_Re_Grid = Re_Grid;
    if (Re_Grid.keys().contains(ui->comboBox_CID->currentText()))
    {
        Re_getGridNum(Re_Grid[ui->comboBox_CID->currentText()]);

        ui->comboBox_RatedFreq->currentIndex()==0? s_Re_Grid.t_RatedFreq = 20: s_Re_Grid.t_RatedFreq = 16.67;
        ui->comboBox_RatedFreq->currentIndex() == 0 ? s_Re_Grid.RatedFreq = 125:s_Re_Grid.RatedFreq = 150;

        s_str_Grid.uOV1 = s_str_Grid.uOV1.number(Dec((s_Re_Grid.uOV1), 2));
        s_str_Grid.tOV1 = s_str_Grid.tOV1.number(Dec((s_Re_Grid.tOV1*s_Re_Grid.t_RatedFreq), 2));
        s_str_Grid.uUV1 = s_str_Grid.uUV1.number(Dec((s_Re_Grid.uUV1), 1));
        s_str_Grid.tUV1 = s_str_Grid.tUV1.number(Dec((s_Re_Grid.tUV1*s_Re_Grid.t_RatedFreq), 2));
        s_str_Grid.uOF1 = s_str_Grid.uOF1.number(Dec((s_Re_Grid.uOF1), 1));
        if (s_Re_Grid.tOF1)
        {
            s_str_Grid.tOF1 = s_str_Grid.tOF1.number(Dec((s_Re_Grid.tOF1*((float)1000/s_Re_Grid.uOF1)), 2));
        }
        else s_str_Grid.tOF1 = "0";

        s_str_Grid.uUF1 = s_str_Grid.uUF1.number(Dec((s_Re_Grid.uUF1), 1));
        if (s_Re_Grid.tUF1)
        {
            s_str_Grid.tUF1 = s_str_Grid.tUF1.number(Dec((s_Re_Grid.tUF1*((float)1000/s_Re_Grid.uUF1)), 2));
        }
        else s_str_Grid.tUF1 = "0";
        s_str_Grid.uOV2 = s_str_Grid.uOV2.number(Dec((s_Re_Grid.uOV2), 1));
        s_str_Grid.tOV2 = s_str_Grid.tOV2.number(Dec((s_Re_Grid.tOV2*s_Re_Grid.t_RatedFreq), 2));
        s_str_Grid.uUV2 = s_str_Grid.uUV2.number(Dec((s_Re_Grid.uUV2), 1));
        s_str_Grid.tUV2 = s_str_Grid.tUV2.number(Dec((s_Re_Grid.tUV2*s_Re_Grid.t_RatedFreq), 2));
        s_str_Grid.uOF2 = s_str_Grid.uOF2.number(Dec((s_Re_Grid.uOF2), 1));
        if (s_Re_Grid.tOF2)
        {
            s_str_Grid.tOF2 = s_str_Grid.tOF2.number(Dec((s_Re_Grid.tOF2*((float)1000/s_Re_Grid.uOF2)), 2));
        }
        else s_str_Grid.tOF2 = "0";
        s_str_Grid.uUF2 = s_str_Grid.uUF2.number(Dec((s_Re_Grid.uUF2), 1));
        if (s_Re_Grid.tUF2)
        {
            s_str_Grid.tUF2 = s_str_Grid.tUF2.number(Dec((s_Re_Grid.tUF2*((float)1000/s_Re_Grid.uUF2)), 2));
        }
        else s_str_Grid.tUF2 = "0";
        s_str_Grid.GT = s_str_Grid.GT.number(s_Re_Grid.GT/s_Re_Grid.RatedFreq);
        s_str_Grid.URov = s_str_Grid.URov.number(Dec((s_Re_Grid.URov), 2));
        s_str_Grid.URuv = s_str_Grid.URuv.number(Dec((s_Re_Grid.URuv), 2));
        s_str_Grid.FRof = s_str_Grid.FRof.number(Dec((s_Re_Grid.FRof), 2));
        s_str_Grid.FRuf = s_str_Grid.FRuf.number(Dec((s_Re_Grid.FRuf), 2));
        s_str_Grid.superPF = s_Re_Grid.superPF;
        s_str_Grid.ASPQU = s_Re_Grid.ASPQU;
        s_str_Grid.CEIDFU = s_Re_Grid.CEIDFU;
        s_str_Grid.Var = s_Re_Grid.Var;
        s_str_Grid.HVRT = s_str_Grid.HVRT.number(s_Re_Grid.HVRT);
        s_str_Grid.LVRT = s_str_Grid.LVRT.number(s_Re_Grid.LVRT);
    }
    else
    {
        s_str_Grid.uOV1 = "";
        s_str_Grid.tOV1 = "";
        s_str_Grid.uUV1 = "";
        s_str_Grid.tUV1 = "";
        s_str_Grid.uOF1 = "";
        s_str_Grid.tOF1 = "";
        s_str_Grid.uUF1 = "";
        s_str_Grid.tUF1 = "";
        s_str_Grid.uOV2 = "";
        s_str_Grid.tOV2 = "";
        s_str_Grid.uUV2 = "";
        s_str_Grid.tUV2 = "";
        s_str_Grid.uOF2 = "";
        s_str_Grid.tOF2 = "";
        s_str_Grid.uUF2 = "";
        s_str_Grid.tUF2 = "";
        s_str_Grid.GT = "";
        s_str_Grid.URov = "";
        s_str_Grid.URuv = "";
        s_str_Grid.FRof = "";
        s_str_Grid.FRuf = "";
        ui->comboBox_SuperPF = 0;
        ui->comboBox_ASPQU = 0;
        ui->comboBox_CEIDFU = 0;
        ui->comboBox_VAR = 0;
        s_str_Grid.HVRT = "";
        s_str_Grid.LVRT = "";
    }

    ui->lineEdit_uOV1->setText(s_str_Grid.uOV1);
    ui->lineEdit_tOV1->setText(s_str_Grid.tOV1);
    ui->lineEdit_uUV1->setText(s_str_Grid.uUV1);
    ui->lineEdit_tUV1->setText(s_str_Grid.tUV1);
    ui->lineEdit_uOF1->setText(s_str_Grid.uOF1);
    ui->lineEdit_tOF1->setText(s_str_Grid.tOF1);
    ui->lineEdit_uUF1->setText(s_str_Grid.uUF1);
    ui->lineEdit_tUF1->setText(s_str_Grid.tUF1);
    ui->lineEdit_uOV2->setText(s_str_Grid.uOV2);
    ui->lineEdit_tOV2->setText(s_str_Grid.tOV2);
    ui->lineEdit_uUV2->setText(s_str_Grid.uUV2);
    ui->lineEdit_tUV2->setText(s_str_Grid.tUV2);
    ui->lineEdit_uOF2->setText(s_str_Grid.uOF2);
    ui->lineEdit_tOF2->setText(s_str_Grid.tOF2);
    ui->lineEdit_uUF2->setText(s_str_Grid.uUF2);
    ui->lineEdit_tUF2->setText(s_str_Grid.tUF2);
    ui->lineEdit_GT->setText(s_str_Grid.GT);
    ui->lineEdit_UROV->setText(s_str_Grid.URov);
    ui->lineEdit_URuV->setText(s_str_Grid.URuv);
    ui->lineEdit_FROF->setText(s_str_Grid.FRof);
    ui->lineEdit_FRuF->setText(s_str_Grid.FRuf);
    ui->comboBox_SuperPF->setCurrentIndex(s_str_Grid.superPF);
    ui->comboBox_ASPQU->setCurrentIndex(s_str_Grid.ASPQU);
    ui->comboBox_CEIDFU->setCurrentIndex(s_str_Grid.CEIDFU);
    ui->comboBox_VAR->setCurrentIndex(s_str_Grid.Var);
    ui->lineEdit_HVRT->setText(s_str_Grid.HVRT);
    ui->lineEdit_LVRT->setText(s_str_Grid.LVRT);

    log_green("并网参数读取成功");
    log_receiveData1(Re_Grid);
//    Grid_Ack = "8b01"+MICID+"01";
//    emit signal_Grid_Ack(Grid_Ack);
}


void Dialog::slot_receiveCer(QHash<QString, QString> Re_Cer)
{
    QString Cer_Ack;
    save_Re_Cer = Re_Cer;

    if (Re_Cer.keys().contains(ui->comboBox_CID->currentText()))
    {
        Re_getCerNum(Re_Cer[ui->comboBox_CID->currentText()]);

        s_str_Cer.Fixed_non_P = s_Re_Cer.Fixed_non_P;
        s_str_Cer.Fixed_non_P_Para = s_str_Cer.Fixed_non_P_Para.number(s_Re_Cer.Fixed_non_P_Para);
        s_str_Cer.Remote_P_slope = s_Re_Cer.Remote_P_slope;
        s_str_Cer.Remote_P_slopePara = s_str_Cer.Remote_P_slopePara.number(Dec((s_Re_Cer.Remote_P_slopePara), 2));
        s_str_Cer.OverVol_10 = s_Re_Cer.OverVol_10;
        s_str_Cer.UF_hyst = s_Re_Cer.UF_hyst;
        s_str_Cer.LFSM_Mode = s_Re_Cer.LFSM_Mode;
        s_str_Cer.LFSMO_fact = s_str_Cer.LFSMO_fact.number(Dec(s_Re_Cer.LFSMO_fact, 2));
        s_str_Cer.LFSMO_fdeact = s_str_Cer.LFSMO_fdeact.number(Dec(s_Re_Cer.LFSMO_fdeact, 2));
        s_str_Cer.LFSMO_Droop = s_str_Cer.LFSMO_Droop.number(Dec((s_Re_Cer.LFSMO_Droop), 2));
        s_str_Cer.LFSMU_fact = s_str_Cer.LFSMU_fact.number(Dec(s_Re_Cer.LFSMU_fact, 2));
        s_str_Cer.LFSMU_fdeact = s_str_Cer.LFSMU_fdeact.number(Dec(s_Re_Cer.LFSMU_fdeact, 2));
        s_str_Cer.LFSMU_Droop = s_str_Cer.LFSMU_Droop.number(Dec(s_Re_Cer.LFSMU_Droop, 2));
        s_str_Cer.LFSMO_Trec = s_str_Cer.LFSMO_Trec.number(Dec(s_Re_Cer.LFSMO_Trec, 0));
        s_str_Cer.LFSMO_P_slope = s_str_Cer.LFSMO_P_slope.number(Dec(s_Re_Cer.LFSMO_P_slope, 2));
        s_str_Cer.Reconnect_P_slope = s_str_Cer.Reconnect_P_slope.number(Dec(s_Re_Cer.Reconnect_P_slope, 2));
        s_str_Cer.Island = s_Re_Cer.Island;
        s_str_Cer.DF1 = s_Re_Cer.DF1;
        s_str_Cer.DF2 = s_Re_Cer.DF2;
        s_str_Cer.FVRT = s_Re_Cer.FVRT;
        s_str_Cer.UF_hyst_powerOn = s_Re_Cer.UF_hyst_powerOn;
        s_str_Cer.QU_mode = s_Re_Cer.QU_mode;
        s_str_Cer.PU_mode = s_Re_Cer.PU_mode;
        s_str_Cer.LFSMO_Pn = s_Re_Cer.LFSMO_Pn;
        s_str_Cer.ratedVol = s_str_Cer.ratedVol.number(Dec(s_Re_Cer.ratedVol, 0));
        s_str_Cer.PU_InitialVol = s_str_Cer.PU_InitialVol.number(Dec(s_Re_Cer.PU_InitialVol, 2));
        s_str_Cer.PU_EndVol = s_str_Cer.PU_EndVol.number(Dec(s_Re_Cer.PU_EndVol, 2));
        s_str_Cer.PU_Droop = s_str_Cer.PU_Droop.number(Dec(s_Re_Cer.PU_Droop, 2));
        s_str_Cer.PU_DroopSpd = s_str_Cer.PU_DroopSpd.number(Dec(s_Re_Cer.PU_DroopSpd, 2));
        s_str_Cer.QU_UVstart = s_str_Cer.QU_UVstart.number(Dec(s_Re_Cer.QU_UVstart, 2));
        s_str_Cer.QU_UVstop = s_str_Cer.QU_UVstop.number(Dec(s_Re_Cer.QU_UVstop, 2));
        s_str_Cer.QU_OVstart = s_str_Cer.QU_OVstart.number(Dec(s_Re_Cer.QU_OVstart, 2));
        s_str_Cer.QU_OVstop = s_str_Cer.QU_OVstop.number(Dec(s_Re_Cer.QU_OVstop, 2));
        s_str_Cer.QU_Plockin = s_str_Cer.QU_Plockin.number(Dec(s_Re_Cer.QU_Plockin, 2));
        s_str_Cer.QU_PlockOut = s_str_Cer.QU_PlockOut.number(Dec(s_Re_Cer.QU_PlockOut, 2));
        s_str_Cer.OverVol_10_Para = s_str_Cer.OverVol_10_Para.number(Dec(s_Re_Cer.OverVol_10_Para, 2));
        switch(s_Re_Cer.Max_non_P)
        {
        case 5: s_str_Cer.Max_non_P = 0; break;
        case 10: s_str_Cer.Max_non_P = 1; break;
        case 20: s_str_Cer.Max_non_P = 2; break;
        default: break;
        }
        s_str_Cer.tao = s_Re_Cer.tao;
        s_str_Cer.certification_En = s_Re_Cer.certification_En;
    }
    else
    {
        s_str_Cer.Fixed_non_P = 0;
        s_str_Cer.Fixed_non_P_Para = "";
        s_str_Cer.Remote_P_slope = 0;
        s_str_Cer.Remote_P_slopePara = "";
        s_str_Cer.OverVol_10 = 0;
        s_str_Cer.UF_hyst = 0;
        s_str_Cer.LFSM_Mode = 0;

        s_str_Cer.LFSMO_fact = "";
        s_str_Cer.LFSMO_fdeact = "";
        s_str_Cer.LFSMO_Droop = "";
        s_str_Cer.LFSMU_fact = "";
        s_str_Cer.LFSMU_fdeact = "";
        s_str_Cer.LFSMU_Droop = "";
        s_str_Cer.LFSMO_Trec = "";
        s_str_Cer.LFSMO_P_slope = "";
        s_str_Cer.Reconnect_P_slope = "";
        s_str_Cer.Island = 0;
        s_str_Cer.DF1 = 0;
        s_str_Cer.DF2 = 0;
        s_str_Cer.FVRT = 0;
        s_str_Cer.UF_hyst_powerOn = 0;
        s_str_Cer.QU_mode = 0;
        s_str_Cer.PU_mode = 0;
        s_str_Cer.LFSMO_Pn = 0;
        s_str_Cer.ratedVol = "";
        s_str_Cer.PU_InitialVol = "";
        s_str_Cer.PU_EndVol = "";
        s_str_Cer.PU_Droop = "";
        s_str_Cer.PU_DroopSpd = "";
        s_str_Cer.QU_UVstart = "";
        s_str_Cer.QU_UVstop = "";
        s_str_Cer.QU_OVstart = "";
        s_str_Cer.QU_OVstop = "";
        s_str_Cer.QU_Plockin = "";
        s_str_Cer.QU_PlockOut = "";
        s_str_Cer.OverVol_10_Para = "";
        s_str_Cer.Max_non_P = 0;
        s_str_Cer.tao = 0;
        s_str_Cer.certification_En = 0;

    }



    ui->comboBox_Fixed_non_P->setCurrentIndex(s_str_Cer.Fixed_non_P);
    ui->lineEdit_FixedPF_Para->setText(s_str_Cer.Fixed_non_P_Para);
    ui->comboBox_Remote_P_slope->setCurrentIndex(s_str_Cer.Remote_P_slope);
    ui->lineEdit_Remote_P_slope->setText(s_str_Cer.Remote_P_slopePara);
    ui->comboBox_OV10min->setCurrentIndex(s_str_Cer.OverVol_10);
    ui->comboBox_UF_hyst->setCurrentIndex(s_str_Cer.UF_hyst);
    ui->comboBox_LFSMMode->setCurrentIndex(s_str_Cer.LFSM_Mode);
    ui->lineEdit_LFSMO_fact->setText(s_str_Cer.LFSMO_fact);
    ui->lineEdit_LFSMO_fdeact->setText(s_str_Cer.LFSMO_fdeact);
    ui->lineEdit_LFSMO_Droop->setText(s_str_Cer.LFSMO_Droop);
    ui->lineEdit_LFSMU_fact->setText(s_str_Cer.LFSMU_fact);
    ui->lineEdit_LFSMU_fdeact->setText(s_str_Cer.LFSMU_fdeact);
    ui->lineEdit_LFSMU_Droop->setText(s_str_Cer.LFSMU_Droop);
    ui->lineEdit_LFSMO_Trec->setText(s_str_Cer.LFSMO_Trec);
    ui->lineEdit_LFSMO_P_slope->setText(s_str_Cer.LFSMO_P_slope);
    ui->lineEdit_Reconnect_P->setText(s_str_Cer.Reconnect_P_slope);
    ui->comboBox_Island->setCurrentIndex(s_str_Cer.Island);
    ui->comboBox_DF1->setCurrentIndex(s_str_Cer.DF1);
    ui->comboBox_DF2->setCurrentIndex(s_str_Cer.DF2);
    ui->comboBox_FVRT->setCurrentIndex(s_str_Cer.FVRT);
    ui->comboBox_UF_hyst_powerOn->setCurrentIndex(s_str_Cer.UF_hyst_powerOn);
    ui->comboBox_QUMode->setCurrentIndex(s_str_Cer.QU_mode);
    ui->comboBox_PUMode->setCurrentIndex(s_str_Cer.PU_mode);
    ui->comboBox_LFSMO_Pn->setCurrentIndex(s_str_Cer.LFSMO_Pn);
    ui->lineEdit_RatedVol->setText(s_str_Cer.ratedVol);
    ui->lineEdit_PU_InitialVol->setText(s_str_Cer.PU_InitialVol);
    ui->lineEdit_PU_EndVol->setText(s_str_Cer.PU_EndVol);
    ui->lineEdit_PU_Droop->setText(s_str_Cer.PU_Droop);
    ui->lineEdit_PU_DroopSpd->setText(s_str_Cer.PU_DroopSpd);
    ui->lineEdit_UV_start->setText(s_str_Cer.QU_UVstart);
    ui->lineEdit_UV_stop->setText(s_str_Cer.QU_UVstop);
    ui->lineEdit_OV_start->setText(s_str_Cer.QU_OVstart);
    ui->lineEdit_OV_stop->setText(s_str_Cer.QU_OVstop);
    ui->lineEdit_Plock_in->setText(s_str_Cer.QU_Plockin);
    ui->lineEdit_Plock_out->setText(s_str_Cer.QU_PlockOut);
    ui->lineEdit_OverVol->setText(s_str_Cer.OverVol_10_Para);
    ui->comboBox_MaxPF_Value->setCurrentIndex(s_str_Cer.Max_non_P);
    ui->comboBox_Tau->setCurrentIndex(s_str_Cer.tao);
    ui->comboBox_cetificationMode->setCurrentIndex(s_str_Cer.certification_En);


    log_green("认证参数读取成功");
    log_receiveData1(Re_Cer);
//    Cer_Ack = "8d01"+MICID+"01";
//    emit signal_Grid_Ack(Cer_Ack);
}

void Dialog::slot_fileSave(QString fileName)
{
    nameList.append(fileName);
    ui->comboBox_program->addItem(fileName);
    ui->comboBox_program->setCurrentText(fileName);
}

void Dialog::slot_openFile()
{
    QDesktopServices::openUrl(QUrl(data_filePath, QUrl::TolerantMode));
}

void Dialog::onm_timer_callback()
{
    QJsonObject js_sel;
    bool is_select_ctl_data = false;

    if(r_MaxOP_ctl_time != "")
    {
        QJsonObject obj;
        QJsonArray arr;
        for(int i=0;i<m_mi_r_MaxOP.size();i++)
        {
            arr.append(m_mi_r_MaxOP[i]);
        }

        obj.insert("r_maxop_ctl_time",r_MaxOP_ctl_time);
        obj.insert("mis",arr);
        js_sel.insert("r_maxop",obj);
        is_select_ctl_data = true;
    }

    if(r_COP_ctl_time != "")
    {
        QJsonObject obj;
        QJsonArray arr;
        for(int i=0;i<m_mi_r_COP.size();i++)
        {
            arr.append(m_mi_r_COP[i]);
        }

        obj.insert("r_cop_ctl_time",r_COP_ctl_time);
        obj.insert("mis",arr);
        js_sel.insert("r_cop",obj);


        is_select_ctl_data = true;
    }

    if(r_Grid_ctl_time != "")
    {
        QJsonObject obj;
        QJsonArray arr;
        for(int i=0;i<m_mi_r_Grid.size();i++)
        {
            arr.append(m_mi_r_Grid[i]);
        }
        obj.insert("r_grid_ctl_time",r_Grid_ctl_time);
        obj.insert("mis",arr);
        js_sel.insert("r_grid",obj);

        is_select_ctl_data = true;
    }

    if(r_Cer_ctl_time != "")
    {
        QJsonObject obj;
        QJsonArray arr;
        for(int i=0;i<m_mi_r_Cer.size();i++)
        {
            arr.append(m_mi_r_Cer[i]);
        }
        obj.insert("r_cer_ctl_time",r_Cer_ctl_time);
        obj.insert("mis",arr);
        js_sel.insert("r_cer",obj);
        is_select_ctl_data = true;
    }


    if(MaxOP_ctl_time != "")
    {
        QJsonObject obj;
        QJsonArray arr;
        for(int i=0;i<m_mi_w_MaxOP.size();i++)
        {
            arr.append(m_mi_w_MaxOP[i]);
        }
        obj.insert("maxop_ctl_time",MaxOP_ctl_time);
        obj.insert("mis",arr);
        js_sel.insert("w_maxop",obj);
        is_select_ctl_data = true;
    }

    if(COP_ctl_time != "")
    {
        QJsonObject obj;
        QJsonArray arr;
        for(int i=0;i<m_mi_w_COP.size();i++)
        {
            arr.append(m_mi_w_COP[i]);
        }
        obj.insert("cop_ctl_time",COP_ctl_time);
        obj.insert("mis",arr);
        js_sel.insert("w_cop",obj);
        is_select_ctl_data = true;
    }

    if(Grid_ctl_time != "")
    {
        QJsonObject obj;
        QJsonArray arr;
        for(int i=0;i<m_mi_w_Grid.size();i++)
        {
            arr.append(m_mi_w_Grid[i]);
        }
        obj.insert("grid_ctl_time",Grid_ctl_time);
        obj.insert("mis",arr);
        js_sel.insert("w_grid",obj);
        is_select_ctl_data = true;
    }

    if(Cer_ctl_time != "")
    {
        QJsonObject obj;
        QJsonArray arr;
        for(int i=0;i<m_mi_w_Cer.size();i++)
        {
            arr.append(m_mi_w_Cer[i]);
        }
        obj.insert("cer_ctl_time",Cer_ctl_time);
        obj.insert("mis",arr);
        js_sel.insert("w_cer",obj);
        is_select_ctl_data = true;
    }

    if(is_select_ctl_data)
    {
        js_sel["station"] = station;
        js_sel["emu_cid"] = emu_CID;
        //js_sel["mi_cid"] = ;
        emit signal_select_back(js_sel);
    }
}

//设置临时功率系数
void Dialog::on_pushButton_COP_set_clicked()
{
    QJsonObject Js_COP_set;
    QString COP;
    QJsonArray Js_COP_Arr;
    get_CID_list();
    if (MICID_list_checked.size() != 0)
    {
        if (MICID_list_checked.size() != 1)
        {
            Hex_COP.resize(2);
            Hex_COP[0] = ui->lineEdit_COP->text().toDouble()/100.0*16384/256;
            Hex_COP[1] = (int)(ui->lineEdit_COP->text().toDouble()/100.0*16384)%256;
            COP = Hex_COP.toHex();

            COP_ctl_time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
            m_mi_w_COP = MICID_list_checked;
            Js_COP_set["station"] = station;
            Js_COP_set["emu_cid"] = emu_CID;

            for (int i = 0; i < MICID_list_checked.size(); ++i)
            {
                QJsonObject JS;
                JS["mi_cid"] = MICID_list_checked[i];
                JS["temporary_power"] = COP+"0000";
                Js_COP_Arr.append(JS);
            }

            Js_COP_set["mis"] = Js_COP_Arr;
            Js_COP_set["server_cmd"] = 8;
            Js_COP_set["data"] = "";
            Js_COP_set["ctl_time"] = COP_ctl_time;
            emit signal_COP_set(Js_COP_set);
        }
        else
        {
            Hex_COP.resize(2);
            Hex_COP[0] = ui->lineEdit_COP->text().toDouble()/100.0*16384/256;
            Hex_COP[1] = (int)(ui->lineEdit_COP->text().toDouble()/100.0*16384)%256;
            COP = Hex_COP.toHex();

            COP_ctl_time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
            m_mi_w_COP = MICID_list_checked;
            Js_COP_set["station"] = station;
            Js_COP_set["emu_cid"] = emu_CID;
            Js_COP_set["mi_cid"] = MICID_list_checked[0];
            Js_COP_set["server_cmd"] = 3;
            Js_COP_set["temporary_power"] = COP+ "0000";
            Js_COP_set["data"] = "";
            Js_COP_set["ctl_time"] = COP_ctl_time;
            emit signal_COP_set(Js_COP_set);
        }
    }
    else QMessageBox::warning(nullptr, "警告","请勾选要设置的微逆CID");

}

//读临时功率系数
void Dialog::on_pushButton_COP_read_clicked()
{
    QJsonObject Js_COP_read;
    QJsonArray Js_COP_Arr;
    QString CID;
    get_CID_list();
    if (MICID_list_checked.size() != 0)
    {
        if (MICID_list_checked.size() != 1)
        {
            QByteArray num;
            QString str_num;
            num.resize(2);
            num[0] = (MICID_list_checked.size()*4+1)/256;
            num[1] = (MICID_list_checked.size()*4+1)%256;
            str_num = num.toHex();

            r_COP_ctl_time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
            m_mi_r_COP = MICID_list_checked;
            Js_COP_read["station"] = station;
            Js_COP_read["emu_cid"] = emu_CID;

            for (int i = 0; i < MICID_list_checked.size(); ++i)
            {
                Js_COP_Arr.append(MICID_list_checked[i]);
                CID += MICID_list_checked[i];
            }

            Js_COP_read["mis"] = Js_COP_Arr;
            Js_COP_read["server_cmd"] = 132;
            Js_COP_read["data"] = "8e"+str_num + CID + "00";
            Js_COP_read["ctl_time"] = r_COP_ctl_time;
            emit signal_COP_read(Js_COP_read);
        }
        else
        {
            r_COP_ctl_time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
            m_mi_r_COP = MICID_list_checked;
            Js_COP_read["station"] = station;
            Js_COP_read["emu_cid"] = emu_CID;
            Js_COP_read["mi_cid"] = MICID_list_checked[0];
            Js_COP_read["server_cmd"] = 128;
            Js_COP_read["data"] = "8605" + MICID_list_checked[0] + "00";
            Js_COP_read["ctl_time"] = r_COP_ctl_time;
            emit signal_COP_read(Js_COP_read);
        }

    }
    else QMessageBox::warning(nullptr, "警告","请勾选要读取的微逆CID");
}

//设置单路最大功率
void Dialog::on_pushButton_MaxOP_set_clicked()
{
    QJsonObject Js_MaxOP_set;
    QString MaxOP;
    QJsonArray Js_MaxOP_Arr;
    get_CID_list();
    if (MICID_list_checked.size() != 0)
    {
        if (MICID_list_checked.size() != 1)
        {
            Hex_MaxOP.resize(1);
            Hex_MaxOP[0] = ui->lineEdit_MaxOP->text().toInt()/10;
            MaxOP = Hex_MaxOP.toHex();

            MaxOP_ctl_time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
            m_mi_w_MaxOP = MICID_list_checked;

            Js_MaxOP_set["station"] = station;
            Js_MaxOP_set["emu_cid"] = emu_CID;

            for (int i = 0; i < MICID_list_checked.size(); ++i)
            {
                QJsonObject JS;
                JS["mi_cid"] = MICID_list_checked[i];
                JS["max_power"] = MaxOP + "00";
                Js_MaxOP_Arr.append(JS);
            }

            Js_MaxOP_set["mis"] = Js_MaxOP_Arr;
            Js_MaxOP_set["server_cmd"] = 9;
            Js_MaxOP_set["data"] = "";
            Js_MaxOP_set["ctl_time"] = MaxOP_ctl_time;
            emit signal_MaxOP_set(Js_MaxOP_set);
        }
        else
        {
            Hex_MaxOP.resize(1);
            Hex_MaxOP[0] = ui->lineEdit_MaxOP->text().toInt()/10;
            MaxOP = Hex_MaxOP.toHex();

            MaxOP_ctl_time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
            m_mi_w_MaxOP = MICID_list_checked;

            Js_MaxOP_set["station"] = station;
            Js_MaxOP_set["emu_cid"] = emu_CID;
            Js_MaxOP_set["mi_cid"] = MICID_list_checked[0];
            Js_MaxOP_set["server_cmd"] = 5;
            Js_MaxOP_set["max_power"] = MaxOP+ "00";
            Js_MaxOP_set["data"] = "";
            Js_MaxOP_set["ctl_time"] = MaxOP_ctl_time;
            emit signal_MaxOP_set(Js_MaxOP_set);
        }

    }
    else QMessageBox::warning(nullptr, "警告","请勾选要设置的微逆CID");
}

//读取单路最大功率
void Dialog::on_pushButton_MaxOP_read_clicked()
{
    QJsonObject Js_MaxOP_read;
    QJsonArray Js_MaxOP_Arr;
    QString CID;
    get_CID_list();
    if (MICID_list_checked.size() != 0)
    {
        if (MICID_list_checked.size() != 1)
        {
            QByteArray num;
            QString str_num;
            num.resize(2);
            num[0] = (MICID_list_checked.size()*4+1)/256;
            num[1] = (MICID_list_checked.size()*4+1)%256;
            str_num = num.toHex();

            r_MaxOP_ctl_time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
            m_mi_r_MaxOP = MICID_list_checked;

            Js_MaxOP_read["station"] = station;
            Js_MaxOP_read["emu_cid"] = emu_CID;

            for (int i = 0; i < MICID_list_checked.size(); ++i)
            {
                Js_MaxOP_Arr.append(MICID_list_checked[i]);
                CID += MICID_list_checked[i];
            }

            Js_MaxOP_read["mis"] = Js_MaxOP_Arr;
            Js_MaxOP_read["server_cmd"] = 133;
            Js_MaxOP_read["data"] = "90"+str_num + CID + "00";
            Js_MaxOP_read["ctl_time"] = r_MaxOP_ctl_time;
            emit signal_MaxOP_read(Js_MaxOP_read);
        }
        else
        {
            r_MaxOP_ctl_time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
            m_mi_r_MaxOP = MICID_list_checked;
            Js_MaxOP_read["station"] = station;
            Js_MaxOP_read["emu_cid"] = emu_CID;
            Js_MaxOP_read["mi_cid"] = MICID_list_checked[0];
            Js_MaxOP_read["server_cmd"] = 129;
            Js_MaxOP_read["data"] = "8805" + MICID_list_checked[0] + "00";
            Js_MaxOP_read["ctl_time"] = r_MaxOP_ctl_time;
            emit signal_MaxOP_read(Js_MaxOP_read);
        }

    }
    else QMessageBox::warning(nullptr, "警告","请勾选要读取的微逆CID");
}




//设置并网参数
void Dialog::on_pushButton_GridSet_clicked()
{   
    QJsonObject Js_Grid_set;
    QString Grid;
    QJsonArray Js_Grid_Arr;
    get_CID_list();
    if (MICID_list_checked.size() != 0)
    {
        if (MICID_list_checked.size() != 1)
        {
            QMessageBox::warning(nullptr, "警告", "只能设置单台微逆的并网参数");
//            getGrid();

//            Hex_Grid.resize(50);

//            Hex_Grid[0] = (s_Grid.uOV1*sqrt(2)*64)/256;
//            Hex_Grid[1] = (int)(s_Grid.uOV1*sqrt(2)*64)%256;
//            Hex_Grid[2] = s_Grid.tOV1/s_Grid.t_RatedFreq/256;
//            Hex_Grid[3] = (int)(s_Grid.tOV1/s_Grid.t_RatedFreq+0.5)%256;
//            Hex_Grid[4] = (s_Grid.uUV1*sqrt(2)*64)/256;
//            Hex_Grid[5] = (int)(s_Grid.uUV1*sqrt(2)*64)%256;
//            Hex_Grid[6] = s_Grid.tUV1/s_Grid.t_RatedFreq/256;
//            Hex_Grid[7] = (int)(s_Grid.tUV1/s_Grid.t_RatedFreq+0.5)%256;
//            Hex_Grid[8] = (50000000/(64*s_Grid.uOF1))/256;
//            Hex_Grid[9] = (int)(50000000/(64*s_Grid.uOF1))%256;
//            Hex_Grid[10] = s_Grid.tOF1/((float)1000/s_Grid.uOF1)/256;
//            Hex_Grid[11] = (int)(s_Grid.tOF1/((float)1000/s_Grid.uOF1)+0.5)%256;
//            Hex_Grid[12] = (50000000/(64*s_Grid.uUF1))/256;
//            Hex_Grid[13] = (int)(50000000/(64*s_Grid.uUF1))%256;
//            Hex_Grid[14] = s_Grid.tUF1/((float)1000/s_Grid.uUF1)/256;
//            Hex_Grid[15] = (int)(s_Grid.tUF1/((float)1000/s_Grid.uUF1)+0.5)%256;
//            Hex_Grid[16] = (s_Grid.uOV2*sqrt(2)*64)/256;
//            Hex_Grid[17] = (int)(s_Grid.uOV2*sqrt(2)*64)%256;
//            Hex_Grid[18] = s_Grid.tOV2/s_Grid.t_RatedFreq/256;
//            Hex_Grid[19] = (int)(s_Grid.tOV2/s_Grid.t_RatedFreq+0.5)%256;
//            Hex_Grid[20] = (s_Grid.uUV2*sqrt(2)*64)/256;
//            Hex_Grid[21] = (int)(s_Grid.uUV2*sqrt(2)*64)%256;
//            Hex_Grid[22] = s_Grid.tUV2/s_Grid.t_RatedFreq/256;
//            Hex_Grid[23] = (int)(s_Grid.tUV2/s_Grid.t_RatedFreq+0.5)%256;
//            Hex_Grid[24] = (50000000/(64*s_Grid.uOF2))/256;
//            Hex_Grid[25] = (int)(50000000/(64*s_Grid.uOF2))%256;
//            Hex_Grid[26] = s_Grid.tOF2/((float)1000/s_Grid.uOF2)/256;
//            Hex_Grid[27] = (int)(s_Grid.tOF2/((float)1000/s_Grid.uOF2)+0.5)%256;
//            Hex_Grid[28] = (50000000/(64*s_Grid.uUF2))/256;
//            Hex_Grid[29] = (int)(50000000/(64*s_Grid.uUF2))%256;
//            Hex_Grid[30] = s_Grid.tUF2/((float)1000/s_Grid.uUF2)/256;
//            Hex_Grid[31] = (int)(s_Grid.tUF2/((float)1000/s_Grid.uUF2)+0.5)%256;
//            Hex_Grid[32] = (s_Grid.GT*s_Grid.RatedFreq)/256;
//            Hex_Grid[33] = (int)(s_Grid.GT*s_Grid.RatedFreq)%256;
//            Hex_Grid[34] = (s_Grid.URov*sqrt(2)*64)/256;
//            Hex_Grid[35] = (int)(s_Grid.URov*sqrt(2)*64)%256;
//            Hex_Grid[36] = (s_Grid.URuv*sqrt(2)*64)/256;
//            Hex_Grid[37] = (int)(s_Grid.URuv*sqrt(2)*64)%256;
//            Hex_Grid[38] = (50000000/(64*s_Grid.FRof))/256;
//            Hex_Grid[39] = (int)(50000000/(64*s_Grid.FRof))%256;
//            Hex_Grid[40] = (50000000/(64*s_Grid.FRuf))/256;
//            Hex_Grid[41] = (int)(50000000/(64*s_Grid.FRuf))%256;
//            Hex_Grid[42] = s_Grid.superPF;
//            Hex_Grid[43] = s_Grid.ASPQU;
//            Hex_Grid[44] = s_Grid.CEIDFU;
//            Hex_Grid[45] = s_Grid.Var;
//            Hex_Grid[46] = s_Grid.HVRT-100;
//            Hex_Grid[47] = s_Grid.LVRT;
//            Hex_Grid[48] = 0;
//            Hex_Grid[49] = 0;
//            Grid = Hex_Grid.toHex();

//            Grid_ctl_time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");

//            Js_Grid_set["station"] = station;
//            Js_Grid_set["emu_cid"] = emu_CID;

//            for (int i = 0; i < MICID_list_checked.size(); ++i)
//            {
//                QJsonObject JS;
//                JS["mi_cid"] = MICID_list_checked[i];
//                JS["grid"] = Grid;
//                Js_Grid_Arr.append(JS);
//            }

//            Js_Grid_set["mis"] = Js_Grid_Arr;
//            Js_Grid_set["server_cmd"] = 6;
//            Js_Grid_set["data"] = "";
//            Js_Grid_set["ctl_time"] = Grid_ctl_time;
//            emit signal_Grid_set(Js_Grid_set);
        }
        else
        {
            getGrid();

            Hex_Grid.resize(50);

            Hex_Grid[0] = (s_Grid.uOV1*sqrt(2)*64)/256;
            Hex_Grid[1] = (int)(s_Grid.uOV1*sqrt(2)*64)%256;
            Hex_Grid[2] = s_Grid.tOV1/s_Grid.t_RatedFreq/256;
            Hex_Grid[3] = (int)(s_Grid.tOV1/s_Grid.t_RatedFreq+0.5)%256;
            Hex_Grid[4] = (s_Grid.uUV1*sqrt(2)*64)/256;
            Hex_Grid[5] = (int)(s_Grid.uUV1*sqrt(2)*64)%256;
            Hex_Grid[6] = s_Grid.tUV1/s_Grid.t_RatedFreq/256;
            Hex_Grid[7] = (int)(s_Grid.tUV1/s_Grid.t_RatedFreq+0.5)%256;
            Hex_Grid[8] = (50000000/(64*s_Grid.uOF1))/256;
            Hex_Grid[9] = (int)(50000000/(64*s_Grid.uOF1))%256;
            Hex_Grid[10] = s_Grid.tOF1/((float)1000/s_Grid.uOF1)/256;
            Hex_Grid[11] = (int)(s_Grid.tOF1/((float)1000/s_Grid.uOF1)+0.5)%256;
            Hex_Grid[12] = (50000000/(64*s_Grid.uUF1))/256;
            Hex_Grid[13] = (int)(50000000/(64*s_Grid.uUF1))%256;
            Hex_Grid[14] = s_Grid.tUF1/((float)1000/s_Grid.uUF1)/256;
            Hex_Grid[15] = (int)(s_Grid.tUF1/((float)1000/s_Grid.uUF1)+0.5)%256;
            Hex_Grid[16] = (s_Grid.uOV2*sqrt(2)*64)/256;
            Hex_Grid[17] = (int)(s_Grid.uOV2*sqrt(2)*64)%256;
            Hex_Grid[18] = s_Grid.tOV2/s_Grid.t_RatedFreq/256;
            Hex_Grid[19] = (int)(s_Grid.tOV2/s_Grid.t_RatedFreq+0.5)%256;
            Hex_Grid[20] = (s_Grid.uUV2*sqrt(2)*64)/256;
            Hex_Grid[21] = (int)(s_Grid.uUV2*sqrt(2)*64)%256;
            Hex_Grid[22] = s_Grid.tUV2/s_Grid.t_RatedFreq/256;
            Hex_Grid[23] = (int)(s_Grid.tUV2/s_Grid.t_RatedFreq+0.5)%256;
            Hex_Grid[24] = (50000000/(64*s_Grid.uOF2))/256;
            Hex_Grid[25] = (int)(50000000/(64*s_Grid.uOF2))%256;
            Hex_Grid[26] = s_Grid.tOF2/((float)1000/s_Grid.uOF2)/256;
            Hex_Grid[27] = (int)(s_Grid.tOF2/((float)1000/s_Grid.uOF2)+0.5)%256;
            Hex_Grid[28] = (50000000/(64*s_Grid.uUF2))/256;
            Hex_Grid[29] = (int)(50000000/(64*s_Grid.uUF2))%256;
            Hex_Grid[30] = s_Grid.tUF2/((float)1000/s_Grid.uUF2)/256;
            Hex_Grid[31] = (int)(s_Grid.tUF2/((float)1000/s_Grid.uUF2)+0.5)%256;
            Hex_Grid[32] = (s_Grid.GT*s_Grid.RatedFreq)/256;
            Hex_Grid[33] = (int)(s_Grid.GT*s_Grid.RatedFreq)%256;
            Hex_Grid[34] = (s_Grid.URov*sqrt(2)*64)/256;
            Hex_Grid[35] = (int)(s_Grid.URov*sqrt(2)*64)%256;
            Hex_Grid[36] = (s_Grid.URuv*sqrt(2)*64)/256;
            Hex_Grid[37] = (int)(s_Grid.URuv*sqrt(2)*64)%256;
            Hex_Grid[38] = (50000000/(64*s_Grid.FRof))/256;
            Hex_Grid[39] = (int)(50000000/(64*s_Grid.FRof))%256;
            Hex_Grid[40] = (50000000/(64*s_Grid.FRuf))/256;
            Hex_Grid[41] = (int)(50000000/(64*s_Grid.FRuf))%256;
            Hex_Grid[42] = s_Grid.superPF;
            Hex_Grid[43] = s_Grid.ASPQU;
            Hex_Grid[44] = s_Grid.CEIDFU;
            Hex_Grid[45] = s_Grid.Var;
            Hex_Grid[46] = s_Grid.HVRT-100;
            Hex_Grid[47] = s_Grid.LVRT;
            Hex_Grid[48] = 0;
            Hex_Grid[49] = 0;
            Grid = Hex_Grid.toHex();

            Grid_ctl_time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
            //m_mi_w_Grid = MICID_list_checked;
            m_mi_w_Grid =QStringList()<< ui->comboBox_CID->currentText();

            Js_Grid_set["station"] = station;
            Js_Grid_set["emu_cid"] = emu_CID;
            Js_Grid_set["mi_cid"] = MICID_list_checked[0];
            Js_Grid_set["server_cmd"] = 6;
            Js_Grid_set["grid"] = Grid;
            Js_Grid_set["data"] = "";
            Js_Grid_set["ctl_time"] = Grid_ctl_time;
            emit signal_Grid_set(Js_Grid_set);
        }
    }
    else QMessageBox::warning(nullptr, "警告","请勾选要设置的微逆CID");
}

//读并网参数
void Dialog::on_pushButton_GridRead_clicked()
{
    QJsonObject Js_Grid_read;
    QJsonArray Js_Grid_Arr;
    QString CID;
    get_CID_list();
    if (MICID_list_checked.size() != 0)
    {
        if (MICID_list_checked.size() != 1)
        {
            QMessageBox::warning(nullptr, "警告", "只能读取单台微逆并网参数");
//            r_Grid_ctl_time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
//            Js_Grid_read["station"] = station;
//            Js_Grid_read["emu_cid"] = emu_CID;

//            for (int i = 0; i < MICID_list_checked.size(); ++i)
//            {
//                Js_Grid_Arr.append(MICID_list_checked[i]);
//                CID += MICID_list_checked[i];
//            }

//            Js_Grid_read["mis"] = Js_Grid_Arr;
//            Js_Grid_read["server_cmd"] = 130;
//            Js_Grid_read["data"] = "8a05" + CID + "00";
//            Js_Grid_read["ctl_time"] = r_Grid_ctl_time;
//            emit signal_Grid_read(Js_Grid_read);
        }
        else
        {
            QJsonObject Js_Grid_read;
            r_Grid_ctl_time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
            //m_mi_r_Grid = MICID_list_checked;
            m_mi_r_Grid = QStringList()<< ui->comboBox_CID->currentText();
            Js_Grid_read["station"] = station;
            Js_Grid_read["emu_cid"] = emu_CID;
            Js_Grid_read["mi_cid"] = MICID_list_checked[0];
            Js_Grid_read["server_cmd"] = 130;
            Js_Grid_read["data"] = "8a05" + MICID_list_checked[0] + "00";
            Js_Grid_read["ctl_time"] = r_Grid_ctl_time;
            emit signal_Grid_read(Js_Grid_read);
        }

    }
    else QMessageBox::warning(nullptr, "警告","请勾选要读取的微逆CID");
}


//设置认证参数
void Dialog::on_pushButton_CerSet_clicked()
{   
    QJsonObject Js_Cer_set;
    QString Cer;
    QJsonArray Js_Cer_Arr;
    get_CID_list();
    if (MICID_list_checked.size() != 0)
    {
        if (MICID_list_checked.size() != 1)
        {
            QMessageBox::warning(nullptr, "警告", "只能设置单台微逆的认证参数");
//            getCer();

//            Hex_Cer.resize(48);

//            Hex_Cer[0] = s_Cer.Fixed_non_P;
//            Hex_Cer[1] = (s_Cer.Fixed_non_P_Para+2)*200/256;
//            Hex_Cer[2] = (int)((s_Cer.Fixed_non_P_Para+2)*200+0.5)%256;
//            Hex_Cer[3] = s_Cer.Remote_P_slope;
//            Hex_Cer[4] = (int)(s_Cer.Remote_P_slopePara*163.84)/256;
//            Hex_Cer[5] = (int)(s_Cer.Remote_P_slopePara*163.84)%256;
//            Hex_Cer[6] = s_Cer.OverVol_10;
//            Hex_Cer[7] = s_Cer.UF_hyst;
//            Hex_Cer[8] = s_Cer.LFSM_Mode;
//            Hex_Cer[9] = (50000000/(s_Cer.LFSMO_fact*64))/256;
//            Hex_Cer[10] = (int)(50000000/(s_Cer.LFSMO_fact*64))%256;
//            Hex_Cer[11] = (int)(50000000/(s_Cer.LFSMO_fdeact*64))/256;
//            Hex_Cer[12] = (int)(50000000/(s_Cer.LFSMO_fdeact*64))%256;
//            Hex_Cer[13] = s_Cer.LFSMO_Droop*10;
//            Hex_Cer[14] = (int)(50000000/(s_Cer.LFSMU_fact*64))/256;
//            Hex_Cer[15] = (int)(50000000/(s_Cer.LFSMU_fact*64))%256;
//            Hex_Cer[16] = (int)(50000000/(s_Cer.LFSMU_fdeact*64))/256;
//            Hex_Cer[17] = (int)(50000000/(s_Cer.LFSMU_fdeact*64))%256;
//            Hex_Cer[18] = s_Cer.LFSMU_Droop*10;
//            Hex_Cer[19] = s_Cer.LFSMO_Trec/256;
//            Hex_Cer[20] = s_Cer.LFSMO_Trec%256;
//            Hex_Cer[21] = (int)(s_Cer.LFSMO_P_slope*163.84)/256;
//            Hex_Cer[22] = (int)(s_Cer.LFSMO_P_slope*163.84)%256;
//            Hex_Cer[23] = (int)(s_Cer.Reconnect_P_slope*163.84)/256;
//            Hex_Cer[24] = (int)(s_Cer.Reconnect_P_slope*163.84)%256;
//            Hex_Cer[25] = s_Cer.Island;
//            Hex_Cer[26] = s_Cer.DF1;
//            Hex_Cer[27] = s_Cer.DF2;
//            Hex_Cer[28] = s_Cer.FVRT;
//            Hex_Cer[29] = s_Cer.UF_hyst_powerOn;
//            Hex_Cer[30] = s_Cer.QU_mode;
//            Hex_Cer[31] = s_Cer.PU_mode;
//            Hex_Cer[32] = s_Cer.LFSMO_Pn;
//            Hex_Cer[33] = s_Cer.ratedVol;
//            Hex_Cer[34] = s_Cer.PU_InitialVol;
//            Hex_Cer[35] = s_Cer.PU_EndVol;
//            Hex_Cer[36] = s_Cer.PU_Droop;
//            Hex_Cer[37] = s_Cer.PU_DroopSpd;
//            Hex_Cer[38] = s_Cer.QU_UVstart;
//            Hex_Cer[39] = s_Cer.QU_UVstop;
//            Hex_Cer[40] = s_Cer.QU_OVstart;
//            Hex_Cer[41] = s_Cer.QU_OVstop;
//            Hex_Cer[42] = s_Cer.QU_Plockin;
//            Hex_Cer[43] = s_Cer.QU_PlockOut;
//            Hex_Cer[44] = (s_Cer.OverVol_10_Para-230)*4;
//            Hex_Cer[45] = s_Cer.Max_non_P;
//            Hex_Cer[46] = s_Cer.tao;
//            Hex_Cer[47] = s_Cer.certification_En;

//            Cer = Hex_Cer.toHex();

//            Cer_ctl_time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");

//            Js_Cer_set["station"] = station;
//            Js_Cer_set["emu_cid"] = emu_CID;

//            for (int i = 0; i < MICID_list_checked.size(); ++i)
//            {
//                QJsonObject JS;
//                JS["mi_cid"] = MICID_list_checked[i];
//                JS["certification"] = Cer;
//                Js_Cer_Arr.append(JS);
//            }

//            Js_Cer_set["mis"] = Js_Cer_Arr;
//            Js_Cer_set["server_cmd"] = 7;
//            Js_Cer_set["data"] = "";
//            Js_Cer_set["ctl_time"] = Cer_ctl_time;
//            emit signal_Cer_set(Js_Cer_set);

        }
        else
        {
            getCer();

            Hex_Cer.resize(48);

            Hex_Cer[0] = s_Cer.Fixed_non_P;
            Hex_Cer[1] = (s_Cer.Fixed_non_P_Para+2)*200/256;
            Hex_Cer[2] = (int)((s_Cer.Fixed_non_P_Para+2)*200+0.5)%256;
            Hex_Cer[3] = s_Cer.Remote_P_slope;
            Hex_Cer[4] = (int)(s_Cer.Remote_P_slopePara*163.84)/256;
            Hex_Cer[5] = (int)(s_Cer.Remote_P_slopePara*163.84)%256;
            Hex_Cer[6] = s_Cer.OverVol_10;
            Hex_Cer[7] = s_Cer.UF_hyst;
            Hex_Cer[8] = s_Cer.LFSM_Mode;
            Hex_Cer[9] = (50000000/(s_Cer.LFSMO_fact*64))/256;
            Hex_Cer[10] = (int)(50000000/(s_Cer.LFSMO_fact*64))%256;
            Hex_Cer[11] = (int)(50000000/(s_Cer.LFSMO_fdeact*64))/256;
            Hex_Cer[12] = (int)(50000000/(s_Cer.LFSMO_fdeact*64))%256;
            Hex_Cer[13] = s_Cer.LFSMO_Droop*10;
            Hex_Cer[14] = (int)(50000000/(s_Cer.LFSMU_fact*64))/256;
            Hex_Cer[15] = (int)(50000000/(s_Cer.LFSMU_fact*64))%256;
            Hex_Cer[16] = (int)(50000000/(s_Cer.LFSMU_fdeact*64))/256;
            Hex_Cer[17] = (int)(50000000/(s_Cer.LFSMU_fdeact*64))%256;
            Hex_Cer[18] = s_Cer.LFSMU_Droop*10;
            Hex_Cer[19] = s_Cer.LFSMO_Trec/256;
            Hex_Cer[20] = s_Cer.LFSMO_Trec%256;
            Hex_Cer[21] = (int)(s_Cer.LFSMO_P_slope*163.84)/256;
            Hex_Cer[22] = (int)(s_Cer.LFSMO_P_slope*163.84)%256;
            Hex_Cer[23] = (int)(s_Cer.Reconnect_P_slope*163.84)/256;
            Hex_Cer[24] = (int)(s_Cer.Reconnect_P_slope*163.84)%256;
            Hex_Cer[25] = s_Cer.Island;
            Hex_Cer[26] = s_Cer.DF1;
            Hex_Cer[27] = s_Cer.DF2;
            Hex_Cer[28] = s_Cer.FVRT;
            Hex_Cer[29] = s_Cer.UF_hyst_powerOn;
            Hex_Cer[30] = s_Cer.QU_mode;
            Hex_Cer[31] = s_Cer.PU_mode;
            Hex_Cer[32] = s_Cer.LFSMO_Pn;
            Hex_Cer[33] = s_Cer.ratedVol;
            Hex_Cer[34] = s_Cer.PU_InitialVol;
            Hex_Cer[35] = s_Cer.PU_EndVol;
            Hex_Cer[36] = s_Cer.PU_Droop;
            Hex_Cer[37] = s_Cer.PU_DroopSpd;
            Hex_Cer[38] = s_Cer.QU_UVstart;
            Hex_Cer[39] = s_Cer.QU_UVstop;
            Hex_Cer[40] = s_Cer.QU_OVstart;
            Hex_Cer[41] = s_Cer.QU_OVstop;
            Hex_Cer[42] = s_Cer.QU_Plockin;
            Hex_Cer[43] = s_Cer.QU_PlockOut;
            Hex_Cer[44] = (s_Cer.OverVol_10_Para-230)*4;
            Hex_Cer[45] = s_Cer.Max_non_P;
            Hex_Cer[46] = s_Cer.tao;
            Hex_Cer[47] = s_Cer.certification_En;

            Cer = Hex_Cer.toHex();

            Cer_ctl_time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
            //m_mi_w_Cer = MICID_list_checked;
            m_mi_w_Cer = QStringList()<< ui->comboBox_CID->currentText();

            Js_Cer_set["station"] = station;
            Js_Cer_set["emu_cid"] = emu_CID;
            Js_Cer_set["mi_cid"] = MICID_list_checked[0];
            Js_Cer_set["server_cmd"] = 7;
            Js_Cer_set["certification"] = Cer;
            Js_Cer_set["data"] = "";
            Js_Cer_set["ctl_time"] = Cer_ctl_time;
            emit signal_Cer_set(Js_Cer_set);
        }
    }
    else QMessageBox::warning(nullptr, "警告","请勾选要设置的微逆CID");
}

//读认证参数
void Dialog::on_pushButton_CerRead_clicked()
{
    QJsonObject Js_Cer_read;
    QJsonArray Js_Cer_Arr;
    QString CID;
    get_CID_list();
    if (MICID_list_checked.size() != 0)
    {
        if (MICID_list_checked.size() != 1)
        {
            QMessageBox::warning(nullptr, "警告", "只能读取单台微逆的认证参数");
//            r_Cer_ctl_time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
//            Js_Cer_read["station"] = station;
//            Js_Cer_read["emu_cid"] = emu_CID;

//            for (int i = 0; i < MICID_list_checked.size(); ++i)
//            {
//                Js_Cer_Arr.append(MICID_list_checked[i]);
//                CID += MICID_list_checked[i];
//            }

//            Js_Cer_read["mis"] = Js_Cer_Arr;
//            Js_Cer_read["server_cmd"] = 131;
//            Js_Cer_read["data"] = "8c05" + CID + "00";
//            Js_Cer_read["ctl_time"] = r_Cer_ctl_time;
//            emit signal_Cer_read(Js_Cer_read);
        }
        else
        {
            r_Cer_ctl_time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
            m_mi_r_Cer = QStringList()<< ui->comboBox_CID->currentText();
            Js_Cer_read["station"] = station;
            Js_Cer_read["emu_cid"] = emu_CID;
            Js_Cer_read["mi_cid"] = MICID_list_checked[0];
            Js_Cer_read["server_cmd"] = 131;
            Js_Cer_read["data"] = "8c05" + MICID_list_checked[0] + "00";
            Js_Cer_read["ctl_time"] = r_Cer_ctl_time;
            emit signal_Cer_read(Js_Cer_read);
        }

    }
    else QMessageBox::warning(nullptr, "警告","请勾选要读取的微逆CID");
}


float Dialog::Dec(float value, int decimalDigits)
{
    switch (decimalDigits)
    {
    case 0:
        value > 0 ? value = (int)(value + 0.5):value = (int)(value - 0.5);
        return value;
        break;
    case 1:
        value > 0 ? value = (int)(value*10 + 0.5)/10.0 : value = (int)(value*10 - 0.5)/10.0;
        return value;
        break;
    case 2:
        value > 0 ? value = (int)(value*100 + 0.5)/100.0 : value = (int)(value*100 - 0.5)/100.0;
        return value;
        break;
    case 3:
        value > 0 ? value = (int)(value*1000 + 0.5)/1000.0 : value = (int)(value*1000 - 0.5)/1000.0;
        return value;
        break;
    case 4:
        value > 0 ? value = (int)(value*10000 + 0.5)/10000.0 : value = (int)(value*10000 - 0.5)/10000.0;
        return value;
        break;
    default: return -999999;
        break;
    }

}

void Dialog::readGridToStr()
{
    s_str_Grid.uOV1 = ui->lineEdit_uOV1->text();
    s_str_Grid.tOV1 = ui->lineEdit_tOV1->text();
    s_str_Grid.uUV1 = ui->lineEdit_uUV1->text();
    s_str_Grid.tUV1 = ui->lineEdit_tUV1->text();
    s_str_Grid.uOF1 = ui->lineEdit_uOF1->text();
    s_str_Grid.tOF1 = ui->lineEdit_tOF1->text();
    s_str_Grid.uUF1 = ui->lineEdit_uUF1->text();
    s_str_Grid.tUF1 = ui->lineEdit_tUF1->text();
    s_str_Grid.uOV2 = ui->lineEdit_uOV2->text();
    s_str_Grid.tOV2 = ui->lineEdit_tOV2->text();
    s_str_Grid.uUV2 = ui->lineEdit_uUV2->text();
    s_str_Grid.tUV2 = ui->lineEdit_tUV2->text();
    s_str_Grid.uOF2 = ui->lineEdit_uOF2->text();
    s_str_Grid.tOF2 = ui->lineEdit_tOF2->text();
    s_str_Grid.uUF2 = ui->lineEdit_uUF2->text();
    s_str_Grid.tUF2 = ui->lineEdit_tUF2->text();
    s_str_Grid.GT = ui->lineEdit_GT->text();
    s_str_Grid.URov = ui->lineEdit_UROV->text();
    s_str_Grid.URuv = ui->lineEdit_URuV->text();
    s_str_Grid.FRof = ui->lineEdit_FROF->text();
    s_str_Grid.FRuf = ui->lineEdit_FRuF->text();
    s_str_Grid.superPF = ui->comboBox_SuperPF->currentIndex();
    s_str_Grid.ASPQU = ui->comboBox_ASPQU->currentIndex();
    s_str_Grid.CEIDFU = ui->comboBox_CEIDFU->currentIndex();
    s_str_Grid.Var = ui->comboBox_VAR->currentIndex();
    s_str_Grid.HVRT = ui->lineEdit_HVRT->text();
    s_str_Grid.LVRT = ui->lineEdit_LVRT->text();
    s_str_Grid.RatedFreq = ui->comboBox_RatedFreq->currentIndex();
}

void Dialog::readCerToStr()
{
    s_str_Cer.Fixed_non_P = ui->comboBox_Fixed_non_P->currentIndex();
    s_str_Cer.Fixed_non_P_Para = ui->lineEdit_FixedPF_Para->text();
    s_str_Cer.Max_non_P = ui->comboBox_MaxPF_Value->currentIndex();
    s_str_Cer.Remote_P_slope = ui->comboBox_Remote_P_slope->currentIndex();
    s_str_Cer.Remote_P_slopePara = ui->lineEdit_Remote_P_slope->text();
    s_str_Cer.Reconnect_P_slope = ui->lineEdit_Reconnect_P->text();
    s_str_Cer.OverVol_10 = ui->comboBox_OV10min->currentIndex();
    s_str_Cer.OverVol_10_Para = ui->lineEdit_OverVol->text();
    s_str_Cer.UF_hyst = ui->comboBox_UF_hyst->currentIndex();
    s_str_Cer.UF_hyst_powerOn = ui->comboBox_UF_hyst_powerOn->currentIndex();
    s_str_Cer.LFSM_Mode = ui->comboBox_LFSMMode->currentIndex();
    s_str_Cer.LFSMO_fact = ui->lineEdit_LFSMO_fact->text();
    s_str_Cer.LFSMO_fdeact = ui->lineEdit_LFSMO_fdeact->text();
    s_str_Cer.LFSMO_Droop = ui->lineEdit_LFSMO_Droop->text();
    s_str_Cer.LFSMO_Trec = ui->lineEdit_LFSMO_Trec->text();
    s_str_Cer.LFSMO_P_slope = ui->lineEdit_LFSMO_P_slope->text();
    s_str_Cer.LFSMO_Pn = ui->comboBox_LFSMO_Pn->currentIndex();
    s_str_Cer.LFSMU_fact = ui->lineEdit_LFSMU_fact->text();
    s_str_Cer.LFSMU_fdeact = ui->lineEdit_LFSMU_fdeact->text();
    s_str_Cer.LFSMU_Droop = ui->lineEdit_LFSMU_Droop->text();
    s_str_Cer.Island = ui->comboBox_Island->currentIndex();
    s_str_Cer.DF1 = ui->comboBox_DF1->currentIndex();
    s_str_Cer.DF2 = ui->comboBox_DF2->currentIndex();
    s_str_Cer.FVRT = ui->comboBox_FVRT->currentIndex();
    s_str_Cer.ratedVol = ui->lineEdit_RatedVol->text();
    s_str_Cer.PU_mode = ui->comboBox_PUMode->currentIndex();
    s_str_Cer.PU_InitialVol = ui->lineEdit_PU_InitialVol->text();
    s_str_Cer.PU_EndVol = ui->lineEdit_PU_EndVol->text();
    s_str_Cer.PU_Droop = ui->lineEdit_PU_Droop->text();
    s_str_Cer.PU_DroopSpd = ui->lineEdit_PU_DroopSpd->text();
    s_str_Cer.QU_mode = ui->comboBox_QUMode->currentIndex();
    s_str_Cer.QU_UVstart = ui->lineEdit_UV_start->text();
    s_str_Cer.QU_UVstop = ui->lineEdit_UV_stop->text();
    s_str_Cer.QU_OVstart = ui->lineEdit_OV_start->text();
    s_str_Cer.QU_OVstop = ui->lineEdit_OV_stop->text();
    s_str_Cer.QU_Plockin = ui->lineEdit_Plock_in->text();
    s_str_Cer.QU_PlockOut = ui->lineEdit_Plock_out->text();
    s_str_Cer.tao = ui->comboBox_Tau->currentIndex();
    s_str_Cer.certification_En = ui->comboBox_cetificationMode->currentIndex();
}

void Dialog::displayGrid(str_Grid *Grid)
{
    ui->lineEdit_uOV1->setText(Grid->uOV1);
    ui->lineEdit_tOV1->setText(Grid->tOV1);
    ui->lineEdit_uUV1->setText(Grid->uUV1);
    ui->lineEdit_tUV1->setText(Grid->tUV1);
    ui->lineEdit_uOF1->setText(Grid->uOF1);
    ui->lineEdit_tOF1->setText(Grid->tOF1);
    ui->lineEdit_uUF1->setText(Grid->uUF1);
    ui->lineEdit_tUF1->setText(Grid->tUF1);
    ui->lineEdit_uOV2->setText(Grid->uOV2);
    ui->lineEdit_tOV2->setText(Grid->tOV2);
    ui->lineEdit_uUV2->setText(Grid->uUV2);
    ui->lineEdit_tUV2->setText(Grid->tUV2);
    ui->lineEdit_uOF2->setText(Grid->uOF2);
    ui->lineEdit_tOF2->setText(Grid->tOF2);
    ui->lineEdit_uUF2->setText(Grid->uUF2);
    ui->lineEdit_tUF2->setText(Grid->tUF2);
    ui->lineEdit_GT->setText(Grid->GT);
    ui->lineEdit_UROV->setText(Grid->URov);
    ui->lineEdit_URuV->setText(Grid->URuv);
    ui->lineEdit_FROF->setText(Grid->FRof);
    ui->lineEdit_FRuF->setText(Grid->FRuf);
    ui->comboBox_SuperPF->setCurrentIndex(Grid->superPF);
    ui->comboBox_ASPQU->setCurrentIndex(Grid->ASPQU);
    ui->comboBox_CEIDFU->setCurrentIndex(Grid->CEIDFU);
    ui->comboBox_VAR->setCurrentIndex(Grid->Var);
    ui->lineEdit_HVRT->setText(Grid->HVRT);
    ui->lineEdit_LVRT->setText(Grid->LVRT);
    ui->comboBox_RatedFreq->setCurrentIndex(Grid->RatedFreq);
}

void Dialog::displayCer(str_Cer *Cer)
{
    ui->comboBox_Fixed_non_P->setCurrentIndex(Cer->Fixed_non_P);
    ui->lineEdit_FixedPF_Para->setText(Cer->Fixed_non_P_Para);
    ui->comboBox_Remote_P_slope->setCurrentIndex(Cer->Remote_P_slope);
    ui->lineEdit_Remote_P_slope->setText(Cer->Remote_P_slopePara);
    ui->comboBox_OV10min->setCurrentIndex(Cer->OverVol_10);
    ui->comboBox_UF_hyst->setCurrentIndex(Cer->UF_hyst);
    ui->comboBox_LFSMMode->setCurrentIndex(Cer->LFSM_Mode);
    ui->lineEdit_LFSMO_fact->setText(Cer->LFSMO_fact);
    ui->lineEdit_LFSMO_fdeact->setText(Cer->LFSMO_fdeact);
    ui->lineEdit_LFSMO_Droop->setText(Cer->LFSMO_Droop);
    ui->lineEdit_LFSMU_fact->setText(Cer->LFSMU_fact);
    ui->lineEdit_LFSMU_fdeact->setText(Cer->LFSMU_fdeact);
    ui->lineEdit_LFSMU_Droop->setText(Cer->LFSMU_Droop);
    ui->lineEdit_LFSMO_Trec->setText(Cer->LFSMO_Trec);
    ui->lineEdit_LFSMO_P_slope->setText(Cer->LFSMO_P_slope);
    ui->lineEdit_Reconnect_P->setText(Cer->Reconnect_P_slope);
    ui->comboBox_Island->setCurrentIndex(Cer->Island);
    ui->comboBox_DF1->setCurrentIndex(Cer->DF1);
    ui->comboBox_DF2->setCurrentIndex(Cer->DF2);
    ui->comboBox_FVRT->setCurrentIndex(Cer->FVRT);
    ui->comboBox_UF_hyst_powerOn->setCurrentIndex(Cer->UF_hyst_powerOn);
    ui->comboBox_QUMode->setCurrentIndex(Cer->QU_mode);
    ui->comboBox_PUMode->setCurrentIndex(Cer->PU_mode);
    ui->comboBox_LFSMO_Pn->setCurrentIndex(Cer->LFSMO_Pn);
    ui->lineEdit_RatedVol->setText(Cer->ratedVol);
    ui->lineEdit_PU_InitialVol->setText(Cer->PU_InitialVol);
    ui->lineEdit_PU_EndVol->setText(Cer->PU_EndVol);
    ui->lineEdit_PU_Droop->setText(Cer->PU_Droop);
    ui->lineEdit_PU_DroopSpd->setText(Cer->PU_DroopSpd);
    ui->lineEdit_UV_start->setText(Cer->QU_UVstart);
    ui->lineEdit_UV_stop->setText(Cer->QU_UVstop);
    ui->lineEdit_OV_start->setText(Cer->QU_OVstart);
    ui->lineEdit_OV_stop->setText(Cer->QU_OVstop);
    ui->lineEdit_Plock_in->setText(Cer->QU_Plockin);
    ui->lineEdit_Plock_out->setText(Cer->QU_PlockOut);
    ui->lineEdit_OverVol->setText(Cer->OverVol_10_Para);
    ui->comboBox_MaxPF_Value->setCurrentIndex(Cer->Max_non_P);
    ui->comboBox_Tau->setCurrentIndex(Cer->tao);
    ui->comboBox_cetificationMode->setCurrentIndex(Cer->certification_En);

}

void Dialog::sacnDataFile()
{
    ui->comboBox_program->clear();
    nameList.clear();

    QDir dir(data_filePath);
    QStringList filter;
    QFileInfo fileInfo;

    filter << QString("*.json");
    dir.setNameFilters(filter);
    dir.setSorting(QDir::Name);
    nameList = dir.entryList();

    for(int i = 0; i < nameList.size() ; i++)
    {
        fileInfo = nameList[i];
        nameList[i] = fileInfo.baseName();
    }
    ui->comboBox_program->addItems(nameList);
}

void Dialog::getFilePath()
{
    data_filePath = QApplication::applicationDirPath();
    data_filePath = data_filePath + '/' +"testDataSave";
    QDir dir(data_filePath);
    if (!dir.exists())
    {
        dir.mkdir(data_filePath);
    }
}

void Dialog::readJsonDoc(QString fileName)
{
    QString fullPath;
    fullPath = data_filePath + '/' + fileName+".json";
    QFile file(fullPath);
    if (!file.open(QIODevice::ReadOnly))
    {
//        emit signal_log_failure("Json文件打开失败");
        return;
    }
    QByteArray data(file.readAll());
    file.close();

    QJsonParseError Err;
    QJsonDocument JDoc = QJsonDocument::fromJson(data, &Err);
    if(Err.error != QJsonParseError::NoError)
    {
//        emit signal_log_failure("Json格式错误");
        return;
    }

    QJsonObject JObj = JDoc.object();

    save_Cer.ratedVol = JObj.value("RatedVol").toString();
    save_Grid.RatedFreq = JObj.value("RatedFreq").toBool();
    save_Cer.certification_En = JObj.value("CertificationMode").toBool();

    save_Grid.uOV1 = JObj.value("uOV1").toString();
    save_Grid.tOV1 = JObj.value("tOV1").toString();
    save_Grid.uOF1 = JObj.value("uOF1").toString();
    save_Grid.tOF1 = JObj.value("tOF1").toString();
    save_Grid.uUV1 = JObj.value("uUV1").toString();
    save_Grid.tUV1 = JObj.value("tUV1").toString();
    save_Grid.uUF1 = JObj.value("uUF1").toString();
    save_Grid.tUF1 = JObj.value("tUF1").toString();
    save_Grid.uOV2 = JObj.value("uOV2").toString();
    save_Grid.tOV2 = JObj.value("tOV2").toString();
    save_Grid.uOF2 = JObj.value("uOF2").toString();
    save_Grid.tOF2 = JObj.value("tOF2").toString();
    save_Grid.uUV2 = JObj.value("uUV2").toString();
    save_Grid.tUV2 = JObj.value("tUV2").toString();
    save_Grid.uUF2 = JObj.value("uUF2").toString();
    save_Grid.tUF2 = JObj.value("tUF2").toString();

    save_Grid.GT = JObj.value("GT").toString();
    save_Grid.URov = JObj.value("UROV").toString();
    save_Grid.URuv = JObj.value("URUV").toString();
    save_Grid.FRof = JObj.value("FROF").toString();
    save_Grid.FRuf = JObj.value("FRUF").toString();

    save_Grid.superPF = JObj.value("SuperPF").toBool();
    save_Grid.ASPQU = JObj.value("ASPQU").toBool();
    save_Grid.CEIDFU = JObj.value("CEIDFU").toBool();
    save_Grid.Var = JObj.value("360VAR").toBool();

    save_Cer.FVRT = JObj.value("FVRT").toBool();
    save_Grid.HVRT = JObj.value("HVRT").toString();
    save_Grid.LVRT = JObj.value("LVRT").toString();

    save_Cer.Island = JObj.value("Island").toBool();
    save_Cer.tao = JObj.value("3Tao").toInt();
    save_Cer.DF1 = JObj.value("DF1").toBool();
    save_Cer.DF2 = JObj.value("DF2").toBool();

    save_Cer.OverVol_10 = JObj.value("OverVol_10min").toBool();
    save_Cer.OverVol_10_Para = JObj.value("OverVol").toString();

    save_Cer.UF_hyst = JObj.value("PonVfhys").toBool();
    save_Cer.UF_hyst_powerOn = JObj.value("VfhysRST").toBool();

    save_Cer.Fixed_non_P = JObj.value("FixedPF").toBool();
    save_Cer.Fixed_non_P_Para = JObj.value("FixedPF_value").toString();
    save_Cer.Max_non_P = JObj.value("MaxPF").toInt();

    save_Cer.Remote_P_slope = JObj.value("PrcsetSramp").toBool();
    save_Cer.Remote_P_slopePara = JObj.value("PrcsetSramp_value").toString();
    save_Cer.Reconnect_P_slope = JObj.value("Reconnect_P").toString();

    save_Cer.PU_mode = JObj.value("PUMode").toBool();
    save_Cer.PU_InitialVol = JObj.value("PU_InitialVol").toString();
    save_Cer.PU_EndVol = JObj.value("PU_EndVol").toString();
    save_Cer.PU_Droop = JObj.value("PU_Droop").toString();
    save_Cer.PU_DroopSpd = JObj.value("PU_DroopSpd").toString();

    save_Cer.QU_mode = JObj.value("QUMode").toBool();
    save_Cer.QU_UVstart = JObj.value("UV_start").toString();
    save_Cer.QU_UVstop = JObj.value("UV_stop").toString();
    save_Cer.QU_OVstart = JObj.value("OV_start").toString();
    save_Cer.QU_OVstop = JObj.value("OV_stop").toString();
    save_Cer.QU_Plockin = JObj.value("PlockIn").toString();
    save_Cer.QU_PlockOut = JObj.value("PlockOut").toString();

    save_Cer.LFSM_Mode = JObj.value("LFSM_Mode").toInt();
    save_Cer.LFSMO_Pn = JObj.value("LFSMO_Pn").toBool();
    save_Cer.LFSMO_fact = JObj.value("LFSMO_fact").toString();
    save_Cer.LFSMO_fdeact = JObj.value("LFSMO_fdeact").toString();
    save_Cer.LFSMO_Droop = JObj.value("LFSMO_Droop").toString();
    save_Cer.LFSMO_Trec = JObj.value("LFSMO_Trec").toString();
    save_Cer.LFSMO_P_slope = JObj.value("LFSMO_Slope").toString();
    save_Cer.LFSMU_fact = JObj.value("LFSMU_fact").toString();
    save_Cer.LFSMU_fdeact = JObj.value("LFSMU_fdeact").toString();
    save_Cer.LFSMU_Droop = JObj.value("LFSMU_Droop").toString();

}

void Dialog::creatJsonFile(str_Grid *s_str_Grid, str_Cer *s_str_Cer, QString filePath)
{
    Json_para["RatedFreq"] = s_str_Grid->RatedFreq;
    Json_para["RatedVol"] = s_str_Cer->ratedVol;
    Json_para["CertificationMode"] = s_str_Cer->certification_En;
    Json_para["uOV1"] = s_str_Grid->uOV1;
    Json_para["tOV1"] = s_str_Grid->tOV1;
    Json_para["uOF1"] = s_str_Grid->uOF1;
    Json_para["tOF1"] = s_str_Grid->tOF1;
    Json_para["uUV1"] = s_str_Grid->uUV1;
    Json_para["tUV1"] = s_str_Grid->tUV1;
    Json_para["uUF1"] = s_str_Grid->uUF1;
    Json_para["tUF1"] = s_str_Grid->tUF1;
    Json_para["uOV2"] = s_str_Grid->uOV2;
    Json_para["tOV2"] = s_str_Grid->tOV2;
    Json_para["uOF2"] = s_str_Grid->uOF2;
    Json_para["tOF2"] = s_str_Grid->tOF2;
    Json_para["uUV2"] = s_str_Grid->uUV2;
    Json_para["tUV2"] = s_str_Grid->tUV2;
    Json_para["uUF2"] = s_str_Grid->uUF2;
    Json_para["tUF2"] = s_str_Grid->tUF2;
    Json_para["UROV"] = s_str_Grid->URov;
    Json_para["URUV"] = s_str_Grid->URuv;
    Json_para["FROF"] = s_str_Grid->FRof;
    Json_para["FRUF"] = s_str_Grid->FRuf;
    Json_para["GT"] = s_str_Grid->GT;
    Json_para["SuperPF"] = s_str_Grid->superPF;
    Json_para["ASPQU"] = s_str_Grid->ASPQU;
    Json_para["CEIDFU"] = s_str_Grid->CEIDFU;
    Json_para["360VAR"] = s_str_Grid->Var;

    Json_para["FVRT"] = s_str_Cer->FVRT;
    Json_para["HVRT"] = s_str_Grid->HVRT;
    Json_para["LVRT"] = s_str_Grid->LVRT;

    Json_para["Island"] = s_str_Cer->Island;
    Json_para["3Tao"] = s_str_Cer->tao;
    Json_para["DF1"] = s_str_Cer->DF1;
    Json_para["DF2"] = s_str_Cer->DF2;

    Json_para["OverVol_10min"] = s_str_Cer->OverVol_10;
    Json_para["OverVol"] = s_str_Cer->OverVol_10_Para;

    Json_para["PonVfhys"] = s_str_Cer->UF_hyst;
    Json_para["VfhysRST"] = s_str_Cer->UF_hyst_powerOn;

    Json_para["FixedPF"] = s_str_Cer->Fixed_non_P;
    Json_para["FixedPF_value"] = s_str_Cer->Fixed_non_P_Para;
    Json_para["MaxPF"] = s_str_Cer->Max_non_P;

    Json_para["PrcsetSramp"] = s_str_Cer->Remote_P_slope;
    Json_para["PrcsetSramp_value"] = s_str_Cer->Remote_P_slopePara;
    Json_para["Reconnect_P"] = s_str_Cer->Reconnect_P_slope;

    Json_para["PUMode"] = s_str_Cer->PU_mode;
    Json_para["PU_InitialVol"] = s_str_Cer->PU_InitialVol;
    Json_para["PU_EndVol"] = s_str_Cer->PU_EndVol;
    Json_para["PU_Droop"] = s_str_Cer->PU_Droop;
    Json_para["PU_DroopSpd"] = s_str_Cer->PU_DroopSpd;

    Json_para["QUMode"] = s_str_Cer->QU_mode;
    Json_para["UV_start"] = s_str_Cer->QU_UVstart;
    Json_para["UV_stop"] = s_str_Cer->QU_UVstop;
    Json_para["OV_start"] = s_str_Cer->QU_OVstart;
    Json_para["OV_stop"] = s_str_Cer->QU_OVstop;
    Json_para["PlockIn"] = s_str_Cer->QU_Plockin;
    Json_para["PlockOut"] = s_str_Cer->QU_PlockOut;

    Json_para["LFSM_Mode"] = s_str_Cer->LFSM_Mode;
    Json_para["LFSMO_Pn"] = s_str_Cer->LFSMO_Pn;
    Json_para["LFSMO_fact"] = s_str_Cer->LFSMO_fact;
    Json_para["LFSMO_fdeact"] = s_str_Cer->LFSMO_fdeact;
    Json_para["LFSMO_Droop"] = s_str_Cer->LFSMO_Droop;
    Json_para["LFSMO_Trec"] = s_str_Cer->LFSMO_Trec;
    Json_para["LFSMO_Slope"] = s_str_Cer->LFSMO_P_slope;
    Json_para["LFSMU_fact"] = s_str_Cer->LFSMU_fact;
    Json_para["LFSMU_fdeact"] = s_str_Cer->LFSMU_fdeact;
    Json_para["LFSMU_Droop"] = s_str_Cer->LFSMU_Droop;

    QJsonDocument document;
    document.setObject(Json_para);
    QFile file(filePath);

    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        return;
    }
    file.write(document.toJson());
    file.close();
}


void Dialog::on_pushButton_add_clicked()
{
    dialog_file * dialogFile = new dialog_file(this);
    connect(this, &Dialog::signal_sendToDialog, dialogFile, &dialog_file::slot_receivePara);
    connect(dialogFile, &dialog_file::signal_fileSave, this, &Dialog::slot_fileSave);
    connect(this, &Dialog::signal_sendFilePath, dialogFile, &dialog_file::slot_receiveFilePath);
    emit signal_sendFilePath(data_filePath);
    readGridToStr();
    readCerToStr();

    emit signal_sendToDialog(&s_str_Grid, &s_str_Cer);
    dialogFile->show();
}


void Dialog::on_pushButton_update_clicked()
{
    QString CurrentFileName = ui->comboBox_program->currentText();
    QString filePath = data_filePath + '/' + CurrentFileName + ".json";
    readCerToStr();
    readGridToStr();

    creatJsonFile(&s_str_Grid, &s_str_Cer, filePath);
    ui->comboBox_program->setCurrentText(CurrentFileName);
    QMessageBox::warning(nullptr, "提示:", "参数修改成功");
}


void Dialog::on_pushButton_delete_clicked()
{
    QString CurrentFileName = ui->comboBox_program->currentText();
    nameList.removeOne(CurrentFileName);
    ui->comboBox_program->removeItem(ui->comboBox_program->currentIndex());
    QFile file(data_filePath + '/' + CurrentFileName +".json");
    file.remove();
    file.close();
}


void Dialog::on_comboBox_program_textActivated(const QString &arg1)
{
    readJsonDoc(arg1);
    displayGrid(&save_Grid);
    displayCer(&save_Cer);
}


void Dialog::on_comboBox_program_currentTextChanged(const QString &arg1)
{
    readJsonDoc(arg1);
    displayGrid(&save_Grid);
    displayCer(&save_Cer);
}

//comboBox当前选项切换
void Dialog::on_comboBox_CID_currentTextChanged(const QString &arg1)
{
    QString COP;
    QString MaxOP;
    double COP_num;
    bool ok;
    if (save_Re_COP.keys().contains(arg1))
    {
        COP_num = save_Re_COP[arg1].mid(0, 4).toInt(&ok, 16)/16384.0*100;
        COP = QString::number((int)(COP_num*10 + 0.5)/10.0);
    }
    else COP = "";
    ui->lineEdit_COP->setText(COP);

    if (save_Re_MaxOP.keys().contains(arg1))
    {
        MaxOP = QString::number(save_Re_MaxOP[arg1].mid(0, 2).toInt(&ok, 16)*10);
    }
    else MaxOP = "";
    ui->lineEdit_MaxOP->setText(MaxOP);

    if (save_Re_Grid.keys().contains(arg1))
    {
        Re_getGridNum(save_Re_Grid[arg1]);

        ui->comboBox_RatedFreq->currentIndex()==0? s_Re_Grid.t_RatedFreq = 20: s_Re_Grid.t_RatedFreq = 16.67;
        ui->comboBox_RatedFreq->currentIndex() == 0 ? s_Re_Grid.RatedFreq = 125:s_Re_Grid.RatedFreq = 150;

        s_str_Grid.uOV1 = s_str_Grid.uOV1.number(Dec((s_Re_Grid.uOV1), 2));
        s_str_Grid.tOV1 = s_str_Grid.tOV1.number(Dec((s_Re_Grid.tOV1*s_Re_Grid.t_RatedFreq), 2));
        s_str_Grid.uUV1 = s_str_Grid.uUV1.number(Dec((s_Re_Grid.uUV1), 1));
        s_str_Grid.tUV1 = s_str_Grid.tUV1.number(Dec((s_Re_Grid.tUV1*s_Re_Grid.t_RatedFreq), 2));
        s_str_Grid.uOF1 = s_str_Grid.uOF1.number(Dec((s_Re_Grid.uOF1), 1));
        if (s_Re_Grid.tOF1)
        {
            s_str_Grid.tOF1 = s_str_Grid.tOF1.number(Dec((s_Re_Grid.tOF1*((float)1000/s_Re_Grid.uOF1)), 2));
        }
        else s_str_Grid.tOF1 = "0";

        s_str_Grid.uUF1 = s_str_Grid.uUF1.number(Dec((s_Re_Grid.uUF1), 1));
        if (s_Re_Grid.tUF1)
        {
            s_str_Grid.tUF1 = s_str_Grid.tUF1.number(Dec((s_Re_Grid.tUF1*((float)1000/s_Re_Grid.uUF1)), 2));
        }
        else s_str_Grid.tUF1 = "0";
        s_str_Grid.uOV2 = s_str_Grid.uOV2.number(Dec((s_Re_Grid.uOV2), 1));
        s_str_Grid.tOV2 = s_str_Grid.tOV2.number(Dec((s_Re_Grid.tOV2*s_Re_Grid.t_RatedFreq), 2));
        s_str_Grid.uUV2 = s_str_Grid.uUV2.number(Dec((s_Re_Grid.uUV2), 1));
        s_str_Grid.tUV2 = s_str_Grid.tUV2.number(Dec((s_Re_Grid.tUV2*s_Re_Grid.t_RatedFreq), 2));
        s_str_Grid.uOF2 = s_str_Grid.uOF2.number(Dec((s_Re_Grid.uOF2), 1));
        if (s_Re_Grid.tOF2)
        {
            s_str_Grid.tOF2 = s_str_Grid.tOF2.number(Dec((s_Re_Grid.tOF2*((float)1000/s_Re_Grid.uOF2)), 2));
        }
        else s_str_Grid.tOF2 = "0";
        s_str_Grid.uUF2 = s_str_Grid.uUF2.number(Dec((s_Re_Grid.uUF2), 1));
        if (s_Re_Grid.tUF2)
        {
            s_str_Grid.tUF2 = s_str_Grid.tUF2.number(Dec((s_Re_Grid.tUF2*((float)1000/s_Re_Grid.uUF2)), 2));
        }
        else s_str_Grid.tUF2 = "0";
        s_str_Grid.GT = s_str_Grid.GT.number(s_Re_Grid.GT/s_Re_Grid.RatedFreq);
        s_str_Grid.URov = s_str_Grid.URov.number(Dec((s_Re_Grid.URov), 2));
        s_str_Grid.URuv = s_str_Grid.URuv.number(Dec((s_Re_Grid.URuv), 2));
        s_str_Grid.FRof = s_str_Grid.FRof.number(Dec((s_Re_Grid.FRof), 2));
        s_str_Grid.FRuf = s_str_Grid.FRuf.number(Dec((s_Re_Grid.FRuf), 2));
        s_str_Grid.superPF = s_Re_Grid.superPF;
        s_str_Grid.ASPQU = s_Re_Grid.ASPQU;
        s_str_Grid.CEIDFU = s_Re_Grid.CEIDFU;
        s_str_Grid.Var = s_Re_Grid.Var;
        s_str_Grid.HVRT = s_str_Grid.HVRT.number(s_Re_Grid.HVRT);
        s_str_Grid.LVRT = s_str_Grid.LVRT.number(s_Re_Grid.LVRT);
    }
    else
    {
        s_str_Grid.uOV1 = "";
        s_str_Grid.tOV1 = "";
        s_str_Grid.uUV1 = "";
        s_str_Grid.tUV1 = "";
        s_str_Grid.uOF1 = "";
        s_str_Grid.tOF1 = "";
        s_str_Grid.uUF1 = "";
        s_str_Grid.tUF1 = "";
        s_str_Grid.uOV2 = "";
        s_str_Grid.tOV2 = "";
        s_str_Grid.uUV2 = "";
        s_str_Grid.tUV2 = "";
        s_str_Grid.uOF2 = "";
        s_str_Grid.tOF2 = "";
        s_str_Grid.uUF2 = "";
        s_str_Grid.tUF2 = "";
        s_str_Grid.GT = "";
        s_str_Grid.URov = "";
        s_str_Grid.URuv = "";
        s_str_Grid.FRof = "";
        s_str_Grid.FRuf = "";
        s_str_Grid.superPF = 0;
        s_str_Grid.ASPQU = 0;
        s_str_Grid.CEIDFU = 0;
        s_str_Grid.Var = 0;
        s_str_Grid.HVRT = "";
        s_str_Grid.LVRT = "";
    }

    ui->lineEdit_uOV1->setText(s_str_Grid.uOV1);
    ui->lineEdit_tOV1->setText(s_str_Grid.tOV1);
    ui->lineEdit_uUV1->setText(s_str_Grid.uUV1);
    ui->lineEdit_tUV1->setText(s_str_Grid.tUV1);
    ui->lineEdit_uOF1->setText(s_str_Grid.uOF1);
    ui->lineEdit_tOF1->setText(s_str_Grid.tOF1);
    ui->lineEdit_uUF1->setText(s_str_Grid.uUF1);
    ui->lineEdit_tUF1->setText(s_str_Grid.tUF1);
    ui->lineEdit_uOV2->setText(s_str_Grid.uOV2);
    ui->lineEdit_tOV2->setText(s_str_Grid.tOV2);
    ui->lineEdit_uUV2->setText(s_str_Grid.uUV2);
    ui->lineEdit_tUV2->setText(s_str_Grid.tUV2);
    ui->lineEdit_uOF2->setText(s_str_Grid.uOF2);
    ui->lineEdit_tOF2->setText(s_str_Grid.tOF2);
    ui->lineEdit_uUF2->setText(s_str_Grid.uUF2);
    ui->lineEdit_tUF2->setText(s_str_Grid.tUF2);
    ui->lineEdit_GT->setText(s_str_Grid.GT);
    ui->lineEdit_UROV->setText(s_str_Grid.URov);
    ui->lineEdit_URuV->setText(s_str_Grid.URuv);
    ui->lineEdit_FROF->setText(s_str_Grid.FRof);
    ui->lineEdit_FRuF->setText(s_str_Grid.FRuf);
    ui->comboBox_SuperPF->setCurrentIndex(s_str_Grid.superPF);
    ui->comboBox_ASPQU->setCurrentIndex(s_str_Grid.ASPQU);
    ui->comboBox_CEIDFU->setCurrentIndex(s_str_Grid.CEIDFU);
    ui->comboBox_VAR->setCurrentIndex(s_str_Grid.Var);
    ui->lineEdit_HVRT->setText(s_str_Grid.HVRT);
    ui->lineEdit_LVRT->setText(s_str_Grid.LVRT);

    if (save_Re_Cer.keys().contains(arg1))
    {
        Re_getCerNum(save_Re_Cer[arg1]);

        s_str_Cer.Fixed_non_P = s_Re_Cer.Fixed_non_P;
        s_str_Cer.Fixed_non_P_Para = s_str_Cer.Fixed_non_P_Para.number(s_Re_Cer.Fixed_non_P_Para);
        s_str_Cer.Remote_P_slope = s_Re_Cer.Remote_P_slope;
        s_str_Cer.Remote_P_slopePara = s_str_Cer.Remote_P_slopePara.number(Dec((s_Re_Cer.Remote_P_slopePara), 2));
        s_str_Cer.OverVol_10 = s_Re_Cer.OverVol_10;
        s_str_Cer.UF_hyst = s_Re_Cer.UF_hyst;
        s_str_Cer.LFSM_Mode = s_Re_Cer.LFSM_Mode;
        s_str_Cer.LFSMO_fact = s_str_Cer.LFSMO_fact.number(Dec(s_Re_Cer.LFSMO_fact, 2));
        s_str_Cer.LFSMO_fdeact = s_str_Cer.LFSMO_fdeact.number(Dec(s_Re_Cer.LFSMO_fdeact, 2));
        s_str_Cer.LFSMO_Droop = s_str_Cer.LFSMO_Droop.number(Dec((s_Re_Cer.LFSMO_Droop), 2));
        s_str_Cer.LFSMU_fact = s_str_Cer.LFSMU_fact.number(Dec(s_Re_Cer.LFSMU_fact, 2));
        s_str_Cer.LFSMU_fdeact = s_str_Cer.LFSMU_fdeact.number(Dec(s_Re_Cer.LFSMU_fdeact, 2));
        s_str_Cer.LFSMU_Droop = s_str_Cer.LFSMU_Droop.number(Dec(s_Re_Cer.LFSMU_Droop, 2));
        s_str_Cer.LFSMO_Trec = s_str_Cer.LFSMO_Trec.number(Dec(s_Re_Cer.LFSMO_Trec, 0));
        s_str_Cer.LFSMO_P_slope = s_str_Cer.LFSMO_P_slope.number(Dec(s_Re_Cer.LFSMO_P_slope, 2));
        s_str_Cer.Reconnect_P_slope = s_str_Cer.Reconnect_P_slope.number(Dec(s_Re_Cer.Reconnect_P_slope, 2));
        s_str_Cer.Island = s_Re_Cer.Island;
        s_str_Cer.DF1 = s_Re_Cer.DF1;
        s_str_Cer.DF2 = s_Re_Cer.DF2;
        s_str_Cer.FVRT = s_Re_Cer.FVRT;
        s_str_Cer.UF_hyst_powerOn = s_Re_Cer.UF_hyst_powerOn;
        s_str_Cer.QU_mode = s_Re_Cer.QU_mode;
        s_str_Cer.PU_mode = s_Re_Cer.PU_mode;
        s_str_Cer.LFSMO_Pn = s_Re_Cer.LFSMO_Pn;
        s_str_Cer.ratedVol = s_str_Cer.ratedVol.number(Dec(s_Re_Cer.ratedVol, 0));
        s_str_Cer.PU_InitialVol = s_str_Cer.PU_InitialVol.number(Dec(s_Re_Cer.PU_InitialVol, 2));
        s_str_Cer.PU_EndVol = s_str_Cer.PU_EndVol.number(Dec(s_Re_Cer.PU_EndVol, 2));
        s_str_Cer.PU_Droop = s_str_Cer.PU_Droop.number(Dec(s_Re_Cer.PU_Droop, 2));
        s_str_Cer.PU_DroopSpd = s_str_Cer.PU_DroopSpd.number(Dec(s_Re_Cer.PU_DroopSpd, 2));
        s_str_Cer.QU_UVstart = s_str_Cer.QU_UVstart.number(Dec(s_Re_Cer.QU_UVstart, 2));
        s_str_Cer.QU_UVstop = s_str_Cer.QU_UVstop.number(Dec(s_Re_Cer.QU_UVstop, 2));
        s_str_Cer.QU_OVstart = s_str_Cer.QU_OVstart.number(Dec(s_Re_Cer.QU_OVstart, 2));
        s_str_Cer.QU_OVstop = s_str_Cer.QU_OVstop.number(Dec(s_Re_Cer.QU_OVstop, 2));
        s_str_Cer.QU_Plockin = s_str_Cer.QU_Plockin.number(Dec(s_Re_Cer.QU_Plockin, 2));
        s_str_Cer.QU_PlockOut = s_str_Cer.QU_PlockOut.number(Dec(s_Re_Cer.QU_PlockOut, 2));
        s_str_Cer.OverVol_10_Para = s_str_Cer.OverVol_10_Para.number(Dec(s_Re_Cer.OverVol_10_Para, 2));
        switch(s_Re_Cer.Max_non_P)
        {
        case 5: s_str_Cer.Max_non_P = 0; break;
        case 10: s_str_Cer.Max_non_P = 1; break;
        case 20: s_str_Cer.Max_non_P = 2; break;
        default: break;
        }
        s_str_Cer.tao = s_Re_Cer.tao;
        s_str_Cer.certification_En = s_Re_Cer.certification_En;
    }
    else
    {
        s_str_Cer.Fixed_non_P = 0;
        s_str_Cer.Fixed_non_P_Para = "";
        s_str_Cer.Remote_P_slope = 0;
        s_str_Cer.Remote_P_slopePara = "";
        s_str_Cer.OverVol_10 = 0;
        s_str_Cer.UF_hyst = 0;
        s_str_Cer.LFSM_Mode = 0;

        s_str_Cer.LFSMO_fact = "";
        s_str_Cer.LFSMO_fdeact = "";
        s_str_Cer.LFSMO_Droop = "";
        s_str_Cer.LFSMU_fact = "";
        s_str_Cer.LFSMU_fdeact = "";
        s_str_Cer.LFSMU_Droop = "";
        s_str_Cer.LFSMO_Trec = "";
        s_str_Cer.LFSMO_P_slope = "";
        s_str_Cer.Reconnect_P_slope = "";
        s_str_Cer.Island = 0;
        s_str_Cer.DF1 = 0;
        s_str_Cer.DF2 = 0;
        s_str_Cer.FVRT = 0;
        s_str_Cer.UF_hyst_powerOn = 0;
        s_str_Cer.QU_mode = 0;
        s_str_Cer.PU_mode = 0;
        s_str_Cer.LFSMO_Pn = 0;
        s_str_Cer.ratedVol = "";
        s_str_Cer.PU_InitialVol = "";
        s_str_Cer.PU_EndVol = "";
        s_str_Cer.PU_Droop = "";
        s_str_Cer.PU_DroopSpd = "";
        s_str_Cer.QU_UVstart = "";
        s_str_Cer.QU_UVstop = "";
        s_str_Cer.QU_OVstart = "";
        s_str_Cer.QU_OVstop = "";
        s_str_Cer.QU_Plockin = "";
        s_str_Cer.QU_PlockOut = "";
        s_str_Cer.OverVol_10_Para = "";
        s_str_Cer.Max_non_P = 0;
        s_str_Cer.tao = 0;
        s_str_Cer.certification_En = 0;
    }
    ui->comboBox_Fixed_non_P->setCurrentIndex(s_str_Cer.Fixed_non_P);
    ui->lineEdit_FixedPF_Para->setText(s_str_Cer.Fixed_non_P_Para);
    ui->comboBox_Remote_P_slope->setCurrentIndex(s_str_Cer.Remote_P_slope);
    ui->lineEdit_Remote_P_slope->setText(s_str_Cer.Remote_P_slopePara);
    ui->comboBox_OV10min->setCurrentIndex(s_str_Cer.OverVol_10);
    ui->comboBox_UF_hyst->setCurrentIndex(s_str_Cer.UF_hyst);
    ui->comboBox_LFSMMode->setCurrentIndex(s_str_Cer.LFSM_Mode);
    ui->lineEdit_LFSMO_fact->setText(s_str_Cer.LFSMO_fact);
    ui->lineEdit_LFSMO_fdeact->setText(s_str_Cer.LFSMO_fdeact);
    ui->lineEdit_LFSMO_Droop->setText(s_str_Cer.LFSMO_Droop);
    ui->lineEdit_LFSMU_fact->setText(s_str_Cer.LFSMU_fact);
    ui->lineEdit_LFSMU_fdeact->setText(s_str_Cer.LFSMU_fdeact);
    ui->lineEdit_LFSMU_Droop->setText(s_str_Cer.LFSMU_Droop);
    ui->lineEdit_LFSMO_Trec->setText(s_str_Cer.LFSMO_Trec);
    ui->lineEdit_LFSMO_P_slope->setText(s_str_Cer.LFSMO_P_slope);
    ui->lineEdit_Reconnect_P->setText(s_str_Cer.Reconnect_P_slope);
    ui->comboBox_Island->setCurrentIndex(s_str_Cer.Island);
    ui->comboBox_DF1->setCurrentIndex(s_str_Cer.DF1);
    ui->comboBox_DF2->setCurrentIndex(s_str_Cer.DF2);
    ui->comboBox_FVRT->setCurrentIndex(s_str_Cer.FVRT);
    ui->comboBox_UF_hyst_powerOn->setCurrentIndex(s_str_Cer.UF_hyst_powerOn);
    ui->comboBox_QUMode->setCurrentIndex(s_str_Cer.QU_mode);
    ui->comboBox_PUMode->setCurrentIndex(s_str_Cer.PU_mode);
    ui->comboBox_LFSMO_Pn->setCurrentIndex(s_str_Cer.LFSMO_Pn);
    ui->lineEdit_RatedVol->setText(s_str_Cer.ratedVol);
    ui->lineEdit_PU_InitialVol->setText(s_str_Cer.PU_InitialVol);
    ui->lineEdit_PU_EndVol->setText(s_str_Cer.PU_EndVol);
    ui->lineEdit_PU_Droop->setText(s_str_Cer.PU_Droop);
    ui->lineEdit_PU_DroopSpd->setText(s_str_Cer.PU_DroopSpd);
    ui->lineEdit_UV_start->setText(s_str_Cer.QU_UVstart);
    ui->lineEdit_UV_stop->setText(s_str_Cer.QU_UVstop);
    ui->lineEdit_OV_start->setText(s_str_Cer.QU_OVstart);
    ui->lineEdit_OV_stop->setText(s_str_Cer.QU_OVstop);
    ui->lineEdit_Plock_in->setText(s_str_Cer.QU_Plockin);
    ui->lineEdit_Plock_out->setText(s_str_Cer.QU_PlockOut);
    ui->lineEdit_OverVol->setText(s_str_Cer.OverVol_10_Para);
    ui->comboBox_MaxPF_Value->setCurrentIndex(s_str_Cer.Max_non_P);
    ui->comboBox_Tau->setCurrentIndex(s_str_Cer.tao);
    ui->comboBox_cetificationMode->setCurrentIndex(s_str_Cer.certification_En);
}

void Dialog::on_checkBox_all_stateChanged(int arg1)
{
    if (ui->checkBox_all->isChecked())
    {
        for (int i = 0; i < ui->tableWidget_CID->rowCount(); ++i)
        {
            set_item_checked(true, i);
        }
    }
    else
    {
        for (int i = 0; i < ui->tableWidget_CID->rowCount(); ++i)
        {
            set_item_checked(false, i);
        }
    }
}
