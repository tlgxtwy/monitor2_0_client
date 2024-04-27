#ifndef JUDGE_PARAM_SET_DLG_H
#define JUDGE_PARAM_SET_DLG_H

#include <QDialog>
#include <QHash>
//#include "sys_mg/bg_mg.h"
#include <QJsonObject>
/*
    老化参数的配置界面

*/

#define CUR_AGING_ALG  ("1.0")

namespace Ui {
class judge_param_set_dlg;
}

class judge_param_set_dlg : public QDialog
{
    Q_OBJECT

public:
    explicit judge_param_set_dlg(QJsonObject def_data,QWidget *parent = nullptr);
    ~judge_param_set_dlg();
    //将当前的界面数据打包成 json格式对象（用于设置当前账号下的老化标准参数，存储于数据库）
    void to_jsonobj(QJsonObject &ret_data);
private slots:
    //界面:更新老化算法参数
    void on_ok_pb_clicked();

    void on_close_pb_clicked();
    //显示更新算法到数据库是否成功
    void onm_update_alg_success(bool status);
signals:
    //HTTP请求:更新老化算法
    void s_update_alg(quint32 timeout, QString path, QJsonObject param);
private:
    Ui::judge_param_set_dlg *ui;
};

#endif // JUDGE_PARAM_SET_DLG_H
