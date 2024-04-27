#include "add_device_dlg.h"
#include "ui_add_device_dlg.h"

#include <QMessageBox>

#include "bym_base.h"
#include "bry_base.h"
add_device_dlg::add_device_dlg(add_device_dlg_type type, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::add_device_dlg)
{
    ui->setupUi(this);

    //逆序移除  因为移除完一个的时候编号会重置
    if(type == add_emu_type)
    {
        ui->tabWidget->removeTab(3);
        ui->tabWidget->removeTab(2);
        ui->tabWidget->removeTab(1);

        ui->station_edt->setEnabled(false);
    }
    else if(type == add_plc_mi_type )
    {
        ui->tabWidget->removeTab(3);
        ui->tabWidget->removeTab(1);
        ui->tabWidget->removeTab(0);

        ui->plc_station_edt->setEnabled(false);
        ui->plc_emu_edt->setEnabled(false);

    }
    else if(type == add_wifi_mi_type)
    {

        ui->tabWidget->removeTab(3);
        ui->tabWidget->removeTab(2);
        ui->tabWidget->removeTab(0);

        ui->wifi_station_edt->setEnabled(false);
    }
    else if(type == add_station_type)
    {
        ui->tabWidget->removeTab(2);
        ui->tabWidget->removeTab(1);
        ui->tabWidget->removeTab(0);
    }
}

add_device_dlg::~add_device_dlg()
{
    delete ui;
}

void add_device_dlg::set_add_emu_station_text(QString station)
{
    ui->station_edt->setText(station);
}

void add_device_dlg::set_add_wifi_station_text(QString station)
{
    ui->wifi_station_edt->setText(station);
}

void add_device_dlg::set_add_plc_station_emu_text(QString station, QString emu)
{
    ui->plc_station_edt->setText(station);
    ui->plc_emu_edt->setText(emu);
}

void add_device_dlg::on_add_emu_ok_pb_clicked()
{
    bool ok = true;
    QString error_str = "";
    if(ui->emu1_edt->text()!= "" && !bry_base::is_general_cid_valid(ui->emu1_edt->text()))
    {
        error_str.append("网关1的编号不符合规范\r\n");
        ok = false;
    }
    if(ui->emu2_edt->text()!= "" && !bry_base::is_general_cid_valid(ui->emu2_edt->text()))
    {
        error_str.append("网关2的编号不符合规范\r\n");
        ok = false;
    }
    if(ui->emu3_edt->text()!= "" && !bry_base::is_general_cid_valid(ui->emu3_edt->text()))
    {
        error_str.append("网关3的编号不符合规范\r\n");
        ok = false;
    }
    if(ui->emu4_edt->text()!= "" && !bry_base::is_general_cid_valid(ui->emu4_edt->text()))
    {
        error_str.append("网关4的编号不符合规范\r\n");
        ok = false;
    }
    if(ui->emu5_edt->text()!= "" && !bry_base::is_general_cid_valid(ui->emu5_edt->text()))
    {
        error_str.append("网关5的编号不符合规范\r\n");
        ok = false;
    }
    if(ui->emu6_edt->text()!= "" && !bry_base::is_general_cid_valid(ui->emu6_edt->text()))
    {
        error_str.append("网关6的编号不符合规范\r\n");
        ok = false;
    }
    if(ui->emu7_edt->text()!= "" && !bry_base::is_general_cid_valid(ui->emu7_edt->text()))
    {
        error_str.append("网关7的编号不符合规范\r\n");
        ok = false;
    }
    if(ui->emu8_edt->text()!= "" && !bry_base::is_general_cid_valid(ui->emu8_edt->text()))
    {
        error_str.append("网关8的编号不符合规范\r\n");
        ok = false;
    }

    if(ok)
    {
        QJsonObject data;
        QJsonArray emus;
        QJsonObject emu;
        if(ui->emu1_edt->text() != "")
        {
            emu.insert("emu_cid",ui->emu1_edt->text());
            emu.insert("emu_desc",ui->desc_emu1_edt->text());
            emus.append(emu);
        }
        if(ui->emu2_edt->text() != "")
        {
            emu.insert("emu_cid",ui->emu2_edt->text());
            emu.insert("emu_desc",ui->desc_emu2_edt->text());
            emus.append(emu);
        }
        if(ui->emu3_edt->text() != "")
        {
            emu.insert("emu_cid",ui->emu3_edt->text());
            emu.insert("emu_desc",ui->desc_emu3_edt->text());
            emus.append(emu);
        }
        if(ui->emu4_edt->text() != "")
        {
            emu.insert("emu_cid",ui->emu4_edt->text());
            emu.insert("emu_desc",ui->desc_emu4_edt->text());
            emus.append(emu);
        }
        if(ui->emu5_edt->text() != "")
        {
            emu.insert("emu_cid",ui->emu5_edt->text());
            emu.insert("emu_desc",ui->desc_emu5_edt->text());
            emus.append(emu);
        }
        if(ui->emu6_edt->text() != "")
        {
            emu.insert("emu_cid",ui->emu6_edt->text());
            emu.insert("emu_desc",ui->desc_emu6_edt->text());
            emus.append(emu);
        }
        if(ui->emu7_edt->text() != "")
        {
            emu.insert("emu_cid",ui->emu7_edt->text());
            emu.insert("emu_desc",ui->desc_emu7_edt->text());
            emus.append(emu);
        }
        if(ui->emu8_edt->text() != "")
        {
            emu.insert("emu_cid",ui->emu8_edt->text());
            emu.insert("emu_desc",ui->desc_emu8_edt->text());
            emus.append(emu);
        }

        data.insert("station",ui->station_edt->text());
        data.insert("emus",emus);

        emit s_add_emu(5000,"/add_emu_cid",data);
        this->close();
    }
    else
    {
        QMessageBox::warning(this, "警告", error_str);
    }
}

