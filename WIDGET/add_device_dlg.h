#ifndef ADD_DEVICE_DLG_H
#define ADD_DEVICE_DLG_H

#include <QDialog>
#include <QHash>

#include <QJsonObject>
/*
    设备添加界面

*/
namespace Ui {
class add_device_dlg;
}

enum add_device_dlg_type
{
    add_emu_type,
    add_wifi_mi_type,
    add_plc_mi_type,
    add_station_type
};

class add_device_dlg : public QDialog
{
    Q_OBJECT

public:
    explicit add_device_dlg(add_device_dlg_type type,QWidget *parent = nullptr);
    ~add_device_dlg();
    void set_add_emu_station_text(QString station);
    void set_add_wifi_station_text(QString station);
    void set_add_plc_station_emu_text(QString station ,QString emu);
private slots:
    void on_add_emu_ok_pb_clicked();

    void on_add_emu_cancel_pb_clicked();

    void on_wifi_mi1_edt_textChanged(const QString &arg1);

    void on_wifi_mi2_edt_textChanged(const QString &arg1);

    void on_wifi_mi3_edt_textChanged(const QString &arg1);

    void on_wifi_mi4_edt_textChanged(const QString &arg1);

    void on_wifi_mi5_edt_textChanged(const QString &arg1);

    void on_wifi_mi6_edt_textChanged(const QString &arg1);

    void on_wifi_mi7_edt_textChanged(const QString &arg1);

    void on_wifi_mi8_edt_textChanged(const QString &arg1);

    void on_wifi_ok_pb_clicked();

    void on_wifi_cancel_pb_clicked();

    void on_plc_ok_pb_clicked();

    void on_plc_cancel_pb_clicked();

    void on_station_ok_pb_clicked();

    void on_station_cancel_pb_clicked();
signals:
    void s_add_station(quint32 timeout, QString path, QJsonObject param);
    void s_add_emu(quint32 timeout, QString path, QJsonObject param);
    void s_add_plc_mi(quint32 timeout, QString path, QJsonObject param);
    void s_add_wifi_mi(quint32 timeout, QString path, QJsonObject param);
private:
    Ui::add_device_dlg *ui;
    QHash<int,QWidget*> m_widget;

};

#endif // ADD_DEVICE_DLG_H
