#ifndef DIALOG_FILE_H
#define DIALOG_FILE_H

#include <QDialog>
#include "dialog.h"
namespace Ui {
class dialog_file;
}

class dialog_file : public QDialog
{
    Q_OBJECT

public:
    explicit dialog_file(QWidget *parent = nullptr);
    ~dialog_file();

public slots:

    void slot_receivePara(str_Grid *s_str_Grid, str_Cer *s_str_Cer);
    void slot_receiveFilePath(QString filePath);
signals:
    void signal_fileSave(QString fileName);

private slots:
    void on_pushButton_save_clicked();

    void on_pushButton_cancel_clicked();

private:
    Ui::dialog_file *ui;
    QJsonObject json_para;
    QString exe_filePath;
};

#endif // DIALOG_FILE_H
