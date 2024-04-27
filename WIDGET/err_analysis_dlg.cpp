#include "err_analysis_dlg.h"
#include "ui_err_analysis_dlg.h"

#include "bym_one.h"
#include "bym_four.h"

err_analysis_dlg::err_analysis_dlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::err_analysis_dlg)
{
    ui->setupUi(this);
}

err_analysis_dlg::~err_analysis_dlg()
{
    delete ui;
}

void err_analysis_dlg::set_combobox_enable(bool b_v)
{
    ui->comboBox->setEnabled(b_v);
    ui->mim1_edt->setEnabled(b_v);
    ui->mim2_edt->setEnabled(b_v);
    ui->mis_edt->setEnabled(b_v);
}


void err_analysis_dlg::analysis_err_code(uint8_t mi_type, QString mim1_err, QString mim2_err, QString mis_err)
{
    if(mi_type == 1)
    {
        ui->comboBox->setCurrentIndex(0);
    }
    else if(mi_type == 2)
    {
        ui->comboBox->setCurrentIndex(1);
    }
    else if(mi_type == 4)
    {
        ui->comboBox->setCurrentIndex(2);
    }
    else {
        return;
    }
    ui->mim1_edt->setText(mim1_err);
    ui->mim2_edt->setText(mim2_err);
    ui->mis_edt->setText(mis_err);

    on_pushButton_clicked();
}

void err_analysis_dlg::on_pushButton_clicked()
{
    QStringList tmp_mim1_err;
    QStringList tmp_mim2_err;
    QStringList tmp_mis_err;

    if(ui->comboBox->currentIndex() == 0)
    {
        tmp_mim1_err = bym_one::power_mim_err_chinese(ui->mim1_edt->text());
        tmp_mis_err = bym_one::power_mis_err_chinese(ui->mis_edt->text());
    }
    else if(ui->comboBox->currentIndex() == 1)
    {


    }
    else if(ui->comboBox->currentIndex() == 2)
    {
        tmp_mim1_err = bym_four::power_mim_err_chinese(ui->mim1_edt->text(),1);
        tmp_mim2_err = bym_four::power_mim_err_chinese(ui->mim2_edt->text(),2);
        tmp_mis_err = bym_four::power_mis_err_chinese(ui->mis_edt->text());
    }

    //清空文本brower
    ui->textBrowser->clear();

    if(tmp_mim1_err.size() !=0)
    {
        ui->textBrowser->append("原边1故障说明:\r\n");
        for(int i=0;i<tmp_mim1_err.size();i++)
        {
            ui->textBrowser->append(QString::number(i+1) + "." + tmp_mim1_err[i] + "\r\n");
        }
    }
    if(tmp_mim2_err.size() !=0)
    {
        ui->textBrowser->append("\r\n原边2故障说明:\r\n");
        for(int i=0;i<tmp_mim2_err.size();i++)
        {
            ui->textBrowser->append(QString::number(i+1) + "." + tmp_mim2_err[i] + "\r\n");
        }
    }
    if(tmp_mis_err.size() != 0)
    {
        ui->textBrowser->append("\r\n副边故障说明: \r\n");

        for(int i=0;i<tmp_mis_err.size();i++)
        {
            ui->textBrowser->append(QString::number(i+1) + "." + tmp_mis_err[i] + "\r\n");
        }
    }

}

