#ifndef USER_LOGIN_DLG_H
#define USER_LOGIN_DLG_H

#include <QDialog>
#include <QJsonObject>
#include <QMap>
#include <QAction>

/*
    用户登录界面
*/

namespace Ui {
class user_login_dlg;
}

class user_login_dlg : public QDialog
{
    Q_OBJECT

public:
    explicit user_login_dlg(QWidget *parent = nullptr);
    ~user_login_dlg();
    //获取用户登录的记录(账户和密码)
    void get_user_login_history(QString path);
    //设置用户登录记录
    void set_user_login_history();


public slots:
    //界面:显示密码可见
    void onm_password_en();
    //界面:显示密码不可见
    void onm_password_dis();

    //界面:显示登录成功
    void onm_new_login_success(QString path);
    //界面:显示登录失败
    void onm_new_login_fail(QString path,QString status_code);
private slots:
    //界面:点击登录按钮
    void on_login_pb_clicked();
    //界面:点击退出按钮
    void on_exit_pb_clicked();
    //界面:点击切换已有账户
    void on_account_cb_currentIndexChanged(int index);
    //界面:手动输入账户密码登录
    void on_account_cb_currentTextChanged(const QString &arg1);

signals:
    //HTTP请求:请求登录 （账户和密码要正确）
    void s_login(quint32 timeout, QString path, QJsonObject param,QString cloud_path,QString account, QString password);
    //通知cs_client 当前账户密码 （cs_client 关系者HTTP请求的通道
    //当前的逻辑是 每次HTTP请求要传递账户密码）
    void s_current_login(QString account,QString password);
private:
    Ui::user_login_dlg *ui;

    QAction m_pwd_en;
    QAction m_pwd_dis;
    QString m_path = "";
    QMap<QString,QString> m_account_password;

};

#endif // USER_LOGIN_DLG_H