void add_device_dlg::on_add_emu_cancel_pb_clicked()
{
    this->close();
}


void add_device_dlg::on_wifi_mi1_edt_textChanged(const QString &arg1)
{
    ui->g_mi1_lb->setText("默认微逆编号: " + bry_base::emu_cid_to_wifi_micid(arg1));
}


void add_device_dlg::on_wifi_mi2_edt_textChanged(const QString &arg1)
{
    ui->g_mi2_lb->setText("默认微逆编号: " + bry_base::emu_cid_to_wifi_micid(arg1));
}


void add_device_dlg::on_wifi_mi3_edt_textChanged(const QString &arg1)
{
    ui->g_mi3_lb->setText("默认微逆编号: " + bry_base::emu_cid_to_wifi_micid(arg1));
}


void add_device_dlg::on_wifi_mi4_edt_textChanged(const QString &arg1)
{
    ui->g_mi4_lb->setText("默认微逆编号: " + bry_base::emu_cid_to_wifi_micid(arg1));
}


void add_device_dlg::on_wifi_mi5_edt_textChanged(const QString &arg1)
{
    ui->g_mi5_lb->setText("默认微逆编号: " + bry_base::emu_cid_to_wifi_micid(arg1));
}


void add_device_dlg::on_wifi_mi6_edt_textChanged(const QString &arg1)
{
    ui->g_mi6_lb->setText("默认微逆编号: " + bry_base::emu_cid_to_wifi_micid(arg1));
}


void add_device_dlg::on_wifi_mi7_edt_textChanged(const QString &arg1)
{
    ui->g_mi7_lb->setText("默认微逆编号: " + bry_base::emu_cid_to_wifi_micid(arg1));
}


void add_device_dlg::on_wifi_mi8_edt_textChanged(const QString &arg1)
{
    ui->g_mi8_lb->setText("默认微逆编号: " + bry_base::emu_cid_to_wifi_micid(arg1));
}


