#include "judge_param_set_dlg.h"
#include "ui_judge_param_set_dlg.h"

#include <QRegExpValidator>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QMessageBox>
#include <QHash>

#include "bridge.h"
//extern QString g_aging_param_path;
//extern QHash<QString,aging_judge_value> g_bym_aging_param;
judge_param_set_dlg::judge_param_set_dlg(QJsonObject def_data, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::judge_param_set_dlg)
{
    ui->setupUi(this);
    this->resize(1400,1100);

    connect(this,&judge_param_set_dlg::s_update_alg,bridge::ins()->csclient(),&cs_client::onm_send);
    connect(bridge::ins()->core(),&core_mg::s_update_alg_status,this,&judge_param_set_dlg::onm_update_alg_success);

    //ui->tabWidget_3->removeTab(4);
    ui->tabWidget_3->removeTab(3);

    QRegExp regx("[0-9]+$");
    QValidator* validator = new QRegExpValidator(regx,this);
    ui->bym500_aging_offset_edt->setValidator(validator);
    ui->bym500_ignore_max_edt->setValidator(validator);
    ui->bym500_drop_max_edt->setValidator(validator);
    ui->bym500_drop_value_edt->setValidator(validator);
    ui->bym500_aging_num_edt->setValidator(validator);
    ui->bym500_aging_time_edt->setValidator(validator);
    ui->bym500_rt40_time_edt->setValidator(validator);
    ui->bym500_rt45_time_edt->setValidator(validator);
    ui->bym500_rt50_time_edt->setValidator(validator);
    ui->bym500_rt55_time_edt->setValidator(validator);
    ui->bym500_rt60_time_edt->setValidator(validator);
    ui->bym500_t40_edt->setValidator(validator);
    ui->bym500_t45_edt->setValidator(validator);
    ui->bym500_t50_edt->setValidator(validator);
    ui->bym500_t55_edt->setValidator(validator);
    ui->bym500_t60_edt->setValidator(validator);
    ui->bym500_rt40_time_pv_edt->setValidator(validator);
    ui->bym500_rt45_time_pv_edt->setValidator(validator);
    ui->bym500_rt50_time_pv_edt->setValidator(validator);
    ui->bym500_rt55_time_pv_edt->setValidator(validator);
    ui->bym500_rt60_time_pv_edt->setValidator(validator);
    ui->bym500_t40_pv_edt->setValidator(validator);
    ui->bym500_t45_pv_edt->setValidator(validator);
    ui->bym500_t50_pv_edt->setValidator(validator);
    ui->bym500_t55_pv_edt->setValidator(validator);
    ui->bym500_t60_pv_edt->setValidator(validator);

    ui->bym550_aging_offset_edt->setValidator(validator);
    ui->bym550_ignore_max_edt->setValidator(validator);
    ui->bym550_drop_max_edt->setValidator(validator);
    ui->bym550_drop_value_edt->setValidator(validator);
    ui->bym550_aging_num_edt->setValidator(validator);
    ui->bym550_aging_time_edt->setValidator(validator);
    ui->bym550_rt40_time_edt->setValidator(validator);
    ui->bym550_rt45_time_edt->setValidator(validator);
    ui->bym550_rt50_time_edt->setValidator(validator);
    ui->bym550_rt55_time_edt->setValidator(validator);
    ui->bym550_rt60_time_edt->setValidator(validator);
    ui->bym550_t40_edt->setValidator(validator);
    ui->bym550_t45_edt->setValidator(validator);
    ui->bym550_t50_edt->setValidator(validator);
    ui->bym550_t55_edt->setValidator(validator);
    ui->bym550_t60_edt->setValidator(validator);
    ui->bym550_rt40_time_pv_edt->setValidator(validator);
    ui->bym550_rt45_time_pv_edt->setValidator(validator);
    ui->bym550_rt50_time_pv_edt->setValidator(validator);
    ui->bym550_rt55_time_pv_edt->setValidator(validator);
    ui->bym550_rt60_time_pv_edt->setValidator(validator);
    ui->bym550_t40_pv_edt->setValidator(validator);
    ui->bym550_t45_pv_edt->setValidator(validator);
    ui->bym550_t50_pv_edt->setValidator(validator);
    ui->bym550_t55_pv_edt->setValidator(validator);
    ui->bym550_t60_pv_edt->setValidator(validator);

    ui->bym600_aging_offset_edt->setValidator(validator);
    ui->bym600_ignore_max_edt->setValidator(validator);
    ui->bym600_drop_max_edt->setValidator(validator);
    ui->bym600_drop_value_edt->setValidator(validator);
    ui->bym600_aging_num_edt->setValidator(validator);
    ui->bym600_aging_time_edt->setValidator(validator);
    ui->bym600_rt40_time_edt->setValidator(validator);
    ui->bym600_rt45_time_edt->setValidator(validator);
    ui->bym600_rt50_time_edt->setValidator(validator);
    ui->bym600_rt55_time_edt->setValidator(validator);
    ui->bym600_rt60_time_edt->setValidator(validator);
    ui->bym600_t40_edt->setValidator(validator);
    ui->bym600_t45_edt->setValidator(validator);
    ui->bym600_t50_edt->setValidator(validator);
    ui->bym600_t55_edt->setValidator(validator);
    ui->bym600_t60_edt->setValidator(validator);
    ui->bym600_rt40_time_pv_edt->setValidator(validator);
    ui->bym600_rt45_time_pv_edt->setValidator(validator);
    ui->bym600_rt50_time_pv_edt->setValidator(validator);
    ui->bym600_rt55_time_pv_edt->setValidator(validator);
    ui->bym600_rt60_time_pv_edt->setValidator(validator);
    ui->bym600_t40_pv_edt->setValidator(validator);
    ui->bym600_t45_pv_edt->setValidator(validator);
    ui->bym600_t50_pv_edt->setValidator(validator);
    ui->bym600_t55_pv_edt->setValidator(validator);
    ui->bym600_t60_pv_edt->setValidator(validator);

    ui->bym700_aging_offset_edt->setValidator(validator);
    ui->bym700_ignore_max_edt->setValidator(validator);
    ui->bym700_drop_max_edt->setValidator(validator);
    ui->bym700_drop_value_edt->setValidator(validator);
    ui->bym700_aging_num_edt->setValidator(validator);
    ui->bym700_aging_time_edt->setValidator(validator);
    ui->bym700_rt40_time_edt->setValidator(validator);
    ui->bym700_rt45_time_edt->setValidator(validator);
    ui->bym700_rt50_time_edt->setValidator(validator);
    ui->bym700_rt55_time_edt->setValidator(validator);
    ui->bym700_rt60_time_edt->setValidator(validator);
    ui->bym700_t40_edt->setValidator(validator);
    ui->bym700_t45_edt->setValidator(validator);
    ui->bym700_t50_edt->setValidator(validator);
    ui->bym700_t55_edt->setValidator(validator);
    ui->bym700_t60_edt->setValidator(validator);
    ui->bym700_rt40_time_pv_edt->setValidator(validator);
    ui->bym700_rt45_time_pv_edt->setValidator(validator);
    ui->bym700_rt50_time_pv_edt->setValidator(validator);
    ui->bym700_rt55_time_pv_edt->setValidator(validator);
    ui->bym700_rt60_time_pv_edt->setValidator(validator);
    ui->bym700_t40_pv_edt->setValidator(validator);
    ui->bym700_t45_pv_edt->setValidator(validator);
    ui->bym700_t50_pv_edt->setValidator(validator);
    ui->bym700_t55_pv_edt->setValidator(validator);
    ui->bym700_t60_pv_edt->setValidator(validator);

    ui->bym800_aging_offset_edt->setValidator(validator);
    ui->bym800_ignore_max_edt->setValidator(validator);
    ui->bym800_drop_max_edt->setValidator(validator);
    ui->bym800_drop_value_edt->setValidator(validator);
    ui->bym800_aging_num_edt->setValidator(validator);
    ui->bym800_aging_time_edt->setValidator(validator);
    ui->bym800_rt40_time_edt->setValidator(validator);
    ui->bym800_rt45_time_edt->setValidator(validator);
    ui->bym800_rt50_time_edt->setValidator(validator);
    ui->bym800_rt55_time_edt->setValidator(validator);
    ui->bym800_rt60_time_edt->setValidator(validator);
    ui->bym800_t40_edt->setValidator(validator);
    ui->bym800_t45_edt->setValidator(validator);
    ui->bym800_t50_edt->setValidator(validator);
    ui->bym800_t55_edt->setValidator(validator);
    ui->bym800_t60_edt->setValidator(validator);
    ui->bym800_rt40_time_pv_edt->setValidator(validator);
    ui->bym800_rt45_time_pv_edt->setValidator(validator);
    ui->bym800_rt50_time_pv_edt->setValidator(validator);
    ui->bym800_rt55_time_pv_edt->setValidator(validator);
    ui->bym800_rt60_time_pv_edt->setValidator(validator);
    ui->bym800_t40_pv_edt->setValidator(validator);
    ui->bym800_t45_pv_edt->setValidator(validator);
    ui->bym800_t50_pv_edt->setValidator(validator);
    ui->bym800_t55_pv_edt->setValidator(validator);
    ui->bym800_t60_pv_edt->setValidator(validator);



    ui->bym1000_aging_offset_edt->setValidator(validator);
    ui->bym1000_ignore_max_edt->setValidator(validator);
    ui->bym1000_drop_max_edt->setValidator(validator);
    ui->bym1000_drop_value_edt->setValidator(validator);
    ui->bym1000_aging_num_edt->setValidator(validator);
    ui->bym1000_aging_time_edt->setValidator(validator);
    ui->bym1000_rt40_time_edt->setValidator(validator);
    ui->bym1000_rt45_time_edt->setValidator(validator);
    ui->bym1000_rt50_time_edt->setValidator(validator);
    ui->bym1000_rt55_time_edt->setValidator(validator);
    ui->bym1000_rt60_time_edt->setValidator(validator);
    ui->bym1000_t40_edt->setValidator(validator);
    ui->bym1000_t45_edt->setValidator(validator);
    ui->bym1000_t50_edt->setValidator(validator);
    ui->bym1000_t55_edt->setValidator(validator);
    ui->bym1000_t60_edt->setValidator(validator);
    ui->bym1000_rt40_time_pv_edt->setValidator(validator);
    ui->bym1000_rt45_time_pv_edt->setValidator(validator);
    ui->bym1000_rt50_time_pv_edt->setValidator(validator);
    ui->bym1000_rt55_time_pv_edt->setValidator(validator);
    ui->bym1000_rt60_time_pv_edt->setValidator(validator);
    ui->bym1000_t40_pv_edt->setValidator(validator);
    ui->bym1000_t45_pv_edt->setValidator(validator);
    ui->bym1000_t50_pv_edt->setValidator(validator);
    ui->bym1000_t55_pv_edt->setValidator(validator);
    ui->bym1000_t60_pv_edt->setValidator(validator);

    ui->bym1200_aging_offset_edt->setValidator(validator);
    ui->bym1200_ignore_max_edt->setValidator(validator);
    ui->bym1200_drop_max_edt->setValidator(validator);
    ui->bym1200_drop_value_edt->setValidator(validator);
    ui->bym1200_aging_num_edt->setValidator(validator);
    ui->bym1200_aging_time_edt->setValidator(validator);
    ui->bym1200_rt40_time_edt->setValidator(validator);
    ui->bym1200_rt45_time_edt->setValidator(validator);
    ui->bym1200_rt50_time_edt->setValidator(validator);
    ui->bym1200_rt55_time_edt->setValidator(validator);
    ui->bym1200_rt60_time_edt->setValidator(validator);
    ui->bym1200_t40_edt->setValidator(validator);
    ui->bym1200_t45_edt->setValidator(validator);
    ui->bym1200_t50_edt->setValidator(validator);
    ui->bym1200_t55_edt->setValidator(validator);
    ui->bym1200_t60_edt->setValidator(validator);
    ui->bym1200_rt40_time_pv_edt->setValidator(validator);
    ui->bym1200_rt45_time_pv_edt->setValidator(validator);
    ui->bym1200_rt50_time_pv_edt->setValidator(validator);
    ui->bym1200_rt55_time_pv_edt->setValidator(validator);
    ui->bym1200_rt60_time_pv_edt->setValidator(validator);
    ui->bym1200_t40_pv_edt->setValidator(validator);
    ui->bym1200_t45_pv_edt->setValidator(validator);
    ui->bym1200_t50_pv_edt->setValidator(validator);
    ui->bym1200_t55_pv_edt->setValidator(validator);
    ui->bym1200_t60_pv_edt->setValidator(validator);

    ui->bym2000_aging_offset_edt->setValidator(validator);
    ui->bym2000_ignore_max_edt->setValidator(validator);
    ui->bym2000_drop_max_edt->setValidator(validator);
    ui->bym2000_drop_value_edt->setValidator(validator);
    ui->bym2000_aging_num_edt->setValidator(validator);
    ui->bym2000_aging_time_edt->setValidator(validator);
    ui->bym2000_rt40_time_edt->setValidator(validator);
    ui->bym2000_rt45_time_edt->setValidator(validator);
    ui->bym2000_rt50_time_edt->setValidator(validator);
    ui->bym2000_rt55_time_edt->setValidator(validator);
    ui->bym2000_rt60_time_edt->setValidator(validator);
    ui->bym2000_t40_edt->setValidator(validator);
    ui->bym2000_t45_edt->setValidator(validator);
    ui->bym2000_t50_edt->setValidator(validator);
    ui->bym2000_t55_edt->setValidator(validator);
    ui->bym2000_t60_edt->setValidator(validator);
    ui->bym2000_rt40_time_pv_edt->setValidator(validator);
    ui->bym2000_rt45_time_pv_edt->setValidator(validator);
    ui->bym2000_rt50_time_pv_edt->setValidator(validator);
    ui->bym2000_rt55_time_pv_edt->setValidator(validator);
    ui->bym2000_rt60_time_pv_edt->setValidator(validator);
    ui->bym2000_t40_pv_edt->setValidator(validator);
    ui->bym2000_t45_pv_edt->setValidator(validator);
    ui->bym2000_t50_pv_edt->setValidator(validator);
    ui->bym2000_t55_pv_edt->setValidator(validator);
    ui->bym2000_t60_pv_edt->setValidator(validator);

    ui->bym2400_aging_offset_edt->setValidator(validator);
    ui->bym2400_ignore_max_edt->setValidator(validator);
    ui->bym2400_drop_max_edt->setValidator(validator);
    ui->bym2400_drop_value_edt->setValidator(validator);
    ui->bym2400_aging_num_edt->setValidator(validator);
    ui->bym2400_aging_time_edt->setValidator(validator);
    ui->bym2400_rt40_time_edt->setValidator(validator);
    ui->bym2400_rt45_time_edt->setValidator(validator);
    ui->bym2400_rt50_time_edt->setValidator(validator);
    ui->bym2400_rt55_time_edt->setValidator(validator);
    ui->bym2400_rt60_time_edt->setValidator(validator);
    ui->bym2400_t40_edt->setValidator(validator);
    ui->bym2400_t45_edt->setValidator(validator);
    ui->bym2400_t50_edt->setValidator(validator);
    ui->bym2400_t55_edt->setValidator(validator);
    ui->bym2400_t60_edt->setValidator(validator);
    ui->bym2400_rt40_time_pv_edt->setValidator(validator);
    ui->bym2400_rt45_time_pv_edt->setValidator(validator);
    ui->bym2400_rt50_time_pv_edt->setValidator(validator);
    ui->bym2400_rt55_time_pv_edt->setValidator(validator);
    ui->bym2400_rt60_time_pv_edt->setValidator(validator);
    ui->bym2400_t40_pv_edt->setValidator(validator);
    ui->bym2400_t45_pv_edt->setValidator(validator);
    ui->bym2400_t50_pv_edt->setValidator(validator);
    ui->bym2400_t55_pv_edt->setValidator(validator);
    ui->bym2400_t60_pv_edt->setValidator(validator);

    ui->bym2800_aging_offset_edt->setValidator(validator);
    ui->bym2800_ignore_max_edt->setValidator(validator);
    ui->bym2800_drop_max_edt->setValidator(validator);
    ui->bym2800_drop_value_edt->setValidator(validator);
    ui->bym2800_aging_num_edt->setValidator(validator);
    ui->bym2800_aging_time_edt->setValidator(validator);
    ui->bym2800_rt40_time_edt->setValidator(validator);
    ui->bym2800_rt45_time_edt->setValidator(validator);
    ui->bym2800_rt50_time_edt->setValidator(validator);
    ui->bym2800_rt55_time_edt->setValidator(validator);
    ui->bym2800_rt60_time_edt->setValidator(validator);
    ui->bym2800_t40_edt->setValidator(validator);
    ui->bym2800_t45_edt->setValidator(validator);
    ui->bym2800_t50_edt->setValidator(validator);
    ui->bym2800_t55_edt->setValidator(validator);
    ui->bym2800_t60_edt->setValidator(validator);
    ui->bym2800_rt40_time_pv_edt->setValidator(validator);
    ui->bym2800_rt45_time_pv_edt->setValidator(validator);
    ui->bym2800_rt50_time_pv_edt->setValidator(validator);
    ui->bym2800_rt55_time_pv_edt->setValidator(validator);
    ui->bym2800_rt60_time_pv_edt->setValidator(validator);
    ui->bym2800_t40_pv_edt->setValidator(validator);
    ui->bym2800_t45_pv_edt->setValidator(validator);
    ui->bym2800_t50_pv_edt->setValidator(validator);
    ui->bym2800_t55_pv_edt->setValidator(validator);
    ui->bym2800_t60_pv_edt->setValidator(validator);
//  bym500
    QJsonObject bym500_jsobj = def_data.value("bym500").toObject();

    ui->bym500_aging_offset_edt->setText(QString::number(bym500_jsobj.value("v_start_point_offset").toInt()));
    ui->bym500_ignore_max_edt->setText(QString::number(bym500_jsobj.value("ignore_points_max").toInt()));
    ui->bym500_drop_max_edt->setText(QString::number(bym500_jsobj.value("drop_points_max").toInt()));
    ui->bym500_drop_value_edt->setText(QString::number(bym500_jsobj.value("drop_value").toInt()));

    if(bym500_jsobj.value("v_aging_points").toInt() == -1)
    {
        ui->bym500_aging_num_ckx->setCheckState(Qt::Unchecked);
        ui->bym500_aging_num_edt->setText("");
    }
    else
    {
        ui->bym500_aging_num_ckx->setCheckState(Qt::Checked);
        ui->bym500_aging_num_edt->setText(QString::number(bym500_jsobj.value("v_aging_points").toInt()));
    }

    if(bym500_jsobj.value("v_aging_time").toInt() == -1)
    {
        ui->bym500_aging_time_ckx->setCheckState(Qt::Unchecked);
        ui->bym500_aging_time_edt->setText("");
    }
    else
    {
        ui->bym500_aging_time_ckx->setCheckState(Qt::Checked);
        ui->bym500_aging_time_edt->setText(QString::number(bym500_jsobj.value("v_aging_time").toInt()));
    }

    if(bym500_jsobj.value("v_rm40_pwmin").toInt() == -1)
    {
        ui->bym500_rt40_time_ckx->setCheckState(Qt::Unchecked);
        ui->bym500_rt40_time_edt->setText("");
    }
    else
    {
        ui->bym500_rt40_time_ckx->setCheckState(Qt::Checked);
        ui->bym500_rt40_time_edt->setText(QString::number(bym500_jsobj.value("v_rm40_pwmin").toInt()));
    }

    if(bym500_jsobj.value("v_rm40_tmax").toInt() == -1)
    {
        ui->bym500_t40_ckx->setCheckState(Qt::Unchecked);
        ui->bym500_t40_edt->setText("");
    }
    else
    {
        ui->bym500_t40_ckx->setCheckState(Qt::Checked);
        ui->bym500_t40_edt->setText(QString::number(bym500_jsobj.value("v_rm40_tmax").toInt()));
    }

    if(bym500_jsobj.value("v_rm45_pwmin").toInt() == -1)
    {
        ui->bym500_rt45_time_ckx->setCheckState(Qt::Unchecked);
        ui->bym500_rt45_time_edt->setText("");
    }
    else
    {
        ui->bym500_rt45_time_ckx->setCheckState(Qt::Checked);
        ui->bym500_rt45_time_edt->setText(QString::number(bym500_jsobj.value("v_rm45_pwmin").toInt()));
    }

    if(bym500_jsobj.value("v_rm45_tmax").toInt() == -1)
    {
        ui->bym500_t45_ckx->setCheckState(Qt::Unchecked);
        ui->bym500_t45_edt->setText("");
    }
    else
    {
        ui->bym500_t45_ckx->setCheckState(Qt::Checked);
        ui->bym500_t45_edt->setText(QString::number(bym500_jsobj.value("v_rm45_tmax").toInt()));
    }

    if(bym500_jsobj.value("v_rm50_pwmin").toInt() == -1)
    {
        ui->bym500_rt50_time_ckx->setCheckState(Qt::Unchecked);
        ui->bym500_rt50_time_edt->setText("");
    }
    else
    {
        ui->bym500_rt50_time_ckx->setCheckState(Qt::Checked);
        ui->bym500_rt50_time_edt->setText(QString::number(bym500_jsobj.value("v_rm50_pwmin").toInt()));
    }

    if(bym500_jsobj.value("v_rm50_tmax").toInt() == -1)
    {
        ui->bym500_t50_ckx->setCheckState(Qt::Unchecked);
        ui->bym500_t50_edt->setText("");
    }
    else
    {
        ui->bym500_t50_ckx->setCheckState(Qt::Checked);
        ui->bym500_t50_edt->setText(QString::number(bym500_jsobj.value("v_rm50_tmax").toInt()));
    }

    if(bym500_jsobj.value("v_rm55_pwmin").toInt() == -1)
    {
        ui->bym500_rt55_time_ckx->setCheckState(Qt::Unchecked);
        ui->bym500_rt55_time_edt->setText("");
    }
    else
    {
        ui->bym500_rt55_time_ckx->setCheckState(Qt::Checked);
        ui->bym500_rt55_time_edt->setText(QString::number(bym500_jsobj.value("v_rm55_pwmin").toInt()));
    }

    if(bym500_jsobj.value("v_rm55_tmax").toInt() == -1)
    {
        ui->bym500_t55_ckx->setCheckState(Qt::Unchecked);
        ui->bym500_t55_edt->setText("");
    }
    else
    {
        ui->bym500_t55_ckx->setCheckState(Qt::Checked);
        ui->bym500_t55_edt->setText(QString::number(bym500_jsobj.value("v_rm55_tmax").toInt()));
    }
    if(bym500_jsobj.value("v_rm60_pwmin").toInt() == -1)
    {
        ui->bym500_rt60_time_ckx->setCheckState(Qt::Unchecked);
        ui->bym500_rt60_time_edt->setText("");
    }
    else
    {
        ui->bym500_rt60_time_ckx->setCheckState(Qt::Checked);
        ui->bym500_rt60_time_edt->setText(QString::number(bym500_jsobj.value("v_rm60_pwmin").toInt()));
    }

    if(bym500_jsobj.value("v_rm60_tmax").toInt() == -1)
    {
        ui->bym500_t60_ckx->setCheckState(Qt::Unchecked);
        ui->bym500_t60_edt->setText("");
    }
    else
    {
        ui->bym500_t60_ckx->setCheckState(Qt::Checked);
        ui->bym500_t60_edt->setText(QString::number(bym500_jsobj.value("v_rm60_tmax").toInt()));
    }

    QJsonObject bym500_pv1_jsobj = bym500_jsobj.value("pv_params").toArray().at(0).toObject();
    if(bym500_pv1_jsobj.value("v_pv_rm40_pwmin").toInt() == -1)
    {
        ui->bym500_rt40_time_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym500_rt40_time_pv_edt->setText("");
    }
    else
    {
        ui->bym500_rt40_time_pv_ckx->setCheckState(Qt::Checked);
        ui->bym500_rt40_time_pv_edt->setText(QString::number(bym500_pv1_jsobj.value("v_pv_rm40_pwmin").toInt()));
    }

    if(bym500_pv1_jsobj.value("v_pv_rm40_tmax").toInt() == -1)
    {
        ui->bym500_t40_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym500_t40_pv_edt->setText("");
    }
    else
    {
        ui->bym500_t40_pv_ckx->setCheckState(Qt::Checked);
        ui->bym500_t40_pv_edt->setText(QString::number(bym500_pv1_jsobj.value("v_pv_rm40_tmax").toInt()));
    }

    if(bym500_pv1_jsobj.value("v_pv_rm45_pwmin").toInt() == -1)
    {
        ui->bym500_rt45_time_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym500_rt45_time_pv_edt->setText("");
    }
    else
    {
        ui->bym500_rt45_time_pv_ckx->setCheckState(Qt::Checked);
        ui->bym500_rt45_time_pv_edt->setText(QString::number(bym500_pv1_jsobj.value("v_pv_rm45_pwmin").toInt()));
    }

    if(bym500_pv1_jsobj.value("v_pv_rm45_tmax").toInt() == -1)
    {
        ui->bym500_t45_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym500_t45_pv_edt->setText("");
    }
    else
    {
        ui->bym500_t45_pv_ckx->setCheckState(Qt::Checked);
        ui->bym500_t45_pv_edt->setText(QString::number(bym500_pv1_jsobj.value("v_pv_rm45_tmax").toInt()));
    }

    if(bym500_pv1_jsobj.value("v_pv_rm50_pwmin").toInt() == -1)
    {
        ui->bym500_rt50_time_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym500_rt50_time_pv_edt->setText("");
    }
    else
    {
        ui->bym500_rt50_time_pv_ckx->setCheckState(Qt::Checked);
        ui->bym500_rt50_time_pv_edt->setText(QString::number(bym500_pv1_jsobj.value("v_pv_rm50_pwmin").toInt()));
    }

    if(bym500_pv1_jsobj.value("v_pv_rm50_tmax").toInt() == -1)
    {
        ui->bym500_t50_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym500_t50_pv_edt->setText("");
    }
    else
    {
        ui->bym500_t50_pv_ckx->setCheckState(Qt::Checked);
        ui->bym500_t50_pv_edt->setText(QString::number(bym500_pv1_jsobj.value("v_pv_rm50_tmax").toInt()));
    }

    if(bym500_pv1_jsobj.value("v_pv_rm55_pwmin").toInt() == -1)
    {
        ui->bym500_rt55_time_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym500_rt55_time_pv_edt->setText("");
    }
    else
    {
        ui->bym500_rt55_time_pv_ckx->setCheckState(Qt::Checked);
        ui->bym500_rt55_time_pv_edt->setText(QString::number(bym500_pv1_jsobj.value("v_pv_rm55_pwmin").toInt()));
    }

    if(bym500_pv1_jsobj.value("v_pv_rm55_tmax").toInt() == -1)
    {
        ui->bym500_t55_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym500_t55_pv_edt->setText("");
    }
    else
    {
        ui->bym500_t55_pv_ckx->setCheckState(Qt::Checked);
        ui->bym500_t55_pv_edt->setText(QString::number(bym500_pv1_jsobj.value("v_pv_rm55_tmax").toInt()));
    }
    if(bym500_pv1_jsobj.value("v_pv_rm60_pwmin").toInt() == -1)
    {
        ui->bym500_rt60_time_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym500_rt60_time_pv_edt->setText("");
    }
    else
    {
        ui->bym500_rt60_time_pv_ckx->setCheckState(Qt::Checked);
        ui->bym500_rt60_time_pv_edt->setText(QString::number(bym500_pv1_jsobj.value("v_pv_rm60_pwmin").toInt()));
    }

    if(bym500_pv1_jsobj.value("v_pv_rm60_tmax").toInt() == -1)
    {
        ui->bym500_t60_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym500_t60_pv_edt->setText("");
    }
    else
    {
        ui->bym500_t60_pv_ckx->setCheckState(Qt::Checked);
        ui->bym500_t60_pv_edt->setText(QString::number(bym500_jsobj.value("v_pv_rm60_tmax").toInt()));
    }
    int bym500_mim_err_mask = bym500_jsobj.value("mim1_err").toInt();
    int bym500_mis_err_mask = bym500_jsobj.value("mis_err").toInt();

    //原边故障
    if(bym500_mim_err_mask & 0x8000)
    {
        ui->bym500_pv_ov_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym500_pv_ov_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym500_mim_err_mask & 0x4000)
    {
        ui->bym500_pv_uv_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym500_pv_uv_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym500_mim_err_mask & 0x2000)
    {
        ui->bym500_dc_ov_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym500_dc_ov_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym500_mim_err_mask & 0x1000)
    {
        ui->bym500_dc_oa_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym500_dc_oa_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym500_mim_err_mask & 0x0800)
    {
        ui->bym500_dc_ot_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym500_dc_ot_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym500_mim_err_mask & 0x0400)
    {
        ui->bym500_land_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym500_land_ckx->setCheckState(Qt::Unchecked);
    }


    if(bym500_mim_err_mask & 0x0200)
    {
        ui->bym500_mppt_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym500_mppt_ckx->setCheckState(Qt::Unchecked);
    }

    //后8位
    if(bym500_mim_err_mask & 0x0008)
    {
        ui->bym500_sync_error->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym500_sync_error->setCheckState(Qt::Unchecked);
    }

    if(bym500_mim_err_mask & 0x0004)
    {
        ui->bym500_safe_chain_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym500_safe_chain_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym500_mim_err_mask & 0x0002)
    {
        ui->bym500_grid_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym500_grid_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym500_mim_err_mask & 0x0001)
    {
        ui->bym500_off_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym500_off_ckx->setCheckState(Qt::Unchecked);
    }

    //副边故障
    if(bym500_mis_err_mask & 0x8000)
    {
        ui->bym500_grid_ov_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym500_grid_ov_ckx->setCheckState(Qt::Unchecked);
    }


    if(bym500_mis_err_mask & 0x4000)
    {
        ui->bym500_grid_uv_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym500_grid_uv_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym500_mis_err_mask & 0x2000)
    {
        ui->bym500_grid_of_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym500_grid_of_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym500_mis_err_mask & 0x1000)
    {
        ui->bym500_grid_uf_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym500_grid_uf_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym500_mis_err_mask & 0x0800)
    {
        ui->bym500_lock_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym500_lock_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym500_mis_err_mask & 0x0400)
    {
        ui->bym500_surge_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym500_surge_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym500_mis_err_mask & 0x0200)
    {
        ui->bym500_mcu_uv_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym500_mcu_uv_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym500_mis_err_mask & 0x0100)
    {
        ui->bym500_pv_uv_ckx_2->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym500_pv_uv_ckx_2->setCheckState(Qt::Unchecked);
    }

    //后8位
    if(bym500_mis_err_mask & 0x0080)
    {
        ui->bym500_hbd_oa_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym500_hbd_oa_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym500_mis_err_mask & 0x0040)
    {
        ui->bym500_hbd_ov_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym500_hbd_ov_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym500_mis_err_mask & 0x0004)
    {
        ui->bym500_cmu_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym500_cmu_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym500_mis_err_mask & 0x0002)
    {
        ui->bym500_gf_out_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym500_gf_out_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym500_mis_err_mask & 0x0001)
    {
        ui->bym500_gv_out_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym500_gv_out_ckx->setCheckState(Qt::Unchecked);
    }
//  bym550
    QJsonObject bym550_jsobj = def_data.value("bym550").toObject();

    ui->bym550_aging_offset_edt->setText(QString::number(bym550_jsobj.value("v_start_point_offset").toInt()));
    ui->bym550_ignore_max_edt->setText(QString::number(bym550_jsobj.value("ignore_points_max").toInt()));
    ui->bym550_drop_max_edt->setText(QString::number(bym550_jsobj.value("drop_points_max").toInt()));
    ui->bym550_drop_value_edt->setText(QString::number(bym550_jsobj.value("drop_value").toInt()));
    if(bym550_jsobj.value("v_aging_points").toInt() == -1)
    {
        ui->bym550_aging_num_ckx->setCheckState(Qt::Unchecked);
        ui->bym550_aging_num_edt->setText("");
    }
    else
    {
        ui->bym550_aging_num_ckx->setCheckState(Qt::Checked);
        ui->bym550_aging_num_edt->setText(QString::number(bym550_jsobj.value("v_aging_points").toInt()));
    }

    if(bym550_jsobj.value("v_aging_time").toInt() == -1)
    {
        ui->bym550_aging_time_ckx->setCheckState(Qt::Unchecked);
        ui->bym550_aging_time_edt->setText("");
    }
    else
    {
        ui->bym550_aging_time_ckx->setCheckState(Qt::Checked);
        ui->bym550_aging_time_edt->setText(QString::number(bym550_jsobj.value("v_aging_time").toInt()));
    }

    if(bym550_jsobj.value("v_rm40_pwmin").toInt() == -1)
    {
        ui->bym550_rt40_time_ckx->setCheckState(Qt::Unchecked);
        ui->bym550_rt40_time_edt->setText("");
    }
    else
    {
        ui->bym550_rt40_time_ckx->setCheckState(Qt::Checked);
        ui->bym550_rt40_time_edt->setText(QString::number(bym550_jsobj.value("v_rm40_pwmin").toInt()));
    }

    if(bym550_jsobj.value("v_rm40_tmax").toInt() == -1)
    {
        ui->bym550_t40_ckx->setCheckState(Qt::Unchecked);
        ui->bym550_t40_edt->setText("");
    }
    else
    {
        ui->bym550_t40_ckx->setCheckState(Qt::Checked);
        ui->bym550_t40_edt->setText(QString::number(bym550_jsobj.value("v_rm40_tmax").toInt()));
    }

    if(bym550_jsobj.value("v_rm45_pwmin").toInt() == -1)
    {
        ui->bym550_rt45_time_ckx->setCheckState(Qt::Unchecked);
        ui->bym550_rt45_time_edt->setText("");
    }
    else
    {
        ui->bym550_rt45_time_ckx->setCheckState(Qt::Checked);
        ui->bym550_rt45_time_edt->setText(QString::number(bym550_jsobj.value("v_rm45_pwmin").toInt()));
    }

    if(bym550_jsobj.value("v_rm45_tmax").toInt() == -1)
    {
        ui->bym550_t45_ckx->setCheckState(Qt::Unchecked);
        ui->bym550_t45_edt->setText("");
    }
    else
    {
        ui->bym550_t45_ckx->setCheckState(Qt::Checked);
        ui->bym550_t45_edt->setText(QString::number(bym550_jsobj.value("v_rm45_tmax").toInt()));
    }

    if(bym550_jsobj.value("v_rm50_pwmin").toInt() == -1)
    {
        ui->bym550_rt50_time_ckx->setCheckState(Qt::Unchecked);
        ui->bym550_rt50_time_edt->setText("");
    }
    else
    {
        ui->bym550_rt50_time_ckx->setCheckState(Qt::Checked);
        ui->bym550_rt50_time_edt->setText(QString::number(bym550_jsobj.value("v_rm50_pwmin").toInt()));
    }

    if(bym550_jsobj.value("v_rm50_tmax").toInt() == -1)
    {
        ui->bym550_t50_ckx->setCheckState(Qt::Unchecked);
        ui->bym550_t50_edt->setText("");
    }
    else
    {
        ui->bym550_t50_ckx->setCheckState(Qt::Checked);
        ui->bym550_t50_edt->setText(QString::number(bym550_jsobj.value("v_rm50_tmax").toInt()));
    }

    if(bym550_jsobj.value("v_rm55_pwmin").toInt() == -1)
    {
        ui->bym550_rt55_time_ckx->setCheckState(Qt::Unchecked);
        ui->bym550_rt55_time_edt->setText("");
    }
    else
    {
        ui->bym550_rt55_time_ckx->setCheckState(Qt::Checked);
        ui->bym550_rt55_time_edt->setText(QString::number(bym550_jsobj.value("v_rm55_pwmin").toInt()));
    }

    if(bym550_jsobj.value("v_rm55_tmax").toInt() == -1)
    {
        ui->bym550_t55_ckx->setCheckState(Qt::Unchecked);
        ui->bym550_t55_edt->setText("");
    }
    else
    {
        ui->bym550_t55_ckx->setCheckState(Qt::Checked);
        ui->bym550_t55_edt->setText(QString::number(bym550_jsobj.value("v_rm55_tmax").toInt()));
    }
    if(bym550_jsobj.value("v_rm60_pwmin").toInt() == -1)
    {
        ui->bym550_rt60_time_ckx->setCheckState(Qt::Unchecked);
        ui->bym550_rt60_time_edt->setText("");
    }
    else
    {
        ui->bym550_rt60_time_ckx->setCheckState(Qt::Checked);
        ui->bym550_rt60_time_edt->setText(QString::number(bym550_jsobj.value("v_rm60_pwmin").toInt()));
    }

    if(bym550_jsobj.value("v_rm60_tmax").toInt() == -1)
    {
        ui->bym550_t60_ckx->setCheckState(Qt::Unchecked);
        ui->bym550_t60_edt->setText("");
    }
    else
    {
        ui->bym550_t60_ckx->setCheckState(Qt::Checked);
        ui->bym550_t60_edt->setText(QString::number(bym550_jsobj.value("v_rm60_tmax").toInt()));
    }

    QJsonObject bym550_pv1_jsobj = bym550_jsobj.value("pv_params").toArray().at(0).toObject();
    if(bym550_pv1_jsobj.value("v_pv_rm40_pwmin").toInt() == -1)
    {
        ui->bym550_rt40_time_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym550_rt40_time_pv_edt->setText("");
    }
    else
    {
        ui->bym550_rt40_time_pv_ckx->setCheckState(Qt::Checked);
        ui->bym550_rt40_time_pv_edt->setText(QString::number(bym550_pv1_jsobj.value("v_pv_rm40_pwmin").toInt()));
    }

    if(bym550_pv1_jsobj.value("v_pv_rm40_tmax").toInt() == -1)
    {
        ui->bym550_t40_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym550_t40_pv_edt->setText("");
    }
    else
    {
        ui->bym550_t40_pv_ckx->setCheckState(Qt::Checked);
        ui->bym550_t40_pv_edt->setText(QString::number(bym550_pv1_jsobj.value("v_pv_rm40_tmax").toInt()));
    }

    if(bym550_pv1_jsobj.value("v_pv_rm45_pwmin").toInt() == -1)
    {
        ui->bym550_rt45_time_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym550_rt45_time_pv_edt->setText("");
    }
    else
    {
        ui->bym550_rt45_time_pv_ckx->setCheckState(Qt::Checked);
        ui->bym550_rt45_time_pv_edt->setText(QString::number(bym550_pv1_jsobj.value("v_pv_rm45_pwmin").toInt()));
    }

    if(bym550_pv1_jsobj.value("v_pv_rm45_tmax").toInt() == -1)
    {
        ui->bym550_t45_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym550_t45_pv_edt->setText("");
    }
    else
    {
        ui->bym550_t45_pv_ckx->setCheckState(Qt::Checked);
        ui->bym550_t45_pv_edt->setText(QString::number(bym550_pv1_jsobj.value("v_pv_rm45_tmax").toInt()));
    }

    if(bym550_pv1_jsobj.value("v_pv_rm50_pwmin").toInt() == -1)
    {
        ui->bym550_rt50_time_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym550_rt50_time_pv_edt->setText("");
    }
    else
    {
        ui->bym550_rt50_time_pv_ckx->setCheckState(Qt::Checked);
        ui->bym550_rt50_time_pv_edt->setText(QString::number(bym550_pv1_jsobj.value("v_pv_rm50_pwmin").toInt()));
    }

    if(bym550_pv1_jsobj.value("v_pv_rm50_tmax").toInt() == -1)
    {
        ui->bym550_t50_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym550_t50_pv_edt->setText("");
    }
    else
    {
        ui->bym550_t50_pv_ckx->setCheckState(Qt::Checked);
        ui->bym550_t50_pv_edt->setText(QString::number(bym550_pv1_jsobj.value("v_pv_rm50_tmax").toInt()));
    }

    if(bym550_pv1_jsobj.value("v_pv_rm55_pwmin").toInt() == -1)
    {
        ui->bym550_rt55_time_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym550_rt55_time_pv_edt->setText("");
    }
    else
    {
        ui->bym550_rt55_time_pv_ckx->setCheckState(Qt::Checked);
        ui->bym550_rt55_time_pv_edt->setText(QString::number(bym550_pv1_jsobj.value("v_pv_rm55_pwmin").toInt()));
    }

    if(bym550_pv1_jsobj.value("v_pv_rm55_tmax").toInt() == -1)
    {
        ui->bym550_t55_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym550_t55_pv_edt->setText("");
    }
    else
    {
        ui->bym550_t55_pv_ckx->setCheckState(Qt::Checked);
        ui->bym550_t55_pv_edt->setText(QString::number(bym550_pv1_jsobj.value("v_pv_rm55_tmax").toInt()));
    }
    if(bym550_pv1_jsobj.value("v_pv_rm60_pwmin").toInt() == -1)
    {
        ui->bym550_rt60_time_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym550_rt60_time_pv_edt->setText("");
    }
    else
    {
        ui->bym550_rt60_time_pv_ckx->setCheckState(Qt::Checked);
        ui->bym550_rt60_time_pv_edt->setText(QString::number(bym550_pv1_jsobj.value("v_pv_rm60_pwmin").toInt()));
    }

    if(bym550_pv1_jsobj.value("v_pv_rm60_tmax").toInt() == -1)
    {
        ui->bym550_t60_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym550_t60_pv_edt->setText("");
    }
    else
    {
        ui->bym550_t60_pv_ckx->setCheckState(Qt::Checked);
        ui->bym550_t60_pv_edt->setText(QString::number(bym550_jsobj.value("v_pv_rm60_tmax").toInt()));
    }
    int bym550_mim_err_mask = bym550_jsobj.value("mim1_err").toInt();
    int bym550_mis_err_mask = bym550_jsobj.value("mis_err").toInt();

    //原边故障
    if(bym550_mim_err_mask & 0x8000)
    {
        ui->bym550_pv_ov_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym550_pv_ov_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym550_mim_err_mask & 0x4000)
    {
        ui->bym550_pv_uv_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym550_pv_uv_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym550_mim_err_mask & 0x2000)
    {
        ui->bym550_dc_ov_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym550_dc_ov_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym550_mim_err_mask & 0x1000)
    {
        ui->bym550_dc_oa_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym550_dc_oa_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym550_mim_err_mask & 0x0800)
    {
        ui->bym550_dc_ot_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym550_dc_ot_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym550_mim_err_mask & 0x0400)
    {
        ui->bym550_land_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym550_land_ckx->setCheckState(Qt::Unchecked);
    }


    if(bym550_mim_err_mask & 0x0200)
    {
        ui->bym550_mppt_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym550_mppt_ckx->setCheckState(Qt::Unchecked);
    }

    //后8位
    if(bym550_mim_err_mask & 0x0008)
    {
        ui->bym550_sync_error->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym550_sync_error->setCheckState(Qt::Unchecked);
    }

    if(bym550_mim_err_mask & 0x0004)
    {
        ui->bym550_safe_chain_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym550_safe_chain_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym550_mim_err_mask & 0x0002)
    {
        ui->bym550_grid_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym550_grid_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym550_mim_err_mask & 0x0001)
    {
        ui->bym550_off_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym550_off_ckx->setCheckState(Qt::Unchecked);
    }

    //副边故障
    if(bym550_mis_err_mask & 0x8000)
    {
        ui->bym550_grid_ov_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym550_grid_ov_ckx->setCheckState(Qt::Unchecked);
    }


    if(bym550_mis_err_mask & 0x4000)
    {
        ui->bym550_grid_uv_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym550_grid_uv_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym550_mis_err_mask & 0x2000)
    {
        ui->bym550_grid_of_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym550_grid_of_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym550_mis_err_mask & 0x1000)
    {
        ui->bym550_grid_uf_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym550_grid_uf_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym550_mis_err_mask & 0x0800)
    {
        ui->bym550_lock_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym550_lock_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym550_mis_err_mask & 0x0400)
    {
        ui->bym550_surge_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym550_surge_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym550_mis_err_mask & 0x0200)
    {
        ui->bym550_mcu_uv_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym550_mcu_uv_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym550_mis_err_mask & 0x0100)
    {
        ui->bym550_pv_uv_ckx_2->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym550_pv_uv_ckx_2->setCheckState(Qt::Unchecked);
    }

    //后8位
    if(bym550_mis_err_mask & 0x0080)
    {
        ui->bym550_hbd_oa_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym550_hbd_oa_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym550_mis_err_mask & 0x0040)
    {
        ui->bym550_hbd_ov_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym550_hbd_ov_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym550_mis_err_mask & 0x0004)
    {
        ui->bym550_cmu_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym550_cmu_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym550_mis_err_mask & 0x0002)
    {
        ui->bym550_gf_out_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym550_gf_out_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym550_mis_err_mask & 0x0001)
    {
        ui->bym550_gv_out_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym550_gv_out_ckx->setCheckState(Qt::Unchecked);
    }

//  bym600
    QJsonObject bym600_jsobj = def_data.value("bym600").toObject();

    ui->bym600_aging_offset_edt->setText(QString::number(bym600_jsobj.value("v_start_point_offset").toInt()));
    ui->bym600_ignore_max_edt->setText(QString::number(bym600_jsobj.value("ignore_points_max").toInt()));
    ui->bym600_drop_max_edt->setText(QString::number(bym600_jsobj.value("drop_points_max").toInt()));
    ui->bym600_drop_value_edt->setText(QString::number(bym600_jsobj.value("drop_value").toInt()));
    if(bym600_jsobj.value("v_aging_points").toInt() == -1)
    {
        ui->bym600_aging_num_ckx->setCheckState(Qt::Unchecked);
        ui->bym600_aging_num_edt->setText("");
    }
    else
    {
        ui->bym600_aging_num_ckx->setCheckState(Qt::Checked);
        ui->bym600_aging_num_edt->setText(QString::number(bym600_jsobj.value("v_aging_points").toInt()));
    }

    if(bym600_jsobj.value("v_aging_time").toInt() == -1)
    {
        ui->bym600_aging_time_ckx->setCheckState(Qt::Unchecked);
        ui->bym600_aging_time_edt->setText("");
    }
    else
    {
        ui->bym600_aging_time_ckx->setCheckState(Qt::Checked);
        ui->bym600_aging_time_edt->setText(QString::number(bym600_jsobj.value("v_aging_time").toInt()));
    }

    if(bym600_jsobj.value("v_rm40_pwmin").toInt() == -1)
    {
        ui->bym600_rt40_time_ckx->setCheckState(Qt::Unchecked);
        ui->bym600_rt40_time_edt->setText("");
    }
    else
    {
        ui->bym600_rt40_time_ckx->setCheckState(Qt::Checked);
        ui->bym600_rt40_time_edt->setText(QString::number(bym600_jsobj.value("v_rm40_pwmin").toInt()));
    }

    if(bym600_jsobj.value("v_rm40_tmax").toInt() == -1)
    {
        ui->bym600_t40_ckx->setCheckState(Qt::Unchecked);
        ui->bym600_t40_edt->setText("");
    }
    else
    {
        ui->bym600_t40_ckx->setCheckState(Qt::Checked);
        ui->bym600_t40_edt->setText(QString::number(bym600_jsobj.value("v_rm40_tmax").toInt()));
    }

    if(bym600_jsobj.value("v_rm45_pwmin").toInt() == -1)
    {
        ui->bym600_rt45_time_ckx->setCheckState(Qt::Unchecked);
        ui->bym600_rt45_time_edt->setText("");
    }
    else
    {
        ui->bym600_rt45_time_ckx->setCheckState(Qt::Checked);
        ui->bym600_rt45_time_edt->setText(QString::number(bym600_jsobj.value("v_rm45_pwmin").toInt()));
    }

    if(bym600_jsobj.value("v_rm45_tmax").toInt() == -1)
    {
        ui->bym600_t45_ckx->setCheckState(Qt::Unchecked);
        ui->bym600_t45_edt->setText("");
    }
    else
    {
        ui->bym600_t45_ckx->setCheckState(Qt::Checked);
        ui->bym600_t45_edt->setText(QString::number(bym600_jsobj.value("v_rm45_tmax").toInt()));
    }

    if(bym600_jsobj.value("v_rm50_pwmin").toInt() == -1)
    {
        ui->bym600_rt50_time_ckx->setCheckState(Qt::Unchecked);
        ui->bym600_rt50_time_edt->setText("");
    }
    else
    {
        ui->bym600_rt50_time_ckx->setCheckState(Qt::Checked);
        ui->bym600_rt50_time_edt->setText(QString::number(bym600_jsobj.value("v_rm50_pwmin").toInt()));
    }

    if(bym600_jsobj.value("v_rm50_tmax").toInt() == -1)
    {
        ui->bym600_t50_ckx->setCheckState(Qt::Unchecked);
        ui->bym600_t50_edt->setText("");
    }
    else
    {
        ui->bym600_t50_ckx->setCheckState(Qt::Checked);
        ui->bym600_t50_edt->setText(QString::number(bym600_jsobj.value("v_rm50_tmax").toInt()));
    }

    if(bym600_jsobj.value("v_rm55_pwmin").toInt() == -1)
    {
        ui->bym600_rt55_time_ckx->setCheckState(Qt::Unchecked);
        ui->bym600_rt55_time_edt->setText("");
    }
    else
    {
        ui->bym600_rt55_time_ckx->setCheckState(Qt::Checked);
        ui->bym600_rt55_time_edt->setText(QString::number(bym600_jsobj.value("v_rm55_pwmin").toInt()));
    }

    if(bym600_jsobj.value("v_rm55_tmax").toInt() == -1)
    {
        ui->bym600_t55_ckx->setCheckState(Qt::Unchecked);
        ui->bym600_t55_edt->setText("");
    }
    else
    {
        ui->bym600_t55_ckx->setCheckState(Qt::Checked);
        ui->bym600_t55_edt->setText(QString::number(bym600_jsobj.value("v_rm55_tmax").toInt()));
    }
    if(bym600_jsobj.value("v_rm60_pwmin").toInt() == -1)
    {
        ui->bym600_rt60_time_ckx->setCheckState(Qt::Unchecked);
        ui->bym600_rt60_time_edt->setText("");
    }
    else
    {
        ui->bym600_rt60_time_ckx->setCheckState(Qt::Checked);
        ui->bym600_rt60_time_edt->setText(QString::number(bym600_jsobj.value("v_rm60_pwmin").toInt()));
    }

    if(bym600_jsobj.value("v_rm60_tmax").toInt() == -1)
    {
        ui->bym600_t60_ckx->setCheckState(Qt::Unchecked);
        ui->bym600_t60_edt->setText("");
    }
    else
    {
        ui->bym600_t60_ckx->setCheckState(Qt::Checked);
        ui->bym600_t60_edt->setText(QString::number(bym600_jsobj.value("v_rm60_tmax").toInt()));
    }

    QJsonObject bym600_pv1_jsobj = bym600_jsobj.value("pv_params").toArray().at(0).toObject();
    if(bym600_pv1_jsobj.value("v_pv_rm40_pwmin").toInt() == -1)
    {
        ui->bym600_rt40_time_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym600_rt40_time_pv_edt->setText("");
    }
    else
    {
        ui->bym600_rt40_time_pv_ckx->setCheckState(Qt::Checked);
        ui->bym600_rt40_time_pv_edt->setText(QString::number(bym600_pv1_jsobj.value("v_pv_rm40_pwmin").toInt()));
    }

    if(bym600_pv1_jsobj.value("v_pv_rm40_tmax").toInt() == -1)
    {
        ui->bym600_t40_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym600_t40_pv_edt->setText("");
    }
    else
    {
        ui->bym600_t40_pv_ckx->setCheckState(Qt::Checked);
        ui->bym600_t40_pv_edt->setText(QString::number(bym600_pv1_jsobj.value("v_pv_rm40_tmax").toInt()));
    }

    if(bym600_pv1_jsobj.value("v_pv_rm45_pwmin").toInt() == -1)
    {
        ui->bym600_rt45_time_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym600_rt45_time_pv_edt->setText("");
    }
    else
    {
        ui->bym600_rt45_time_pv_ckx->setCheckState(Qt::Checked);
        ui->bym600_rt45_time_pv_edt->setText(QString::number(bym600_pv1_jsobj.value("v_pv_rm45_pwmin").toInt()));
    }

    if(bym600_pv1_jsobj.value("v_pv_rm45_tmax").toInt() == -1)
    {
        ui->bym600_t45_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym600_t45_pv_edt->setText("");
    }
    else
    {
        ui->bym600_t45_pv_ckx->setCheckState(Qt::Checked);
        ui->bym600_t45_pv_edt->setText(QString::number(bym600_pv1_jsobj.value("v_pv_rm45_tmax").toInt()));
    }

    if(bym600_pv1_jsobj.value("v_pv_rm50_pwmin").toInt() == -1)
    {
        ui->bym600_rt50_time_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym600_rt50_time_pv_edt->setText("");
    }
    else
    {
        ui->bym600_rt50_time_pv_ckx->setCheckState(Qt::Checked);
        ui->bym600_rt50_time_pv_edt->setText(QString::number(bym600_pv1_jsobj.value("v_pv_rm50_pwmin").toInt()));
    }

    if(bym600_pv1_jsobj.value("v_pv_rm50_tmax").toInt() == -1)
    {
        ui->bym600_t50_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym600_t50_pv_edt->setText("");
    }
    else
    {
        ui->bym600_t50_pv_ckx->setCheckState(Qt::Checked);
        ui->bym600_t50_pv_edt->setText(QString::number(bym600_pv1_jsobj.value("v_pv_rm50_tmax").toInt()));
    }

    if(bym600_pv1_jsobj.value("v_pv_rm55_pwmin").toInt() == -1)
    {
        ui->bym600_rt55_time_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym600_rt55_time_pv_edt->setText("");
    }
    else
    {
        ui->bym600_rt55_time_pv_ckx->setCheckState(Qt::Checked);
        ui->bym600_rt55_time_pv_edt->setText(QString::number(bym600_pv1_jsobj.value("v_pv_rm55_pwmin").toInt()));
    }

    if(bym600_pv1_jsobj.value("v_pv_rm55_tmax").toInt() == -1)
    {
        ui->bym600_t55_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym600_t55_pv_edt->setText("");
    }
    else
    {
        ui->bym600_t55_pv_ckx->setCheckState(Qt::Checked);
        ui->bym600_t55_pv_edt->setText(QString::number(bym600_pv1_jsobj.value("v_pv_rm55_tmax").toInt()));
    }
    if(bym600_pv1_jsobj.value("v_pv_rm60_pwmin").toInt() == -1)
    {
        ui->bym600_rt60_time_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym600_rt60_time_pv_edt->setText("");
    }
    else
    {
        ui->bym600_rt60_time_pv_ckx->setCheckState(Qt::Checked);
        ui->bym600_rt60_time_pv_edt->setText(QString::number(bym600_pv1_jsobj.value("v_pv_rm60_pwmin").toInt()));
    }

    if(bym600_pv1_jsobj.value("v_pv_rm60_tmax").toInt() == -1)
    {
        ui->bym600_t60_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym600_t60_pv_edt->setText("");
    }
    else
    {
        ui->bym600_t60_pv_ckx->setCheckState(Qt::Checked);
        ui->bym600_t60_pv_edt->setText(QString::number(bym600_jsobj.value("v_pv_rm60_tmax").toInt()));
    }
    int bym600_mim_err_mask = bym600_jsobj.value("mim1_err").toInt();
    int bym600_mis_err_mask = bym600_jsobj.value("mis_err").toInt();

    //原边故障
    if(bym600_mim_err_mask & 0x8000)
    {
        ui->bym600_pv_ov_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym600_pv_ov_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym600_mim_err_mask & 0x4000)
    {
        ui->bym600_pv_uv_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym600_pv_uv_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym600_mim_err_mask & 0x2000)
    {
        ui->bym600_dc_ov_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym600_dc_ov_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym600_mim_err_mask & 0x1000)
    {
        ui->bym600_dc_oa_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym600_dc_oa_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym600_mim_err_mask & 0x0800)
    {
        ui->bym600_dc_ot_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym600_dc_ot_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym600_mim_err_mask & 0x0400)
    {
        ui->bym600_land_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym600_land_ckx->setCheckState(Qt::Unchecked);
    }


    if(bym600_mim_err_mask & 0x0200)
    {
        ui->bym600_mppt_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym600_mppt_ckx->setCheckState(Qt::Unchecked);
    }

    //后8位
    if(bym600_mim_err_mask & 0x0008)
    {
        ui->bym600_sync_error->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym600_sync_error->setCheckState(Qt::Unchecked);
    }

    if(bym600_mim_err_mask & 0x0004)
    {
        ui->bym600_safe_chain_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym600_safe_chain_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym600_mim_err_mask & 0x0002)
    {
        ui->bym600_grid_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym600_grid_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym600_mim_err_mask & 0x0001)
    {
        ui->bym600_off_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym600_off_ckx->setCheckState(Qt::Unchecked);
    }

    //副边故障
    if(bym600_mis_err_mask & 0x8000)
    {
        ui->bym600_grid_ov_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym600_grid_ov_ckx->setCheckState(Qt::Unchecked);
    }


    if(bym600_mis_err_mask & 0x4000)
    {
        ui->bym600_grid_uv_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym600_grid_uv_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym600_mis_err_mask & 0x2000)
    {
        ui->bym600_grid_of_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym600_grid_of_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym600_mis_err_mask & 0x1000)
    {
        ui->bym600_grid_uf_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym600_grid_uf_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym600_mis_err_mask & 0x0800)
    {
        ui->bym600_lock_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym600_lock_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym600_mis_err_mask & 0x0400)
    {
        ui->bym600_surge_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym600_surge_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym600_mis_err_mask & 0x0200)
    {
        ui->bym600_mcu_uv_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym600_mcu_uv_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym600_mis_err_mask & 0x0100)
    {
        ui->bym600_pv_uv_ckx_2->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym600_pv_uv_ckx_2->setCheckState(Qt::Unchecked);
    }

    //后8位
    if(bym600_mis_err_mask & 0x0080)
    {
        ui->bym600_hbd_oa_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym600_hbd_oa_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym600_mis_err_mask & 0x0040)
    {
        ui->bym600_hbd_ov_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym600_hbd_ov_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym600_mis_err_mask & 0x0004)
    {
        ui->bym600_cmu_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym600_cmu_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym600_mis_err_mask & 0x0002)
    {
        ui->bym600_gf_out_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym600_gf_out_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym600_mis_err_mask & 0x0001)
    {
        ui->bym600_gv_out_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym600_gv_out_ckx->setCheckState(Qt::Unchecked);
    }

//  bym700
    QJsonObject bym700_jsobj = def_data.value("bym700").toObject();

    ui->bym700_aging_offset_edt->setText(QString::number(bym700_jsobj.value("v_start_point_offset").toInt()));
    ui->bym700_ignore_max_edt->setText(QString::number(bym700_jsobj.value("ignore_points_max").toInt()));
    ui->bym700_drop_max_edt->setText(QString::number(bym700_jsobj.value("drop_points_max").toInt()));
    ui->bym700_drop_value_edt->setText(QString::number(bym700_jsobj.value("drop_value").toInt()));
    if(bym700_jsobj.value("v_aging_points").toInt() == -1)
    {
        ui->bym700_aging_num_ckx->setCheckState(Qt::Unchecked);
        ui->bym700_aging_num_edt->setText("");
    }
    else
    {
        ui->bym700_aging_num_ckx->setCheckState(Qt::Checked);
        ui->bym700_aging_num_edt->setText(QString::number(bym700_jsobj.value("v_aging_points").toInt()));
    }

    if(bym700_jsobj.value("v_aging_time").toInt() == -1)
    {
        ui->bym700_aging_time_ckx->setCheckState(Qt::Unchecked);
        ui->bym700_aging_time_edt->setText("");
    }
    else
    {
        ui->bym700_aging_time_ckx->setCheckState(Qt::Checked);
        ui->bym700_aging_time_edt->setText(QString::number(bym700_jsobj.value("v_aging_time").toInt()));
    }

    if(bym700_jsobj.value("v_rm40_pwmin").toInt() == -1)
    {
        ui->bym700_rt40_time_ckx->setCheckState(Qt::Unchecked);
        ui->bym700_rt40_time_edt->setText("");
    }
    else
    {
        ui->bym700_rt40_time_ckx->setCheckState(Qt::Checked);
        ui->bym700_rt40_time_edt->setText(QString::number(bym700_jsobj.value("v_rm40_pwmin").toInt()));
    }

    if(bym700_jsobj.value("v_rm40_tmax").toInt() == -1)
    {
        ui->bym700_t40_ckx->setCheckState(Qt::Unchecked);
        ui->bym700_t40_edt->setText("");
    }
    else
    {
        ui->bym700_t40_ckx->setCheckState(Qt::Checked);
        ui->bym700_t40_edt->setText(QString::number(bym700_jsobj.value("v_rm40_tmax").toInt()));
    }

    if(bym700_jsobj.value("v_rm45_pwmin").toInt() == -1)
    {
        ui->bym700_rt45_time_ckx->setCheckState(Qt::Unchecked);
        ui->bym700_rt45_time_edt->setText("");
    }
    else
    {
        ui->bym700_rt45_time_ckx->setCheckState(Qt::Checked);
        ui->bym700_rt45_time_edt->setText(QString::number(bym700_jsobj.value("v_rm45_pwmin").toInt()));
    }

    if(bym700_jsobj.value("v_rm45_tmax").toInt() == -1)
    {
        ui->bym700_t45_ckx->setCheckState(Qt::Unchecked);
        ui->bym700_t45_edt->setText("");
    }
    else
    {
        ui->bym700_t45_ckx->setCheckState(Qt::Checked);
        ui->bym700_t45_edt->setText(QString::number(bym700_jsobj.value("v_rm45_tmax").toInt()));
    }

    if(bym700_jsobj.value("v_rm50_pwmin").toInt() == -1)
    {
        ui->bym700_rt50_time_ckx->setCheckState(Qt::Unchecked);
        ui->bym700_rt50_time_edt->setText("");
    }
    else
    {
        ui->bym700_rt50_time_ckx->setCheckState(Qt::Checked);
        ui->bym700_rt50_time_edt->setText(QString::number(bym700_jsobj.value("v_rm50_pwmin").toInt()));
    }

    if(bym700_jsobj.value("v_rm50_tmax").toInt() == -1)
    {
        ui->bym700_t50_ckx->setCheckState(Qt::Unchecked);
        ui->bym700_t50_edt->setText("");
    }
    else
    {
        ui->bym700_t50_ckx->setCheckState(Qt::Checked);
        ui->bym700_t50_edt->setText(QString::number(bym700_jsobj.value("v_rm50_tmax").toInt()));
    }

    if(bym700_jsobj.value("v_rm55_pwmin").toInt() == -1)
    {
        ui->bym700_rt55_time_ckx->setCheckState(Qt::Unchecked);
        ui->bym700_rt55_time_edt->setText("");
    }
    else
    {
        ui->bym700_rt55_time_ckx->setCheckState(Qt::Checked);
        ui->bym700_rt55_time_edt->setText(QString::number(bym700_jsobj.value("v_rm55_pwmin").toInt()));
    }

    if(bym700_jsobj.value("v_rm55_tmax").toInt() == -1)
    {
        ui->bym700_t55_ckx->setCheckState(Qt::Unchecked);
        ui->bym700_t55_edt->setText("");
    }
    else
    {
        ui->bym700_t55_ckx->setCheckState(Qt::Checked);
        ui->bym700_t55_edt->setText(QString::number(bym700_jsobj.value("v_rm55_tmax").toInt()));
    }
    if(bym700_jsobj.value("v_rm60_pwmin").toInt() == -1)
    {
        ui->bym700_rt60_time_ckx->setCheckState(Qt::Unchecked);
        ui->bym700_rt60_time_edt->setText("");
    }
    else
    {
        ui->bym700_rt60_time_ckx->setCheckState(Qt::Checked);
        ui->bym700_rt60_time_edt->setText(QString::number(bym700_jsobj.value("v_rm60_pwmin").toInt()));
    }

    if(bym700_jsobj.value("v_rm60_tmax").toInt() == -1)
    {
        ui->bym700_t60_ckx->setCheckState(Qt::Unchecked);
        ui->bym700_t60_edt->setText("");
    }
    else
    {
        ui->bym700_t60_ckx->setCheckState(Qt::Checked);
        ui->bym700_t60_edt->setText(QString::number(bym700_jsobj.value("v_rm60_tmax").toInt()));
    }

    QJsonObject bym700_pv1_jsobj = bym700_jsobj.value("pv_params").toArray().at(0).toObject();
    if(bym700_pv1_jsobj.value("v_pv_rm40_pwmin").toInt() == -1)
    {
        ui->bym700_rt40_time_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym700_rt40_time_pv_edt->setText("");
    }
    else
    {
        ui->bym700_rt40_time_pv_ckx->setCheckState(Qt::Checked);
        ui->bym700_rt40_time_pv_edt->setText(QString::number(bym700_pv1_jsobj.value("v_pv_rm40_pwmin").toInt()));
    }

    if(bym700_pv1_jsobj.value("v_pv_rm40_tmax").toInt() == -1)
    {
        ui->bym700_t40_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym700_t40_pv_edt->setText("");
    }
    else
    {
        ui->bym700_t40_pv_ckx->setCheckState(Qt::Checked);
        ui->bym700_t40_pv_edt->setText(QString::number(bym700_pv1_jsobj.value("v_pv_rm40_tmax").toInt()));
    }

    if(bym700_pv1_jsobj.value("v_pv_rm45_pwmin").toInt() == -1)
    {
        ui->bym700_rt45_time_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym700_rt45_time_pv_edt->setText("");
    }
    else
    {
        ui->bym700_rt45_time_pv_ckx->setCheckState(Qt::Checked);
        ui->bym700_rt45_time_pv_edt->setText(QString::number(bym700_pv1_jsobj.value("v_pv_rm45_pwmin").toInt()));
    }

    if(bym700_pv1_jsobj.value("v_pv_rm45_tmax").toInt() == -1)
    {
        ui->bym700_t45_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym700_t45_pv_edt->setText("");
    }
    else
    {
        ui->bym700_t45_pv_ckx->setCheckState(Qt::Checked);
        ui->bym700_t45_pv_edt->setText(QString::number(bym700_pv1_jsobj.value("v_pv_rm45_tmax").toInt()));
    }

    if(bym700_pv1_jsobj.value("v_pv_rm50_pwmin").toInt() == -1)
    {
        ui->bym700_rt50_time_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym700_rt50_time_pv_edt->setText("");
    }
    else
    {
        ui->bym700_rt50_time_pv_ckx->setCheckState(Qt::Checked);
        ui->bym700_rt50_time_pv_edt->setText(QString::number(bym700_pv1_jsobj.value("v_pv_rm50_pwmin").toInt()));
    }

    if(bym700_pv1_jsobj.value("v_pv_rm50_tmax").toInt() == -1)
    {
        ui->bym700_t50_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym700_t50_pv_edt->setText("");
    }
    else
    {
        ui->bym700_t50_pv_ckx->setCheckState(Qt::Checked);
        ui->bym700_t50_pv_edt->setText(QString::number(bym700_pv1_jsobj.value("v_pv_rm50_tmax").toInt()));
    }

    if(bym700_pv1_jsobj.value("v_pv_rm55_pwmin").toInt() == -1)
    {
        ui->bym700_rt55_time_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym700_rt55_time_pv_edt->setText("");
    }
    else
    {
        ui->bym700_rt55_time_pv_ckx->setCheckState(Qt::Checked);
        ui->bym700_rt55_time_pv_edt->setText(QString::number(bym700_pv1_jsobj.value("v_pv_rm55_pwmin").toInt()));
    }

    if(bym700_pv1_jsobj.value("v_pv_rm55_tmax").toInt() == -1)
    {
        ui->bym700_t55_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym700_t55_pv_edt->setText("");
    }
    else
    {
        ui->bym700_t55_pv_ckx->setCheckState(Qt::Checked);
        ui->bym700_t55_pv_edt->setText(QString::number(bym700_pv1_jsobj.value("v_pv_rm55_tmax").toInt()));
    }
    if(bym700_pv1_jsobj.value("v_pv_rm60_pwmin").toInt() == -1)
    {
        ui->bym700_rt60_time_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym700_rt60_time_pv_edt->setText("");
    }
    else
    {
        ui->bym700_rt60_time_pv_ckx->setCheckState(Qt::Checked);
        ui->bym700_rt60_time_pv_edt->setText(QString::number(bym700_pv1_jsobj.value("v_pv_rm60_pwmin").toInt()));
    }

    if(bym700_pv1_jsobj.value("v_pv_rm60_tmax").toInt() == -1)
    {
        ui->bym700_t60_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym700_t60_pv_edt->setText("");
    }
    else
    {
        ui->bym700_t60_pv_ckx->setCheckState(Qt::Checked);
        ui->bym700_t60_pv_edt->setText(QString::number(bym700_jsobj.value("v_pv_rm60_tmax").toInt()));
    }
    int bym700_mim_err_mask = bym700_jsobj.value("mim1_err").toInt();
    int bym700_mis_err_mask = bym700_jsobj.value("mis_err").toInt();

    //原边故障
    if(bym700_mim_err_mask & 0x8000)
    {
        ui->bym700_pv_ov_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym700_pv_ov_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym700_mim_err_mask & 0x4000)
    {
        ui->bym700_pv_uv_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym700_pv_uv_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym700_mim_err_mask & 0x2000)
    {
        ui->bym700_dc_ov_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym700_dc_ov_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym700_mim_err_mask & 0x1000)
    {
        ui->bym700_dc_oa_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym700_dc_oa_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym700_mim_err_mask & 0x0800)
    {
        ui->bym700_dc_ot_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym700_dc_ot_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym700_mim_err_mask & 0x0400)
    {
        ui->bym700_land_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym700_land_ckx->setCheckState(Qt::Unchecked);
    }


    if(bym700_mim_err_mask & 0x0200)
    {
        ui->bym700_mppt_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym700_mppt_ckx->setCheckState(Qt::Unchecked);
    }

    //后8位
    if(bym700_mim_err_mask & 0x0008)
    {
        ui->bym700_sync_error->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym700_sync_error->setCheckState(Qt::Unchecked);
    }

    if(bym700_mim_err_mask & 0x0004)
    {
        ui->bym700_safe_chain_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym700_safe_chain_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym700_mim_err_mask & 0x0002)
    {
        ui->bym700_grid_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym700_grid_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym700_mim_err_mask & 0x0001)
    {
        ui->bym700_off_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym700_off_ckx->setCheckState(Qt::Unchecked);
    }

    //副边故障
    if(bym700_mis_err_mask & 0x8000)
    {
        ui->bym700_grid_ov_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym700_grid_ov_ckx->setCheckState(Qt::Unchecked);
    }


    if(bym700_mis_err_mask & 0x4000)
    {
        ui->bym700_grid_uv_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym700_grid_uv_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym700_mis_err_mask & 0x2000)
    {
        ui->bym700_grid_of_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym700_grid_of_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym700_mis_err_mask & 0x1000)
    {
        ui->bym700_grid_uf_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym700_grid_uf_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym700_mis_err_mask & 0x0800)
    {
        ui->bym700_lock_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym700_lock_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym700_mis_err_mask & 0x0400)
    {
        ui->bym700_surge_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym700_surge_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym700_mis_err_mask & 0x0200)
    {
        ui->bym700_mcu_uv_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym700_mcu_uv_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym700_mis_err_mask & 0x0100)
    {
        ui->bym700_pv_uv_ckx_2->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym700_pv_uv_ckx_2->setCheckState(Qt::Unchecked);
    }

    //后8位
    if(bym700_mis_err_mask & 0x0080)
    {
        ui->bym700_hbd_oa_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym700_hbd_oa_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym700_mis_err_mask & 0x0040)
    {
        ui->bym700_hbd_ov_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym700_hbd_ov_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym700_mis_err_mask & 0x0004)
    {
        ui->bym700_cmu_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym700_cmu_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym700_mis_err_mask & 0x0002)
    {
        ui->bym700_gf_out_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym700_gf_out_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym700_mis_err_mask & 0x0001)
    {
        ui->bym700_gv_out_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym700_gv_out_ckx->setCheckState(Qt::Unchecked);
    }

//  bym800
    QJsonObject bym800_jsobj = def_data.value("bym800").toObject();

    ui->bym800_aging_offset_edt->setText(QString::number(bym800_jsobj.value("v_start_point_offset").toInt()));
    ui->bym800_ignore_max_edt->setText(QString::number(bym800_jsobj.value("ignore_points_max").toInt()));
    ui->bym800_drop_max_edt->setText(QString::number(bym800_jsobj.value("drop_points_max").toInt()));
    ui->bym800_drop_value_edt->setText(QString::number(bym800_jsobj.value("drop_value").toInt()));
    if(bym800_jsobj.value("v_aging_points").toInt() == -1)
    {
        ui->bym800_aging_num_ckx->setCheckState(Qt::Unchecked);
        ui->bym800_aging_num_edt->setText("");
    }
    else
    {
        ui->bym800_aging_num_ckx->setCheckState(Qt::Checked);
        ui->bym800_aging_num_edt->setText(QString::number(bym800_jsobj.value("v_aging_points").toInt()));
    }

    if(bym800_jsobj.value("v_aging_time").toInt() == -1)
    {
        ui->bym800_aging_time_ckx->setCheckState(Qt::Unchecked);
        ui->bym800_aging_time_edt->setText("");
    }
    else
    {
        ui->bym800_aging_time_ckx->setCheckState(Qt::Checked);
        ui->bym800_aging_time_edt->setText(QString::number(bym800_jsobj.value("v_aging_time").toInt()));
    }

    if(bym800_jsobj.value("v_rm40_pwmin").toInt() == -1)
    {
        ui->bym800_rt40_time_ckx->setCheckState(Qt::Unchecked);
        ui->bym800_rt40_time_edt->setText("");
    }
    else
    {
        ui->bym800_rt40_time_ckx->setCheckState(Qt::Checked);
        ui->bym800_rt40_time_edt->setText(QString::number(bym800_jsobj.value("v_rm40_pwmin").toInt()));
    }

    if(bym800_jsobj.value("v_rm40_tmax").toInt() == -1)
    {
        ui->bym800_t40_ckx->setCheckState(Qt::Unchecked);
        ui->bym800_t40_edt->setText("");
    }
    else
    {
        ui->bym800_t40_ckx->setCheckState(Qt::Checked);
        ui->bym800_t40_edt->setText(QString::number(bym800_jsobj.value("v_rm40_tmax").toInt()));
    }

    if(bym800_jsobj.value("v_rm45_pwmin").toInt() == -1)
    {
        ui->bym800_rt45_time_ckx->setCheckState(Qt::Unchecked);
        ui->bym800_rt45_time_edt->setText("");
    }
    else
    {
        ui->bym800_rt45_time_ckx->setCheckState(Qt::Checked);
        ui->bym800_rt45_time_edt->setText(QString::number(bym800_jsobj.value("v_rm45_pwmin").toInt()));
    }

    if(bym800_jsobj.value("v_rm45_tmax").toInt() == -1)
    {
        ui->bym800_t45_ckx->setCheckState(Qt::Unchecked);
        ui->bym800_t45_edt->setText("");
    }
    else
    {
        ui->bym800_t45_ckx->setCheckState(Qt::Checked);
        ui->bym800_t45_edt->setText(QString::number(bym800_jsobj.value("v_rm45_tmax").toInt()));
    }

    if(bym800_jsobj.value("v_rm50_pwmin").toInt() == -1)
    {
        ui->bym800_rt50_time_ckx->setCheckState(Qt::Unchecked);
        ui->bym800_rt50_time_edt->setText("");
    }
    else
    {
        ui->bym800_rt50_time_ckx->setCheckState(Qt::Checked);
        ui->bym800_rt50_time_edt->setText(QString::number(bym800_jsobj.value("v_rm50_pwmin").toInt()));
    }

    if(bym800_jsobj.value("v_rm50_tmax").toInt() == -1)
    {
        ui->bym800_t50_ckx->setCheckState(Qt::Unchecked);
        ui->bym800_t50_edt->setText("");
    }
    else
    {
        ui->bym800_t50_ckx->setCheckState(Qt::Checked);
        ui->bym800_t50_edt->setText(QString::number(bym800_jsobj.value("v_rm50_tmax").toInt()));
    }

    if(bym800_jsobj.value("v_rm55_pwmin").toInt() == -1)
    {
        ui->bym800_rt55_time_ckx->setCheckState(Qt::Unchecked);
        ui->bym800_rt55_time_edt->setText("");
    }
    else
    {
        ui->bym800_rt55_time_ckx->setCheckState(Qt::Checked);
        ui->bym800_rt55_time_edt->setText(QString::number(bym800_jsobj.value("v_rm55_pwmin").toInt()));
    }

    if(bym800_jsobj.value("v_rm55_tmax").toInt() == -1)
    {
        ui->bym800_t55_ckx->setCheckState(Qt::Unchecked);
        ui->bym800_t55_edt->setText("");
    }
    else
    {
        ui->bym800_t55_ckx->setCheckState(Qt::Checked);
        ui->bym800_t55_edt->setText(QString::number(bym800_jsobj.value("v_rm55_tmax").toInt()));
    }
    if(bym800_jsobj.value("v_rm60_pwmin").toInt() == -1)
    {
        ui->bym800_rt60_time_ckx->setCheckState(Qt::Unchecked);
        ui->bym800_rt60_time_edt->setText("");
    }
    else
    {
        ui->bym800_rt60_time_ckx->setCheckState(Qt::Checked);
        ui->bym800_rt60_time_edt->setText(QString::number(bym800_jsobj.value("v_rm60_pwmin").toInt()));
    }

    if(bym800_jsobj.value("v_rm60_tmax").toInt() == -1)
    {
        ui->bym800_t60_ckx->setCheckState(Qt::Unchecked);
        ui->bym800_t60_edt->setText("");
    }
    else
    {
        ui->bym800_t60_ckx->setCheckState(Qt::Checked);
        ui->bym800_t60_edt->setText(QString::number(bym800_jsobj.value("v_rm60_tmax").toInt()));
    }

    QJsonObject bym800_pv1_jsobj = bym800_jsobj.value("pv_params").toArray().at(0).toObject();
    if(bym800_pv1_jsobj.value("v_pv_rm40_pwmin").toInt() == -1)
    {
        ui->bym800_rt40_time_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym800_rt40_time_pv_edt->setText("");
    }
    else
    {
        ui->bym800_rt40_time_pv_ckx->setCheckState(Qt::Checked);
        ui->bym800_rt40_time_pv_edt->setText(QString::number(bym800_pv1_jsobj.value("v_pv_rm40_pwmin").toInt()));
    }

    if(bym800_pv1_jsobj.value("v_pv_rm40_tmax").toInt() == -1)
    {
        ui->bym800_t40_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym800_t40_pv_edt->setText("");
    }
    else
    {
        ui->bym800_t40_pv_ckx->setCheckState(Qt::Checked);
        ui->bym800_t40_pv_edt->setText(QString::number(bym800_pv1_jsobj.value("v_pv_rm40_tmax").toInt()));
    }

    if(bym800_pv1_jsobj.value("v_pv_rm45_pwmin").toInt() == -1)
    {
        ui->bym800_rt45_time_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym800_rt45_time_pv_edt->setText("");
    }
    else
    {
        ui->bym800_rt45_time_pv_ckx->setCheckState(Qt::Checked);
        ui->bym800_rt45_time_pv_edt->setText(QString::number(bym800_pv1_jsobj.value("v_pv_rm45_pwmin").toInt()));
    }

    if(bym800_pv1_jsobj.value("v_pv_rm45_tmax").toInt() == -1)
    {
        ui->bym800_t45_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym800_t45_pv_edt->setText("");
    }
    else
    {
        ui->bym800_t45_pv_ckx->setCheckState(Qt::Checked);
        ui->bym800_t45_pv_edt->setText(QString::number(bym800_pv1_jsobj.value("v_pv_rm45_tmax").toInt()));
    }

    if(bym800_pv1_jsobj.value("v_pv_rm50_pwmin").toInt() == -1)
    {
        ui->bym800_rt50_time_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym800_rt50_time_pv_edt->setText("");
    }
    else
    {
        ui->bym800_rt50_time_pv_ckx->setCheckState(Qt::Checked);
        ui->bym800_rt50_time_pv_edt->setText(QString::number(bym800_pv1_jsobj.value("v_pv_rm50_pwmin").toInt()));
    }

    if(bym800_pv1_jsobj.value("v_pv_rm50_tmax").toInt() == -1)
    {
        ui->bym800_t50_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym800_t50_pv_edt->setText("");
    }
    else
    {
        ui->bym800_t50_pv_ckx->setCheckState(Qt::Checked);
        ui->bym800_t50_pv_edt->setText(QString::number(bym800_pv1_jsobj.value("v_pv_rm50_tmax").toInt()));
    }

    if(bym800_pv1_jsobj.value("v_pv_rm55_pwmin").toInt() == -1)
    {
        ui->bym800_rt55_time_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym800_rt55_time_pv_edt->setText("");
    }
    else
    {
        ui->bym800_rt55_time_pv_ckx->setCheckState(Qt::Checked);
        ui->bym800_rt55_time_pv_edt->setText(QString::number(bym800_pv1_jsobj.value("v_pv_rm55_pwmin").toInt()));
    }

    if(bym800_pv1_jsobj.value("v_pv_rm55_tmax").toInt() == -1)
    {
        ui->bym800_t55_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym800_t55_pv_edt->setText("");
    }
    else
    {
        ui->bym800_t55_pv_ckx->setCheckState(Qt::Checked);
        ui->bym800_t55_pv_edt->setText(QString::number(bym800_pv1_jsobj.value("v_pv_rm55_tmax").toInt()));
    }
    if(bym800_pv1_jsobj.value("v_pv_rm60_pwmin").toInt() == -1)
    {
        ui->bym800_rt60_time_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym800_rt60_time_pv_edt->setText("");
    }
    else
    {
        ui->bym800_rt60_time_pv_ckx->setCheckState(Qt::Checked);
        ui->bym800_rt60_time_pv_edt->setText(QString::number(bym800_pv1_jsobj.value("v_pv_rm60_pwmin").toInt()));
    }

    if(bym800_pv1_jsobj.value("v_pv_rm60_tmax").toInt() == -1)
    {
        ui->bym800_t60_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym800_t60_pv_edt->setText("");
    }
    else
    {
        ui->bym800_t60_pv_ckx->setCheckState(Qt::Checked);
        ui->bym800_t60_pv_edt->setText(QString::number(bym800_jsobj.value("v_pv_rm60_tmax").toInt()));
    }
    int bym800_mim_err_mask = bym800_jsobj.value("mim1_err").toInt();
    int bym800_mis_err_mask = bym800_jsobj.value("mis_err").toInt();

    //原边故障
    if(bym800_mim_err_mask & 0x8000)
    {
        ui->bym800_pv_ov_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym800_pv_ov_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym800_mim_err_mask & 0x4000)
    {
        ui->bym800_pv_uv_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym800_pv_uv_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym800_mim_err_mask & 0x2000)
    {
        ui->bym800_dc_ov_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym800_dc_ov_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym800_mim_err_mask & 0x1000)
    {
        ui->bym800_dc_oa_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym800_dc_oa_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym800_mim_err_mask & 0x0800)
    {
        ui->bym800_dc_ot_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym800_dc_ot_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym800_mim_err_mask & 0x0400)
    {
        ui->bym800_land_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym800_land_ckx->setCheckState(Qt::Unchecked);
    }


    if(bym800_mim_err_mask & 0x0200)
    {
        ui->bym800_mppt_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym800_mppt_ckx->setCheckState(Qt::Unchecked);
    }

    //后8位
    if(bym800_mim_err_mask & 0x0008)
    {
        ui->bym800_sync_error->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym800_sync_error->setCheckState(Qt::Unchecked);
    }

    if(bym800_mim_err_mask & 0x0004)
    {
        ui->bym800_safe_chain_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym800_safe_chain_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym800_mim_err_mask & 0x0002)
    {
        ui->bym800_grid_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym800_grid_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym800_mim_err_mask & 0x0001)
    {
        ui->bym800_off_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym800_off_ckx->setCheckState(Qt::Unchecked);
    }

    //副边故障
    if(bym800_mis_err_mask & 0x8000)
    {
        ui->bym800_grid_ov_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym800_grid_ov_ckx->setCheckState(Qt::Unchecked);
    }


    if(bym800_mis_err_mask & 0x4000)
    {
        ui->bym800_grid_uv_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym800_grid_uv_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym800_mis_err_mask & 0x2000)
    {
        ui->bym800_grid_of_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym800_grid_of_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym800_mis_err_mask & 0x1000)
    {
        ui->bym800_grid_uf_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym800_grid_uf_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym800_mis_err_mask & 0x0800)
    {
        ui->bym800_lock_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym800_lock_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym800_mis_err_mask & 0x0400)
    {
        ui->bym800_surge_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym800_surge_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym800_mis_err_mask & 0x0200)
    {
        ui->bym800_mcu_uv_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym800_mcu_uv_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym800_mis_err_mask & 0x0100)
    {
        ui->bym800_pv_uv_ckx_2->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym800_pv_uv_ckx_2->setCheckState(Qt::Unchecked);
    }

    //后8位
    if(bym800_mis_err_mask & 0x0080)
    {
        ui->bym800_hbd_oa_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym800_hbd_oa_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym800_mis_err_mask & 0x0040)
    {
        ui->bym800_hbd_ov_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym800_hbd_ov_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym800_mis_err_mask & 0x0004)
    {
        ui->bym800_cmu_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym800_cmu_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym800_mis_err_mask & 0x0002)
    {
        ui->bym800_gf_out_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym800_gf_out_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym800_mis_err_mask & 0x0001)
    {
        ui->bym800_gv_out_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym800_gv_out_ckx->setCheckState(Qt::Unchecked);
    }


//  bym1000
    QJsonObject bym1000_jsobj = def_data.value("bym1000").toObject();

    ui->bym1000_aging_offset_edt->setText(QString::number(bym1000_jsobj.value("v_start_point_offset").toInt()));
    ui->bym1000_ignore_max_edt->setText(QString::number(bym1000_jsobj.value("ignore_points_max").toInt()));
    ui->bym1000_drop_max_edt->setText(QString::number(bym1000_jsobj.value("drop_points_max").toInt()));
    ui->bym1000_drop_value_edt->setText(QString::number(bym1000_jsobj.value("drop_value").toInt()));
    if(bym1000_jsobj.value("v_aging_points").toInt() == -1)
    {
        ui->bym1000_aging_num_ckx->setCheckState(Qt::Unchecked);
        ui->bym1000_aging_num_edt->setText("");
    }
    else
    {
        ui->bym1000_aging_num_ckx->setCheckState(Qt::Checked);
        ui->bym1000_aging_num_edt->setText(QString::number(bym1000_jsobj.value("v_aging_points").toInt()));
    }

    if(bym1000_jsobj.value("v_aging_time").toInt() == -1)
    {
        ui->bym1000_aging_time_ckx->setCheckState(Qt::Unchecked);
        ui->bym1000_aging_time_edt->setText("");
    }
    else
    {
        ui->bym1000_aging_time_ckx->setCheckState(Qt::Checked);
        ui->bym1000_aging_time_edt->setText(QString::number(bym1000_jsobj.value("v_aging_time").toInt()));
    }

    if(bym1000_jsobj.value("v_rm40_pwmin").toInt() == -1)
    {
        ui->bym1000_rt40_time_ckx->setCheckState(Qt::Unchecked);
        ui->bym1000_rt40_time_edt->setText("");
    }
    else
    {
        ui->bym1000_rt40_time_ckx->setCheckState(Qt::Checked);
        ui->bym1000_rt40_time_edt->setText(QString::number(bym1000_jsobj.value("v_rm40_pwmin").toInt()));
    }

    if(bym1000_jsobj.value("v_rm40_tmax").toInt() == -1)
    {
        ui->bym1000_t40_ckx->setCheckState(Qt::Unchecked);
        ui->bym1000_t40_edt->setText("");
    }
    else
    {
        ui->bym1000_t40_ckx->setCheckState(Qt::Checked);
        ui->bym1000_t40_edt->setText(QString::number(bym1000_jsobj.value("v_rm40_tmax").toInt()));
    }

    if(bym1000_jsobj.value("v_rm45_pwmin").toInt() == -1)
    {
        ui->bym1000_rt45_time_ckx->setCheckState(Qt::Unchecked);
        ui->bym1000_rt45_time_edt->setText("");
    }
    else
    {
        ui->bym1000_rt45_time_ckx->setCheckState(Qt::Checked);
        ui->bym1000_rt45_time_edt->setText(QString::number(bym1000_jsobj.value("v_rm45_pwmin").toInt()));
    }

    if(bym1000_jsobj.value("v_rm45_tmax").toInt() == -1)
    {
        ui->bym1000_t45_ckx->setCheckState(Qt::Unchecked);
        ui->bym1000_t45_edt->setText("");
    }
    else
    {
        ui->bym1000_t45_ckx->setCheckState(Qt::Checked);
        ui->bym1000_t45_edt->setText(QString::number(bym1000_jsobj.value("v_rm45_tmax").toInt()));
    }

    if(bym1000_jsobj.value("v_rm50_pwmin").toInt() == -1)
    {
        ui->bym1000_rt50_time_ckx->setCheckState(Qt::Unchecked);
        ui->bym1000_rt50_time_edt->setText("");
    }
    else
    {
        ui->bym1000_rt50_time_ckx->setCheckState(Qt::Checked);
        ui->bym1000_rt50_time_edt->setText(QString::number(bym1000_jsobj.value("v_rm50_pwmin").toInt()));
    }

    if(bym1000_jsobj.value("v_rm50_tmax").toInt() == -1)
    {
        ui->bym1000_t50_ckx->setCheckState(Qt::Unchecked);
        ui->bym1000_t50_edt->setText("");
    }
    else
    {
        ui->bym1000_t50_ckx->setCheckState(Qt::Checked);
        ui->bym1000_t50_edt->setText(QString::number(bym1000_jsobj.value("v_rm50_tmax").toInt()));
    }

    if(bym1000_jsobj.value("v_rm55_pwmin").toInt() == -1)
    {
        ui->bym1000_rt55_time_ckx->setCheckState(Qt::Unchecked);
        ui->bym1000_rt55_time_edt->setText("");
    }
    else
    {
        ui->bym1000_rt55_time_ckx->setCheckState(Qt::Checked);
        ui->bym1000_rt55_time_edt->setText(QString::number(bym1000_jsobj.value("v_rm55_pwmin").toInt()));
    }

    if(bym1000_jsobj.value("v_rm55_tmax").toInt() == -1)
    {
        ui->bym1000_t55_ckx->setCheckState(Qt::Unchecked);
        ui->bym1000_t55_edt->setText("");
    }
    else
    {
        ui->bym1000_t55_ckx->setCheckState(Qt::Checked);
        ui->bym1000_t55_edt->setText(QString::number(bym1000_jsobj.value("v_rm55_tmax").toInt()));
    }
    if(bym1000_jsobj.value("v_rm60_pwmin").toInt() == -1)
    {
        ui->bym1000_rt60_time_ckx->setCheckState(Qt::Unchecked);
        ui->bym1000_rt60_time_edt->setText("");
    }
    else
    {
        ui->bym1000_rt60_time_ckx->setCheckState(Qt::Checked);
        ui->bym1000_rt60_time_edt->setText(QString::number(bym1000_jsobj.value("v_rm60_pwmin").toInt()));
    }

    if(bym1000_jsobj.value("v_rm60_tmax").toInt() == -1)
    {
        ui->bym1000_t60_ckx->setCheckState(Qt::Unchecked);
        ui->bym1000_t60_edt->setText("");
    }
    else
    {
        ui->bym1000_t60_ckx->setCheckState(Qt::Checked);
        ui->bym1000_t60_edt->setText(QString::number(bym1000_jsobj.value("v_rm60_tmax").toInt()));
    }
    //目前每路都共用一个pv参数
    QJsonObject bym1000_pv1_jsobj = bym1000_jsobj.value("pv_params").toArray().at(0).toObject();
    if(bym1000_pv1_jsobj.value("v_pv_rm40_pwmin").toInt() == -1)
    {
        ui->bym1000_rt40_time_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym1000_rt40_time_pv_edt->setText("");
    }
    else
    {
        ui->bym1000_rt40_time_pv_ckx->setCheckState(Qt::Checked);
        ui->bym1000_rt40_time_pv_edt->setText(QString::number(bym1000_pv1_jsobj.value("v_pv_rm40_pwmin").toInt()));
    }

    if(bym1000_pv1_jsobj.value("v_pv_rm40_tmax").toInt() == -1)
    {
        ui->bym1000_t40_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym1000_t40_pv_edt->setText("");
    }
    else
    {
        ui->bym1000_t40_pv_ckx->setCheckState(Qt::Checked);
        ui->bym1000_t40_pv_edt->setText(QString::number(bym1000_pv1_jsobj.value("v_pv_rm40_tmax").toInt()));
    }

    if(bym1000_pv1_jsobj.value("v_pv_rm45_pwmin").toInt() == -1)
    {
        ui->bym1000_rt45_time_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym1000_rt45_time_pv_edt->setText("");
    }
    else
    {
        ui->bym1000_rt45_time_pv_ckx->setCheckState(Qt::Checked);
        ui->bym1000_rt45_time_pv_edt->setText(QString::number(bym1000_pv1_jsobj.value("v_pv_rm45_pwmin").toInt()));
    }

    if(bym1000_pv1_jsobj.value("v_pv_rm45_tmax").toInt() == -1)
    {
        ui->bym1000_t45_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym1000_t45_pv_edt->setText("");
    }
    else
    {
        ui->bym1000_t45_pv_ckx->setCheckState(Qt::Checked);
        ui->bym1000_t45_pv_edt->setText(QString::number(bym1000_pv1_jsobj.value("v_pv_rm45_tmax").toInt()));
    }

    if(bym1000_pv1_jsobj.value("v_pv_rm50_pwmin").toInt() == -1)
    {
        ui->bym1000_rt50_time_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym1000_rt50_time_pv_edt->setText("");
    }
    else
    {
        ui->bym1000_rt50_time_pv_ckx->setCheckState(Qt::Checked);
        ui->bym1000_rt50_time_pv_edt->setText(QString::number(bym1000_pv1_jsobj.value("v_pv_rm50_pwmin").toInt()));
    }

    if(bym1000_pv1_jsobj.value("v_pv_rm50_tmax").toInt() == -1)
    {
        ui->bym1000_t50_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym1000_t50_pv_edt->setText("");
    }
    else
    {
        ui->bym1000_t50_pv_ckx->setCheckState(Qt::Checked);
        ui->bym1000_t50_pv_edt->setText(QString::number(bym1000_pv1_jsobj.value("v_pv_rm50_tmax").toInt()));
    }

    if(bym1000_pv1_jsobj.value("v_pv_rm55_pwmin").toInt() == -1)
    {
        ui->bym1000_rt55_time_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym1000_rt55_time_pv_edt->setText("");
    }
    else
    {
        ui->bym1000_rt55_time_pv_ckx->setCheckState(Qt::Checked);
        ui->bym1000_rt55_time_pv_edt->setText(QString::number(bym1000_pv1_jsobj.value("v_pv_rm55_pwmin").toInt()));
    }

    if(bym1000_pv1_jsobj.value("v_pv_rm55_tmax").toInt() == -1)
    {
        ui->bym1000_t55_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym1000_t55_pv_edt->setText("");
    }
    else
    {
        ui->bym1000_t55_pv_ckx->setCheckState(Qt::Checked);
        ui->bym1000_t55_pv_edt->setText(QString::number(bym1000_pv1_jsobj.value("v_pv_rm55_tmax").toInt()));
    }
    if(bym1000_pv1_jsobj.value("v_pv_rm60_pwmin").toInt() == -1)
    {
        ui->bym1000_rt60_time_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym1000_rt60_time_pv_edt->setText("");
    }
    else
    {
        ui->bym1000_rt60_time_pv_ckx->setCheckState(Qt::Checked);
        ui->bym1000_rt60_time_pv_edt->setText(QString::number(bym1000_pv1_jsobj.value("v_pv_rm60_pwmin").toInt()));
    }

    if(bym1000_pv1_jsobj.value("v_pv_rm60_tmax").toInt() == -1)
    {
        ui->bym1000_t60_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym1000_t60_pv_edt->setText("");
    }
    else
    {
        ui->bym1000_t60_pv_ckx->setCheckState(Qt::Checked);
        ui->bym1000_t60_pv_edt->setText(QString::number(bym1000_jsobj.value("v_pv_rm60_tmax").toInt()));
    }
    int bym1000_mim1_err_mask = bym1000_jsobj.value("mim1_err").toInt();
    int bym1000_mis_err_mask = bym1000_jsobj.value("mis_err").toInt();
    //int bym1000_mim2_err_mask = bym1000_jsobj.value("mim2_err").toInt();

    //原边故障pv12
    if(bym1000_mim1_err_mask & 0x8000)
    {
        ui->bym1000_pv_ov_bym4_pv1_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym1000_pv_ov_bym4_pv1_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym1000_mim1_err_mask & 0x4000)
    {
        ui->bym1000_pv_uv_bym4_pv1_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym1000_pv_uv_bym4_pv1_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym1000_mim1_err_mask & 0x1000)
    {
        ui->bym1000_dc_ov_bym4_pv1_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym1000_dc_ov_bym4_pv1_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym1000_mim1_err_mask & 0x1000)
    {
        ui->bym1000_dc_oa_bym4_pv1_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym1000_dc_oa_bym4_pv1_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym1000_mim1_err_mask & 0x0800)
    {
        ui->bym1000_dc_ot_bym4_pv1_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym1000_dc_ot_bym4_pv1_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym1000_mim1_err_mask & 0x0400)
    {
        ui->bym1000_land_bym4_pv12_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym1000_land_bym4_pv12_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym1000_mim1_err_mask & 0x0200)
    {
        ui->bym1000_mppt_bym4_pv12_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym1000_mppt_bym4_pv12_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym1000_mim1_err_mask & 0x0100)
    {
        ui->bym1000_dc_ot_bym4_pv2_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym1000_dc_ot_bym4_pv2_ckx->setCheckState(Qt::Unchecked);
    }


    if(bym1000_mim1_err_mask & 0x0080)
    {
        ui->bym1000_pv_ov_bym4_pv2_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym1000_pv_ov_bym4_pv2_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym1000_mim1_err_mask & 0x0040)
    {
        ui->bym1000_pv_uv_bym4_pv2_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym1000_pv_uv_bym4_pv2_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym1000_mim1_err_mask & 0x0020)
    {
        ui->bym1000_dc_ov_bym4_pv2_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym1000_dc_ov_bym4_pv2_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym1000_mim1_err_mask & 0x1000)
    {
        ui->bym1000_dc_oa_bym4_pv2_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym1000_dc_oa_bym4_pv2_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym1000_mim1_err_mask & 0x0008)
    {
        ui->bym1000_sync_error_bym4_pv12_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym1000_sync_error_bym4_pv12_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym1000_mim1_err_mask & 0x0004)
    {
        ui->bym1000_safe_chain_bym4_pv12_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym1000_safe_chain_bym4_pv12_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym1000_mim1_err_mask & 0x0002)
    {
        ui->bym1000_grid_bym4_pv12_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym1000_grid_bym4_pv12_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym1000_mim1_err_mask & 0x0001)
    {
        ui->bym1000_off_bym4_pv12_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym1000_off_bym4_pv12_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym1000_mis_err_mask & 0x8000)
    {
        ui->bym1000_grid_ov_bym4_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym1000_grid_ov_bym4_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym1000_mis_err_mask & 0x4000)
    {
        ui->bym1000_grid_uv_bym4_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym1000_grid_uv_bym4_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym1000_mis_err_mask & 0x2000)
    {
        ui->bym1000_grid_of_bym4_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym1000_grid_of_bym4_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym1000_mis_err_mask & 0x1000)
    {
        ui->bym1000_grid_uf_bym4_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym1000_grid_uf_bym4_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym1000_mis_err_mask & 0x0800)
    {
        ui->bym1000_lock_ckx_bym4_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym1000_lock_ckx_bym4_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym1000_mis_err_mask & 0x0400)
    {
        ui->bym1000_surge_bym4_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym1000_surge_bym4_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym1000_mis_err_mask & 0x0200)
    {
        ui->bym1000_mcu_uv_bym4_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym1000_mcu_uv_bym4_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym1000_mis_err_mask & 0x0100)
    {
        ui->bym1000_pv_uv_bym4_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym1000_pv_uv_bym4_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym1000_mis_err_mask & 0x0080)
    {
        ui->bym1000_hbd_oa_bym4_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym1000_hbd_oa_bym4_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym1000_mis_err_mask & 0x0040)
    {
        ui->bym1000_hbd_ov_bym4_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym1000_hbd_ov_bym4_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym1000_mis_err_mask & 0x0008)
    {
        ui->bym1000_cmu_primary2_bym4_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym1000_cmu_primary2_bym4_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym1000_mis_err_mask & 0x0004)
    {
        ui->bym1000_cmu_primary1_bym4_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym1000_cmu_primary1_bym4_ckx->setCheckState(Qt::Unchecked);
    }

//  bym1200
    QJsonObject bym1200_jsobj = def_data.value("bym1200").toObject();

    ui->bym1200_aging_offset_edt->setText(QString::number(bym1200_jsobj.value("v_start_point_offset").toInt()));
    ui->bym1200_ignore_max_edt->setText(QString::number(bym1200_jsobj.value("ignore_points_max").toInt()));
    ui->bym1200_drop_max_edt->setText(QString::number(bym1200_jsobj.value("drop_points_max").toInt()));
    ui->bym1200_drop_value_edt->setText(QString::number(bym1200_jsobj.value("drop_value").toInt()));
    if(bym1200_jsobj.value("v_aging_points").toInt() == -1)
    {
        ui->bym1200_aging_num_ckx->setCheckState(Qt::Unchecked);
        ui->bym1200_aging_num_edt->setText("");
    }
    else
    {
        ui->bym1200_aging_num_ckx->setCheckState(Qt::Checked);
        ui->bym1200_aging_num_edt->setText(QString::number(bym1200_jsobj.value("v_aging_points").toInt()));
    }

    if(bym1200_jsobj.value("v_aging_time").toInt() == -1)
    {
        ui->bym1200_aging_time_ckx->setCheckState(Qt::Unchecked);
        ui->bym1200_aging_time_edt->setText("");
    }
    else
    {
        ui->bym1200_aging_time_ckx->setCheckState(Qt::Checked);
        ui->bym1200_aging_time_edt->setText(QString::number(bym1200_jsobj.value("v_aging_time").toInt()));
    }

    if(bym1200_jsobj.value("v_rm40_pwmin").toInt() == -1)
    {
        ui->bym1200_rt40_time_ckx->setCheckState(Qt::Unchecked);
        ui->bym1200_rt40_time_edt->setText("");
    }
    else
    {
        ui->bym1200_rt40_time_ckx->setCheckState(Qt::Checked);
        ui->bym1200_rt40_time_edt->setText(QString::number(bym1200_jsobj.value("v_rm40_pwmin").toInt()));
    }

    if(bym1200_jsobj.value("v_rm40_tmax").toInt() == -1)
    {
        ui->bym1200_t40_ckx->setCheckState(Qt::Unchecked);
        ui->bym1200_t40_edt->setText("");
    }
    else
    {
        ui->bym1200_t40_ckx->setCheckState(Qt::Checked);
        ui->bym1200_t40_edt->setText(QString::number(bym1200_jsobj.value("v_rm40_tmax").toInt()));
    }

    if(bym1200_jsobj.value("v_rm45_pwmin").toInt() == -1)
    {
        ui->bym1200_rt45_time_ckx->setCheckState(Qt::Unchecked);
        ui->bym1200_rt45_time_edt->setText("");
    }
    else
    {
        ui->bym1200_rt45_time_ckx->setCheckState(Qt::Checked);
        ui->bym1200_rt45_time_edt->setText(QString::number(bym1200_jsobj.value("v_rm45_pwmin").toInt()));
    }

    if(bym1200_jsobj.value("v_rm45_tmax").toInt() == -1)
    {
        ui->bym1200_t45_ckx->setCheckState(Qt::Unchecked);
        ui->bym1200_t45_edt->setText("");
    }
    else
    {
        ui->bym1200_t45_ckx->setCheckState(Qt::Checked);
        ui->bym1200_t45_edt->setText(QString::number(bym1200_jsobj.value("v_rm45_tmax").toInt()));
    }

    if(bym1200_jsobj.value("v_rm50_pwmin").toInt() == -1)
    {
        ui->bym1200_rt50_time_ckx->setCheckState(Qt::Unchecked);
        ui->bym1200_rt50_time_edt->setText("");
    }
    else
    {
        ui->bym1200_rt50_time_ckx->setCheckState(Qt::Checked);
        ui->bym1200_rt50_time_edt->setText(QString::number(bym1200_jsobj.value("v_rm50_pwmin").toInt()));
    }

    if(bym1200_jsobj.value("v_rm50_tmax").toInt() == -1)
    {
        ui->bym1200_t50_ckx->setCheckState(Qt::Unchecked);
        ui->bym1200_t50_edt->setText("");
    }
    else
    {
        ui->bym1200_t50_ckx->setCheckState(Qt::Checked);
        ui->bym1200_t50_edt->setText(QString::number(bym1200_jsobj.value("v_rm50_tmax").toInt()));
    }

    if(bym1200_jsobj.value("v_rm55_pwmin").toInt() == -1)
    {
        ui->bym1200_rt55_time_ckx->setCheckState(Qt::Unchecked);
        ui->bym1200_rt55_time_edt->setText("");
    }
    else
    {
        ui->bym1200_rt55_time_ckx->setCheckState(Qt::Checked);
        ui->bym1200_rt55_time_edt->setText(QString::number(bym1200_jsobj.value("v_rm55_pwmin").toInt()));
    }

    if(bym1200_jsobj.value("v_rm55_tmax").toInt() == -1)
    {
        ui->bym1200_t55_ckx->setCheckState(Qt::Unchecked);
        ui->bym1200_t55_edt->setText("");
    }
    else
    {
        ui->bym1200_t55_ckx->setCheckState(Qt::Checked);
        ui->bym1200_t55_edt->setText(QString::number(bym1200_jsobj.value("v_rm55_tmax").toInt()));
    }
    if(bym1200_jsobj.value("v_rm60_pwmin").toInt() == -1)
    {
        ui->bym1200_rt60_time_ckx->setCheckState(Qt::Unchecked);
        ui->bym1200_rt60_time_edt->setText("");
    }
    else
    {
        ui->bym1200_rt60_time_ckx->setCheckState(Qt::Checked);
        ui->bym1200_rt60_time_edt->setText(QString::number(bym1200_jsobj.value("v_rm60_pwmin").toInt()));
    }

    if(bym1200_jsobj.value("v_rm60_tmax").toInt() == -1)
    {
        ui->bym1200_t60_ckx->setCheckState(Qt::Unchecked);
        ui->bym1200_t60_edt->setText("");
    }
    else
    {
        ui->bym1200_t60_ckx->setCheckState(Qt::Checked);
        ui->bym1200_t60_edt->setText(QString::number(bym1200_jsobj.value("v_rm60_tmax").toInt()));
    }
    //目前每路都共用一个pv参数
    QJsonObject bym1200_pv1_jsobj = bym1200_jsobj.value("pv_params").toArray().at(0).toObject();
    if(bym1200_pv1_jsobj.value("v_pv_rm40_pwmin").toInt() == -1)
    {
        ui->bym1200_rt40_time_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym1200_rt40_time_pv_edt->setText("");
    }
    else
    {
        ui->bym1200_rt40_time_pv_ckx->setCheckState(Qt::Checked);
        ui->bym1200_rt40_time_pv_edt->setText(QString::number(bym1200_pv1_jsobj.value("v_pv_rm40_pwmin").toInt()));
    }

    if(bym1200_pv1_jsobj.value("v_pv_rm40_tmax").toInt() == -1)
    {
        ui->bym1200_t40_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym1200_t40_pv_edt->setText("");
    }
    else
    {
        ui->bym1200_t40_pv_ckx->setCheckState(Qt::Checked);
        ui->bym1200_t40_pv_edt->setText(QString::number(bym1200_pv1_jsobj.value("v_pv_rm40_tmax").toInt()));
    }

    if(bym1200_pv1_jsobj.value("v_pv_rm45_pwmin").toInt() == -1)
    {
        ui->bym1200_rt45_time_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym1200_rt45_time_pv_edt->setText("");
    }
    else
    {
        ui->bym1200_rt45_time_pv_ckx->setCheckState(Qt::Checked);
        ui->bym1200_rt45_time_pv_edt->setText(QString::number(bym1200_pv1_jsobj.value("v_pv_rm45_pwmin").toInt()));
    }

    if(bym1200_pv1_jsobj.value("v_pv_rm45_tmax").toInt() == -1)
    {
        ui->bym1200_t45_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym1200_t45_pv_edt->setText("");
    }
    else
    {
        ui->bym1200_t45_pv_ckx->setCheckState(Qt::Checked);
        ui->bym1200_t45_pv_edt->setText(QString::number(bym1200_pv1_jsobj.value("v_pv_rm45_tmax").toInt()));
    }

    if(bym1200_pv1_jsobj.value("v_pv_rm50_pwmin").toInt() == -1)
    {
        ui->bym1200_rt50_time_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym1200_rt50_time_pv_edt->setText("");
    }
    else
    {
        ui->bym1200_rt50_time_pv_ckx->setCheckState(Qt::Checked);
        ui->bym1200_rt50_time_pv_edt->setText(QString::number(bym1200_pv1_jsobj.value("v_pv_rm50_pwmin").toInt()));
    }

    if(bym1200_pv1_jsobj.value("v_pv_rm50_tmax").toInt() == -1)
    {
        ui->bym1200_t50_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym1200_t50_pv_edt->setText("");
    }
    else
    {
        ui->bym1200_t50_pv_ckx->setCheckState(Qt::Checked);
        ui->bym1200_t50_pv_edt->setText(QString::number(bym1200_pv1_jsobj.value("v_pv_rm50_tmax").toInt()));
    }

    if(bym1200_pv1_jsobj.value("v_pv_rm55_pwmin").toInt() == -1)
    {
        ui->bym1200_rt55_time_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym1200_rt55_time_pv_edt->setText("");
    }
    else
    {
        ui->bym1200_rt55_time_pv_ckx->setCheckState(Qt::Checked);
        ui->bym1200_rt55_time_pv_edt->setText(QString::number(bym1200_pv1_jsobj.value("v_pv_rm55_pwmin").toInt()));
    }

    if(bym1200_pv1_jsobj.value("v_pv_rm55_tmax").toInt() == -1)
    {
        ui->bym1200_t55_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym1200_t55_pv_edt->setText("");
    }
    else
    {
        ui->bym1200_t55_pv_ckx->setCheckState(Qt::Checked);
        ui->bym1200_t55_pv_edt->setText(QString::number(bym1200_pv1_jsobj.value("v_pv_rm55_tmax").toInt()));
    }
    if(bym1200_pv1_jsobj.value("v_pv_rm60_pwmin").toInt() == -1)
    {
        ui->bym1200_rt60_time_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym1200_rt60_time_pv_edt->setText("");
    }
    else
    {
        ui->bym1200_rt60_time_pv_ckx->setCheckState(Qt::Checked);
        ui->bym1200_rt60_time_pv_edt->setText(QString::number(bym1200_pv1_jsobj.value("v_pv_rm60_pwmin").toInt()));
    }

    if(bym1200_pv1_jsobj.value("v_pv_rm60_tmax").toInt() == -1)
    {
        ui->bym1200_t60_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym1200_t60_pv_edt->setText("");
    }
    else
    {
        ui->bym1200_t60_pv_ckx->setCheckState(Qt::Checked);
        ui->bym1200_t60_pv_edt->setText(QString::number(bym1200_jsobj.value("v_pv_rm60_tmax").toInt()));
    }
    int bym1200_mim1_err_mask = bym1200_jsobj.value("mim1_err").toInt();
    int bym1200_mis_err_mask = bym1200_jsobj.value("mis_err").toInt();
    //int bym1200_mim2_err_mask = bym1200_jsobj.value("mim2_err").toInt();

    //原边故障pv12
    if(bym1200_mim1_err_mask & 0x8000)
    {
        ui->bym1200_pv_ov_bym4_pv1_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym1200_pv_ov_bym4_pv1_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym1200_mim1_err_mask & 0x4000)
    {
        ui->bym1200_pv_uv_bym4_pv1_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym1200_pv_uv_bym4_pv1_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym1200_mim1_err_mask & 0x1200)
    {
        ui->bym1200_dc_ov_bym4_pv1_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym1200_dc_ov_bym4_pv1_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym1200_mim1_err_mask & 0x1200)
    {
        ui->bym1200_dc_oa_bym4_pv1_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym1200_dc_oa_bym4_pv1_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym1200_mim1_err_mask & 0x0800)
    {
        ui->bym1200_dc_ot_bym4_pv1_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym1200_dc_ot_bym4_pv1_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym1200_mim1_err_mask & 0x0400)
    {
        ui->bym1200_land_bym4_pv12_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym1200_land_bym4_pv12_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym1200_mim1_err_mask & 0x0200)
    {
        ui->bym1200_mppt_bym4_pv12_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym1200_mppt_bym4_pv12_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym1200_mim1_err_mask & 0x0100)
    {
        ui->bym1200_dc_ot_bym4_pv2_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym1200_dc_ot_bym4_pv2_ckx->setCheckState(Qt::Unchecked);
    }


    if(bym1200_mim1_err_mask & 0x0080)
    {
        ui->bym1200_pv_ov_bym4_pv2_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym1200_pv_ov_bym4_pv2_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym1200_mim1_err_mask & 0x0040)
    {
        ui->bym1200_pv_uv_bym4_pv2_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym1200_pv_uv_bym4_pv2_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym1200_mim1_err_mask & 0x0020)
    {
        ui->bym1200_dc_ov_bym4_pv2_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym1200_dc_ov_bym4_pv2_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym1200_mim1_err_mask & 0x1200)
    {
        ui->bym1200_dc_oa_bym4_pv2_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym1200_dc_oa_bym4_pv2_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym1200_mim1_err_mask & 0x0008)
    {
        ui->bym1200_sync_error_bym4_pv12_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym1200_sync_error_bym4_pv12_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym1200_mim1_err_mask & 0x0004)
    {
        ui->bym1200_safe_chain_bym4_pv12_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym1200_safe_chain_bym4_pv12_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym1200_mim1_err_mask & 0x0002)
    {
        ui->bym1200_grid_bym4_pv12_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym1200_grid_bym4_pv12_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym1200_mim1_err_mask & 0x0001)
    {
        ui->bym1200_off_bym4_pv12_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym1200_off_bym4_pv12_ckx->setCheckState(Qt::Unchecked);
    }

    //副边故障
    if(bym1200_mis_err_mask & 0x8000)
    {
        ui->bym1200_grid_ov_bym4_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym1200_grid_ov_bym4_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym1200_mis_err_mask & 0x4000)
    {
        ui->bym1200_grid_uv_bym4_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym1200_grid_uv_bym4_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym1200_mis_err_mask & 0x1200)
    {
        ui->bym1200_grid_of_bym4_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym1200_grid_of_bym4_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym1200_mis_err_mask & 0x1200)
    {
        ui->bym1200_grid_uf_bym4_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym1200_grid_uf_bym4_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym1200_mis_err_mask & 0x0800)
    {
        ui->bym1200_lock_ckx_bym4_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym1200_lock_ckx_bym4_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym1200_mis_err_mask & 0x0400)
    {
        ui->bym1200_surge_bym4_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym1200_surge_bym4_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym1200_mis_err_mask & 0x0200)
    {
        ui->bym1200_mcu_uv_bym4_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym1200_mcu_uv_bym4_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym1200_mis_err_mask & 0x0100)
    {
        ui->bym1200_pv_uv_bym4_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym1200_pv_uv_bym4_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym1200_mis_err_mask & 0x0080)
    {
        ui->bym1200_hbd_oa_bym4_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym1200_hbd_oa_bym4_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym1200_mis_err_mask & 0x0040)
    {
        ui->bym1200_hbd_ov_bym4_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym1200_hbd_ov_bym4_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym1200_mis_err_mask & 0x0008)
    {
        ui->bym1200_cmu_primary2_bym4_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym1200_cmu_primary2_bym4_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym1200_mis_err_mask & 0x0004)
    {
        ui->bym1200_cmu_primary1_bym4_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym1200_cmu_primary1_bym4_ckx->setCheckState(Qt::Unchecked);
    }
    //副边故障
    if(bym1200_mis_err_mask & 0x8000)
    {
        ui->bym1200_grid_ov_bym4_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym1200_grid_ov_bym4_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym1200_mis_err_mask & 0x4000)
    {
        ui->bym1200_grid_uv_bym4_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym1200_grid_uv_bym4_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym1200_mis_err_mask & 0x1200)
    {
        ui->bym1200_grid_of_bym4_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym1200_grid_of_bym4_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym1200_mis_err_mask & 0x1200)
    {
        ui->bym1200_grid_uf_bym4_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym1200_grid_uf_bym4_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym1200_mis_err_mask & 0x0800)
    {
        ui->bym1200_lock_ckx_bym4_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym1200_lock_ckx_bym4_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym1200_mis_err_mask & 0x0400)
    {
        ui->bym1200_surge_bym4_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym1200_surge_bym4_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym1200_mis_err_mask & 0x0200)
    {
        ui->bym1200_mcu_uv_bym4_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym1200_mcu_uv_bym4_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym1200_mis_err_mask & 0x0100)
    {
        ui->bym1200_pv_uv_bym4_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym1200_pv_uv_bym4_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym1200_mis_err_mask & 0x0080)
    {
        ui->bym1200_hbd_oa_bym4_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym1200_hbd_oa_bym4_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym1200_mis_err_mask & 0x0040)
    {
        ui->bym1200_hbd_ov_bym4_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym1200_hbd_ov_bym4_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym1200_mis_err_mask & 0x0008)
    {
        ui->bym1200_cmu_primary2_bym4_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym1200_cmu_primary2_bym4_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym1200_mis_err_mask & 0x0004)
    {
        ui->bym1200_cmu_primary1_bym4_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym1200_cmu_primary1_bym4_ckx->setCheckState(Qt::Unchecked);
    }
//  bym2000
    QJsonObject bym2000_jsobj = def_data.value("bym2000").toObject();

    ui->bym2000_aging_offset_edt->setText(QString::number(bym2000_jsobj.value("v_start_point_offset").toInt()));
    ui->bym2000_ignore_max_edt->setText(QString::number(bym2000_jsobj.value("ignore_points_max").toInt()));
    ui->bym2000_drop_max_edt->setText(QString::number(bym2000_jsobj.value("drop_points_max").toInt()));
    ui->bym2000_drop_value_edt->setText(QString::number(bym2000_jsobj.value("drop_value").toInt()));
    if(bym2000_jsobj.value("v_aging_points").toInt() == -1)
    {
        ui->bym2000_aging_num_ckx->setCheckState(Qt::Unchecked);
        ui->bym2000_aging_num_edt->setText("");
    }
    else
    {
        ui->bym2000_aging_num_ckx->setCheckState(Qt::Checked);
        ui->bym2000_aging_num_edt->setText(QString::number(bym2000_jsobj.value("v_aging_points").toInt()));
    }

    if(bym2000_jsobj.value("v_aging_time").toInt() == -1)
    {
        ui->bym2000_aging_time_ckx->setCheckState(Qt::Unchecked);
        ui->bym2000_aging_time_edt->setText("");
    }
    else
    {
        ui->bym2000_aging_time_ckx->setCheckState(Qt::Checked);
        ui->bym2000_aging_time_edt->setText(QString::number(bym2000_jsobj.value("v_aging_time").toInt()));
    }

    if(bym2000_jsobj.value("v_rm40_pwmin").toInt() == -1)
    {
        ui->bym2000_rt40_time_ckx->setCheckState(Qt::Unchecked);
        ui->bym2000_rt40_time_edt->setText("");
    }
    else
    {
        ui->bym2000_rt40_time_ckx->setCheckState(Qt::Checked);
        ui->bym2000_rt40_time_edt->setText(QString::number(bym2000_jsobj.value("v_rm40_pwmin").toInt()));
    }

    if(bym2000_jsobj.value("v_rm40_tmax").toInt() == -1)
    {
        ui->bym2000_t40_ckx->setCheckState(Qt::Unchecked);
        ui->bym2000_t40_edt->setText("");
    }
    else
    {
        ui->bym2000_t40_ckx->setCheckState(Qt::Checked);
        ui->bym2000_t40_edt->setText(QString::number(bym2000_jsobj.value("v_rm40_tmax").toInt()));
    }

    if(bym2000_jsobj.value("v_rm45_pwmin").toInt() == -1)
    {
        ui->bym2000_rt45_time_ckx->setCheckState(Qt::Unchecked);
        ui->bym2000_rt45_time_edt->setText("");
    }
    else
    {
        ui->bym2000_rt45_time_ckx->setCheckState(Qt::Checked);
        ui->bym2000_rt45_time_edt->setText(QString::number(bym2000_jsobj.value("v_rm45_pwmin").toInt()));
    }

    if(bym2000_jsobj.value("v_rm45_tmax").toInt() == -1)
    {
        ui->bym2000_t45_ckx->setCheckState(Qt::Unchecked);
        ui->bym2000_t45_edt->setText("");
    }
    else
    {
        ui->bym2000_t45_ckx->setCheckState(Qt::Checked);
        ui->bym2000_t45_edt->setText(QString::number(bym2000_jsobj.value("v_rm45_tmax").toInt()));
    }

    if(bym2000_jsobj.value("v_rm50_pwmin").toInt() == -1)
    {
        ui->bym2000_rt50_time_ckx->setCheckState(Qt::Unchecked);
        ui->bym2000_rt50_time_edt->setText("");
    }
    else
    {
        ui->bym2000_rt50_time_ckx->setCheckState(Qt::Checked);
        ui->bym2000_rt50_time_edt->setText(QString::number(bym2000_jsobj.value("v_rm50_pwmin").toInt()));
    }

    if(bym2000_jsobj.value("v_rm50_tmax").toInt() == -1)
    {
        ui->bym2000_t50_ckx->setCheckState(Qt::Unchecked);
        ui->bym2000_t50_edt->setText("");
    }
    else
    {
        ui->bym2000_t50_ckx->setCheckState(Qt::Checked);
        ui->bym2000_t50_edt->setText(QString::number(bym2000_jsobj.value("v_rm50_tmax").toInt()));
    }

    if(bym2000_jsobj.value("v_rm55_pwmin").toInt() == -1)
    {
        ui->bym2000_rt55_time_ckx->setCheckState(Qt::Unchecked);
        ui->bym2000_rt55_time_edt->setText("");
    }
    else
    {
        ui->bym2000_rt55_time_ckx->setCheckState(Qt::Checked);
        ui->bym2000_rt55_time_edt->setText(QString::number(bym2000_jsobj.value("v_rm55_pwmin").toInt()));
    }

    if(bym2000_jsobj.value("v_rm55_tmax").toInt() == -1)
    {
        ui->bym2000_t55_ckx->setCheckState(Qt::Unchecked);
        ui->bym2000_t55_edt->setText("");
    }
    else
    {
        ui->bym2000_t55_ckx->setCheckState(Qt::Checked);
        ui->bym2000_t55_edt->setText(QString::number(bym2000_jsobj.value("v_rm55_tmax").toInt()));
    }
    if(bym2000_jsobj.value("v_rm60_pwmin").toInt() == -1)
    {
        ui->bym2000_rt60_time_ckx->setCheckState(Qt::Unchecked);
        ui->bym2000_rt60_time_edt->setText("");
    }
    else
    {
        ui->bym2000_rt60_time_ckx->setCheckState(Qt::Checked);
        ui->bym2000_rt60_time_edt->setText(QString::number(bym2000_jsobj.value("v_rm60_pwmin").toInt()));
    }

    if(bym2000_jsobj.value("v_rm60_tmax").toInt() == -1)
    {
        ui->bym2000_t60_ckx->setCheckState(Qt::Unchecked);
        ui->bym2000_t60_edt->setText("");
    }
    else
    {
        ui->bym2000_t60_ckx->setCheckState(Qt::Checked);
        ui->bym2000_t60_edt->setText(QString::number(bym2000_jsobj.value("v_rm60_tmax").toInt()));
    }
    //目前每路都共用一个pv参数
    QJsonObject bym2000_pv1_jsobj = bym2000_jsobj.value("pv_params").toArray().at(0).toObject();
    if(bym2000_pv1_jsobj.value("v_pv_rm40_pwmin").toInt() == -1)
    {
        ui->bym2000_rt40_time_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym2000_rt40_time_pv_edt->setText("");
    }
    else
    {
        ui->bym2000_rt40_time_pv_ckx->setCheckState(Qt::Checked);
        ui->bym2000_rt40_time_pv_edt->setText(QString::number(bym2000_pv1_jsobj.value("v_pv_rm40_pwmin").toInt()));
    }

    if(bym2000_pv1_jsobj.value("v_pv_rm40_tmax").toInt() == -1)
    {
        ui->bym2000_t40_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym2000_t40_pv_edt->setText("");
    }
    else
    {
        ui->bym2000_t40_pv_ckx->setCheckState(Qt::Checked);
        ui->bym2000_t40_pv_edt->setText(QString::number(bym2000_pv1_jsobj.value("v_pv_rm40_tmax").toInt()));
    }

    if(bym2000_pv1_jsobj.value("v_pv_rm45_pwmin").toInt() == -1)
    {
        ui->bym2000_rt45_time_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym2000_rt45_time_pv_edt->setText("");
    }
    else
    {
        ui->bym2000_rt45_time_pv_ckx->setCheckState(Qt::Checked);
        ui->bym2000_rt45_time_pv_edt->setText(QString::number(bym2000_pv1_jsobj.value("v_pv_rm45_pwmin").toInt()));
    }

    if(bym2000_pv1_jsobj.value("v_pv_rm45_tmax").toInt() == -1)
    {
        ui->bym2000_t45_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym2000_t45_pv_edt->setText("");
    }
    else
    {
        ui->bym2000_t45_pv_ckx->setCheckState(Qt::Checked);
        ui->bym2000_t45_pv_edt->setText(QString::number(bym2000_pv1_jsobj.value("v_pv_rm45_tmax").toInt()));
    }

    if(bym2000_pv1_jsobj.value("v_pv_rm50_pwmin").toInt() == -1)
    {
        ui->bym2000_rt50_time_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym2000_rt50_time_pv_edt->setText("");
    }
    else
    {
        ui->bym2000_rt50_time_pv_ckx->setCheckState(Qt::Checked);
        ui->bym2000_rt50_time_pv_edt->setText(QString::number(bym2000_pv1_jsobj.value("v_pv_rm50_pwmin").toInt()));
    }

    if(bym2000_pv1_jsobj.value("v_pv_rm50_tmax").toInt() == -1)
    {
        ui->bym2000_t50_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym2000_t50_pv_edt->setText("");
    }
    else
    {
        ui->bym2000_t50_pv_ckx->setCheckState(Qt::Checked);
        ui->bym2000_t50_pv_edt->setText(QString::number(bym2000_pv1_jsobj.value("v_pv_rm50_tmax").toInt()));
    }

    if(bym2000_pv1_jsobj.value("v_pv_rm55_pwmin").toInt() == -1)
    {
        ui->bym2000_rt55_time_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym2000_rt55_time_pv_edt->setText("");
    }
    else
    {
        ui->bym2000_rt55_time_pv_ckx->setCheckState(Qt::Checked);
        ui->bym2000_rt55_time_pv_edt->setText(QString::number(bym2000_pv1_jsobj.value("v_pv_rm55_pwmin").toInt()));
    }

    if(bym2000_pv1_jsobj.value("v_pv_rm55_tmax").toInt() == -1)
    {
        ui->bym2000_t55_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym2000_t55_pv_edt->setText("");
    }
    else
    {
        ui->bym2000_t55_pv_ckx->setCheckState(Qt::Checked);
        ui->bym2000_t55_pv_edt->setText(QString::number(bym2000_pv1_jsobj.value("v_pv_rm55_tmax").toInt()));
    }
    if(bym2000_pv1_jsobj.value("v_pv_rm60_pwmin").toInt() == -1)
    {
        ui->bym2000_rt60_time_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym2000_rt60_time_pv_edt->setText("");
    }
    else
    {
        ui->bym2000_rt60_time_pv_ckx->setCheckState(Qt::Checked);
        ui->bym2000_rt60_time_pv_edt->setText(QString::number(bym2000_pv1_jsobj.value("v_pv_rm60_pwmin").toInt()));
    }

    if(bym2000_pv1_jsobj.value("v_pv_rm60_tmax").toInt() == -1)
    {
        ui->bym2000_t60_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym2000_t60_pv_edt->setText("");
    }
    else
    {
        ui->bym2000_t60_pv_ckx->setCheckState(Qt::Checked);
        ui->bym2000_t60_pv_edt->setText(QString::number(bym2000_jsobj.value("v_pv_rm60_tmax").toInt()));
    }
    int bym2000_mim1_err_mask = bym2000_jsobj.value("mim1_err").toInt();
    int bym2000_mis_err_mask = bym2000_jsobj.value("mis_err").toInt();
    int bym2000_mim2_err_mask = bym2000_jsobj.value("mim2_err").toInt();

    //原边故障pv12
    if(bym2000_mim1_err_mask & 0x8000)
    {
        ui->bym2000_pv_ov_bym4_pv1_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2000_pv_ov_bym4_pv1_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym2000_mim1_err_mask & 0x4000)
    {
        ui->bym2000_pv_uv_bym4_pv1_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2000_pv_uv_bym4_pv1_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym2000_mim1_err_mask & 0x2000)
    {
        ui->bym2000_dc_ov_bym4_pv1_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2000_dc_ov_bym4_pv1_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym2000_mim1_err_mask & 0x1000)
    {
        ui->bym2000_dc_oa_bym4_pv1_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2000_dc_oa_bym4_pv1_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym2000_mim1_err_mask & 0x0800)
    {
        ui->bym2000_dc_ot_bym4_pv1_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2000_dc_ot_bym4_pv1_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym2000_mim1_err_mask & 0x0400)
    {
        ui->bym2000_land_bym4_pv12_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2000_land_bym4_pv12_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym2000_mim1_err_mask & 0x0200)
    {
        ui->bym2000_mppt_bym4_pv12_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2000_mppt_bym4_pv12_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym2000_mim1_err_mask & 0x0100)
    {
        ui->bym2000_dc_ot_bym4_pv2_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2000_dc_ot_bym4_pv2_ckx->setCheckState(Qt::Unchecked);
    }


    if(bym2000_mim1_err_mask & 0x0080)
    {
        ui->bym2000_pv_ov_bym4_pv2_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2000_pv_ov_bym4_pv2_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym2000_mim1_err_mask & 0x0040)
    {
        ui->bym2000_pv_uv_bym4_pv2_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2000_pv_uv_bym4_pv2_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym2000_mim1_err_mask & 0x0020)
    {
        ui->bym2000_dc_ov_bym4_pv2_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2000_dc_ov_bym4_pv2_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym2000_mim1_err_mask & 0x1000)
    {
        ui->bym2000_dc_oa_bym4_pv2_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2000_dc_oa_bym4_pv2_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym2000_mim1_err_mask & 0x0008)
    {
        ui->bym2000_sync_error_bym4_pv12_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2000_sync_error_bym4_pv12_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym2000_mim1_err_mask & 0x0004)
    {
        ui->bym2000_safe_chain_bym4_pv12_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2000_safe_chain_bym4_pv12_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym2000_mim1_err_mask & 0x0002)
    {
        ui->bym2000_grid_bym4_pv12_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2000_grid_bym4_pv12_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym2000_mim1_err_mask & 0x0001)
    {
        ui->bym2000_off_bym4_pv12_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2000_off_bym4_pv12_ckx->setCheckState(Qt::Unchecked);
    }
    //原边故障pv34
    if(bym2000_mim2_err_mask & 0x8000)
    {
        ui->bym2000_pv_ov_bym4_pv3_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2000_pv_ov_bym4_pv3_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym2000_mim2_err_mask & 0x4000)
    {
        ui->bym2000_pv_uv_bym4_pv3_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2000_pv_uv_bym4_pv3_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym2000_mim2_err_mask & 0x2000)
    {
        ui->bym2000_dc_ov_bym4_pv3_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2000_dc_ov_bym4_pv3_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym2000_mim2_err_mask & 0x1000)
    {
        ui->bym2000_dc_oa_bym4_pv3_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2000_dc_oa_bym4_pv3_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym2000_mim2_err_mask & 0x0800)
    {
        ui->bym2000_dc_ot_bym4_pv3_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2000_dc_ot_bym4_pv3_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym2000_mim2_err_mask & 0x0400)
    {
        ui->bym2000_land_bym4_pv34_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2000_land_bym4_pv34_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym2000_mim2_err_mask & 0x0200)
    {
        ui->bym2000_mppt_bym4_pv34_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2000_mppt_bym4_pv34_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym2000_mim2_err_mask & 0x0100)
    {
        ui->bym2000_dc_ot_bym4_pv4_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2000_dc_ot_bym4_pv4_ckx->setCheckState(Qt::Unchecked);
    }


    if(bym2000_mim2_err_mask & 0x0080)
    {
        ui->bym2000_pv_ov_bym4_pv4_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2000_pv_ov_bym4_pv4_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym2000_mim2_err_mask & 0x0040)
    {
        ui->bym2000_pv_uv_bym4_pv4_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2000_pv_uv_bym4_pv4_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym2000_mim2_err_mask & 0x0020)
    {
        ui->bym2000_dc_ov_bym4_pv4_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2000_dc_ov_bym4_pv4_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym2000_mim2_err_mask & 0x1000)
    {
        ui->bym2000_dc_oa_bym4_pv4_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2000_dc_oa_bym4_pv4_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym2000_mim2_err_mask & 0x0008)
    {
        ui->bym2000_sync_error_bym4_pv34_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2000_sync_error_bym4_pv34_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym2000_mim2_err_mask & 0x0004)
    {
        ui->bym2000_safe_chain_bym4_pv34_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2000_safe_chain_bym4_pv34_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym2000_mim2_err_mask & 0x0002)
    {
        ui->bym2000_grid_bym4_pv34_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2000_grid_bym4_pv34_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym2000_mim2_err_mask & 0x0001)
    {
        ui->bym2000_off_bym4_pv34_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2000_off_bym4_pv34_ckx->setCheckState(Qt::Unchecked);
    }



    //副边故障
    if(bym2000_mis_err_mask & 0x8000)
    {
        ui->bym2000_grid_ov_bym4_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2000_grid_ov_bym4_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym2000_mis_err_mask & 0x4000)
    {
        ui->bym2000_grid_uv_bym4_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2000_grid_uv_bym4_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym2000_mis_err_mask & 0x2000)
    {
        ui->bym2000_grid_of_bym4_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2000_grid_of_bym4_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym2000_mis_err_mask & 0x1000)
    {
        ui->bym2000_grid_uf_bym4_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2000_grid_uf_bym4_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym2000_mis_err_mask & 0x0800)
    {
        ui->bym2000_lock_ckx_bym4_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2000_lock_ckx_bym4_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym2000_mis_err_mask & 0x0400)
    {
        ui->bym2000_surge_bym4_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2000_surge_bym4_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym2000_mis_err_mask & 0x0200)
    {
        ui->bym2000_mcu_uv_bym4_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2000_mcu_uv_bym4_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym2000_mis_err_mask & 0x0100)
    {
        ui->bym2000_pv_uv_bym4_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2000_pv_uv_bym4_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym2000_mis_err_mask & 0x0080)
    {
        ui->bym2000_hbd_oa_bym4_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2000_hbd_oa_bym4_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym2000_mis_err_mask & 0x0040)
    {
        ui->bym2000_hbd_ov_bym4_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2000_hbd_ov_bym4_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym2000_mis_err_mask & 0x0008)
    {
        ui->bym2000_cmu_primary2_bym4_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2000_cmu_primary2_bym4_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym2000_mis_err_mask & 0x0004)
    {
        ui->bym2000_cmu_primary1_bym4_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2000_cmu_primary1_bym4_ckx->setCheckState(Qt::Unchecked);
    }

//  bym2400
    QJsonObject bym2400_jsobj = def_data.value("bym2400").toObject();

    ui->bym2400_aging_offset_edt->setText(QString::number(bym2400_jsobj.value("v_start_point_offset").toInt()));
    ui->bym2400_ignore_max_edt->setText(QString::number(bym2400_jsobj.value("ignore_points_max").toInt()));
    ui->bym2400_drop_max_edt->setText(QString::number(bym2400_jsobj.value("drop_points_max").toInt()));
    ui->bym2400_drop_value_edt->setText(QString::number(bym2400_jsobj.value("drop_value").toInt()));
    if(bym2400_jsobj.value("v_aging_points").toInt() == -1)
    {
        ui->bym2400_aging_num_ckx->setCheckState(Qt::Unchecked);
        ui->bym2400_aging_num_edt->setText("");
    }
    else
    {
        ui->bym2400_aging_num_ckx->setCheckState(Qt::Checked);
        ui->bym2400_aging_num_edt->setText(QString::number(bym2400_jsobj.value("v_aging_points").toInt()));
    }

    if(bym2400_jsobj.value("v_aging_time").toInt() == -1)
    {
        ui->bym2400_aging_time_ckx->setCheckState(Qt::Unchecked);
        ui->bym2400_aging_time_edt->setText("");
    }
    else
    {
        ui->bym2400_aging_time_ckx->setCheckState(Qt::Checked);
        ui->bym2400_aging_time_edt->setText(QString::number(bym2400_jsobj.value("v_aging_time").toInt()));
    }

    if(bym2400_jsobj.value("v_rm40_pwmin").toInt() == -1)
    {
        ui->bym2400_rt40_time_ckx->setCheckState(Qt::Unchecked);
        ui->bym2400_rt40_time_edt->setText("");
    }
    else
    {
        ui->bym2400_rt40_time_ckx->setCheckState(Qt::Checked);
        ui->bym2400_rt40_time_edt->setText(QString::number(bym2400_jsobj.value("v_rm40_pwmin").toInt()));
    }

    if(bym2400_jsobj.value("v_rm40_tmax").toInt() == -1)
    {
        ui->bym2400_t40_ckx->setCheckState(Qt::Unchecked);
        ui->bym2400_t40_edt->setText("");
    }
    else
    {
        ui->bym2400_t40_ckx->setCheckState(Qt::Checked);
        ui->bym2400_t40_edt->setText(QString::number(bym2400_jsobj.value("v_rm40_tmax").toInt()));
    }

    if(bym2400_jsobj.value("v_rm45_pwmin").toInt() == -1)
    {
        ui->bym2400_rt45_time_ckx->setCheckState(Qt::Unchecked);
        ui->bym2400_rt45_time_edt->setText("");
    }
    else
    {
        ui->bym2400_rt45_time_ckx->setCheckState(Qt::Checked);
        ui->bym2400_rt45_time_edt->setText(QString::number(bym2400_jsobj.value("v_rm45_pwmin").toInt()));
    }

    if(bym2400_jsobj.value("v_rm45_tmax").toInt() == -1)
    {
        ui->bym2400_t45_ckx->setCheckState(Qt::Unchecked);
        ui->bym2400_t45_edt->setText("");
    }
    else
    {
        ui->bym2400_t45_ckx->setCheckState(Qt::Checked);
        ui->bym2400_t45_edt->setText(QString::number(bym2400_jsobj.value("v_rm45_tmax").toInt()));
    }

    if(bym2400_jsobj.value("v_rm50_pwmin").toInt() == -1)
    {
        ui->bym2400_rt50_time_ckx->setCheckState(Qt::Unchecked);
        ui->bym2400_rt50_time_edt->setText("");
    }
    else
    {
        ui->bym2400_rt50_time_ckx->setCheckState(Qt::Checked);
        ui->bym2400_rt50_time_edt->setText(QString::number(bym2400_jsobj.value("v_rm50_pwmin").toInt()));
    }

    if(bym2400_jsobj.value("v_rm50_tmax").toInt() == -1)
    {
        ui->bym2400_t50_ckx->setCheckState(Qt::Unchecked);
        ui->bym2400_t50_edt->setText("");
    }
    else
    {
        ui->bym2400_t50_ckx->setCheckState(Qt::Checked);
        ui->bym2400_t50_edt->setText(QString::number(bym2400_jsobj.value("v_rm50_tmax").toInt()));
    }

    if(bym2400_jsobj.value("v_rm55_pwmin").toInt() == -1)
    {
        ui->bym2400_rt55_time_ckx->setCheckState(Qt::Unchecked);
        ui->bym2400_rt55_time_edt->setText("");
    }
    else
    {
        ui->bym2400_rt55_time_ckx->setCheckState(Qt::Checked);
        ui->bym2400_rt55_time_edt->setText(QString::number(bym2400_jsobj.value("v_rm55_pwmin").toInt()));
    }

    if(bym2400_jsobj.value("v_rm55_tmax").toInt() == -1)
    {
        ui->bym2400_t55_ckx->setCheckState(Qt::Unchecked);
        ui->bym2400_t55_edt->setText("");
    }
    else
    {
        ui->bym2400_t55_ckx->setCheckState(Qt::Checked);
        ui->bym2400_t55_edt->setText(QString::number(bym2400_jsobj.value("v_rm55_tmax").toInt()));
    }
    if(bym2400_jsobj.value("v_rm60_pwmin").toInt() == -1)
    {
        ui->bym2400_rt60_time_ckx->setCheckState(Qt::Unchecked);
        ui->bym2400_rt60_time_edt->setText("");
    }
    else
    {
        ui->bym2400_rt60_time_ckx->setCheckState(Qt::Checked);
        ui->bym2400_rt60_time_edt->setText(QString::number(bym2400_jsobj.value("v_rm60_pwmin").toInt()));
    }

    if(bym2400_jsobj.value("v_rm60_tmax").toInt() == -1)
    {
        ui->bym2400_t60_ckx->setCheckState(Qt::Unchecked);
        ui->bym2400_t60_edt->setText("");
    }
    else
    {
        ui->bym2400_t60_ckx->setCheckState(Qt::Checked);
        ui->bym2400_t60_edt->setText(QString::number(bym2400_jsobj.value("v_rm60_tmax").toInt()));
    }
    //目前每路都共用一个pv参数
    QJsonObject bym2400_pv1_jsobj = bym2400_jsobj.value("pv_params").toArray().at(0).toObject();
    if(bym2400_pv1_jsobj.value("v_pv_rm40_pwmin").toInt() == -1)
    {
        ui->bym2400_rt40_time_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym2400_rt40_time_pv_edt->setText("");
    }
    else
    {
        ui->bym2400_rt40_time_pv_ckx->setCheckState(Qt::Checked);
        ui->bym2400_rt40_time_pv_edt->setText(QString::number(bym2400_pv1_jsobj.value("v_pv_rm40_pwmin").toInt()));
    }

    if(bym2400_pv1_jsobj.value("v_pv_rm40_tmax").toInt() == -1)
    {
        ui->bym2400_t40_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym2400_t40_pv_edt->setText("");
    }
    else
    {
        ui->bym2400_t40_pv_ckx->setCheckState(Qt::Checked);
        ui->bym2400_t40_pv_edt->setText(QString::number(bym2400_pv1_jsobj.value("v_pv_rm40_tmax").toInt()));
    }

    if(bym2400_pv1_jsobj.value("v_pv_rm45_pwmin").toInt() == -1)
    {
        ui->bym2400_rt45_time_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym2400_rt45_time_pv_edt->setText("");
    }
    else
    {
        ui->bym2400_rt45_time_pv_ckx->setCheckState(Qt::Checked);
        ui->bym2400_rt45_time_pv_edt->setText(QString::number(bym2400_pv1_jsobj.value("v_pv_rm45_pwmin").toInt()));
    }

    if(bym2400_pv1_jsobj.value("v_pv_rm45_tmax").toInt() == -1)
    {
        ui->bym2400_t45_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym2400_t45_pv_edt->setText("");
    }
    else
    {
        ui->bym2400_t45_pv_ckx->setCheckState(Qt::Checked);
        ui->bym2400_t45_pv_edt->setText(QString::number(bym2400_pv1_jsobj.value("v_pv_rm45_tmax").toInt()));
    }

    if(bym2400_pv1_jsobj.value("v_pv_rm50_pwmin").toInt() == -1)
    {
        ui->bym2400_rt50_time_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym2400_rt50_time_pv_edt->setText("");
    }
    else
    {
        ui->bym2400_rt50_time_pv_ckx->setCheckState(Qt::Checked);
        ui->bym2400_rt50_time_pv_edt->setText(QString::number(bym2400_pv1_jsobj.value("v_pv_rm50_pwmin").toInt()));
    }

    if(bym2400_pv1_jsobj.value("v_pv_rm50_tmax").toInt() == -1)
    {
        ui->bym2400_t50_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym2400_t50_pv_edt->setText("");
    }
    else
    {
        ui->bym2400_t50_pv_ckx->setCheckState(Qt::Checked);
        ui->bym2400_t50_pv_edt->setText(QString::number(bym2400_pv1_jsobj.value("v_pv_rm50_tmax").toInt()));
    }

    if(bym2400_pv1_jsobj.value("v_pv_rm55_pwmin").toInt() == -1)
    {
        ui->bym2400_rt55_time_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym2400_rt55_time_pv_edt->setText("");
    }
    else
    {
        ui->bym2400_rt55_time_pv_ckx->setCheckState(Qt::Checked);
        ui->bym2400_rt55_time_pv_edt->setText(QString::number(bym2400_pv1_jsobj.value("v_pv_rm55_pwmin").toInt()));
    }

    if(bym2400_pv1_jsobj.value("v_pv_rm55_tmax").toInt() == -1)
    {
        ui->bym2400_t55_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym2400_t55_pv_edt->setText("");
    }
    else
    {
        ui->bym2400_t55_pv_ckx->setCheckState(Qt::Checked);
        ui->bym2400_t55_pv_edt->setText(QString::number(bym2400_pv1_jsobj.value("v_pv_rm55_tmax").toInt()));
    }
    if(bym2400_pv1_jsobj.value("v_pv_rm60_pwmin").toInt() == -1)
    {
        ui->bym2400_rt60_time_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym2400_rt60_time_pv_edt->setText("");
    }
    else
    {
        ui->bym2400_rt60_time_pv_ckx->setCheckState(Qt::Checked);
        ui->bym2400_rt60_time_pv_edt->setText(QString::number(bym2400_pv1_jsobj.value("v_pv_rm60_pwmin").toInt()));
    }

    if(bym2400_pv1_jsobj.value("v_pv_rm60_tmax").toInt() == -1)
    {
        ui->bym2400_t60_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym2400_t60_pv_edt->setText("");
    }
    else
    {
        ui->bym2400_t60_pv_ckx->setCheckState(Qt::Checked);
        ui->bym2400_t60_pv_edt->setText(QString::number(bym2400_jsobj.value("v_pv_rm60_tmax").toInt()));
    }
    int bym2400_mim1_err_mask = bym2400_jsobj.value("mim1_err").toInt();
    int bym2400_mis_err_mask = bym2400_jsobj.value("mis_err").toInt();
    int bym2400_mim2_err_mask = bym2400_jsobj.value("mim2_err").toInt();

    //原边故障pv12
    if(bym2400_mim1_err_mask & 0x8000)
    {
        ui->bym2400_pv_ov_bym4_pv1_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2400_pv_ov_bym4_pv1_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym2400_mim1_err_mask & 0x4000)
    {
        ui->bym2400_pv_uv_bym4_pv1_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2400_pv_uv_bym4_pv1_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym2400_mim1_err_mask & 0x2000)
    {
        ui->bym2400_dc_ov_bym4_pv1_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2400_dc_ov_bym4_pv1_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym2400_mim1_err_mask & 0x1000)
    {
        ui->bym2400_dc_oa_bym4_pv1_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2400_dc_oa_bym4_pv1_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym2400_mim1_err_mask & 0x0800)
    {
        ui->bym2400_dc_ot_bym4_pv1_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2400_dc_ot_bym4_pv1_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym2400_mim1_err_mask & 0x0400)
    {
        ui->bym2400_land_bym4_pv12_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2400_land_bym4_pv12_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym2400_mim1_err_mask & 0x0200)
    {
        ui->bym2400_mppt_bym4_pv12_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2400_mppt_bym4_pv12_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym2400_mim1_err_mask & 0x0100)
    {
        ui->bym2400_dc_ot_bym4_pv2_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2400_dc_ot_bym4_pv2_ckx->setCheckState(Qt::Unchecked);
    }


    if(bym2400_mim1_err_mask & 0x0080)
    {
        ui->bym2400_pv_ov_bym4_pv2_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2400_pv_ov_bym4_pv2_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym2400_mim1_err_mask & 0x0040)
    {
        ui->bym2400_pv_uv_bym4_pv2_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2400_pv_uv_bym4_pv2_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym2400_mim1_err_mask & 0x0020)
    {
        ui->bym2400_dc_ov_bym4_pv2_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2400_dc_ov_bym4_pv2_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym2400_mim1_err_mask & 0x1000)
    {
        ui->bym2400_dc_oa_bym4_pv2_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2400_dc_oa_bym4_pv2_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym2400_mim1_err_mask & 0x0008)
    {
        ui->bym2400_sync_error_bym4_pv12_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2400_sync_error_bym4_pv12_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym2400_mim1_err_mask & 0x0004)
    {
        ui->bym2400_safe_chain_bym4_pv12_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2400_safe_chain_bym4_pv12_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym2400_mim1_err_mask & 0x0002)
    {
        ui->bym2400_grid_bym4_pv12_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2400_grid_bym4_pv12_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym2400_mim1_err_mask & 0x0001)
    {
        ui->bym2400_off_bym4_pv12_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2400_off_bym4_pv12_ckx->setCheckState(Qt::Unchecked);
    }
    //原边故障pv34
    if(bym2400_mim2_err_mask & 0x8000)
    {
        ui->bym2400_pv_ov_bym4_pv3_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2400_pv_ov_bym4_pv3_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym2400_mim2_err_mask & 0x4000)
    {
        ui->bym2400_pv_uv_bym4_pv3_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2400_pv_uv_bym4_pv3_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym2400_mim2_err_mask & 0x2000)
    {
        ui->bym2400_dc_ov_bym4_pv3_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2400_dc_ov_bym4_pv3_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym2400_mim2_err_mask & 0x1000)
    {
        ui->bym2400_dc_oa_bym4_pv3_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2400_dc_oa_bym4_pv3_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym2400_mim2_err_mask & 0x0800)
    {
        ui->bym2400_dc_ot_bym4_pv3_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2400_dc_ot_bym4_pv3_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym2400_mim2_err_mask & 0x0400)
    {
        ui->bym2400_land_bym4_pv34_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2400_land_bym4_pv34_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym2400_mim2_err_mask & 0x0200)
    {
        ui->bym2400_mppt_bym4_pv34_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2400_mppt_bym4_pv34_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym2400_mim2_err_mask & 0x0100)
    {
        ui->bym2400_dc_ot_bym4_pv4_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2400_dc_ot_bym4_pv4_ckx->setCheckState(Qt::Unchecked);
    }


    if(bym2400_mim2_err_mask & 0x0080)
    {
        ui->bym2400_pv_ov_bym4_pv4_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2400_pv_ov_bym4_pv4_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym2400_mim2_err_mask & 0x0040)
    {
        ui->bym2400_pv_uv_bym4_pv4_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2400_pv_uv_bym4_pv4_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym2400_mim2_err_mask & 0x0020)
    {
        ui->bym2400_dc_ov_bym4_pv4_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2400_dc_ov_bym4_pv4_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym2400_mim2_err_mask & 0x1000)
    {
        ui->bym2400_dc_oa_bym4_pv4_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2400_dc_oa_bym4_pv4_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym2400_mim2_err_mask & 0x0008)
    {
        ui->bym2400_sync_error_bym4_pv34_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2400_sync_error_bym4_pv34_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym2400_mim2_err_mask & 0x0004)
    {
        ui->bym2400_safe_chain_bym4_pv34_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2400_safe_chain_bym4_pv34_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym2400_mim2_err_mask & 0x0002)
    {
        ui->bym2400_grid_bym4_pv34_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2400_grid_bym4_pv34_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym2400_mim2_err_mask & 0x0001)
    {
        ui->bym2400_off_bym4_pv34_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2400_off_bym4_pv34_ckx->setCheckState(Qt::Unchecked);
    }



    //副边故障
    if(bym2400_mis_err_mask & 0x8000)
    {
        ui->bym2400_grid_ov_bym4_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2400_grid_ov_bym4_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym2400_mis_err_mask & 0x4000)
    {
        ui->bym2400_grid_uv_bym4_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2400_grid_uv_bym4_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym2400_mis_err_mask & 0x2000)
    {
        ui->bym2400_grid_of_bym4_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2400_grid_of_bym4_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym2400_mis_err_mask & 0x1000)
    {
        ui->bym2400_grid_uf_bym4_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2400_grid_uf_bym4_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym2400_mis_err_mask & 0x0800)
    {
        ui->bym2400_lock_ckx_bym4_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2400_lock_ckx_bym4_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym2400_mis_err_mask & 0x0400)
    {
        ui->bym2400_surge_bym4_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2400_surge_bym4_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym2400_mis_err_mask & 0x0200)
    {
        ui->bym2400_mcu_uv_bym4_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2400_mcu_uv_bym4_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym2400_mis_err_mask & 0x0100)
    {
        ui->bym2400_pv_uv_bym4_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2400_pv_uv_bym4_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym2400_mis_err_mask & 0x0080)
    {
        ui->bym2400_hbd_oa_bym4_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2400_hbd_oa_bym4_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym2400_mis_err_mask & 0x0040)
    {
        ui->bym2400_hbd_ov_bym4_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2400_hbd_ov_bym4_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym2400_mis_err_mask & 0x0008)
    {
        ui->bym2400_cmu_primary2_bym4_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2400_cmu_primary2_bym4_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym2400_mis_err_mask & 0x0004)
    {
        ui->bym2400_cmu_primary1_bym4_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2400_cmu_primary1_bym4_ckx->setCheckState(Qt::Unchecked);
    }

//  bym2800
    QJsonObject bym2800_jsobj = def_data.value("bym2800").toObject();

    ui->bym2800_aging_offset_edt->setText(QString::number(bym2800_jsobj.value("v_start_point_offset").toInt()));
    ui->bym2800_ignore_max_edt->setText(QString::number(bym2800_jsobj.value("ignore_points_max").toInt()));
    ui->bym2800_drop_max_edt->setText(QString::number(bym2800_jsobj.value("drop_points_max").toInt()));
    ui->bym2800_drop_value_edt->setText(QString::number(bym2800_jsobj.value("drop_value").toInt()));
    if(bym2800_jsobj.value("v_aging_points").toInt() == -1)
    {
        ui->bym2800_aging_num_ckx->setCheckState(Qt::Unchecked);
        ui->bym2800_aging_num_edt->setText("");
    }
    else
    {
        ui->bym2800_aging_num_ckx->setCheckState(Qt::Checked);
        ui->bym2800_aging_num_edt->setText(QString::number(bym2800_jsobj.value("v_aging_points").toInt()));
    }

    if(bym2800_jsobj.value("v_aging_time").toInt() == -1)
    {
        ui->bym2800_aging_time_ckx->setCheckState(Qt::Unchecked);
        ui->bym2800_aging_time_edt->setText("");
    }
    else
    {
        ui->bym2800_aging_time_ckx->setCheckState(Qt::Checked);
        ui->bym2800_aging_time_edt->setText(QString::number(bym2800_jsobj.value("v_aging_time").toInt()));
    }

    if(bym2800_jsobj.value("v_rm40_pwmin").toInt() == -1)
    {
        ui->bym2800_rt40_time_ckx->setCheckState(Qt::Unchecked);
        ui->bym2800_rt40_time_edt->setText("");
    }
    else
    {
        ui->bym2800_rt40_time_ckx->setCheckState(Qt::Checked);
        ui->bym2800_rt40_time_edt->setText(QString::number(bym2800_jsobj.value("v_rm40_pwmin").toInt()));
    }

    if(bym2800_jsobj.value("v_rm40_tmax").toInt() == -1)
    {
        ui->bym2800_t40_ckx->setCheckState(Qt::Unchecked);
        ui->bym2800_t40_edt->setText("");
    }
    else
    {
        ui->bym2800_t40_ckx->setCheckState(Qt::Checked);
        ui->bym2800_t40_edt->setText(QString::number(bym2800_jsobj.value("v_rm40_tmax").toInt()));
    }

    if(bym2800_jsobj.value("v_rm45_pwmin").toInt() == -1)
    {
        ui->bym2800_rt45_time_ckx->setCheckState(Qt::Unchecked);
        ui->bym2800_rt45_time_edt->setText("");
    }
    else
    {
        ui->bym2800_rt45_time_ckx->setCheckState(Qt::Checked);
        ui->bym2800_rt45_time_edt->setText(QString::number(bym2800_jsobj.value("v_rm45_pwmin").toInt()));
    }

    if(bym2800_jsobj.value("v_rm45_tmax").toInt() == -1)
    {
        ui->bym2800_t45_ckx->setCheckState(Qt::Unchecked);
        ui->bym2800_t45_edt->setText("");
    }
    else
    {
        ui->bym2800_t45_ckx->setCheckState(Qt::Checked);
        ui->bym2800_t45_edt->setText(QString::number(bym2800_jsobj.value("v_rm45_tmax").toInt()));
    }

    if(bym2800_jsobj.value("v_rm50_pwmin").toInt() == -1)
    {
        ui->bym2800_rt50_time_ckx->setCheckState(Qt::Unchecked);
        ui->bym2800_rt50_time_edt->setText("");
    }
    else
    {
        ui->bym2800_rt50_time_ckx->setCheckState(Qt::Checked);
        ui->bym2800_rt50_time_edt->setText(QString::number(bym2800_jsobj.value("v_rm50_pwmin").toInt()));
    }

    if(bym2800_jsobj.value("v_rm50_tmax").toInt() == -1)
    {
        ui->bym2800_t50_ckx->setCheckState(Qt::Unchecked);
        ui->bym2800_t50_edt->setText("");
    }
    else
    {
        ui->bym2800_t50_ckx->setCheckState(Qt::Checked);
        ui->bym2800_t50_edt->setText(QString::number(bym2800_jsobj.value("v_rm50_tmax").toInt()));
    }

    if(bym2800_jsobj.value("v_rm55_pwmin").toInt() == -1)
    {
        ui->bym2800_rt55_time_ckx->setCheckState(Qt::Unchecked);
        ui->bym2800_rt55_time_edt->setText("");
    }
    else
    {
        ui->bym2800_rt55_time_ckx->setCheckState(Qt::Checked);
        ui->bym2800_rt55_time_edt->setText(QString::number(bym2800_jsobj.value("v_rm55_pwmin").toInt()));
    }

    if(bym2800_jsobj.value("v_rm55_tmax").toInt() == -1)
    {
        ui->bym2800_t55_ckx->setCheckState(Qt::Unchecked);
        ui->bym2800_t55_edt->setText("");
    }
    else
    {
        ui->bym2800_t55_ckx->setCheckState(Qt::Checked);
        ui->bym2800_t55_edt->setText(QString::number(bym2800_jsobj.value("v_rm55_tmax").toInt()));
    }
    if(bym2800_jsobj.value("v_rm60_pwmin").toInt() == -1)
    {
        ui->bym2800_rt60_time_ckx->setCheckState(Qt::Unchecked);
        ui->bym2800_rt60_time_edt->setText("");
    }
    else
    {
        ui->bym2800_rt60_time_ckx->setCheckState(Qt::Checked);
        ui->bym2800_rt60_time_edt->setText(QString::number(bym2800_jsobj.value("v_rm60_pwmin").toInt()));
    }

    if(bym2800_jsobj.value("v_rm60_tmax").toInt() == -1)
    {
        ui->bym2800_t60_ckx->setCheckState(Qt::Unchecked);
        ui->bym2800_t60_edt->setText("");
    }
    else
    {
        ui->bym2800_t60_ckx->setCheckState(Qt::Checked);
        ui->bym2800_t60_edt->setText(QString::number(bym2800_jsobj.value("v_rm60_tmax").toInt()));
    }
    //目前每路都共用一个pv参数
    QJsonObject bym2800_pv1_jsobj = bym2800_jsobj.value("pv_params").toArray().at(0).toObject();
    if(bym2800_pv1_jsobj.value("v_pv_rm40_pwmin").toInt() == -1)
    {
        ui->bym2800_rt40_time_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym2800_rt40_time_pv_edt->setText("");
    }
    else
    {
        ui->bym2800_rt40_time_pv_ckx->setCheckState(Qt::Checked);
        ui->bym2800_rt40_time_pv_edt->setText(QString::number(bym2800_pv1_jsobj.value("v_pv_rm40_pwmin").toInt()));
    }

    if(bym2800_pv1_jsobj.value("v_pv_rm40_tmax").toInt() == -1)
    {
        ui->bym2800_t40_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym2800_t40_pv_edt->setText("");
    }
    else
    {
        ui->bym2800_t40_pv_ckx->setCheckState(Qt::Checked);
        ui->bym2800_t40_pv_edt->setText(QString::number(bym2800_pv1_jsobj.value("v_pv_rm40_tmax").toInt()));
    }

    if(bym2800_pv1_jsobj.value("v_pv_rm45_pwmin").toInt() == -1)
    {
        ui->bym2800_rt45_time_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym2800_rt45_time_pv_edt->setText("");
    }
    else
    {
        ui->bym2800_rt45_time_pv_ckx->setCheckState(Qt::Checked);
        ui->bym2800_rt45_time_pv_edt->setText(QString::number(bym2800_pv1_jsobj.value("v_pv_rm45_pwmin").toInt()));
    }

    if(bym2800_pv1_jsobj.value("v_pv_rm45_tmax").toInt() == -1)
    {
        ui->bym2800_t45_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym2800_t45_pv_edt->setText("");
    }
    else
    {
        ui->bym2800_t45_pv_ckx->setCheckState(Qt::Checked);
        ui->bym2800_t45_pv_edt->setText(QString::number(bym2800_pv1_jsobj.value("v_pv_rm45_tmax").toInt()));
    }

    if(bym2800_pv1_jsobj.value("v_pv_rm50_pwmin").toInt() == -1)
    {
        ui->bym2800_rt50_time_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym2800_rt50_time_pv_edt->setText("");
    }
    else
    {
        ui->bym2800_rt50_time_pv_ckx->setCheckState(Qt::Checked);
        ui->bym2800_rt50_time_pv_edt->setText(QString::number(bym2800_pv1_jsobj.value("v_pv_rm50_pwmin").toInt()));
    }

    if(bym2800_pv1_jsobj.value("v_pv_rm50_tmax").toInt() == -1)
    {
        ui->bym2800_t50_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym2800_t50_pv_edt->setText("");
    }
    else
    {
        ui->bym2800_t50_pv_ckx->setCheckState(Qt::Checked);
        ui->bym2800_t50_pv_edt->setText(QString::number(bym2800_pv1_jsobj.value("v_pv_rm50_tmax").toInt()));
    }

    if(bym2800_pv1_jsobj.value("v_pv_rm55_pwmin").toInt() == -1)
    {
        ui->bym2800_rt55_time_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym2800_rt55_time_pv_edt->setText("");
    }
    else
    {
        ui->bym2800_rt55_time_pv_ckx->setCheckState(Qt::Checked);
        ui->bym2800_rt55_time_pv_edt->setText(QString::number(bym2800_pv1_jsobj.value("v_pv_rm55_pwmin").toInt()));
    }

    if(bym2800_pv1_jsobj.value("v_pv_rm55_tmax").toInt() == -1)
    {
        ui->bym2800_t55_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym2800_t55_pv_edt->setText("");
    }
    else
    {
        ui->bym2800_t55_pv_ckx->setCheckState(Qt::Checked);
        ui->bym2800_t55_pv_edt->setText(QString::number(bym2800_pv1_jsobj.value("v_pv_rm55_tmax").toInt()));
    }
    if(bym2800_pv1_jsobj.value("v_pv_rm60_pwmin").toInt() == -1)
    {
        ui->bym2800_rt60_time_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym2800_rt60_time_pv_edt->setText("");
    }
    else
    {
        ui->bym2800_rt60_time_pv_ckx->setCheckState(Qt::Checked);
        ui->bym2800_rt60_time_pv_edt->setText(QString::number(bym2800_pv1_jsobj.value("v_pv_rm60_pwmin").toInt()));
    }

    if(bym2800_pv1_jsobj.value("v_pv_rm60_tmax").toInt() == -1)
    {
        ui->bym2800_t60_pv_ckx->setCheckState(Qt::Unchecked);
        ui->bym2800_t60_pv_edt->setText("");
    }
    else
    {
        ui->bym2800_t60_pv_ckx->setCheckState(Qt::Checked);
        ui->bym2800_t60_pv_edt->setText(QString::number(bym2800_jsobj.value("v_pv_rm60_tmax").toInt()));
    }
    int bym2800_mim1_err_mask = bym2800_jsobj.value("mim1_err").toInt();
    int bym2800_mis_err_mask = bym2800_jsobj.value("mis_err").toInt();
    int bym2800_mim2_err_mask = bym2800_jsobj.value("mim2_err").toInt();

    //原边故障pv12
    if(bym2800_mim1_err_mask & 0x8000)
    {
        ui->bym2800_pv_ov_bym4_pv1_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2800_pv_ov_bym4_pv1_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym2800_mim1_err_mask & 0x4000)
    {
        ui->bym2800_pv_uv_bym4_pv1_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2800_pv_uv_bym4_pv1_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym2800_mim1_err_mask & 0x2000)
    {
        ui->bym2800_dc_ov_bym4_pv1_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2800_dc_ov_bym4_pv1_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym2800_mim1_err_mask & 0x1000)
    {
        ui->bym2800_dc_oa_bym4_pv1_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2800_dc_oa_bym4_pv1_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym2800_mim1_err_mask & 0x0800)
    {
        ui->bym2800_dc_ot_bym4_pv1_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2800_dc_ot_bym4_pv1_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym2800_mim1_err_mask & 0x0400)
    {
        ui->bym2800_land_bym4_pv12_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2800_land_bym4_pv12_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym2800_mim1_err_mask & 0x0200)
    {
        ui->bym2800_mppt_bym4_pv12_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2800_mppt_bym4_pv12_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym2800_mim1_err_mask & 0x0100)
    {
        ui->bym2800_dc_ot_bym4_pv2_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2800_dc_ot_bym4_pv2_ckx->setCheckState(Qt::Unchecked);
    }


    if(bym2800_mim1_err_mask & 0x0080)
    {
        ui->bym2800_pv_ov_bym4_pv2_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2800_pv_ov_bym4_pv2_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym2800_mim1_err_mask & 0x0040)
    {
        ui->bym2800_pv_uv_bym4_pv2_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2800_pv_uv_bym4_pv2_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym2800_mim1_err_mask & 0x0020)
    {
        ui->bym2800_dc_ov_bym4_pv2_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2800_dc_ov_bym4_pv2_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym2800_mim1_err_mask & 0x1000)
    {
        ui->bym2800_dc_oa_bym4_pv2_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2800_dc_oa_bym4_pv2_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym2800_mim1_err_mask & 0x0008)
    {
        ui->bym2800_sync_error_bym4_pv12_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2800_sync_error_bym4_pv12_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym2800_mim1_err_mask & 0x0004)
    {
        ui->bym2800_safe_chain_bym4_pv12_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2800_safe_chain_bym4_pv12_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym2800_mim1_err_mask & 0x0002)
    {
        ui->bym2800_grid_bym4_pv12_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2800_grid_bym4_pv12_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym2800_mim1_err_mask & 0x0001)
    {
        ui->bym2800_off_bym4_pv12_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2800_off_bym4_pv12_ckx->setCheckState(Qt::Unchecked);
    }
    //原边故障pv34
    if(bym2800_mim2_err_mask & 0x8000)
    {
        ui->bym2800_pv_ov_bym4_pv3_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2800_pv_ov_bym4_pv3_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym2800_mim2_err_mask & 0x4000)
    {
        ui->bym2800_pv_uv_bym4_pv3_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2800_pv_uv_bym4_pv3_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym2800_mim2_err_mask & 0x2000)
    {
        ui->bym2800_dc_ov_bym4_pv3_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2800_dc_ov_bym4_pv3_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym2800_mim2_err_mask & 0x1000)
    {
        ui->bym2800_dc_oa_bym4_pv3_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2800_dc_oa_bym4_pv3_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym2800_mim2_err_mask & 0x0800)
    {
        ui->bym2800_dc_ot_bym4_pv3_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2800_dc_ot_bym4_pv3_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym2800_mim2_err_mask & 0x0400)
    {
        ui->bym2800_land_bym4_pv34_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2800_land_bym4_pv34_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym2800_mim2_err_mask & 0x0200)
    {
        ui->bym2800_mppt_bym4_pv34_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2800_mppt_bym4_pv34_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym2800_mim2_err_mask & 0x0100)
    {
        ui->bym2800_dc_ot_bym4_pv4_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2800_dc_ot_bym4_pv4_ckx->setCheckState(Qt::Unchecked);
    }


    if(bym2800_mim2_err_mask & 0x0080)
    {
        ui->bym2800_pv_ov_bym4_pv4_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2800_pv_ov_bym4_pv4_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym2800_mim2_err_mask & 0x0040)
    {
        ui->bym2800_pv_uv_bym4_pv4_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2800_pv_uv_bym4_pv4_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym2800_mim2_err_mask & 0x0020)
    {
        ui->bym2800_dc_ov_bym4_pv4_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2800_dc_ov_bym4_pv4_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym2800_mim2_err_mask & 0x1000)
    {
        ui->bym2800_dc_oa_bym4_pv4_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2800_dc_oa_bym4_pv4_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym2800_mim2_err_mask & 0x0008)
    {
        ui->bym2800_sync_error_bym4_pv34_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2800_sync_error_bym4_pv34_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym2800_mim2_err_mask & 0x0004)
    {
        ui->bym2800_safe_chain_bym4_pv34_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2800_safe_chain_bym4_pv34_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym2800_mim2_err_mask & 0x0002)
    {
        ui->bym2800_grid_bym4_pv34_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2800_grid_bym4_pv34_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym2800_mim2_err_mask & 0x0001)
    {
        ui->bym2800_off_bym4_pv34_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2800_off_bym4_pv34_ckx->setCheckState(Qt::Unchecked);
    }



    //副边故障
    if(bym2800_mis_err_mask & 0x8000)
    {
        ui->bym2800_grid_ov_bym4_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2800_grid_ov_bym4_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym2800_mis_err_mask & 0x4000)
    {
        ui->bym2800_grid_uv_bym4_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2800_grid_uv_bym4_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym2800_mis_err_mask & 0x2000)
    {
        ui->bym2800_grid_of_bym4_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2800_grid_of_bym4_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym2800_mis_err_mask & 0x1000)
    {
        ui->bym2800_grid_uf_bym4_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2800_grid_uf_bym4_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym2800_mis_err_mask & 0x0800)
    {
        ui->bym2800_lock_ckx_bym4_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2800_lock_ckx_bym4_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym2800_mis_err_mask & 0x0400)
    {
        ui->bym2800_surge_bym4_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2800_surge_bym4_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym2800_mis_err_mask & 0x0200)
    {
        ui->bym2800_mcu_uv_bym4_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2800_mcu_uv_bym4_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym2800_mis_err_mask & 0x0100)
    {
        ui->bym2800_pv_uv_bym4_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2800_pv_uv_bym4_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym2800_mis_err_mask & 0x0080)
    {
        ui->bym2800_hbd_oa_bym4_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2800_hbd_oa_bym4_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym2800_mis_err_mask & 0x0040)
    {
        ui->bym2800_hbd_ov_bym4_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2800_hbd_ov_bym4_ckx->setCheckState(Qt::Unchecked);
    }

    if(bym2800_mis_err_mask & 0x0008)
    {
        ui->bym2800_cmu_primary2_bym4_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2800_cmu_primary2_bym4_ckx->setCheckState(Qt::Unchecked);
    }
    if(bym2800_mis_err_mask & 0x0004)
    {
        ui->bym2800_cmu_primary1_bym4_ckx->setCheckState(Qt::Checked);
    }
    else
    {
        ui->bym2800_cmu_primary1_bym4_ckx->setCheckState(Qt::Unchecked);
    }

}

