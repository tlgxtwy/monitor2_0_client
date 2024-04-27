#include "dialog_file.h"
#include "ui_dialog_file.h"
#include "QJsonDocument"
#include <QMessageBox>
dialog_file::dialog_file(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialog_file)
{

    ui->setupUi(this);
    this->setWindowTitle("请设置文件名称");
    this->setWindowFlags(Qt::Dialog | Qt::WindowSystemMenuHint | Qt::WindowCloseButtonHint);


}

dialog_file::~dialog_file()
{
    delete ui;
}

//创建json文件
void dialog_file::slot_receivePara(str_Grid *s_str_Grid, str_Cer *s_str_Cer)
{
    json_para["RatedFreq"] = s_str_Grid->RatedFreq;
    json_para["RatedVol"] = s_str_Cer->ratedVol;
    json_para["CertificationMode"] = s_str_Cer->certification_En;
    json_para["uOV1"] = s_str_Grid->uOV1;
    json_para["tOV1"] = s_str_Grid->tOV1;
    json_para["uOF1"] = s_str_Grid->uOF1;
    json_para["tOF1"] = s_str_Grid->tOF1;
    json_para["uUV1"] = s_str_Grid->uUV1;
    json_para["tUV1"] = s_str_Grid->tUV1;
    json_para["uUF1"] = s_str_Grid->uUF1;
    json_para["tUF1"] = s_str_Grid->tUF1;
    json_para["uOV2"] = s_str_Grid->uOV2;
    json_para["tOV2"] = s_str_Grid->tOV2;
    json_para["uOF2"] = s_str_Grid->uOF2;
    json_para["tOF2"] = s_str_Grid->tOF2;
    json_para["uUV2"] = s_str_Grid->uUV2;
    json_para["tUV2"] = s_str_Grid->tUV2;
    json_para["uUF2"] = s_str_Grid->uUF2;
    json_para["tUF2"] = s_str_Grid->tUF2;
    json_para["UROV"] = s_str_Grid->URov;
    json_para["URUV"] = s_str_Grid->URuv;
    json_para["FROF"] = s_str_Grid->FRof;
    json_para["FRUF"] = s_str_Grid->FRuf;
    json_para["GT"] = s_str_Grid->GT;
    json_para["SuperPF"] = s_str_Grid->superPF;
    json_para["ASPQU"] = s_str_Grid->ASPQU;
    json_para["CEIDFU"] = s_str_Grid->CEIDFU;
    json_para["360VAR"] = s_str_Grid->Var;

    json_para["FVRT"] = s_str_Cer->FVRT;
    json_para["HVRT"] = s_str_Grid->HVRT;
    json_para["LVRT"] = s_str_Grid->LVRT;

    json_para["Island"] = s_str_Cer->Island;
    json_para["3Tao"] = s_str_Cer->tao;
    json_para["DF1"] = s_str_Cer->DF1;
    json_para["DF2"] = s_str_Cer->DF2;

    json_para["OverVol_10min"] = s_str_Cer->OverVol_10;
    json_para["OverVol"] = s_str_Cer->OverVol_10_Para;

    json_para["PonVfhys"] = s_str_Cer->UF_hyst;
    json_para["VfhysRST"] = s_str_Cer->UF_hyst_powerOn;

    json_para["FixedPF"] = s_str_Cer->Fixed_non_P;
    json_para["FixedPF_value"] = s_str_Cer->Fixed_non_P_Para;
    json_para["MaxPF"] = s_str_Cer->Max_non_P;

    json_para["PrcsetSramp"] = s_str_Cer->Remote_P_slope;
    json_para["PrcsetSramp_value"] = s_str_Cer->Remote_P_slopePara;
    json_para["Reconnect_P"] = s_str_Cer->Reconnect_P_slope;

    json_para["PUMode"] = s_str_Cer->PU_mode;
    json_para["PU_InitialVol"] = s_str_Cer->PU_InitialVol;
    json_para["PU_EndVol"] = s_str_Cer->PU_EndVol;
    json_para["PU_Droop"] = s_str_Cer->PU_Droop;
    json_para["PU_DroopSpd"] = s_str_Cer->PU_DroopSpd;

    json_para["QUMode"] = s_str_Cer->QU_mode;
    json_para["UV_start"] = s_str_Cer->QU_UVstart;
    json_para["UV_stop"] = s_str_Cer->QU_UVstop;
    json_para["OV_start"] = s_str_Cer->QU_OVstart;
    json_para["OV_stop"] = s_str_Cer->QU_OVstop;
    json_para["PlockIn"] = s_str_Cer->QU_Plockin;
    json_para["PlockOut"] = s_str_Cer->QU_PlockOut;

    json_para["LFSM_Mode"] = s_str_Cer->LFSM_Mode;
    json_para["LFSMO_Pn"] = s_str_Cer->LFSMO_Pn;
    json_para["LFSMO_fact"] = s_str_Cer->LFSMO_fact;
    json_para["LFSMO_fdeact"] = s_str_Cer->LFSMO_fdeact;
    json_para["LFSMO_Droop"] = s_str_Cer->LFSMO_Droop;
    json_para["LFSMO_Trec"] = s_str_Cer->LFSMO_Trec;
    json_para["LFSMO_Slope"] = s_str_Cer->LFSMO_P_slope;
    json_para["LFSMU_fact"] = s_str_Cer->LFSMU_fact;
    json_para["LFSMU_fdeact"] = s_str_Cer->LFSMU_fdeact;
    json_para["LFSMU_Droop"] = s_str_Cer->LFSMU_Droop;

}

void dialog_file::slot_receiveFilePath(QString filePath)
{
    exe_filePath = filePath;
}


void dialog_file::on_pushButton_cancel_clicked()
{

    this->close();
}

//点击保存
void dialog_file::on_pushButton_save_clicked()
{
    QString fileName, filePath;
    fileName = ui->lineEdit->text();
    filePath = exe_filePath + '/' + fileName + ".json";
    QJsonDocument document;
    document.setObject(json_para);
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QMessageBox::warning(nullptr, "错误", "文件保存失败");

        return;
    }
    file.write(document.toJson());
    file.close();
    emit signal_fileSave(fileName);
    this->close();
}