void add_device_dlg::on_wifi_ok_pb_clicked()
{
    bool ok = true;
    QString error_str = "";
    if(ui->wifi_mi1_edt->text()!= "" && !bry_base::is_wifiemu_cid_valid(ui->wifi_mi1_edt->text()))
    {
        error_str.append("WIFI版微逆1的编号不符合规范\r\n");
        ok = false;
    }
    if(ui->wifi_mi2_edt->text()!= "" && !bry_base::is_wifiemu_cid_valid(ui->wifi_mi2_edt->text()))
    {
        error_str.append("WIFI版微逆2的编号不符合规范\r\n");
        ok = false;
    }

    if(ui->wifi_mi3_edt->text()!= "" && !bry_base::is_wifiemu_cid_valid(ui->wifi_mi3_edt->text()))
    {
        error_str.append("WIFI版微逆3的编号不符合规范\r\n");
        ok = false;
    }

    if(ui->wifi_mi4_edt->text()!= "" && !bry_base::is_wifiemu_cid_valid(ui->wifi_mi4_edt->text()))
    {
        error_str.append("WIFI版微逆4的编号不符合规范\r\n");
        ok = false;
    }

    if(ui->wifi_mi5_edt->text()!= "" && !bry_base::is_wifiemu_cid_valid(ui->wifi_mi5_edt->text()))
    {
        error_str.append("WIFI版微逆5的编号不符合规范\r\n");
        ok = false;
    }

    if(ui->wifi_mi6_edt->text()!= "" && !bry_base::is_wifiemu_cid_valid(ui->wifi_mi6_edt->text()))
    {
        error_str.append("WIFI版微逆6的编号不符合规范\r\n");
        ok = false;
    }

    if(ui->wifi_mi7_edt->text()!= "" && !bry_base::is_wifiemu_cid_valid(ui->wifi_mi7_edt->text()))
    {
        error_str.append("WIFI版微逆7的编号不符合规范\r\n");
        ok = false;
    }

    if(ui->wifi_mi8_edt->text()!= "" && !bry_base::is_wifiemu_cid_valid(ui->wifi_mi8_edt->text()))
    {
        error_str.append("WIFI版微逆8的编号不符合规范\r\n");
        ok = false;
    }

    if(ok)
    {
        QJsonObject data;
        QJsonArray emus;

        QJsonObject emu;
        QJsonObject mi;
        if(ui->wifi_mi1_edt->text() != "")
        {
            mi.insert("mi_cid",bry_base::emu_cid_to_wifi_micid(ui->wifi_mi1_edt->text()));
            mi.insert("mi_desc",ui->desc_wifimi1_edt->text());
            emu.insert("mi",mi);
            emu.insert("emu",ui->wifi_mi1_edt->text());

            emus.append(emu);
        }
        if(ui->wifi_mi2_edt->text() != "")
        {
            mi.insert("mi_cid",bry_base::emu_cid_to_wifi_micid(ui->wifi_mi2_edt->text()));
            mi.insert("mi_desc",ui->desc_wifimi2_edt->text());
            emu.insert("mi",mi);
            emu.insert("emu",ui->wifi_mi2_edt->text());
            emus.append(emu);
        }
        if(ui->wifi_mi3_edt->text() != "")
        {
            mi.insert("mi_cid",bry_base::emu_cid_to_wifi_micid(ui->wifi_mi3_edt->text()));
            mi.insert("mi_desc",ui->desc_wifimi3_edt->text());
            emu.insert("mi",mi);
            emu.insert("emu",ui->wifi_mi3_edt->text());
            emus.append(emu);
        }
        if(ui->wifi_mi4_edt->text() != "")
        {
            mi.insert("mi_cid",bry_base::emu_cid_to_wifi_micid(ui->wifi_mi4_edt->text()));
            mi.insert("mi_desc",ui->desc_wifimi4_edt->text());
            emu.insert("mi",mi);
            emu.insert("emu",ui->wifi_mi4_edt->text());
            emus.append(emu);
        }
        if(ui->wifi_mi5_edt->text() != "")
        {
            mi.insert("mi_cid",bry_base::emu_cid_to_wifi_micid(ui->wifi_mi5_edt->text()));
            mi.insert("mi_desc",ui->desc_wifimi5_edt->text());
            emu.insert("mi",mi);
            emu.insert("emu",ui->wifi_mi5_edt->text());
            emus.append(emu);
        }
        if(ui->wifi_mi6_edt->text() != "")
        {
            mi.insert("mi_cid",bry_base::emu_cid_to_wifi_micid(ui->wifi_mi6_edt->text()));
            mi.insert("mi_desc",ui->desc_wifimi6_edt->text());
            emu.insert("mi",mi);
            emu.insert("emu",ui->wifi_mi6_edt->text());
            emus.append(emu);
        }
        if(ui->wifi_mi7_edt->text() != "")
        {
            mi.insert("mi_cid",bry_base::emu_cid_to_wifi_micid(ui->wifi_mi7_edt->text()));
            mi.insert("mi_desc",ui->desc_wifimi7_edt->text());
            emu.insert("mi",mi);
            emu.insert("emu",ui->wifi_mi7_edt->text());
            emus.append(emu);
        }
        if(ui->wifi_mi8_edt->text() != "")
        {
            mi.insert("mi_cid",bry_base::emu_cid_to_wifi_micid(ui->wifi_mi8_edt->text()));
            mi.insert("mi_desc",ui->desc_wifimi8_edt->text());
            emu.insert("mi",mi);
            emu.insert("emu",ui->wifi_mi8_edt->text());
            emus.append(emu);
        }

        data.insert("station",ui->wifi_station_edt->text());
        data.insert("emus",emus);

        emit s_add_wifi_mi(5000,"/add_wifimi_cid",data);
        this->close();

    }
    else
    {
        QMessageBox::warning(this, "警告", error_str);
    }
}