judge_param_set_dlg::~judge_param_set_dlg()
{
    delete ui;
}

void judge_param_set_dlg::to_jsonobj(QJsonObject &ret_data)
{
    //bym500
    QJsonObject bym500_jsobj;

    bym500_jsobj.insert("v_start_point_offset",ui->bym500_aging_offset_edt->text().toInt());

    bym500_jsobj.insert("ignore_points_max",ui->bym500_ignore_max_edt->text().toInt());
    bym500_jsobj.insert("drop_points_max",ui->bym500_drop_max_edt->text().toInt());
    bym500_jsobj.insert("drop_value",ui->bym500_drop_value_edt->text().toInt());

    if(ui->bym500_aging_num_ckx->checkState() == Qt::Unchecked)
    {
        bym500_jsobj.insert("v_aging_points",-1);
    }
    else
    {
        bym500_jsobj.insert("v_aging_points",ui->bym500_aging_num_edt->text().toInt());
    }

    if(ui->bym500_aging_time_ckx->checkState() == Qt::Unchecked)
    {
        bym500_jsobj.insert("v_aging_time",-1);
    }
    else
    {
        bym500_jsobj.insert("v_aging_time",ui->bym500_aging_time_edt->text().toInt());
    }

    if(ui->bym500_rt40_time_ckx->checkState() == Qt::Unchecked)
    {
        bym500_jsobj.insert("v_rm40_pwmin",-1);
    }
    else
    {
        bym500_jsobj.insert("v_rm40_pwmin",ui->bym500_rt40_time_edt->text().toInt());
    }

    if(ui->bym500_t40_ckx->checkState() == Qt::Unchecked)
    {
        bym500_jsobj.insert("v_rm40_tmax",-1);
    }
    else
    {
        bym500_jsobj.insert("v_rm40_tmax",ui->bym500_t40_edt->text().toInt());
    }

    if(ui->bym500_rt45_time_ckx->checkState() == Qt::Unchecked)
    {
        bym500_jsobj.insert("v_rm45_pwmin",-1);
    }
    else
    {
        bym500_jsobj.insert("v_rm45_pwmin",ui->bym500_rt45_time_edt->text().toInt());
    }

    if(ui->bym500_t45_ckx->checkState() == Qt::Unchecked)
    {
        bym500_jsobj.insert("v_rm45_tmax",-1);
    }
    else
    {
        bym500_jsobj.insert("v_rm45_tmax",ui->bym500_t45_edt->text().toInt());
    }

    if(ui->bym500_rt50_time_ckx->checkState() == Qt::Unchecked)
    {
        bym500_jsobj.insert("v_rm50_pwmin",-1);
    }
    else
    {
        bym500_jsobj.insert("v_rm50_pwmin",ui->bym500_rt50_time_edt->text().toInt());
    }

    if(ui->bym500_t50_ckx->checkState() == Qt::Unchecked)
    {
        bym500_jsobj.insert("v_rm50_tmax",-1);
    }
    else
    {
        bym500_jsobj.insert("v_rm50_tmax",ui->bym500_t50_edt->text().toInt());
    }

    if(ui->bym500_rt55_time_ckx->checkState() == Qt::Unchecked)
    {
        bym500_jsobj.insert("v_rm55_pwmin",-1);
    }
    else
    {
        bym500_jsobj.insert("v_rm55_pwmin",ui->bym500_rt55_time_edt->text().toInt());
    }

    if(ui->bym500_t55_ckx->checkState() == Qt::Unchecked)
    {
        bym500_jsobj.insert("v_rm55_tmax",-1);
    }
    else
    {
        bym500_jsobj.insert("v_rm55_tmax",ui->bym500_t55_edt->text().toInt());
    }

    if(ui->bym500_rt60_time_ckx->checkState() == Qt::Unchecked)
    {
        bym500_jsobj.insert("v_rm60_pwmin",-1);
    }
    else
    {
        bym500_jsobj.insert("v_rm60_pwmin",ui->bym500_rt60_time_edt->text().toInt());
    }

    if(ui->bym500_t60_ckx->checkState() == Qt::Unchecked)
    {
        bym500_jsobj.insert("v_rm60_tmax",-1);
    }
    else
    {
        bym500_jsobj.insert("v_rm60_tmax",ui->bym500_t60_edt->text().toInt());
    }

    QJsonObject bym500_pv_jsobj;

    if(ui->bym500_rt40_time_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym500_pv_jsobj.insert("v_pv_rm40_pwmin",-1);
    }
    else
    {
        bym500_pv_jsobj.insert("v_pv_rm40_pwmin",ui->bym500_rt40_time_pv_edt->text().toInt());
    }

    if(ui->bym500_t40_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym500_pv_jsobj.insert("v_pv_rm40_tmax",-1);
    }
    else
    {
        bym500_pv_jsobj.insert("v_pv_rm40_tmax",ui->bym500_t40_pv_edt->text().toInt());
    }

    if(ui->bym500_rt45_time_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym500_pv_jsobj.insert("v_pv_rm45_pwmin",-1);
    }
    else
    {
        bym500_pv_jsobj.insert("v_pv_rm45_pwmin",ui->bym500_rt45_time_pv_edt->text().toInt());
    }

    if(ui->bym500_t45_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym500_pv_jsobj.insert("v_pv_rm45_tmax",-1);
    }
    else
    {
        bym500_pv_jsobj.insert("v_pv_rm45_tmax",ui->bym500_t45_pv_edt->text().toInt());
    }

    if(ui->bym500_rt50_time_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym500_pv_jsobj.insert("v_pv_rm50_pwmin",-1);
    }
    else
    {
        bym500_pv_jsobj.insert("v_pv_rm50_pwmin",ui->bym500_rt50_time_pv_edt->text().toInt());
    }

    if(ui->bym500_t50_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym500_pv_jsobj.insert("v_pv_rm50_tmax",-1);
    }
    else
    {
        bym500_pv_jsobj.insert("v_pv_rm50_tmax",ui->bym500_t50_pv_edt->text().toInt());
    }

    if(ui->bym500_rt55_time_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym500_pv_jsobj.insert("v_pv_rm55_pwmin",-1);
    }
    else
    {
        bym500_pv_jsobj.insert("v_pv_rm55_pwmin",ui->bym500_rt55_time_pv_edt->text().toInt());
    }

    if(ui->bym500_t55_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym500_pv_jsobj.insert("v_pv_rm55_tmax",-1);
    }
    else
    {
        bym500_pv_jsobj.insert("v_pv_rm55_tmax",ui->bym500_t55_pv_edt->text().toInt());
    }

    if(ui->bym500_rt60_time_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym500_pv_jsobj.insert("v_pv_rm60_pwmin",-1);
    }
    else
    {
        bym500_pv_jsobj.insert("v_pv_rm60_pwmin",ui->bym500_rt60_time_pv_edt->text().toInt());
    }

    if(ui->bym500_t60_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym500_pv_jsobj.insert("v_pv_rm60_tmax",-1);
    }
    else
    {
        bym500_pv_jsobj.insert("v_pv_rm60_tmax",ui->bym500_t60_pv_edt->text().toInt());
    }

    QJsonArray bym500_pvs;
    bym500_pvs.append(bym500_pv_jsobj);

    bym500_jsobj.insert("pv_params",bym500_pvs);

    uint16_t bym500_mim_err_mask = 0;
    uint16_t bym500_mis_err_mask = 0;

    if(ui->bym500_pv_ov_ckx->isChecked())
        bym500_mim_err_mask |= 0x8000;
    if(ui->bym500_pv_uv_ckx->isChecked())
        bym500_mim_err_mask |= 0x4000;
    if(ui->bym500_dc_ov_ckx->isChecked())
        bym500_mim_err_mask |= 0x2000;
    if(ui->bym500_dc_oa_ckx->isChecked())
        bym500_mim_err_mask |= 0x1000;
    if(ui->bym500_dc_ot_ckx->isChecked())
        bym500_mim_err_mask |= 0x0800;
    if(ui->bym500_land_ckx->isChecked())
        bym500_mim_err_mask |= 0x0400;
    if(ui->bym500_mppt_ckx->isChecked())
        bym500_mim_err_mask |= 0x0200;
    //后8位
    if(ui->bym500_sync_error->isChecked())
        bym500_mim_err_mask |= 0x0008;
    if(ui->bym500_safe_chain_ckx->isChecked())
        bym500_mim_err_mask |= 0x0004;
    if(ui->bym500_grid_ckx->isChecked())
        bym500_mim_err_mask |= 0x0002;
    if(ui->bym500_off_ckx->isChecked())
        bym500_mim_err_mask |= 0x0001;
    //单路副边
    if(ui->bym500_grid_ov_ckx->isChecked())
        bym500_mis_err_mask |= 0x8000;
    if(ui->bym500_grid_uv_ckx->isChecked())
        bym500_mis_err_mask |= 0x4000;
    if(ui->bym500_grid_of_ckx->isChecked())
        bym500_mis_err_mask |= 0x2000;
    if(ui->bym500_grid_uf_ckx->isChecked())
        bym500_mis_err_mask |= 0x1000;
    if(ui->bym500_lock_ckx->isChecked())
        bym500_mis_err_mask |= 0x0800;
    if(ui->bym500_surge_ckx->isChecked())
        bym500_mis_err_mask |= 0x0400;
    if(ui->bym500_mcu_uv_ckx->isChecked())
        bym500_mis_err_mask |= 0x0200;
    if(ui->bym500_pv_uv_ckx_2->isChecked())
        bym500_mis_err_mask |= 0x0100;

    if(ui->bym500_hbd_oa_ckx->isChecked())
        bym500_mis_err_mask |= 0x0080;
    if(ui->bym500_hbd_ov_ckx->isChecked())
        bym500_mis_err_mask |= 0x0040;
    if(ui->bym500_cmu_ckx->isChecked())
        bym500_mis_err_mask |= 0x0004;
    if(ui->bym500_gf_out_ckx->isChecked())
        bym500_mis_err_mask |= 0x0002;
    if(ui->bym500_gv_out_ckx->isChecked())
        bym500_mis_err_mask |= 0x0001;

    bym500_jsobj.insert("mim1_err",bym500_mim_err_mask);
    bym500_jsobj.insert("mis_err",bym500_mis_err_mask);

    //bym550
    QJsonObject bym550_jsobj;

    bym550_jsobj.insert("v_start_point_offset",ui->bym550_aging_offset_edt->text().toInt());
    bym550_jsobj.insert("ignore_points_max",ui->bym550_ignore_max_edt->text().toInt());
    bym550_jsobj.insert("drop_points_max",ui->bym550_drop_max_edt->text().toInt());
    bym550_jsobj.insert("drop_value",ui->bym550_drop_value_edt->text().toInt());
    if(ui->bym550_aging_num_ckx->checkState() == Qt::Unchecked)
    {
        bym550_jsobj.insert("v_aging_points",-1);
    }
    else
    {
        bym550_jsobj.insert("v_aging_points",ui->bym550_aging_num_edt->text().toInt());
    }

    if(ui->bym550_aging_time_ckx->checkState() == Qt::Unchecked)
    {
        bym550_jsobj.insert("v_aging_time",-1);
    }
    else
    {
        bym550_jsobj.insert("v_aging_time",ui->bym550_aging_time_edt->text().toInt());
    }

    if(ui->bym550_rt40_time_ckx->checkState() == Qt::Unchecked)
    {
        bym550_jsobj.insert("v_rm40_pwmin",-1);
    }
    else
    {
        bym550_jsobj.insert("v_rm40_pwmin",ui->bym550_rt40_time_edt->text().toInt());
    }

    if(ui->bym550_t40_ckx->checkState() == Qt::Unchecked)
    {
        bym550_jsobj.insert("v_rm40_tmax",-1);
    }
    else
    {
        bym550_jsobj.insert("v_rm40_tmax",ui->bym550_t40_edt->text().toInt());
    }

    if(ui->bym550_rt45_time_ckx->checkState() == Qt::Unchecked)
    {
        bym550_jsobj.insert("v_rm45_pwmin",-1);
    }
    else
    {
        bym550_jsobj.insert("v_rm45_pwmin",ui->bym550_rt45_time_edt->text().toInt());
    }

    if(ui->bym550_t45_ckx->checkState() == Qt::Unchecked)
    {
        bym550_jsobj.insert("v_rm45_tmax",-1);
    }
    else
    {
        bym550_jsobj.insert("v_rm45_tmax",ui->bym550_t45_edt->text().toInt());
    }

    if(ui->bym550_rt50_time_ckx->checkState() == Qt::Unchecked)
    {
        bym550_jsobj.insert("v_rm50_pwmin",-1);
    }
    else
    {
        bym550_jsobj.insert("v_rm50_pwmin",ui->bym550_rt50_time_edt->text().toInt());
    }

    if(ui->bym550_t50_ckx->checkState() == Qt::Unchecked)
    {
        bym550_jsobj.insert("v_rm50_tmax",-1);
    }
    else
    {
        bym550_jsobj.insert("v_rm50_tmax",ui->bym550_t50_edt->text().toInt());
    }

    if(ui->bym550_rt55_time_ckx->checkState() == Qt::Unchecked)
    {
        bym550_jsobj.insert("v_rm55_pwmin",-1);
    }
    else
    {
        bym550_jsobj.insert("v_rm55_pwmin",ui->bym550_rt55_time_edt->text().toInt());
    }

    if(ui->bym550_t55_ckx->checkState() == Qt::Unchecked)
    {
        bym550_jsobj.insert("v_rm55_tmax",-1);
    }
    else
    {
        bym550_jsobj.insert("v_rm55_tmax",ui->bym550_t55_edt->text().toInt());
    }

    if(ui->bym550_rt60_time_ckx->checkState() == Qt::Unchecked)
    {
        bym550_jsobj.insert("v_rm60_pwmin",-1);
    }
    else
    {
        bym550_jsobj.insert("v_rm60_pwmin",ui->bym550_rt60_time_edt->text().toInt());
    }

    if(ui->bym550_t60_ckx->checkState() == Qt::Unchecked)
    {
        bym550_jsobj.insert("v_rm60_tmax",-1);
    }
    else
    {
        bym550_jsobj.insert("v_rm60_tmax",ui->bym550_t60_edt->text().toInt());
    }

    QJsonObject bym550_pv_jsobj;

    if(ui->bym550_rt40_time_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym550_pv_jsobj.insert("v_pv_rm40_pwmin",-1);
    }
    else
    {
        bym550_pv_jsobj.insert("v_pv_rm40_pwmin",ui->bym550_rt40_time_pv_edt->text().toInt());
    }

    if(ui->bym550_t40_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym550_pv_jsobj.insert("v_pv_rm40_tmax",-1);
    }
    else
    {
        bym550_pv_jsobj.insert("v_pv_rm40_tmax",ui->bym550_t40_pv_edt->text().toInt());
    }

    if(ui->bym550_rt45_time_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym550_pv_jsobj.insert("v_pv_rm45_pwmin",-1);
    }
    else
    {
        bym550_pv_jsobj.insert("v_pv_rm45_pwmin",ui->bym550_rt45_time_pv_edt->text().toInt());
    }

    if(ui->bym550_t45_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym550_pv_jsobj.insert("v_pv_rm45_tmax",-1);
    }
    else
    {
        bym550_pv_jsobj.insert("v_pv_rm45_tmax",ui->bym550_t45_pv_edt->text().toInt());
    }

    if(ui->bym550_rt50_time_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym550_pv_jsobj.insert("v_pv_rm50_pwmin",-1);
    }
    else
    {
        bym550_pv_jsobj.insert("v_pv_rm50_pwmin",ui->bym550_rt50_time_pv_edt->text().toInt());
    }

    if(ui->bym550_t50_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym550_pv_jsobj.insert("v_pv_rm50_tmax",-1);
    }
    else
    {
        bym550_pv_jsobj.insert("v_pv_rm50_tmax",ui->bym550_t50_pv_edt->text().toInt());
    }

    if(ui->bym550_rt55_time_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym550_pv_jsobj.insert("v_pv_rm55_pwmin",-1);
    }
    else
    {
        bym550_pv_jsobj.insert("v_pv_rm55_pwmin",ui->bym550_rt55_time_pv_edt->text().toInt());
    }

    if(ui->bym550_t55_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym550_pv_jsobj.insert("v_pv_rm55_tmax",-1);
    }
    else
    {
        bym550_pv_jsobj.insert("v_pv_rm55_tmax",ui->bym550_t55_pv_edt->text().toInt());
    }

    if(ui->bym550_rt60_time_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym550_pv_jsobj.insert("v_pv_rm60_pwmin",-1);
    }
    else
    {
        bym550_pv_jsobj.insert("v_pv_rm60_pwmin",ui->bym550_rt60_time_pv_edt->text().toInt());
    }

    if(ui->bym550_t60_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym550_pv_jsobj.insert("v_pv_rm60_tmax",-1);
    }
    else
    {
        bym550_pv_jsobj.insert("v_pv_rm60_tmax",ui->bym550_t60_pv_edt->text().toInt());
    }

    QJsonArray bym550_pvs;
    bym550_pvs.append(bym550_pv_jsobj);

    bym550_jsobj.insert("pv_params",bym550_pvs);

    uint16_t bym550_mim_err_mask = 0;
    uint16_t bym550_mis_err_mask = 0;

    if(ui->bym550_pv_ov_ckx->isChecked())
        bym550_mim_err_mask |= 0x8000;
    if(ui->bym550_pv_uv_ckx->isChecked())
        bym550_mim_err_mask |= 0x4000;
    if(ui->bym550_dc_ov_ckx->isChecked())
        bym550_mim_err_mask |= 0x2000;
    if(ui->bym550_dc_oa_ckx->isChecked())
        bym550_mim_err_mask |= 0x1000;
    if(ui->bym550_dc_ot_ckx->isChecked())
        bym550_mim_err_mask |= 0x0800;
    if(ui->bym550_land_ckx->isChecked())
        bym550_mim_err_mask |= 0x0400;
    if(ui->bym550_mppt_ckx->isChecked())
        bym550_mim_err_mask |= 0x0200;
    //后8位
    if(ui->bym550_sync_error->isChecked())
        bym550_mim_err_mask |= 0x0008;
    if(ui->bym550_safe_chain_ckx->isChecked())
        bym550_mim_err_mask |= 0x0004;
    if(ui->bym550_grid_ckx->isChecked())
        bym550_mim_err_mask |= 0x0002;
    if(ui->bym550_off_ckx->isChecked())
        bym550_mim_err_mask |= 0x0001;
    //单路副边
    if(ui->bym550_grid_ov_ckx->isChecked())
        bym550_mis_err_mask |= 0x8000;
    if(ui->bym550_grid_uv_ckx->isChecked())
        bym550_mis_err_mask |= 0x4000;
    if(ui->bym550_grid_of_ckx->isChecked())
        bym550_mis_err_mask |= 0x2000;
    if(ui->bym550_grid_uf_ckx->isChecked())
        bym550_mis_err_mask |= 0x1000;
    if(ui->bym550_lock_ckx->isChecked())
        bym550_mis_err_mask |= 0x0800;
    if(ui->bym550_surge_ckx->isChecked())
        bym550_mis_err_mask |= 0x0400;
    if(ui->bym550_mcu_uv_ckx->isChecked())
        bym550_mis_err_mask |= 0x0200;
    if(ui->bym550_pv_uv_ckx_2->isChecked())
        bym550_mis_err_mask |= 0x0100;

    if(ui->bym550_hbd_oa_ckx->isChecked())
        bym550_mis_err_mask |= 0x0080;
    if(ui->bym550_hbd_ov_ckx->isChecked())
        bym550_mis_err_mask |= 0x0040;
    if(ui->bym550_cmu_ckx->isChecked())
        bym550_mis_err_mask |= 0x0004;
    if(ui->bym550_gf_out_ckx->isChecked())
        bym550_mis_err_mask |= 0x0002;
    if(ui->bym550_gv_out_ckx->isChecked())
        bym550_mis_err_mask |= 0x0001;

    bym550_jsobj.insert("mim1_err",bym550_mim_err_mask);
    bym550_jsobj.insert("mis_err",bym550_mis_err_mask);
    //bym600
    QJsonObject bym600_jsobj;

    bym600_jsobj.insert("v_start_point_offset",ui->bym600_aging_offset_edt->text().toInt());
    bym600_jsobj.insert("ignore_points_max",ui->bym600_ignore_max_edt->text().toInt());
    bym600_jsobj.insert("drop_points_max",ui->bym600_drop_max_edt->text().toInt());
    bym600_jsobj.insert("drop_value",ui->bym600_drop_value_edt->text().toInt());
    if(ui->bym600_aging_num_ckx->checkState() == Qt::Unchecked)
    {
        bym600_jsobj.insert("v_aging_points",-1);
    }
    else
    {
        bym600_jsobj.insert("v_aging_points",ui->bym600_aging_num_edt->text().toInt());
    }

    if(ui->bym600_aging_time_ckx->checkState() == Qt::Unchecked)
    {
        bym600_jsobj.insert("v_aging_time",-1);
    }
    else
    {
        bym600_jsobj.insert("v_aging_time",ui->bym600_aging_time_edt->text().toInt());
    }

    if(ui->bym600_rt40_time_ckx->checkState() == Qt::Unchecked)
    {
        bym600_jsobj.insert("v_rm40_pwmin",-1);
    }
    else
    {
        bym600_jsobj.insert("v_rm40_pwmin",ui->bym600_rt40_time_edt->text().toInt());
    }

    if(ui->bym600_t40_ckx->checkState() == Qt::Unchecked)
    {
        bym600_jsobj.insert("v_rm40_tmax",-1);
    }
    else
    {
        bym600_jsobj.insert("v_rm40_tmax",ui->bym600_t40_edt->text().toInt());
    }

    if(ui->bym600_rt45_time_ckx->checkState() == Qt::Unchecked)
    {
        bym600_jsobj.insert("v_rm45_pwmin",-1);
    }
    else
    {
        bym600_jsobj.insert("v_rm45_pwmin",ui->bym600_rt45_time_edt->text().toInt());
    }

    if(ui->bym600_t45_ckx->checkState() == Qt::Unchecked)
    {
        bym600_jsobj.insert("v_rm45_tmax",-1);
    }
    else
    {
        bym600_jsobj.insert("v_rm45_tmax",ui->bym600_t45_edt->text().toInt());
    }

    if(ui->bym600_rt50_time_ckx->checkState() == Qt::Unchecked)
    {
        bym600_jsobj.insert("v_rm50_pwmin",-1);
    }
    else
    {
        bym600_jsobj.insert("v_rm50_pwmin",ui->bym600_rt50_time_edt->text().toInt());
    }

    if(ui->bym600_t50_ckx->checkState() == Qt::Unchecked)
    {
        bym600_jsobj.insert("v_rm50_tmax",-1);
    }
    else
    {
        bym600_jsobj.insert("v_rm50_tmax",ui->bym600_t50_edt->text().toInt());
    }

    if(ui->bym600_rt55_time_ckx->checkState() == Qt::Unchecked)
    {
        bym600_jsobj.insert("v_rm55_pwmin",-1);
    }
    else
    {
        bym600_jsobj.insert("v_rm55_pwmin",ui->bym600_rt55_time_edt->text().toInt());
    }

    if(ui->bym600_t55_ckx->checkState() == Qt::Unchecked)
    {
        bym600_jsobj.insert("v_rm55_tmax",-1);
    }
    else
    {
        bym600_jsobj.insert("v_rm55_tmax",ui->bym600_t55_edt->text().toInt());
    }

    if(ui->bym600_rt60_time_ckx->checkState() == Qt::Unchecked)
    {
        bym600_jsobj.insert("v_rm60_pwmin",-1);
    }
    else
    {
        bym600_jsobj.insert("v_rm60_pwmin",ui->bym600_rt60_time_edt->text().toInt());
    }

    if(ui->bym600_t60_ckx->checkState() == Qt::Unchecked)
    {
        bym600_jsobj.insert("v_rm60_tmax",-1);
    }
    else
    {
        bym600_jsobj.insert("v_rm60_tmax",ui->bym600_t60_edt->text().toInt());
    }

    QJsonObject bym600_pv_jsobj;

    if(ui->bym600_rt40_time_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym600_pv_jsobj.insert("v_pv_rm40_pwmin",-1);
    }
    else
    {
        bym600_pv_jsobj.insert("v_pv_rm40_pwmin",ui->bym600_rt40_time_pv_edt->text().toInt());
    }

    if(ui->bym600_t40_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym600_pv_jsobj.insert("v_pv_rm40_tmax",-1);
    }
    else
    {
        bym600_pv_jsobj.insert("v_pv_rm40_tmax",ui->bym600_t40_pv_edt->text().toInt());
    }

    if(ui->bym600_rt45_time_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym600_pv_jsobj.insert("v_pv_rm45_pwmin",-1);
    }
    else
    {
        bym600_pv_jsobj.insert("v_pv_rm45_pwmin",ui->bym600_rt45_time_pv_edt->text().toInt());
    }

    if(ui->bym600_t45_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym600_pv_jsobj.insert("v_pv_rm45_tmax",-1);
    }
    else
    {
        bym600_pv_jsobj.insert("v_pv_rm45_tmax",ui->bym600_t45_pv_edt->text().toInt());
    }

    if(ui->bym600_rt50_time_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym600_pv_jsobj.insert("v_pv_rm50_pwmin",-1);
    }
    else
    {
        bym600_pv_jsobj.insert("v_pv_rm50_pwmin",ui->bym600_rt50_time_pv_edt->text().toInt());
    }

    if(ui->bym600_t50_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym600_pv_jsobj.insert("v_pv_rm50_tmax",-1);
    }
    else
    {
        bym600_pv_jsobj.insert("v_pv_rm50_tmax",ui->bym600_t50_pv_edt->text().toInt());
    }

    if(ui->bym600_rt55_time_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym600_pv_jsobj.insert("v_pv_rm55_pwmin",-1);
    }
    else
    {
        bym600_pv_jsobj.insert("v_pv_rm55_pwmin",ui->bym600_rt55_time_pv_edt->text().toInt());
    }

    if(ui->bym600_t55_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym600_pv_jsobj.insert("v_pv_rm55_tmax",-1);
    }
    else
    {
        bym600_pv_jsobj.insert("v_pv_rm55_tmax",ui->bym600_t55_pv_edt->text().toInt());
    }

    if(ui->bym600_rt60_time_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym600_pv_jsobj.insert("v_pv_rm60_pwmin",-1);
    }
    else
    {
        bym600_pv_jsobj.insert("v_pv_rm60_pwmin",ui->bym600_rt60_time_pv_edt->text().toInt());
    }

    if(ui->bym600_t60_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym600_pv_jsobj.insert("v_pv_rm60_tmax",-1);
    }
    else
    {
        bym600_pv_jsobj.insert("v_pv_rm60_tmax",ui->bym600_t60_pv_edt->text().toInt());
    }

    QJsonArray bym600_pvs;
    bym600_pvs.append(bym600_pv_jsobj);

    bym600_jsobj.insert("pv_params",bym600_pvs);

    uint16_t bym600_mim_err_mask = 0;
    uint16_t bym600_mis_err_mask = 0;

    if(ui->bym600_pv_ov_ckx->isChecked())
        bym600_mim_err_mask |= 0x8000;
    if(ui->bym600_pv_uv_ckx->isChecked())
        bym600_mim_err_mask |= 0x4000;
    if(ui->bym600_dc_ov_ckx->isChecked())
        bym600_mim_err_mask |= 0x2000;
    if(ui->bym600_dc_oa_ckx->isChecked())
        bym600_mim_err_mask |= 0x1000;
    if(ui->bym600_dc_ot_ckx->isChecked())
        bym600_mim_err_mask |= 0x0800;
    if(ui->bym600_land_ckx->isChecked())
        bym600_mim_err_mask |= 0x0400;
    if(ui->bym600_mppt_ckx->isChecked())
        bym600_mim_err_mask |= 0x0200;
    //后8位
    if(ui->bym600_sync_error->isChecked())
        bym600_mim_err_mask |= 0x0008;
    if(ui->bym600_safe_chain_ckx->isChecked())
        bym600_mim_err_mask |= 0x0004;
    if(ui->bym600_grid_ckx->isChecked())
        bym600_mim_err_mask |= 0x0002;
    if(ui->bym600_off_ckx->isChecked())
        bym600_mim_err_mask |= 0x0001;
    //单路副边
    if(ui->bym600_grid_ov_ckx->isChecked())
        bym600_mis_err_mask |= 0x8000;
    if(ui->bym600_grid_uv_ckx->isChecked())
        bym600_mis_err_mask |= 0x4000;
    if(ui->bym600_grid_of_ckx->isChecked())
        bym600_mis_err_mask |= 0x2000;
    if(ui->bym600_grid_uf_ckx->isChecked())
        bym600_mis_err_mask |= 0x1000;
    if(ui->bym600_lock_ckx->isChecked())
        bym600_mis_err_mask |= 0x0800;
    if(ui->bym600_surge_ckx->isChecked())
        bym600_mis_err_mask |= 0x0400;
    if(ui->bym600_mcu_uv_ckx->isChecked())
        bym600_mis_err_mask |= 0x0200;
    if(ui->bym600_pv_uv_ckx_2->isChecked())
        bym600_mis_err_mask |= 0x0100;

    if(ui->bym600_hbd_oa_ckx->isChecked())
        bym600_mis_err_mask |= 0x0080;
    if(ui->bym600_hbd_ov_ckx->isChecked())
        bym600_mis_err_mask |= 0x0040;
    if(ui->bym600_cmu_ckx->isChecked())
        bym600_mis_err_mask |= 0x0004;
    if(ui->bym600_gf_out_ckx->isChecked())
        bym600_mis_err_mask |= 0x0002;
    if(ui->bym600_gv_out_ckx->isChecked())
        bym600_mis_err_mask |= 0x0001;

    bym600_jsobj.insert("mim1_err",bym600_mim_err_mask);
    bym600_jsobj.insert("mis_err",bym600_mis_err_mask);


    //bym700
    QJsonObject bym700_jsobj;

    bym700_jsobj.insert("v_start_point_offset",ui->bym700_aging_offset_edt->text().toInt());

    bym700_jsobj.insert("ignore_points_max",ui->bym700_ignore_max_edt->text().toInt());
    bym700_jsobj.insert("drop_points_max",ui->bym700_drop_max_edt->text().toInt());
    bym700_jsobj.insert("drop_value",ui->bym700_drop_value_edt->text().toInt());

    if(ui->bym700_aging_num_ckx->checkState() == Qt::Unchecked)
    {
        bym700_jsobj.insert("v_aging_points",-1);
    }
    else
    {
        bym700_jsobj.insert("v_aging_points",ui->bym700_aging_num_edt->text().toInt());
    }

    if(ui->bym700_aging_time_ckx->checkState() == Qt::Unchecked)
    {
        bym700_jsobj.insert("v_aging_time",-1);
    }
    else
    {
        bym700_jsobj.insert("v_aging_time",ui->bym700_aging_time_edt->text().toInt());
    }

    if(ui->bym700_rt40_time_ckx->checkState() == Qt::Unchecked)
    {
        bym700_jsobj.insert("v_rm40_pwmin",-1);
    }
    else
    {
        bym700_jsobj.insert("v_rm40_pwmin",ui->bym700_rt40_time_edt->text().toInt());
    }

    if(ui->bym700_t40_ckx->checkState() == Qt::Unchecked)
    {
        bym700_jsobj.insert("v_rm40_tmax",-1);
    }
    else
    {
        bym700_jsobj.insert("v_rm40_tmax",ui->bym700_t40_edt->text().toInt());
    }

    if(ui->bym700_rt45_time_ckx->checkState() == Qt::Unchecked)
    {
        bym700_jsobj.insert("v_rm45_pwmin",-1);
    }
    else
    {
        bym700_jsobj.insert("v_rm45_pwmin",ui->bym700_rt45_time_edt->text().toInt());
    }

    if(ui->bym700_t45_ckx->checkState() == Qt::Unchecked)
    {
        bym700_jsobj.insert("v_rm45_tmax",-1);
    }
    else
    {
        bym700_jsobj.insert("v_rm45_tmax",ui->bym700_t45_edt->text().toInt());
    }

    if(ui->bym700_rt50_time_ckx->checkState() == Qt::Unchecked)
    {
        bym700_jsobj.insert("v_rm50_pwmin",-1);
    }
    else
    {
        bym700_jsobj.insert("v_rm50_pwmin",ui->bym700_rt50_time_edt->text().toInt());
    }

    if(ui->bym700_t50_ckx->checkState() == Qt::Unchecked)
    {
        bym700_jsobj.insert("v_rm50_tmax",-1);
    }
    else
    {
        bym700_jsobj.insert("v_rm50_tmax",ui->bym700_t50_edt->text().toInt());
    }

    if(ui->bym700_rt55_time_ckx->checkState() == Qt::Unchecked)
    {
        bym700_jsobj.insert("v_rm55_pwmin",-1);
    }
    else
    {
        bym700_jsobj.insert("v_rm55_pwmin",ui->bym700_rt55_time_edt->text().toInt());
    }

    if(ui->bym700_t55_ckx->checkState() == Qt::Unchecked)
    {
        bym700_jsobj.insert("v_rm55_tmax",-1);
    }
    else
    {
        bym700_jsobj.insert("v_rm55_tmax",ui->bym700_t55_edt->text().toInt());
    }

    if(ui->bym700_rt60_time_ckx->checkState() == Qt::Unchecked)
    {
        bym700_jsobj.insert("v_rm60_pwmin",-1);
    }
    else
    {
        bym700_jsobj.insert("v_rm60_pwmin",ui->bym700_rt60_time_edt->text().toInt());
    }

    if(ui->bym700_t60_ckx->checkState() == Qt::Unchecked)
    {
        bym700_jsobj.insert("v_rm60_tmax",-1);
    }
    else
    {
        bym700_jsobj.insert("v_rm60_tmax",ui->bym700_t60_edt->text().toInt());
    }

    QJsonObject bym700_pv_jsobj;

    if(ui->bym700_rt40_time_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym700_pv_jsobj.insert("v_pv_rm40_pwmin",-1);
    }
    else
    {
        bym700_pv_jsobj.insert("v_pv_rm40_pwmin",ui->bym700_rt40_time_pv_edt->text().toInt());
    }

    if(ui->bym700_t40_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym700_pv_jsobj.insert("v_pv_rm40_tmax",-1);
    }
    else
    {
        bym700_pv_jsobj.insert("v_pv_rm40_tmax",ui->bym700_t40_pv_edt->text().toInt());
    }

    if(ui->bym700_rt45_time_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym700_pv_jsobj.insert("v_pv_rm45_pwmin",-1);
    }
    else
    {
        bym700_pv_jsobj.insert("v_pv_rm45_pwmin",ui->bym700_rt45_time_pv_edt->text().toInt());
    }

    if(ui->bym700_t45_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym700_pv_jsobj.insert("v_pv_rm45_tmax",-1);
    }
    else
    {
        bym700_pv_jsobj.insert("v_pv_rm45_tmax",ui->bym700_t45_pv_edt->text().toInt());
    }

    if(ui->bym700_rt50_time_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym700_pv_jsobj.insert("v_pv_rm50_pwmin",-1);
    }
    else
    {
        bym700_pv_jsobj.insert("v_pv_rm50_pwmin",ui->bym700_rt50_time_pv_edt->text().toInt());
    }

    if(ui->bym700_t50_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym700_pv_jsobj.insert("v_pv_rm50_tmax",-1);
    }
    else
    {
        bym700_pv_jsobj.insert("v_pv_rm50_tmax",ui->bym700_t50_pv_edt->text().toInt());
    }

    if(ui->bym700_rt55_time_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym700_pv_jsobj.insert("v_pv_rm55_pwmin",-1);
    }
    else
    {
        bym700_pv_jsobj.insert("v_pv_rm55_pwmin",ui->bym700_rt55_time_pv_edt->text().toInt());
    }

    if(ui->bym700_t55_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym700_pv_jsobj.insert("v_pv_rm55_tmax",-1);
    }
    else
    {
        bym700_pv_jsobj.insert("v_pv_rm55_tmax",ui->bym700_t55_pv_edt->text().toInt());
    }

    if(ui->bym700_rt60_time_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym700_pv_jsobj.insert("v_pv_rm60_pwmin",-1);
    }
    else
    {
        bym700_pv_jsobj.insert("v_pv_rm60_pwmin",ui->bym700_rt60_time_pv_edt->text().toInt());
    }

    if(ui->bym700_t60_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym700_pv_jsobj.insert("v_pv_rm60_tmax",-1);
    }
    else
    {
        bym700_pv_jsobj.insert("v_pv_rm60_tmax",ui->bym700_t60_pv_edt->text().toInt());
    }

    QJsonArray bym700_pvs;
    bym700_pvs.append(bym700_pv_jsobj);

    bym700_jsobj.insert("pv_params",bym700_pvs);

    uint16_t bym700_mim_err_mask = 0;
    uint16_t bym700_mis_err_mask = 0;

    if(ui->bym700_pv_ov_ckx->isChecked())
        bym700_mim_err_mask |= 0x8000;
    if(ui->bym700_pv_uv_ckx->isChecked())
        bym700_mim_err_mask |= 0x4000;
    if(ui->bym700_dc_ov_ckx->isChecked())
        bym700_mim_err_mask |= 0x2000;
    if(ui->bym700_dc_oa_ckx->isChecked())
        bym700_mim_err_mask |= 0x1000;
    if(ui->bym700_dc_ot_ckx->isChecked())
        bym700_mim_err_mask |= 0x0800;
    if(ui->bym700_land_ckx->isChecked())
        bym700_mim_err_mask |= 0x0400;
    if(ui->bym700_mppt_ckx->isChecked())
        bym700_mim_err_mask |= 0x0200;
    //后8位
    if(ui->bym700_sync_error->isChecked())
        bym700_mim_err_mask |= 0x0008;
    if(ui->bym700_safe_chain_ckx->isChecked())
        bym700_mim_err_mask |= 0x0004;
    if(ui->bym700_grid_ckx->isChecked())
        bym700_mim_err_mask |= 0x0002;
    if(ui->bym700_off_ckx->isChecked())
        bym700_mim_err_mask |= 0x0001;
    //单路副边
    if(ui->bym700_grid_ov_ckx->isChecked())
        bym700_mis_err_mask |= 0x8000;
    if(ui->bym700_grid_uv_ckx->isChecked())
        bym700_mis_err_mask |= 0x4000;
    if(ui->bym700_grid_of_ckx->isChecked())
        bym700_mis_err_mask |= 0x2000;
    if(ui->bym700_grid_uf_ckx->isChecked())
        bym700_mis_err_mask |= 0x1000;
    if(ui->bym700_lock_ckx->isChecked())
        bym700_mis_err_mask |= 0x0800;
    if(ui->bym700_surge_ckx->isChecked())
        bym700_mis_err_mask |= 0x0400;
    if(ui->bym700_mcu_uv_ckx->isChecked())
        bym700_mis_err_mask |= 0x0200;
    if(ui->bym700_pv_uv_ckx_2->isChecked())
        bym700_mis_err_mask |= 0x0100;

    if(ui->bym700_hbd_oa_ckx->isChecked())
        bym700_mis_err_mask |= 0x0080;
    if(ui->bym700_hbd_ov_ckx->isChecked())
        bym700_mis_err_mask |= 0x0040;
    if(ui->bym700_cmu_ckx->isChecked())
        bym700_mis_err_mask |= 0x0004;
    if(ui->bym700_gf_out_ckx->isChecked())
        bym700_mis_err_mask |= 0x0002;
    if(ui->bym700_gv_out_ckx->isChecked())
        bym700_mis_err_mask |= 0x0001;

    bym700_jsobj.insert("mim1_err",bym700_mim_err_mask);
    bym700_jsobj.insert("mis_err",bym700_mis_err_mask);

    //bym800
    QJsonObject bym800_jsobj;

    bym800_jsobj.insert("v_start_point_offset",ui->bym800_aging_offset_edt->text().toInt());
    bym800_jsobj.insert("ignore_points_max",ui->bym800_ignore_max_edt->text().toInt());
    bym800_jsobj.insert("drop_points_max",ui->bym800_drop_max_edt->text().toInt());
    bym800_jsobj.insert("drop_value",ui->bym800_drop_value_edt->text().toInt());
    if(ui->bym800_aging_num_ckx->checkState() == Qt::Unchecked)
    {
        bym800_jsobj.insert("v_aging_points",-1);
    }
    else
    {
        bym800_jsobj.insert("v_aging_points",ui->bym800_aging_num_edt->text().toInt());
    }

    if(ui->bym800_aging_time_ckx->checkState() == Qt::Unchecked)
    {
        bym800_jsobj.insert("v_aging_time",-1);
    }
    else
    {
        bym800_jsobj.insert("v_aging_time",ui->bym800_aging_time_edt->text().toInt());
    }

    if(ui->bym800_rt40_time_ckx->checkState() == Qt::Unchecked)
    {
        bym800_jsobj.insert("v_rm40_pwmin",-1);
    }
    else
    {
        bym800_jsobj.insert("v_rm40_pwmin",ui->bym800_rt40_time_edt->text().toInt());
    }

    if(ui->bym800_t40_ckx->checkState() == Qt::Unchecked)
    {
        bym800_jsobj.insert("v_rm40_tmax",-1);
    }
    else
    {
        bym800_jsobj.insert("v_rm40_tmax",ui->bym800_t40_edt->text().toInt());
    }

    if(ui->bym800_rt45_time_ckx->checkState() == Qt::Unchecked)
    {
        bym800_jsobj.insert("v_rm45_pwmin",-1);
    }
    else
    {
        bym800_jsobj.insert("v_rm45_pwmin",ui->bym800_rt45_time_edt->text().toInt());
    }

    if(ui->bym800_t45_ckx->checkState() == Qt::Unchecked)
    {
        bym800_jsobj.insert("v_rm45_tmax",-1);
    }
    else
    {
        bym800_jsobj.insert("v_rm45_tmax",ui->bym800_t45_edt->text().toInt());
    }

    if(ui->bym800_rt50_time_ckx->checkState() == Qt::Unchecked)
    {
        bym800_jsobj.insert("v_rm50_pwmin",-1);
    }
    else
    {
        bym800_jsobj.insert("v_rm50_pwmin",ui->bym800_rt50_time_edt->text().toInt());
    }

    if(ui->bym800_t50_ckx->checkState() == Qt::Unchecked)
    {
        bym800_jsobj.insert("v_rm50_tmax",-1);
    }
    else
    {
        bym800_jsobj.insert("v_rm50_tmax",ui->bym800_t50_edt->text().toInt());
    }

    if(ui->bym800_rt55_time_ckx->checkState() == Qt::Unchecked)
    {
        bym800_jsobj.insert("v_rm55_pwmin",-1);
    }
    else
    {
        bym800_jsobj.insert("v_rm55_pwmin",ui->bym800_rt55_time_edt->text().toInt());
    }

    if(ui->bym800_t55_ckx->checkState() == Qt::Unchecked)
    {
        bym800_jsobj.insert("v_rm55_tmax",-1);
    }
    else
    {
        bym800_jsobj.insert("v_rm55_tmax",ui->bym800_t55_edt->text().toInt());
    }

    if(ui->bym800_rt60_time_ckx->checkState() == Qt::Unchecked)
    {
        bym800_jsobj.insert("v_rm60_pwmin",-1);
    }
    else
    {
        bym800_jsobj.insert("v_rm60_pwmin",ui->bym800_rt60_time_edt->text().toInt());
    }

    if(ui->bym800_t60_ckx->checkState() == Qt::Unchecked)
    {
        bym800_jsobj.insert("v_rm60_tmax",-1);
    }
    else
    {
        bym800_jsobj.insert("v_rm60_tmax",ui->bym800_t60_edt->text().toInt());
    }

    QJsonObject bym800_pv_jsobj;

    if(ui->bym800_rt40_time_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym800_pv_jsobj.insert("v_pv_rm40_pwmin",-1);
    }
    else
    {
        bym800_pv_jsobj.insert("v_pv_rm40_pwmin",ui->bym800_rt40_time_pv_edt->text().toInt());
    }

    if(ui->bym800_t40_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym800_pv_jsobj.insert("v_pv_rm40_tmax",-1);
    }
    else
    {
        bym800_pv_jsobj.insert("v_pv_rm40_tmax",ui->bym800_t40_pv_edt->text().toInt());
    }

    if(ui->bym800_rt45_time_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym800_pv_jsobj.insert("v_pv_rm45_pwmin",-1);
    }
    else
    {
        bym800_pv_jsobj.insert("v_pv_rm45_pwmin",ui->bym800_rt45_time_pv_edt->text().toInt());
    }

    if(ui->bym800_t45_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym800_pv_jsobj.insert("v_pv_rm45_tmax",-1);
    }
    else
    {
        bym800_pv_jsobj.insert("v_pv_rm45_tmax",ui->bym800_t45_pv_edt->text().toInt());
    }

    if(ui->bym800_rt50_time_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym800_pv_jsobj.insert("v_pv_rm50_pwmin",-1);
    }
    else
    {
        bym800_pv_jsobj.insert("v_pv_rm50_pwmin",ui->bym800_rt50_time_pv_edt->text().toInt());
    }

    if(ui->bym800_t50_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym800_pv_jsobj.insert("v_pv_rm50_tmax",-1);
    }
    else
    {
        bym800_pv_jsobj.insert("v_pv_rm50_tmax",ui->bym800_t50_pv_edt->text().toInt());
    }

    if(ui->bym800_rt55_time_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym800_pv_jsobj.insert("v_pv_rm55_pwmin",-1);
    }
    else
    {
        bym800_pv_jsobj.insert("v_pv_rm55_pwmin",ui->bym800_rt55_time_pv_edt->text().toInt());
    }

    if(ui->bym800_t55_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym800_pv_jsobj.insert("v_pv_rm55_tmax",-1);
    }
    else
    {
        bym800_pv_jsobj.insert("v_pv_rm55_tmax",ui->bym800_t55_pv_edt->text().toInt());
    }

    if(ui->bym800_rt60_time_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym800_pv_jsobj.insert("v_pv_rm60_pwmin",-1);
    }
    else
    {
        bym800_pv_jsobj.insert("v_pv_rm60_pwmin",ui->bym800_rt60_time_pv_edt->text().toInt());
    }

    if(ui->bym800_t60_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym800_pv_jsobj.insert("v_pv_rm60_tmax",-1);
    }
    else
    {
        bym800_pv_jsobj.insert("v_pv_rm60_tmax",ui->bym800_t60_pv_edt->text().toInt());
    }

    QJsonArray bym800_pvs;
    bym800_pvs.append(bym800_pv_jsobj);

    bym800_jsobj.insert("pv_params",bym800_pvs);

    uint16_t bym800_mim_err_mask = 0;
    uint16_t bym800_mis_err_mask = 0;

    if(ui->bym800_pv_ov_ckx->isChecked())
        bym800_mim_err_mask |= 0x8000;
    if(ui->bym800_pv_uv_ckx->isChecked())
        bym800_mim_err_mask |= 0x4000;
    if(ui->bym800_dc_ov_ckx->isChecked())
        bym800_mim_err_mask |= 0x2000;
    if(ui->bym800_dc_oa_ckx->isChecked())
        bym800_mim_err_mask |= 0x1000;
    if(ui->bym800_dc_ot_ckx->isChecked())
        bym800_mim_err_mask |= 0x0800;
    if(ui->bym800_land_ckx->isChecked())
        bym800_mim_err_mask |= 0x0400;
    if(ui->bym800_mppt_ckx->isChecked())
        bym800_mim_err_mask |= 0x0200;
    //后8位
    if(ui->bym800_sync_error->isChecked())
        bym800_mim_err_mask |= 0x0008;
    if(ui->bym800_safe_chain_ckx->isChecked())
        bym800_mim_err_mask |= 0x0004;
    if(ui->bym800_grid_ckx->isChecked())
        bym800_mim_err_mask |= 0x0002;
    if(ui->bym800_off_ckx->isChecked())
        bym800_mim_err_mask |= 0x0001;
    //单路副边
    if(ui->bym800_grid_ov_ckx->isChecked())
        bym800_mis_err_mask |= 0x8000;
    if(ui->bym800_grid_uv_ckx->isChecked())
        bym800_mis_err_mask |= 0x4000;
    if(ui->bym800_grid_of_ckx->isChecked())
        bym800_mis_err_mask |= 0x2000;
    if(ui->bym800_grid_uf_ckx->isChecked())
        bym800_mis_err_mask |= 0x1000;
    if(ui->bym800_lock_ckx->isChecked())
        bym800_mis_err_mask |= 0x0800;
    if(ui->bym800_surge_ckx->isChecked())
        bym800_mis_err_mask |= 0x0400;
    if(ui->bym800_mcu_uv_ckx->isChecked())
        bym800_mis_err_mask |= 0x0200;
    if(ui->bym800_pv_uv_ckx_2->isChecked())
        bym800_mis_err_mask |= 0x0100;

    if(ui->bym800_hbd_oa_ckx->isChecked())
        bym800_mis_err_mask |= 0x0080;
    if(ui->bym800_hbd_ov_ckx->isChecked())
        bym800_mis_err_mask |= 0x0040;
    if(ui->bym800_cmu_ckx->isChecked())
        bym800_mis_err_mask |= 0x0004;
    if(ui->bym800_gf_out_ckx->isChecked())
        bym800_mis_err_mask |= 0x0002;
    if(ui->bym800_gv_out_ckx->isChecked())
        bym800_mis_err_mask |= 0x0001;

    bym800_jsobj.insert("mim1_err",bym800_mim_err_mask);
    bym800_jsobj.insert("mis_err",bym800_mis_err_mask);



    //bym1000
    QJsonObject bym1000_jsobj;

    bym1000_jsobj.insert("v_start_point_offset",ui->bym1000_aging_offset_edt->text().toInt());
    bym1000_jsobj.insert("ignore_points_max",ui->bym1000_ignore_max_edt->text().toInt());
    bym1000_jsobj.insert("drop_points_max",ui->bym1000_drop_max_edt->text().toInt());
    bym1000_jsobj.insert("drop_value",ui->bym1000_drop_value_edt->text().toInt());
    if(ui->bym1000_aging_num_ckx->checkState() == Qt::Unchecked)
    {
        bym1000_jsobj.insert("v_aging_points",-1);
    }
    else
    {
        bym1000_jsobj.insert("v_aging_points",ui->bym1000_aging_num_edt->text().toInt());
    }

    if(ui->bym1000_aging_time_ckx->checkState() == Qt::Unchecked)
    {
        bym1000_jsobj.insert("v_aging_time",-1);
    }
    else
    {
        bym1000_jsobj.insert("v_aging_time",ui->bym1000_aging_time_edt->text().toInt());
    }

    if(ui->bym1000_rt40_time_ckx->checkState() == Qt::Unchecked)
    {
        bym1000_jsobj.insert("v_rm40_pwmin",-1);
    }
    else
    {
        bym1000_jsobj.insert("v_rm40_pwmin",ui->bym1000_rt40_time_edt->text().toInt());
    }

    if(ui->bym1000_t40_ckx->checkState() == Qt::Unchecked)
    {
        bym1000_jsobj.insert("v_rm40_tmax",-1);
    }
    else
    {
        bym1000_jsobj.insert("v_rm40_tmax",ui->bym1000_t40_edt->text().toInt());
    }

    if(ui->bym1000_rt45_time_ckx->checkState() == Qt::Unchecked)
    {
        bym1000_jsobj.insert("v_rm45_pwmin",-1);
    }
    else
    {
        bym1000_jsobj.insert("v_rm45_pwmin",ui->bym1000_rt45_time_edt->text().toInt());
    }

    if(ui->bym1000_t45_ckx->checkState() == Qt::Unchecked)
    {
        bym1000_jsobj.insert("v_rm45_tmax",-1);
    }
    else
    {
        bym1000_jsobj.insert("v_rm45_tmax",ui->bym1000_t45_edt->text().toInt());
    }

    if(ui->bym1000_rt50_time_ckx->checkState() == Qt::Unchecked)
    {
        bym1000_jsobj.insert("v_rm50_pwmin",-1);
    }
    else
    {
        bym1000_jsobj.insert("v_rm50_pwmin",ui->bym1000_rt50_time_edt->text().toInt());
    }

    if(ui->bym1000_t50_ckx->checkState() == Qt::Unchecked)
    {
        bym1000_jsobj.insert("v_rm50_tmax",-1);
    }
    else
    {
        bym1000_jsobj.insert("v_rm50_tmax",ui->bym1000_t50_edt->text().toInt());
    }

    if(ui->bym1000_rt55_time_ckx->checkState() == Qt::Unchecked)
    {
        bym1000_jsobj.insert("v_rm55_pwmin",-1);
    }
    else
    {
        bym1000_jsobj.insert("v_rm55_pwmin",ui->bym1000_rt55_time_edt->text().toInt());
    }

    if(ui->bym1000_t55_ckx->checkState() == Qt::Unchecked)
    {
        bym1000_jsobj.insert("v_rm55_tmax",-1);
    }
    else
    {
        bym1000_jsobj.insert("v_rm55_tmax",ui->bym1000_t55_edt->text().toInt());
    }

    if(ui->bym1000_rt60_time_ckx->checkState() == Qt::Unchecked)
    {
        bym1000_jsobj.insert("v_rm60_pwmin",-1);
    }
    else
    {
        bym1000_jsobj.insert("v_rm60_pwmin",ui->bym1000_rt60_time_edt->text().toInt());
    }

    if(ui->bym1000_t60_ckx->checkState() == Qt::Unchecked)
    {
        bym1000_jsobj.insert("v_rm60_tmax",-1);
    }
    else
    {
        bym1000_jsobj.insert("v_rm60_tmax",ui->bym1000_t60_edt->text().toInt());
    }

    QJsonObject bym1000_pv_jsobj;

    if(ui->bym1000_rt40_time_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym1000_pv_jsobj.insert("v_pv_rm40_pwmin",-1);
    }
    else
    {
        bym1000_pv_jsobj.insert("v_pv_rm40_pwmin",ui->bym1000_rt40_time_pv_edt->text().toInt());
    }

    if(ui->bym1000_t40_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym1000_pv_jsobj.insert("v_pv_rm40_tmax",-1);
    }
    else
    {
        bym1000_pv_jsobj.insert("v_pv_rm40_tmax",ui->bym1000_t40_pv_edt->text().toInt());
    }

    if(ui->bym1000_rt45_time_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym1000_pv_jsobj.insert("v_pv_rm45_pwmin",-1);
    }
    else
    {
        bym1000_pv_jsobj.insert("v_pv_rm45_pwmin",ui->bym1000_rt45_time_pv_edt->text().toInt());
    }

    if(ui->bym1000_t45_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym1000_pv_jsobj.insert("v_pv_rm45_tmax",-1);
    }
    else
    {
        bym1000_pv_jsobj.insert("v_pv_rm45_tmax",ui->bym1000_t45_pv_edt->text().toInt());
    }

    if(ui->bym1000_rt50_time_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym1000_pv_jsobj.insert("v_pv_rm50_pwmin",-1);
    }
    else
    {
        bym1000_pv_jsobj.insert("v_pv_rm50_pwmin",ui->bym1000_rt50_time_pv_edt->text().toInt());
    }

    if(ui->bym1000_t50_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym1000_pv_jsobj.insert("v_pv_rm50_tmax",-1);
    }
    else
    {
        bym1000_pv_jsobj.insert("v_pv_rm50_tmax",ui->bym1000_t50_pv_edt->text().toInt());
    }

    if(ui->bym1000_rt55_time_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym1000_pv_jsobj.insert("v_pv_rm55_pwmin",-1);
    }
    else
    {
        bym1000_pv_jsobj.insert("v_pv_rm55_pwmin",ui->bym1000_rt55_time_pv_edt->text().toInt());
    }

    if(ui->bym1000_t55_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym1000_pv_jsobj.insert("v_pv_rm55_tmax",-1);
    }
    else
    {
        bym1000_pv_jsobj.insert("v_pv_rm55_tmax",ui->bym1000_t55_pv_edt->text().toInt());
    }

    if(ui->bym1000_rt60_time_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym1000_pv_jsobj.insert("v_pv_rm60_pwmin",-1);
    }
    else
    {
        bym1000_pv_jsobj.insert("v_pv_rm60_pwmin",ui->bym1000_rt60_time_pv_edt->text().toInt());
    }

    if(ui->bym1000_t60_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym1000_pv_jsobj.insert("v_pv_rm60_tmax",-1);
    }
    else
    {
        bym1000_pv_jsobj.insert("v_pv_rm60_tmax",ui->bym1000_t60_pv_edt->text().toInt());
    }

    QJsonArray bym1000_pvs;
    bym1000_pvs.append(bym1000_pv_jsobj);

    bym1000_jsobj.insert("pv_params",bym1000_pvs);

    uint16_t bym1000_mim1_err_mask = 0;
    //uint16_t bym1000_mim2_err_mask = 0;
    uint16_t bym1000_mis_err_mask = 0;

    if(ui->bym1000_pv_ov_bym4_pv1_ckx->isChecked())
        bym1000_mim1_err_mask |= 0x8000;
    if(ui->bym1000_pv_uv_bym4_pv1_ckx->isChecked())
        bym1000_mim1_err_mask |= 0x4000;
    if(ui->bym1000_dc_ov_bym4_pv1_ckx->isChecked())
        bym1000_mim1_err_mask |= 0x2000;
    if(ui->bym1000_dc_oa_bym4_pv1_ckx->isChecked())
        bym1000_mim1_err_mask |= 0x1000;
    if(ui->bym1000_dc_ot_bym4_pv1_ckx->isChecked())
        bym1000_mim1_err_mask |= 0x0800;
    if(ui->bym1000_land_bym4_pv12_ckx->isChecked())
        bym1000_mim1_err_mask |= 0x0400;
    if(ui->bym1000_mppt_bym4_pv12_ckx->isChecked())
        bym1000_mim1_err_mask |= 0x0200;
    if(ui->bym1000_dc_ot_bym4_pv2_ckx->isChecked())
        bym1000_mim1_err_mask |= 0x0100;
    if(ui->bym1000_pv_ov_bym4_pv2_ckx->isChecked())
        bym1000_mim1_err_mask |= 0x0080;
    if(ui->bym1000_pv_uv_bym4_pv2_ckx->isChecked())
        bym1000_mim1_err_mask |= 0x0040;
    if(ui->bym1000_dc_ov_bym4_pv2_ckx->isChecked())
        bym1000_mim1_err_mask |= 0x0020;
    if(ui->bym1000_dc_oa_bym4_pv2_ckx->isChecked())
        bym1000_mim1_err_mask |= 0x0010;
    if(ui->bym1000_sync_error_bym4_pv12_ckx->isChecked())
        bym1000_mim1_err_mask |= 0x0008;
    if(ui->bym1000_safe_chain_bym4_pv12_ckx->isChecked())
        bym1000_mim1_err_mask |= 0x0004;
    if(ui->bym1000_grid_bym4_pv12_ckx->isChecked())
        bym1000_mim1_err_mask |= 0x0002;
    if(ui->bym1000_off_bym4_pv12_ckx->isChecked())
        bym1000_mim1_err_mask |= 0x0001;
    //4路副边
    if(ui->bym1000_grid_ov_bym4_ckx->isChecked())
        bym1000_mis_err_mask |= 0x8000;
    if(ui->bym1000_grid_uv_bym4_ckx->isChecked())
        bym1000_mis_err_mask |= 0x4000;
    if(ui->bym1000_grid_of_bym4_ckx->isChecked())
        bym1000_mis_err_mask |= 0x2000;
    if(ui->bym1000_grid_uf_bym4_ckx->isChecked())
        bym1000_mis_err_mask |= 0x1000;
    if(ui->bym1000_lock_ckx_bym4_ckx->isChecked())
        bym1000_mis_err_mask |= 0x0800;
    if(ui->bym1000_surge_bym4_ckx->isChecked())
        bym1000_mis_err_mask |= 0x0400;
    if(ui->bym1000_mcu_uv_bym4_ckx->isChecked())
        bym1000_mis_err_mask |= 0x0200;
    if(ui->bym1000_pv_uv_bym4_ckx->isChecked())
        bym1000_mis_err_mask |= 0x0100;
    if(ui->bym1000_hbd_oa_bym4_ckx->isChecked())
        bym1000_mis_err_mask |= 0x0080;
    if(ui->bym1000_hbd_ov_bym4_ckx->isChecked())
        bym1000_mis_err_mask |= 0x0040;
    if(ui->bym1000_cmu_primary2_bym4_ckx->isChecked())
        bym1000_mis_err_mask |= 0x0008;
    if(ui->bym1000_cmu_primary1_bym4_ckx->isChecked())
        bym1000_mis_err_mask |= 0x0004;

    bym1000_jsobj.insert("mim1_err",bym1000_mim1_err_mask);
    //bym1000_jsobj.insert("mim2_err",bym1000_mim2_err_mask);
    bym1000_jsobj.insert("mis_err",bym1000_mis_err_mask);

    //bym1200
    QJsonObject bym1200_jsobj;

    bym1200_jsobj.insert("v_start_point_offset",ui->bym1200_aging_offset_edt->text().toInt());
    bym1200_jsobj.insert("ignore_points_max",ui->bym1200_ignore_max_edt->text().toInt());
    bym1200_jsobj.insert("drop_points_max",ui->bym1200_drop_max_edt->text().toInt());
    bym1200_jsobj.insert("drop_value",ui->bym1200_drop_value_edt->text().toInt());
    if(ui->bym1200_aging_num_ckx->checkState() == Qt::Unchecked)
    {
        bym1200_jsobj.insert("v_aging_points",-1);
    }
    else
    {
        bym1200_jsobj.insert("v_aging_points",ui->bym1200_aging_num_edt->text().toInt());
    }

    if(ui->bym1200_aging_time_ckx->checkState() == Qt::Unchecked)
    {
        bym1200_jsobj.insert("v_aging_time",-1);
    }
    else
    {
        bym1200_jsobj.insert("v_aging_time",ui->bym1200_aging_time_edt->text().toInt());
    }

    if(ui->bym1200_rt40_time_ckx->checkState() == Qt::Unchecked)
    {
        bym1200_jsobj.insert("v_rm40_pwmin",-1);
    }
    else
    {
        bym1200_jsobj.insert("v_rm40_pwmin",ui->bym1200_rt40_time_edt->text().toInt());
    }

    if(ui->bym1200_t40_ckx->checkState() == Qt::Unchecked)
    {
        bym1200_jsobj.insert("v_rm40_tmax",-1);
    }
    else
    {
        bym1200_jsobj.insert("v_rm40_tmax",ui->bym1200_t40_edt->text().toInt());
    }

    if(ui->bym1200_rt45_time_ckx->checkState() == Qt::Unchecked)
    {
        bym1200_jsobj.insert("v_rm45_pwmin",-1);
    }
    else
    {
        bym1200_jsobj.insert("v_rm45_pwmin",ui->bym1200_rt45_time_edt->text().toInt());
    }

    if(ui->bym1200_t45_ckx->checkState() == Qt::Unchecked)
    {
        bym1200_jsobj.insert("v_rm45_tmax",-1);
    }
    else
    {
        bym1200_jsobj.insert("v_rm45_tmax",ui->bym1200_t45_edt->text().toInt());
    }

    if(ui->bym1200_rt50_time_ckx->checkState() == Qt::Unchecked)
    {
        bym1200_jsobj.insert("v_rm50_pwmin",-1);
    }
    else
    {
        bym1200_jsobj.insert("v_rm50_pwmin",ui->bym1200_rt50_time_edt->text().toInt());
    }

    if(ui->bym1200_t50_ckx->checkState() == Qt::Unchecked)
    {
        bym1200_jsobj.insert("v_rm50_tmax",-1);
    }
    else
    {
        bym1200_jsobj.insert("v_rm50_tmax",ui->bym1200_t50_edt->text().toInt());
    }

    if(ui->bym1200_rt55_time_ckx->checkState() == Qt::Unchecked)
    {
        bym1200_jsobj.insert("v_rm55_pwmin",-1);
    }
    else
    {
        bym1200_jsobj.insert("v_rm55_pwmin",ui->bym1200_rt55_time_edt->text().toInt());
    }

    if(ui->bym1200_t55_ckx->checkState() == Qt::Unchecked)
    {
        bym1200_jsobj.insert("v_rm55_tmax",-1);
    }
    else
    {
        bym1200_jsobj.insert("v_rm55_tmax",ui->bym1200_t55_edt->text().toInt());
    }

    if(ui->bym1200_rt60_time_ckx->checkState() == Qt::Unchecked)
    {
        bym1200_jsobj.insert("v_rm60_pwmin",-1);
    }
    else
    {
        bym1200_jsobj.insert("v_rm60_pwmin",ui->bym1200_rt60_time_edt->text().toInt());
    }

    if(ui->bym1200_t60_ckx->checkState() == Qt::Unchecked)
    {
        bym1200_jsobj.insert("v_rm60_tmax",-1);
    }
    else
    {
        bym1200_jsobj.insert("v_rm60_tmax",ui->bym1200_t60_edt->text().toInt());
    }

    QJsonObject bym1200_pv_jsobj;

    if(ui->bym1200_rt40_time_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym1200_pv_jsobj.insert("v_pv_rm40_pwmin",-1);
    }
    else
    {
        bym1200_pv_jsobj.insert("v_pv_rm40_pwmin",ui->bym1200_rt40_time_pv_edt->text().toInt());
    }

    if(ui->bym1200_t40_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym1200_pv_jsobj.insert("v_pv_rm40_tmax",-1);
    }
    else
    {
        bym1200_pv_jsobj.insert("v_pv_rm40_tmax",ui->bym1200_t40_pv_edt->text().toInt());
    }

    if(ui->bym1200_rt45_time_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym1200_pv_jsobj.insert("v_pv_rm45_pwmin",-1);
    }
    else
    {
        bym1200_pv_jsobj.insert("v_pv_rm45_pwmin",ui->bym1200_rt45_time_pv_edt->text().toInt());
    }

    if(ui->bym1200_t45_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym1200_pv_jsobj.insert("v_pv_rm45_tmax",-1);
    }
    else
    {
        bym1200_pv_jsobj.insert("v_pv_rm45_tmax",ui->bym1200_t45_pv_edt->text().toInt());
    }

    if(ui->bym1200_rt50_time_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym1200_pv_jsobj.insert("v_pv_rm50_pwmin",-1);
    }
    else
    {
        bym1200_pv_jsobj.insert("v_pv_rm50_pwmin",ui->bym1200_rt50_time_pv_edt->text().toInt());
    }

    if(ui->bym1200_t50_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym1200_pv_jsobj.insert("v_pv_rm50_tmax",-1);
    }
    else
    {
        bym1200_pv_jsobj.insert("v_pv_rm50_tmax",ui->bym1200_t50_pv_edt->text().toInt());
    }

    if(ui->bym1200_rt55_time_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym1200_pv_jsobj.insert("v_pv_rm55_pwmin",-1);
    }
    else
    {
        bym1200_pv_jsobj.insert("v_pv_rm55_pwmin",ui->bym1200_rt55_time_pv_edt->text().toInt());
    }

    if(ui->bym1200_t55_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym1200_pv_jsobj.insert("v_pv_rm55_tmax",-1);
    }
    else
    {
        bym1200_pv_jsobj.insert("v_pv_rm55_tmax",ui->bym1200_t55_pv_edt->text().toInt());
    }

    if(ui->bym1200_rt60_time_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym1200_pv_jsobj.insert("v_pv_rm60_pwmin",-1);
    }
    else
    {
        bym1200_pv_jsobj.insert("v_pv_rm60_pwmin",ui->bym1200_rt60_time_pv_edt->text().toInt());
    }

    if(ui->bym1200_t60_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym1200_pv_jsobj.insert("v_pv_rm60_tmax",-1);
    }
    else
    {
        bym1200_pv_jsobj.insert("v_pv_rm60_tmax",ui->bym1200_t60_pv_edt->text().toInt());
    }

    QJsonArray bym1200_pvs;
    bym1200_pvs.append(bym1200_pv_jsobj);

    bym1200_jsobj.insert("pv_params",bym1200_pvs);

    uint16_t bym1200_mim1_err_mask = 0;
    //uint16_t bym1200_mim2_err_mask = 0;
    uint16_t bym1200_mis_err_mask = 0;

    if(ui->bym1200_pv_ov_bym4_pv1_ckx->isChecked())
        bym1200_mim1_err_mask |= 0x8000;
    if(ui->bym1200_pv_uv_bym4_pv1_ckx->isChecked())
        bym1200_mim1_err_mask |= 0x4000;
    if(ui->bym1200_dc_ov_bym4_pv1_ckx->isChecked())
        bym1200_mim1_err_mask |= 0x2000;
    if(ui->bym1200_dc_oa_bym4_pv1_ckx->isChecked())
        bym1200_mim1_err_mask |= 0x1000;
    if(ui->bym1200_dc_ot_bym4_pv1_ckx->isChecked())
        bym1200_mim1_err_mask |= 0x0800;
    if(ui->bym1200_land_bym4_pv12_ckx->isChecked())
        bym1200_mim1_err_mask |= 0x0400;
    if(ui->bym1200_mppt_bym4_pv12_ckx->isChecked())
        bym1200_mim1_err_mask |= 0x0200;
    if(ui->bym1200_dc_ot_bym4_pv2_ckx->isChecked())
        bym1200_mim1_err_mask |= 0x0100;
    if(ui->bym1200_pv_ov_bym4_pv2_ckx->isChecked())
        bym1200_mim1_err_mask |= 0x0080;
    if(ui->bym1200_pv_uv_bym4_pv2_ckx->isChecked())
        bym1200_mim1_err_mask |= 0x0040;
    if(ui->bym1200_dc_ov_bym4_pv2_ckx->isChecked())
        bym1200_mim1_err_mask |= 0x0020;
    if(ui->bym1200_dc_oa_bym4_pv2_ckx->isChecked())
        bym1200_mim1_err_mask |= 0x0010;
    if(ui->bym1200_sync_error_bym4_pv12_ckx->isChecked())
        bym1200_mim1_err_mask |= 0x0008;
    if(ui->bym1200_safe_chain_bym4_pv12_ckx->isChecked())
        bym1200_mim1_err_mask |= 0x0004;
    if(ui->bym1200_grid_bym4_pv12_ckx->isChecked())
        bym1200_mim1_err_mask |= 0x0002;
    if(ui->bym1200_off_bym4_pv12_ckx->isChecked())
        bym1200_mim1_err_mask |= 0x0001;
    //4路副边
    if(ui->bym1200_grid_ov_bym4_ckx->isChecked())
        bym1200_mis_err_mask |= 0x8000;
    if(ui->bym1200_grid_uv_bym4_ckx->isChecked())
        bym1200_mis_err_mask |= 0x4000;
    if(ui->bym1200_grid_of_bym4_ckx->isChecked())
        bym1200_mis_err_mask |= 0x2000;
    if(ui->bym1200_grid_uf_bym4_ckx->isChecked())
        bym1200_mis_err_mask |= 0x1000;
    if(ui->bym1200_lock_ckx_bym4_ckx->isChecked())
        bym1200_mis_err_mask |= 0x0800;
    if(ui->bym1200_surge_bym4_ckx->isChecked())
        bym1200_mis_err_mask |= 0x0400;
    if(ui->bym1200_mcu_uv_bym4_ckx->isChecked())
        bym1200_mis_err_mask |= 0x0200;
    if(ui->bym1200_pv_uv_bym4_ckx->isChecked())
        bym1200_mis_err_mask |= 0x0100;
    if(ui->bym1200_hbd_oa_bym4_ckx->isChecked())
        bym1200_mis_err_mask |= 0x0080;
    if(ui->bym1200_hbd_ov_bym4_ckx->isChecked())
        bym1200_mis_err_mask |= 0x0040;
    if(ui->bym1200_cmu_primary2_bym4_ckx->isChecked())
        bym1200_mis_err_mask |= 0x0008;
    if(ui->bym1200_cmu_primary1_bym4_ckx->isChecked())
        bym1200_mis_err_mask |= 0x0004;

    bym1200_jsobj.insert("mim1_err",bym1200_mim1_err_mask);
    //bym1200_jsobj.insert("mim2_err",bym1200_mim2_err_mask);
    bym1200_jsobj.insert("mis_err",bym1200_mis_err_mask);

    //bym2000
    QJsonObject bym2000_jsobj;

    bym2000_jsobj.insert("v_start_point_offset",ui->bym2000_aging_offset_edt->text().toInt());
    bym2000_jsobj.insert("ignore_points_max",ui->bym2000_ignore_max_edt->text().toInt());
    bym2000_jsobj.insert("drop_points_max",ui->bym2000_drop_max_edt->text().toInt());
    bym2000_jsobj.insert("drop_value",ui->bym2000_drop_value_edt->text().toInt());
    if(ui->bym2000_aging_num_ckx->checkState() == Qt::Unchecked)
    {
        bym2000_jsobj.insert("v_aging_points",-1);
    }
    else
    {
        bym2000_jsobj.insert("v_aging_points",ui->bym2000_aging_num_edt->text().toInt());
    }

    if(ui->bym2000_aging_time_ckx->checkState() == Qt::Unchecked)
    {
        bym2000_jsobj.insert("v_aging_time",-1);
    }
    else
    {
        bym2000_jsobj.insert("v_aging_time",ui->bym2000_aging_time_edt->text().toInt());
    }

    if(ui->bym2000_rt40_time_ckx->checkState() == Qt::Unchecked)
    {
        bym2000_jsobj.insert("v_rm40_pwmin",-1);
    }
    else
    {
        bym2000_jsobj.insert("v_rm40_pwmin",ui->bym2000_rt40_time_edt->text().toInt());
    }

    if(ui->bym2000_t40_ckx->checkState() == Qt::Unchecked)
    {
        bym2000_jsobj.insert("v_rm40_tmax",-1);
    }
    else
    {
        bym2000_jsobj.insert("v_rm40_tmax",ui->bym2000_t40_edt->text().toInt());
    }

    if(ui->bym2000_rt45_time_ckx->checkState() == Qt::Unchecked)
    {
        bym2000_jsobj.insert("v_rm45_pwmin",-1);
    }
    else
    {
        bym2000_jsobj.insert("v_rm45_pwmin",ui->bym2000_rt45_time_edt->text().toInt());
    }

    if(ui->bym2000_t45_ckx->checkState() == Qt::Unchecked)
    {
        bym2000_jsobj.insert("v_rm45_tmax",-1);
    }
    else
    {
        bym2000_jsobj.insert("v_rm45_tmax",ui->bym2000_t45_edt->text().toInt());
    }

    if(ui->bym2000_rt50_time_ckx->checkState() == Qt::Unchecked)
    {
        bym2000_jsobj.insert("v_rm50_pwmin",-1);
    }
    else
    {
        bym2000_jsobj.insert("v_rm50_pwmin",ui->bym2000_rt50_time_edt->text().toInt());
    }

    if(ui->bym2000_t50_ckx->checkState() == Qt::Unchecked)
    {
        bym2000_jsobj.insert("v_rm50_tmax",-1);
    }
    else
    {
        bym2000_jsobj.insert("v_rm50_tmax",ui->bym2000_t50_edt->text().toInt());
    }

    if(ui->bym2000_rt55_time_ckx->checkState() == Qt::Unchecked)
    {
        bym2000_jsobj.insert("v_rm55_pwmin",-1);
    }
    else
    {
        bym2000_jsobj.insert("v_rm55_pwmin",ui->bym2000_rt55_time_edt->text().toInt());
    }

    if(ui->bym2000_t55_ckx->checkState() == Qt::Unchecked)
    {
        bym2000_jsobj.insert("v_rm55_tmax",-1);
    }
    else
    {
        bym2000_jsobj.insert("v_rm55_tmax",ui->bym2000_t55_edt->text().toInt());
    }

    if(ui->bym2000_rt60_time_ckx->checkState() == Qt::Unchecked)
    {
        bym2000_jsobj.insert("v_rm60_pwmin",-1);
    }
    else
    {
        bym2000_jsobj.insert("v_rm60_pwmin",ui->bym2000_rt60_time_edt->text().toInt());
    }

    if(ui->bym2000_t60_ckx->checkState() == Qt::Unchecked)
    {
        bym2000_jsobj.insert("v_rm60_tmax",-1);
    }
    else
    {
        bym2000_jsobj.insert("v_rm60_tmax",ui->bym2000_t60_edt->text().toInt());
    }

    QJsonObject bym2000_pv_jsobj;

    if(ui->bym2000_rt40_time_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym2000_pv_jsobj.insert("v_pv_rm40_pwmin",-1);
    }
    else
    {
        bym2000_pv_jsobj.insert("v_pv_rm40_pwmin",ui->bym2000_rt40_time_pv_edt->text().toInt());
    }

    if(ui->bym2000_t40_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym2000_pv_jsobj.insert("v_pv_rm40_tmax",-1);
    }
    else
    {
        bym2000_pv_jsobj.insert("v_pv_rm40_tmax",ui->bym2000_t40_pv_edt->text().toInt());
    }

    if(ui->bym2000_rt45_time_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym2000_pv_jsobj.insert("v_pv_rm45_pwmin",-1);
    }
    else
    {
        bym2000_pv_jsobj.insert("v_pv_rm45_pwmin",ui->bym2000_rt45_time_pv_edt->text().toInt());
    }

    if(ui->bym2000_t45_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym2000_pv_jsobj.insert("v_pv_rm45_tmax",-1);
    }
    else
    {
        bym2000_pv_jsobj.insert("v_pv_rm45_tmax",ui->bym2000_t45_pv_edt->text().toInt());
    }

    if(ui->bym2000_rt50_time_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym2000_pv_jsobj.insert("v_pv_rm50_pwmin",-1);
    }
    else
    {
        bym2000_pv_jsobj.insert("v_pv_rm50_pwmin",ui->bym2000_rt50_time_pv_edt->text().toInt());
    }

    if(ui->bym2000_t50_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym2000_pv_jsobj.insert("v_pv_rm50_tmax",-1);
    }
    else
    {
        bym2000_pv_jsobj.insert("v_pv_rm50_tmax",ui->bym2000_t50_pv_edt->text().toInt());
    }

    if(ui->bym2000_rt55_time_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym2000_pv_jsobj.insert("v_pv_rm55_pwmin",-1);
    }
    else
    {
        bym2000_pv_jsobj.insert("v_pv_rm55_pwmin",ui->bym2000_rt55_time_pv_edt->text().toInt());
    }

    if(ui->bym2000_t55_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym2000_pv_jsobj.insert("v_pv_rm55_tmax",-1);
    }
    else
    {
        bym2000_pv_jsobj.insert("v_pv_rm55_tmax",ui->bym2000_t55_pv_edt->text().toInt());
    }

    if(ui->bym2000_rt60_time_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym2000_pv_jsobj.insert("v_pv_rm60_pwmin",-1);
    }
    else
    {
        bym2000_pv_jsobj.insert("v_pv_rm60_pwmin",ui->bym2000_rt60_time_pv_edt->text().toInt());
    }

    if(ui->bym2000_t60_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym2000_pv_jsobj.insert("v_pv_rm60_tmax",-1);
    }
    else
    {
        bym2000_pv_jsobj.insert("v_pv_rm60_tmax",ui->bym2000_t60_pv_edt->text().toInt());
    }

    QJsonArray bym2000_pvs;
    bym2000_pvs.append(bym2000_pv_jsobj);

    bym2000_jsobj.insert("pv_params",bym2000_pvs);

    uint16_t bym2000_mim1_err_mask = 0;
    uint16_t bym2000_mim2_err_mask = 0;
    uint16_t bym2000_mis_err_mask = 0;

    if(ui->bym2000_pv_ov_bym4_pv1_ckx->isChecked())
        bym2000_mim1_err_mask |= 0x8000;
    if(ui->bym2000_pv_uv_bym4_pv1_ckx->isChecked())
        bym2000_mim1_err_mask |= 0x4000;
    if(ui->bym2000_dc_ov_bym4_pv1_ckx->isChecked())
        bym2000_mim1_err_mask |= 0x2000;
    if(ui->bym2000_dc_oa_bym4_pv1_ckx->isChecked())
        bym2000_mim1_err_mask |= 0x1000;
    if(ui->bym2000_dc_ot_bym4_pv1_ckx->isChecked())
        bym2000_mim1_err_mask |= 0x0800;
    if(ui->bym2000_land_bym4_pv12_ckx->isChecked())
        bym2000_mim1_err_mask |= 0x0400;
    if(ui->bym2000_mppt_bym4_pv12_ckx->isChecked())
        bym2000_mim1_err_mask |= 0x0200;
    if(ui->bym2000_dc_ot_bym4_pv2_ckx->isChecked())
        bym2000_mim1_err_mask |= 0x0100;
    if(ui->bym2000_pv_ov_bym4_pv2_ckx->isChecked())
        bym2000_mim1_err_mask |= 0x0080;
    if(ui->bym2000_pv_uv_bym4_pv2_ckx->isChecked())
        bym2000_mim1_err_mask |= 0x0040;
    if(ui->bym2000_dc_ov_bym4_pv2_ckx->isChecked())
        bym2000_mim1_err_mask |= 0x0020;
    if(ui->bym2000_dc_oa_bym4_pv2_ckx->isChecked())
        bym2000_mim1_err_mask |= 0x0010;
    if(ui->bym2000_sync_error_bym4_pv12_ckx->isChecked())
        bym2000_mim1_err_mask |= 0x0008;
    if(ui->bym2000_safe_chain_bym4_pv12_ckx->isChecked())
        bym2000_mim1_err_mask |= 0x0004;
    if(ui->bym2000_grid_bym4_pv12_ckx->isChecked())
        bym2000_mim1_err_mask |= 0x0002;
    if(ui->bym2000_off_bym4_pv12_ckx->isChecked())
        bym2000_mim1_err_mask |= 0x0001;
    //4路原边2
    if(ui->bym2000_pv_ov_bym4_pv3_ckx->isChecked())
        bym2000_mim2_err_mask |= 0x8000;
    if(ui->bym2000_pv_uv_bym4_pv3_ckx->isChecked())
        bym2000_mim2_err_mask |= 0x4000;
    if(ui->bym2000_dc_ov_bym4_pv3_ckx->isChecked())
        bym2000_mim2_err_mask |= 0x2000;
    if(ui->bym2000_dc_oa_bym4_pv3_ckx->isChecked())
        bym2000_mim2_err_mask |= 0x1000;
    if(ui->bym2000_dc_ot_bym4_pv3_ckx->isChecked())
        bym2000_mim2_err_mask |= 0x0800;
    if(ui->bym2000_land_bym4_pv34_ckx->isChecked())
        bym2000_mim2_err_mask |= 0x0400;
    if(ui->bym2000_mppt_bym4_pv34_ckx->isChecked())
        bym2000_mim2_err_mask |= 0x0200;
    if(ui->bym2000_dc_ot_bym4_pv4_ckx->isChecked())
        bym2000_mim2_err_mask |= 0x0100;
    if(ui->bym2000_pv_ov_bym4_pv4_ckx->isChecked())
        bym2000_mim2_err_mask |= 0x0080;
    if(ui->bym2000_pv_uv_bym4_pv4_ckx->isChecked())
        bym2000_mim2_err_mask |= 0x0040;
    if(ui->bym2000_dc_ov_bym4_pv4_ckx->isChecked())
        bym2000_mim2_err_mask |= 0x0020;
    if(ui->bym2000_dc_oa_bym4_pv4_ckx->isChecked())
        bym2000_mim2_err_mask |= 0x0010;
    if(ui->bym2000_sync_error_bym4_pv34_ckx->isChecked())
        bym2000_mim2_err_mask |= 0x0008;
    if(ui->bym2000_safe_chain_bym4_pv34_ckx->isChecked())
        bym2000_mim2_err_mask |= 0x0004;
    if(ui->bym2000_grid_bym4_pv34_ckx->isChecked())
        bym2000_mim2_err_mask |= 0x0002;
    if(ui->bym2000_off_bym4_pv34_ckx->isChecked())
        bym2000_mim2_err_mask |= 0x0001;

    //4路副边
    if(ui->bym2000_grid_ov_bym4_ckx->isChecked())
        bym2000_mis_err_mask |= 0x8000;
    if(ui->bym2000_grid_uv_bym4_ckx->isChecked())
        bym2000_mis_err_mask |= 0x4000;
    if(ui->bym2000_grid_of_bym4_ckx->isChecked())
        bym2000_mis_err_mask |= 0x2000;
    if(ui->bym2000_grid_uf_bym4_ckx->isChecked())
        bym2000_mis_err_mask |= 0x1000;
    if(ui->bym2000_lock_ckx_bym4_ckx->isChecked())
        bym2000_mis_err_mask |= 0x0800;
    if(ui->bym2000_surge_bym4_ckx->isChecked())
        bym2000_mis_err_mask |= 0x0400;
    if(ui->bym2000_mcu_uv_bym4_ckx->isChecked())
        bym2000_mis_err_mask |= 0x0200;
    if(ui->bym2000_pv_uv_bym4_ckx->isChecked())
        bym2000_mis_err_mask |= 0x0100;
    if(ui->bym2000_hbd_oa_bym4_ckx->isChecked())
        bym2000_mis_err_mask |= 0x0080;
    if(ui->bym2000_hbd_ov_bym4_ckx->isChecked())
        bym2000_mis_err_mask |= 0x0040;
    if(ui->bym2000_cmu_primary2_bym4_ckx->isChecked())
        bym2000_mis_err_mask |= 0x0008;
    if(ui->bym2000_cmu_primary1_bym4_ckx->isChecked())
        bym2000_mis_err_mask |= 0x0004;

    bym2000_jsobj.insert("mim1_err",bym2000_mim1_err_mask);
    bym2000_jsobj.insert("mim2_err",bym2000_mim2_err_mask);
    bym2000_jsobj.insert("mis_err",bym2000_mis_err_mask);

    //bym2400
    QJsonObject bym2400_jsobj;

    bym2400_jsobj.insert("v_start_point_offset",ui->bym2400_aging_offset_edt->text().toInt());
    bym2400_jsobj.insert("ignore_points_max",ui->bym2400_ignore_max_edt->text().toInt());
    bym2400_jsobj.insert("drop_points_max",ui->bym2400_drop_max_edt->text().toInt());
    bym2400_jsobj.insert("drop_value",ui->bym2400_drop_value_edt->text().toInt());
    if(ui->bym2400_aging_num_ckx->checkState() == Qt::Unchecked)
    {
        bym2400_jsobj.insert("v_aging_points",-1);
    }
    else
    {
        bym2400_jsobj.insert("v_aging_points",ui->bym2400_aging_num_edt->text().toInt());
    }

    if(ui->bym2400_aging_time_ckx->checkState() == Qt::Unchecked)
    {
        bym2400_jsobj.insert("v_aging_time",-1);
    }
    else
    {
        bym2400_jsobj.insert("v_aging_time",ui->bym2400_aging_time_edt->text().toInt());
    }

    if(ui->bym2400_rt40_time_ckx->checkState() == Qt::Unchecked)
    {
        bym2400_jsobj.insert("v_rm40_pwmin",-1);
    }
    else
    {
        bym2400_jsobj.insert("v_rm40_pwmin",ui->bym2400_rt40_time_edt->text().toInt());
    }

    if(ui->bym2400_t40_ckx->checkState() == Qt::Unchecked)
    {
        bym2400_jsobj.insert("v_rm40_tmax",-1);
    }
    else
    {
        bym2400_jsobj.insert("v_rm40_tmax",ui->bym2400_t40_edt->text().toInt());
    }

    if(ui->bym2400_rt45_time_ckx->checkState() == Qt::Unchecked)
    {
        bym2400_jsobj.insert("v_rm45_pwmin",-1);
    }
    else
    {
        bym2400_jsobj.insert("v_rm45_pwmin",ui->bym2400_rt45_time_edt->text().toInt());
    }

    if(ui->bym2400_t45_ckx->checkState() == Qt::Unchecked)
    {
        bym2400_jsobj.insert("v_rm45_tmax",-1);
    }
    else
    {
        bym2400_jsobj.insert("v_rm45_tmax",ui->bym2400_t45_edt->text().toInt());
    }

    if(ui->bym2400_rt50_time_ckx->checkState() == Qt::Unchecked)
    {
        bym2400_jsobj.insert("v_rm50_pwmin",-1);
    }
    else
    {
        bym2400_jsobj.insert("v_rm50_pwmin",ui->bym2400_rt50_time_edt->text().toInt());
    }

    if(ui->bym2400_t50_ckx->checkState() == Qt::Unchecked)
    {
        bym2400_jsobj.insert("v_rm50_tmax",-1);
    }
    else
    {
        bym2400_jsobj.insert("v_rm50_tmax",ui->bym2400_t50_edt->text().toInt());
    }

    if(ui->bym2400_rt55_time_ckx->checkState() == Qt::Unchecked)
    {
        bym2400_jsobj.insert("v_rm55_pwmin",-1);
    }
    else
    {
        bym2400_jsobj.insert("v_rm55_pwmin",ui->bym2400_rt55_time_edt->text().toInt());
    }

    if(ui->bym2400_t55_ckx->checkState() == Qt::Unchecked)
    {
        bym2400_jsobj.insert("v_rm55_tmax",-1);
    }
    else
    {
        bym2400_jsobj.insert("v_rm55_tmax",ui->bym2400_t55_edt->text().toInt());
    }

    if(ui->bym2400_rt60_time_ckx->checkState() == Qt::Unchecked)
    {
        bym2400_jsobj.insert("v_rm60_pwmin",-1);
    }
    else
    {
        bym2400_jsobj.insert("v_rm60_pwmin",ui->bym2400_rt60_time_edt->text().toInt());
    }

    if(ui->bym2400_t60_ckx->checkState() == Qt::Unchecked)
    {
        bym2400_jsobj.insert("v_rm60_tmax",-1);
    }
    else
    {
        bym2400_jsobj.insert("v_rm60_tmax",ui->bym2400_t60_edt->text().toInt());
    }

    QJsonObject bym2400_pv_jsobj;

    if(ui->bym2400_rt40_time_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym2400_pv_jsobj.insert("v_pv_rm40_pwmin",-1);
    }
    else
    {
        bym2400_pv_jsobj.insert("v_pv_rm40_pwmin",ui->bym2400_rt40_time_pv_edt->text().toInt());
    }

    if(ui->bym2400_t40_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym2400_pv_jsobj.insert("v_pv_rm40_tmax",-1);
    }
    else
    {
        bym2400_pv_jsobj.insert("v_pv_rm40_tmax",ui->bym2400_t40_pv_edt->text().toInt());
    }

    if(ui->bym2400_rt45_time_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym2400_pv_jsobj.insert("v_pv_rm45_pwmin",-1);
    }
    else
    {
        bym2400_pv_jsobj.insert("v_pv_rm45_pwmin",ui->bym2400_rt45_time_pv_edt->text().toInt());
    }

    if(ui->bym2400_t45_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym2400_pv_jsobj.insert("v_pv_rm45_tmax",-1);
    }
    else
    {
        bym2400_pv_jsobj.insert("v_pv_rm45_tmax",ui->bym2400_t45_pv_edt->text().toInt());
    }

    if(ui->bym2400_rt50_time_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym2400_pv_jsobj.insert("v_pv_rm50_pwmin",-1);
    }
    else
    {
        bym2400_pv_jsobj.insert("v_pv_rm50_pwmin",ui->bym2400_rt50_time_pv_edt->text().toInt());
    }

    if(ui->bym2400_t50_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym2400_pv_jsobj.insert("v_pv_rm50_tmax",-1);
    }
    else
    {
        bym2400_pv_jsobj.insert("v_pv_rm50_tmax",ui->bym2400_t50_pv_edt->text().toInt());
    }

    if(ui->bym2400_rt55_time_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym2400_pv_jsobj.insert("v_pv_rm55_pwmin",-1);
    }
    else
    {
        bym2400_pv_jsobj.insert("v_pv_rm55_pwmin",ui->bym2400_rt55_time_pv_edt->text().toInt());
    }

    if(ui->bym2400_t55_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym2400_pv_jsobj.insert("v_pv_rm55_tmax",-1);
    }
    else
    {
        bym2400_pv_jsobj.insert("v_pv_rm55_tmax",ui->bym2400_t55_pv_edt->text().toInt());
    }

    if(ui->bym2400_rt60_time_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym2400_pv_jsobj.insert("v_pv_rm60_pwmin",-1);
    }
    else
    {
        bym2400_pv_jsobj.insert("v_pv_rm60_pwmin",ui->bym2400_rt60_time_pv_edt->text().toInt());
    }

    if(ui->bym2400_t60_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym2400_pv_jsobj.insert("v_pv_rm60_tmax",-1);
    }
    else
    {
        bym2400_pv_jsobj.insert("v_pv_rm60_tmax",ui->bym2400_t60_pv_edt->text().toInt());
    }

    QJsonArray bym2400_pvs;
    bym2400_pvs.append(bym2400_pv_jsobj);

    bym2400_jsobj.insert("pv_params",bym2400_pvs);

    uint16_t bym2400_mim1_err_mask = 0;
    uint16_t bym2400_mim2_err_mask = 0;
    uint16_t bym2400_mis_err_mask = 0;

    if(ui->bym2400_pv_ov_bym4_pv1_ckx->isChecked())
        bym2400_mim1_err_mask |= 0x8000;
    if(ui->bym2400_pv_uv_bym4_pv1_ckx->isChecked())
        bym2400_mim1_err_mask |= 0x4000;
    if(ui->bym2400_dc_ov_bym4_pv1_ckx->isChecked())
        bym2400_mim1_err_mask |= 0x2000;
    if(ui->bym2400_dc_oa_bym4_pv1_ckx->isChecked())
        bym2400_mim1_err_mask |= 0x1000;
    if(ui->bym2400_dc_ot_bym4_pv1_ckx->isChecked())
        bym2400_mim1_err_mask |= 0x0800;
    if(ui->bym2400_land_bym4_pv12_ckx->isChecked())
        bym2400_mim1_err_mask |= 0x0400;
    if(ui->bym2400_mppt_bym4_pv12_ckx->isChecked())
        bym2400_mim1_err_mask |= 0x0200;
    if(ui->bym2400_dc_ot_bym4_pv2_ckx->isChecked())
        bym2400_mim1_err_mask |= 0x0100;
    if(ui->bym2400_pv_ov_bym4_pv2_ckx->isChecked())
        bym2400_mim1_err_mask |= 0x0080;
    if(ui->bym2400_pv_uv_bym4_pv2_ckx->isChecked())
        bym2400_mim1_err_mask |= 0x0040;
    if(ui->bym2400_dc_ov_bym4_pv2_ckx->isChecked())
        bym2400_mim1_err_mask |= 0x0020;
    if(ui->bym2400_dc_oa_bym4_pv2_ckx->isChecked())
        bym2400_mim1_err_mask |= 0x0010;
    if(ui->bym2400_sync_error_bym4_pv12_ckx->isChecked())
        bym2400_mim1_err_mask |= 0x0008;
    if(ui->bym2400_safe_chain_bym4_pv12_ckx->isChecked())
        bym2400_mim1_err_mask |= 0x0004;
    if(ui->bym2400_grid_bym4_pv12_ckx->isChecked())
        bym2400_mim1_err_mask |= 0x0002;
    if(ui->bym2400_off_bym4_pv12_ckx->isChecked())
        bym2400_mim1_err_mask |= 0x0001;
    //4路原边2
    if(ui->bym2400_pv_ov_bym4_pv3_ckx->isChecked())
        bym2400_mim2_err_mask |= 0x8000;
    if(ui->bym2400_pv_uv_bym4_pv3_ckx->isChecked())
        bym2400_mim2_err_mask |= 0x4000;
    if(ui->bym2400_dc_ov_bym4_pv3_ckx->isChecked())
        bym2400_mim2_err_mask |= 0x2000;
    if(ui->bym2400_dc_oa_bym4_pv3_ckx->isChecked())
        bym2400_mim2_err_mask |= 0x1000;
    if(ui->bym2400_dc_ot_bym4_pv3_ckx->isChecked())
        bym2400_mim2_err_mask |= 0x0800;
    if(ui->bym2400_land_bym4_pv34_ckx->isChecked())
        bym2400_mim2_err_mask |= 0x0400;
    if(ui->bym2400_mppt_bym4_pv34_ckx->isChecked())
        bym2400_mim2_err_mask |= 0x0200;
    if(ui->bym2400_dc_ot_bym4_pv4_ckx->isChecked())
        bym2400_mim2_err_mask |= 0x0100;
    if(ui->bym2400_pv_ov_bym4_pv4_ckx->isChecked())
        bym2400_mim2_err_mask |= 0x0080;
    if(ui->bym2400_pv_uv_bym4_pv4_ckx->isChecked())
        bym2400_mim2_err_mask |= 0x0040;
    if(ui->bym2400_dc_ov_bym4_pv4_ckx->isChecked())
        bym2400_mim2_err_mask |= 0x0020;
    if(ui->bym2400_dc_oa_bym4_pv4_ckx->isChecked())
        bym2400_mim2_err_mask |= 0x0010;
    if(ui->bym2400_sync_error_bym4_pv34_ckx->isChecked())
        bym2400_mim2_err_mask |= 0x0008;
    if(ui->bym2400_safe_chain_bym4_pv34_ckx->isChecked())
        bym2400_mim2_err_mask |= 0x0004;
    if(ui->bym2400_grid_bym4_pv34_ckx->isChecked())
        bym2400_mim2_err_mask |= 0x0002;
    if(ui->bym2400_off_bym4_pv34_ckx->isChecked())
        bym2400_mim2_err_mask |= 0x0001;

    //4路副边
    if(ui->bym2400_grid_ov_bym4_ckx->isChecked())
        bym2400_mis_err_mask |= 0x8000;
    if(ui->bym2400_grid_uv_bym4_ckx->isChecked())
        bym2400_mis_err_mask |= 0x4000;
    if(ui->bym2400_grid_of_bym4_ckx->isChecked())
        bym2400_mis_err_mask |= 0x2000;
    if(ui->bym2400_grid_uf_bym4_ckx->isChecked())
        bym2400_mis_err_mask |= 0x1000;
    if(ui->bym2400_lock_ckx_bym4_ckx->isChecked())
        bym2400_mis_err_mask |= 0x0800;
    if(ui->bym2400_surge_bym4_ckx->isChecked())
        bym2400_mis_err_mask |= 0x0400;
    if(ui->bym2400_mcu_uv_bym4_ckx->isChecked())
        bym2400_mis_err_mask |= 0x0200;
    if(ui->bym2400_pv_uv_bym4_ckx->isChecked())
        bym2400_mis_err_mask |= 0x0100;
    if(ui->bym2400_hbd_oa_bym4_ckx->isChecked())
        bym2400_mis_err_mask |= 0x0080;
    if(ui->bym2400_hbd_ov_bym4_ckx->isChecked())
        bym2400_mis_err_mask |= 0x0040;
    if(ui->bym2400_cmu_primary2_bym4_ckx->isChecked())
        bym2400_mis_err_mask |= 0x0008;
    if(ui->bym2400_cmu_primary1_bym4_ckx->isChecked())
        bym2400_mis_err_mask |= 0x0004;

    bym2400_jsobj.insert("mim1_err",bym2400_mim1_err_mask);
    bym2400_jsobj.insert("mim2_err",bym2400_mim2_err_mask);
    bym2400_jsobj.insert("mis_err",bym2400_mis_err_mask);

    //bym2800
    QJsonObject bym2800_jsobj;

    bym2800_jsobj.insert("v_start_point_offset",ui->bym2800_aging_offset_edt->text().toInt());
    bym2800_jsobj.insert("ignore_points_max",ui->bym2800_ignore_max_edt->text().toInt());
    bym2800_jsobj.insert("drop_points_max",ui->bym2800_drop_max_edt->text().toInt());
    bym2800_jsobj.insert("drop_value",ui->bym2800_drop_value_edt->text().toInt());
    if(ui->bym2800_aging_num_ckx->checkState() == Qt::Unchecked)
    {
        bym2800_jsobj.insert("v_aging_points",-1);
    }
    else
    {
        bym2800_jsobj.insert("v_aging_points",ui->bym2800_aging_num_edt->text().toInt());
    }

    if(ui->bym2800_aging_time_ckx->checkState() == Qt::Unchecked)
    {
        bym2800_jsobj.insert("v_aging_time",-1);
    }
    else
    {
        bym2800_jsobj.insert("v_aging_time",ui->bym2800_aging_time_edt->text().toInt());
    }

    if(ui->bym2800_rt40_time_ckx->checkState() == Qt::Unchecked)
    {
        bym2800_jsobj.insert("v_rm40_pwmin",-1);
    }
    else
    {
        bym2800_jsobj.insert("v_rm40_pwmin",ui->bym2800_rt40_time_edt->text().toInt());
    }

    if(ui->bym2800_t40_ckx->checkState() == Qt::Unchecked)
    {
        bym2800_jsobj.insert("v_rm40_tmax",-1);
    }
    else
    {
        bym2800_jsobj.insert("v_rm40_tmax",ui->bym2800_t40_edt->text().toInt());
    }

    if(ui->bym2800_rt45_time_ckx->checkState() == Qt::Unchecked)
    {
        bym2800_jsobj.insert("v_rm45_pwmin",-1);
    }
    else
    {
        bym2800_jsobj.insert("v_rm45_pwmin",ui->bym2800_rt45_time_edt->text().toInt());
    }

    if(ui->bym2800_t45_ckx->checkState() == Qt::Unchecked)
    {
        bym2800_jsobj.insert("v_rm45_tmax",-1);
    }
    else
    {
        bym2800_jsobj.insert("v_rm45_tmax",ui->bym2800_t45_edt->text().toInt());
    }

    if(ui->bym2800_rt50_time_ckx->checkState() == Qt::Unchecked)
    {
        bym2800_jsobj.insert("v_rm50_pwmin",-1);
    }
    else
    {
        bym2800_jsobj.insert("v_rm50_pwmin",ui->bym2800_rt50_time_edt->text().toInt());
    }

    if(ui->bym2800_t50_ckx->checkState() == Qt::Unchecked)
    {
        bym2800_jsobj.insert("v_rm50_tmax",-1);
    }
    else
    {
        bym2800_jsobj.insert("v_rm50_tmax",ui->bym2800_t50_edt->text().toInt());
    }

    if(ui->bym2800_rt55_time_ckx->checkState() == Qt::Unchecked)
    {
        bym2800_jsobj.insert("v_rm55_pwmin",-1);
    }
    else
    {
        bym2800_jsobj.insert("v_rm55_pwmin",ui->bym2800_rt55_time_edt->text().toInt());
    }

    if(ui->bym2800_t55_ckx->checkState() == Qt::Unchecked)
    {
        bym2800_jsobj.insert("v_rm55_tmax",-1);
    }
    else
    {
        bym2800_jsobj.insert("v_rm55_tmax",ui->bym2800_t55_edt->text().toInt());
    }

    if(ui->bym2800_rt60_time_ckx->checkState() == Qt::Unchecked)
    {
        bym2800_jsobj.insert("v_rm60_pwmin",-1);
    }
    else
    {
        bym2800_jsobj.insert("v_rm60_pwmin",ui->bym2800_rt60_time_edt->text().toInt());
    }

    if(ui->bym2800_t60_ckx->checkState() == Qt::Unchecked)
    {
        bym2800_jsobj.insert("v_rm60_tmax",-1);
    }
    else
    {
        bym2800_jsobj.insert("v_rm60_tmax",ui->bym2800_t60_edt->text().toInt());
    }

    QJsonObject bym2800_pv_jsobj;

    if(ui->bym2800_rt40_time_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym2800_pv_jsobj.insert("v_pv_rm40_pwmin",-1);
    }
    else
    {
        bym2800_pv_jsobj.insert("v_pv_rm40_pwmin",ui->bym2800_rt40_time_pv_edt->text().toInt());
    }

    if(ui->bym2800_t40_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym2800_pv_jsobj.insert("v_pv_rm40_tmax",-1);
    }
    else
    {
        bym2800_pv_jsobj.insert("v_pv_rm40_tmax",ui->bym2800_t40_pv_edt->text().toInt());
    }

    if(ui->bym2800_rt45_time_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym2800_pv_jsobj.insert("v_pv_rm45_pwmin",-1);
    }
    else
    {
        bym2800_pv_jsobj.insert("v_pv_rm45_pwmin",ui->bym2800_rt45_time_pv_edt->text().toInt());
    }

    if(ui->bym2800_t45_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym2800_pv_jsobj.insert("v_pv_rm45_tmax",-1);
    }
    else
    {
        bym2800_pv_jsobj.insert("v_pv_rm45_tmax",ui->bym2800_t45_pv_edt->text().toInt());
    }

    if(ui->bym2800_rt50_time_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym2800_pv_jsobj.insert("v_pv_rm50_pwmin",-1);
    }
    else
    {
        bym2800_pv_jsobj.insert("v_pv_rm50_pwmin",ui->bym2800_rt50_time_pv_edt->text().toInt());
    }

    if(ui->bym2800_t50_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym2800_pv_jsobj.insert("v_pv_rm50_tmax",-1);
    }
    else
    {
        bym2800_pv_jsobj.insert("v_pv_rm50_tmax",ui->bym2800_t50_pv_edt->text().toInt());
    }

    if(ui->bym2800_rt55_time_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym2800_pv_jsobj.insert("v_pv_rm55_pwmin",-1);
    }
    else
    {
        bym2800_pv_jsobj.insert("v_pv_rm55_pwmin",ui->bym2800_rt55_time_pv_edt->text().toInt());
    }

    if(ui->bym2800_t55_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym2800_pv_jsobj.insert("v_pv_rm55_tmax",-1);
    }
    else
    {
        bym2800_pv_jsobj.insert("v_pv_rm55_tmax",ui->bym2800_t55_pv_edt->text().toInt());
    }

    if(ui->bym2800_rt60_time_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym2800_pv_jsobj.insert("v_pv_rm60_pwmin",-1);
    }
    else
    {
        bym2800_pv_jsobj.insert("v_pv_rm60_pwmin",ui->bym2800_rt60_time_pv_edt->text().toInt());
    }

    if(ui->bym2800_t60_pv_ckx->checkState() == Qt::Unchecked)
    {
        bym2800_pv_jsobj.insert("v_pv_rm60_tmax",-1);
    }
    else
    {
        bym2800_pv_jsobj.insert("v_pv_rm60_tmax",ui->bym2800_t60_pv_edt->text().toInt());
    }

    QJsonArray bym2800_pvs;
    bym2800_pvs.append(bym2800_pv_jsobj);

    bym2800_jsobj.insert("pv_params",bym2800_pvs);

    uint16_t bym2800_mim1_err_mask = 0;
    uint16_t bym2800_mim2_err_mask = 0;
    uint16_t bym2800_mis_err_mask = 0;

    if(ui->bym2800_pv_ov_bym4_pv1_ckx->isChecked())
        bym2800_mim1_err_mask |= 0x8000;
    if(ui->bym2800_pv_uv_bym4_pv1_ckx->isChecked())
        bym2800_mim1_err_mask |= 0x4000;
    if(ui->bym2800_dc_ov_bym4_pv1_ckx->isChecked())
        bym2800_mim1_err_mask |= 0x2000;
    if(ui->bym2800_dc_oa_bym4_pv1_ckx->isChecked())
        bym2800_mim1_err_mask |= 0x1000;
    if(ui->bym2800_dc_ot_bym4_pv1_ckx->isChecked())
        bym2800_mim1_err_mask |= 0x0800;
    if(ui->bym2800_land_bym4_pv12_ckx->isChecked())
        bym2800_mim1_err_mask |= 0x0400;
    if(ui->bym2800_mppt_bym4_pv12_ckx->isChecked())
        bym2800_mim1_err_mask |= 0x0200;
    if(ui->bym2800_dc_ot_bym4_pv2_ckx->isChecked())
        bym2800_mim1_err_mask |= 0x0100;
    if(ui->bym2800_pv_ov_bym4_pv2_ckx->isChecked())
        bym2800_mim1_err_mask |= 0x0080;
    if(ui->bym2800_pv_uv_bym4_pv2_ckx->isChecked())
        bym2800_mim1_err_mask |= 0x0040;
    if(ui->bym2800_dc_ov_bym4_pv2_ckx->isChecked())
        bym2800_mim1_err_mask |= 0x0020;
    if(ui->bym2800_dc_oa_bym4_pv2_ckx->isChecked())
        bym2800_mim1_err_mask |= 0x0010;
    if(ui->bym2800_sync_error_bym4_pv12_ckx->isChecked())
        bym2800_mim1_err_mask |= 0x0008;
    if(ui->bym2800_safe_chain_bym4_pv12_ckx->isChecked())
        bym2800_mim1_err_mask |= 0x0004;
    if(ui->bym2800_grid_bym4_pv12_ckx->isChecked())
        bym2800_mim1_err_mask |= 0x0002;
    if(ui->bym2800_off_bym4_pv12_ckx->isChecked())
        bym2800_mim1_err_mask |= 0x0001;
    //4路原边2
    if(ui->bym2800_pv_ov_bym4_pv3_ckx->isChecked())
        bym2800_mim2_err_mask |= 0x8000;
    if(ui->bym2800_pv_uv_bym4_pv3_ckx->isChecked())
        bym2800_mim2_err_mask |= 0x4000;
    if(ui->bym2800_dc_ov_bym4_pv3_ckx->isChecked())
        bym2800_mim2_err_mask |= 0x2000;
    if(ui->bym2800_dc_oa_bym4_pv3_ckx->isChecked())
        bym2800_mim2_err_mask |= 0x1000;
    if(ui->bym2800_dc_ot_bym4_pv3_ckx->isChecked())
        bym2800_mim2_err_mask |= 0x0800;
    if(ui->bym2800_land_bym4_pv34_ckx->isChecked())
        bym2800_mim2_err_mask |= 0x0400;
    if(ui->bym2800_mppt_bym4_pv34_ckx->isChecked())
        bym2800_mim2_err_mask |= 0x0200;
    if(ui->bym2800_dc_ot_bym4_pv4_ckx->isChecked())
        bym2800_mim2_err_mask |= 0x0100;
    if(ui->bym2800_pv_ov_bym4_pv4_ckx->isChecked())
        bym2800_mim2_err_mask |= 0x0080;
    if(ui->bym2800_pv_uv_bym4_pv4_ckx->isChecked())
        bym2800_mim2_err_mask |= 0x0040;
    if(ui->bym2800_dc_ov_bym4_pv4_ckx->isChecked())
        bym2800_mim2_err_mask |= 0x0020;
    if(ui->bym2800_dc_oa_bym4_pv4_ckx->isChecked())
        bym2800_mim2_err_mask |= 0x0010;
    if(ui->bym2800_sync_error_bym4_pv34_ckx->isChecked())
        bym2800_mim2_err_mask |= 0x0008;
    if(ui->bym2800_safe_chain_bym4_pv34_ckx->isChecked())
        bym2800_mim2_err_mask |= 0x0004;
    if(ui->bym2800_grid_bym4_pv34_ckx->isChecked())
        bym2800_mim2_err_mask |= 0x0002;
    if(ui->bym2800_off_bym4_pv34_ckx->isChecked())
        bym2800_mim2_err_mask |= 0x0001;

    //4路副边
    if(ui->bym2800_grid_ov_bym4_ckx->isChecked())
        bym2800_mis_err_mask |= 0x8000;
    if(ui->bym2800_grid_uv_bym4_ckx->isChecked())
        bym2800_mis_err_mask |= 0x4000;
    if(ui->bym2800_grid_of_bym4_ckx->isChecked())
        bym2800_mis_err_mask |= 0x2000;
    if(ui->bym2800_grid_uf_bym4_ckx->isChecked())
        bym2800_mis_err_mask |= 0x1000;
    if(ui->bym2800_lock_ckx_bym4_ckx->isChecked())
        bym2800_mis_err_mask |= 0x0800;
    if(ui->bym2800_surge_bym4_ckx->isChecked())
        bym2800_mis_err_mask |= 0x0400;
    if(ui->bym2800_mcu_uv_bym4_ckx->isChecked())
        bym2800_mis_err_mask |= 0x0200;
    if(ui->bym2800_pv_uv_bym4_ckx->isChecked())
        bym2800_mis_err_mask |= 0x0100;
    if(ui->bym2800_hbd_oa_bym4_ckx->isChecked())
        bym2800_mis_err_mask |= 0x0080;
    if(ui->bym2800_hbd_ov_bym4_ckx->isChecked())
        bym2800_mis_err_mask |= 0x0040;
    if(ui->bym2800_cmu_primary2_bym4_ckx->isChecked())
        bym2800_mis_err_mask |= 0x0008;
    if(ui->bym2800_cmu_primary1_bym4_ckx->isChecked())
        bym2800_mis_err_mask |= 0x0004;

    bym2800_jsobj.insert("mim1_err",bym2800_mim1_err_mask);
    bym2800_jsobj.insert("mim2_err",bym2800_mim2_err_mask);
    bym2800_jsobj.insert("mis_err",bym2800_mis_err_mask);



    bym500_jsobj.insert("version",CUR_AGING_ALG);
    bym550_jsobj.insert("version",CUR_AGING_ALG);
    bym600_jsobj.insert("version",CUR_AGING_ALG);
    bym700_jsobj.insert("version",CUR_AGING_ALG);
    bym800_jsobj.insert("version",CUR_AGING_ALG);
    bym1000_jsobj.insert("version",CUR_AGING_ALG);
    bym1200_jsobj.insert("version",CUR_AGING_ALG);
    bym2000_jsobj.insert("version",CUR_AGING_ALG);
    bym2400_jsobj.insert("version",CUR_AGING_ALG);
    bym2800_jsobj.insert("version",CUR_AGING_ALG);

    bym500_jsobj.insert("mi_type","bym500");
    bym550_jsobj.insert("mi_type","bym550");
    bym600_jsobj.insert("mi_type","bym600");
    bym700_jsobj.insert("mi_type","bym700");
    bym800_jsobj.insert("mi_type","bym800");
    bym1000_jsobj.insert("mi_type","bym1000");
    bym1200_jsobj.insert("mi_type","bym1200");
    bym2000_jsobj.insert("mi_type","bym2000");
    bym2400_jsobj.insert("mi_type","bym2400");
    bym2800_jsobj.insert("mi_type","bym2800");

    ret_data.insert("bym500",bym500_jsobj);
    ret_data.insert("bym550",bym550_jsobj);
    ret_data.insert("bym600",bym600_jsobj);
    ret_data.insert("bym700",bym700_jsobj);
    ret_data.insert("bym800",bym800_jsobj);
    ret_data.insert("bym1000",bym1000_jsobj);
    ret_data.insert("bym1200",bym1200_jsobj);
    ret_data.insert("bym2000",bym2000_jsobj);
    ret_data.insert("bym2400",bym2400_jsobj);
    ret_data.insert("bym2800",bym2800_jsobj);
}



void judge_param_set_dlg::on_ok_pb_clicked()
{
    QJsonObject root_obj;
    to_jsonobj(root_obj);

    emit s_update_alg(5000,"/update_alg",root_obj);
}


void judge_param_set_dlg::on_close_pb_clicked()
{
    this->close();
}

void judge_param_set_dlg::onm_update_alg_success(bool status)
{
    QJsonObject obj;
    if(status)
    {
        QMessageBox::information(this,"通知","写入老化算法成功");

        to_jsonobj(obj);
        //设置算法
        bridge::ins()->core()->set_user_alg(QString(QJsonDocument(obj).toJson()));

        this->close();
    }
    else
    {
        QMessageBox::information(this,"通知","写入老化算法失败");
    }
}

