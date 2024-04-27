#ifndef ERR_ANALYSIS_DLG_H
#define ERR_ANALYSIS_DLG_H

#include <QDialog>

/*
    微逆错误代码解析界面
*/

namespace Ui {
class err_analysis_dlg;
}

class err_analysis_dlg : public QDialog
{
    Q_OBJECT

public:
    explicit err_analysis_dlg(QWidget *parent = nullptr);
    ~err_analysis_dlg();
    void set_combobox_enable(bool);
    //解析错误代码
    void analysis_err_code(uint8_t mi_type,QString mim1_err,QString mim2_err,QString mis_err);
private slots:

    void on_pushButton_clicked();
private:
    Ui::err_analysis_dlg *ui;
};

#endif // ERR_ANALYSIS_DLG_H