void add_device_dlg::on_wifi_cancel_pb_clicked()
{
    this->close();
}


void add_device_dlg::on_plc_ok_pb_clicked()
{
    bool ok = true;
    QString error_str = "";
    if(ui->plc_mi1_edt->text()!= "" && !bym_base::is_cid_valid(ui->plc_mi1_edt->text()))
    {
        error_str.append("微逆1的编号不符合规范\r\n");
        ok = false;
    }
    if(ui->plc_mi2_edt->text()!= "" && !bym_base::is_cid_valid(ui->plc_mi2_edt->text()))
    {
        error_str.append("微逆2的编号不符合规范\r\n");
        ok = false;
    }

    if(ui->plc_mi3_edt->text()!= "" && !bym_base::is_cid_valid(ui->plc_mi3_edt->text()))
    {
        error_str.append("微逆3的编号不符合规范\r\n");
        ok = false;
    }

    if(ui->plc_mi4_edt->text()!= "" && !bym_base::is_cid_valid(ui->plc_mi4_edt->text()))
    {
        error_str.append("微逆4的编号不符合规范\r\n");
        ok = false;
    }

    if(ui->plc_mi5_edt->text()!= "" && !bym_base::is_cid_valid(ui->plc_mi5_edt->text()))
    {
        error_str.append("微逆5的编号不符合规范\r\n");
        ok = false;
    }

    if(ui->plc_mi6_edt->text()!= "" && !bym_base::is_cid_valid(ui->plc_mi6_edt->text()))
    {
        error_str.append("微逆6的编号不符合规范\r\n");
        ok = false;
    }

    if(ui->plc_mi7_edt->text()!= "" && !bym_base::is_cid_valid(ui->plc_mi7_edt->text()))
    {
        error_str.append("微逆7的编号不符合规范\r\n");
        ok = false;
    }

    if(ui->plc_mi8_edt->text()!= "" && !bym_base::is_cid_valid(ui->plc_mi8_edt->text()))
    {
        error_str.append("微逆8的编号不符合规范\r\n");
        ok = false;
    }

    if(ok)
    {
        QJsonObject data;
        QJsonArray mis;
        QJsonObject mi;
        if(ui->plc_mi1_edt->text() != "")
        {
            mi.insert("mi_cid",ui->plc_mi1_edt->text());
            mi.insert("mi_desc",ui->desc_plcmi1_edt->text());
            mis.append(mi);
        }
        if(ui->plc_mi2_edt->text() != "")
        {
            mi.insert("mi_cid",ui->plc_mi2_edt->text());
            mi.insert("mi_desc",ui->desc_plcmi2_edt->text());
            mis.append(mi);
        }
        if(ui->plc_mi3_edt->text() != "")
        {
            mi.insert("mi_cid",ui->plc_mi3_edt->text());
            mi.insert("mi_desc",ui->desc_plcmi3_edt->text());
            mis.append(mi);
        }
        if(ui->plc_mi4_edt->text() != "")
        {
            mi.insert("mi_cid",ui->plc_mi4_edt->text());
            mi.insert("mi_desc",ui->desc_plcmi4_edt->text());
            mis.append(mi);
        }
        if(ui->plc_mi5_edt->text() != "")
        {
            mi.insert("mi_cid",ui->plc_mi5_edt->text());
            mi.insert("mi_desc",ui->desc_plcmi5_edt->text());
            mis.append(mi);
        }
        if(ui->plc_mi6_edt->text() != "")
        {
            mi.insert("mi_cid",ui->plc_mi6_edt->text());
            mi.insert("mi_desc",ui->desc_plcmi6_edt->text());
            mis.append(mi);
        }
        if(ui->plc_mi7_edt->text() != "")
        {
            mi.insert("mi_cid",ui->plc_mi7_edt->text());
            mi.insert("mi_desc",ui->desc_plcmi7_edt->text());
            mis.append(mi);
        }
        if(ui->plc_mi8_edt->text() != "")
        {
            mi.insert("mi_cid",ui->plc_mi8_edt->text());
            mi.insert("mi_desc",ui->desc_plcmi8_edt->text());
            mis.append(mi);
        }

        data.insert("station",ui->plc_station_edt->text());
        data.insert("emu",ui->plc_emu_edt->text());
        data.insert("mis",mis);

        emit s_add_plc_mi(5000,"/add_plcmi_cid",data);
        this->close();

    }
    else
    {
        QMessageBox::warning(this, "警告", error_str);
    }
}

void add_device_dlg::on_plc_cancel_pb_clicked()
{
    this->close();
}


void add_device_dlg::on_station_ok_pb_clicked()
{
    QJsonObject data;
    QJsonObject params;
    QJsonArray stations;
    if(ui->station1_edt->text() != "")
        stations.append(ui->station1_edt->text());
    if(ui->station2_edt->text() != "")
        stations.append(ui->station2_edt->text());
    if(ui->station3_edt->text() != "")
        stations.append(ui->station3_edt->text());
    if(ui->station4_edt->text() != "")
        stations.append(ui->station4_edt->text());
    if(ui->station5_edt->text() != "")
        stations.append(ui->station5_edt->text());
    if(ui->station6_edt->text() != "")
        stations.append(ui->station6_edt->text());
    if(ui->station7_edt->text() != "")
        stations.append(ui->station7_edt->text());
    if(ui->station8_edt->text() != "")
        stations.append(ui->station8_edt->text());

    data.insert("station",stations);

    emit s_add_station(5000,"/add_station",data);

    this->close();
}


void add_device_dlg::on_station_cancel_pb_clicked()
{
    this->close();
}

