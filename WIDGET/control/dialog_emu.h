#ifndef DIALOG_EMU_H
#define DIALOG_EMU_H

#include <QDialog>
#include <QtCore>

namespace Ui {
class dialog_emu;
}

class dialog_emu : public QDialog
{
    Q_OBJECT

public:
    explicit dialog_emu(QWidget *parent = nullptr);
    ~dialog_emu();

public slots:
    void slot_getEMUCID(QString EMUCID, QString STATION);
    void slot_get_EMU_status(QString status,QString reserve, QString func, QString sign, QString run_mode,QString time);
signals:
    void signal_set_EMU_code(QJsonObject data);
    void signal_get_EMU_stauts(QJsonObject data);
private slots:
    //点击设置状态码
    //void on_pushButton_clicked();

    void on_pushButton_Reflux_set_clicked();

    void on_pushButton_EMU_Info_get_clicked();

private:
    Ui::dialog_emu *ui;
    QString emu_CID;
    QString station;
};

#endif // DIALOG_EMU_H
