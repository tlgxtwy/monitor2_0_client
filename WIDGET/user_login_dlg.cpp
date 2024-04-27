#include "user_login_dlg.h"
#include "ui_user_login_dlg.h"

#include <QAction>
#include <QFile>
#include <QMessageBox>
#include "bridge.h"



user_login_dlg::user_login_dlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::user_login_dlg)
{
    ui->setupUi(this);

    ui->account_cb->setEditable(true);
    ui->password_edt->setEchoMode(QLineEdit::Password);

    m_pwd_en.setIcon(QIcon(":/icon/icon/pwd_en.png"));
    m_pwd_dis.setIcon(QIcon(":/icon/icon/pwd_dis.png"));

    ui->password_edt->addAction(&m_pwd_dis,QLineEdit::TrailingPosition);
    //当前不可见时  点击后槽函数要可见  注意双方的槽函数
    connect(&m_pwd_en,&QAction::triggered,this,&user_login_dlg::onm_password_dis);
    connect(&m_pwd_dis,&QAction::triggered,this,&user_login_dlg::onm_password_en);

    connect(this,&user_login_dlg::s_login,bridge::ins()->csclient(),&cs_client::onm_send_user);
    connect(bridge::ins()->csclient(),&cs_client::s_cs_request_new_msg,this,&user_login_dlg::onm_new_login_success);
    connect(bridge::ins()->csclient(),&cs_client::s_cs_request_err_status,this,&user_login_dlg::onm_new_login_fail);

    connect(this,&user_login_dlg::s_current_login,bridge::ins()->csclient(),&cs_client::onm_set_account_password);
}

user_login_dlg::~user_login_dlg()
{
    delete ui;
}

void user_login_dlg::get_user_login_history(QString path)
{
    QFile file(path);
    QByteArray cfg;

    m_path = path;

    if(file.open(QIODevice::ReadOnly))
    {
        cfg = file.readAll();
        QJsonParseError err_pt;
        QJsonDocument root_doc = QJsonDocument::fromJson(cfg,&err_pt);
        QJsonObject root_obj = root_doc.object();

        if(err_pt.error == QJsonParseError::NoError)
        {
            QJsonArray tmp_array = root_obj.value("users_history").toArray();
            for(int i=0;i<tmp_array.size();i++)
            {
                m_account_password.insert(tmp_array[i].toObject().value("account").toString(),
                                          tmp_array[i].toObject().value("password").toString());

                //界面加入内容
                ui->account_cb->insertItem(i,tmp_array[i].toObject().value("account").toString());

                ui->account_cb->setCurrentIndex(0);
            }


            if(m_account_password.contains(root_obj.value("last_account").toString()))
            {
                ui->account_cb->setCurrentText(root_obj.value("last_account").toString());
            }
        }
    }
}

void user_login_dlg::set_user_login_history()
{
    QFile file(m_path);
    QJsonDocument doc;
    QJsonObject history_obj;
    if(file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate))
    {
        QJsonArray tmp_users;
        QStringList keys = m_account_password.keys();
        for(int i =0;i<keys.size();i++)
        {
            QJsonObject user_obj;
            user_obj.insert("account",keys[i]);
            if(ui->account_cb->currentText() == keys[i])
            {
                user_obj.insert("password",ui->password_edt->text());
            }
            else
            {
                user_obj.insert("password",m_account_password[keys[i]]);
            }
            tmp_users.append(user_obj);
        }
        history_obj.insert("users_history",tmp_users);
        history_obj.insert("last_account",ui->account_cb->lineEdit()->text());
        doc.setObject(history_obj);
        file.write(doc.toJson(QJsonDocument::Indented));
        file.close();
    }
    else
    {

    }

}

void user_login_dlg::onm_password_en()
{
    ui->password_edt->setEchoMode(QLineEdit::Normal);
    ui->password_edt->removeAction(&m_pwd_dis);
    ui->password_edt->addAction(&m_pwd_en,QLineEdit::TrailingPosition);
}

void user_login_dlg::onm_password_dis()
{
    ui->password_edt->setEchoMode(QLineEdit::Password);
    ui->password_edt->removeAction(&m_pwd_en);
    ui->password_edt->addAction(&m_pwd_dis,QLineEdit::TrailingPosition);
}

void user_login_dlg::onm_new_login_success(QString path)
{
    if(path == "/r_user_property")
    {
        disconnect(bridge::ins()->csclient(),&cs_client::s_cs_request_new_msg,this,&user_login_dlg::onm_new_login_success);
        //覆盖同名账户
        m_account_password.insert(ui->account_cb->lineEdit()->text(),ui->password_edt->text());

        //记录登录行为到本地
        set_user_login_history();

        emit s_current_login(ui->account_cb->lineEdit()->text(),ui->password_edt->text());
        accept();
    }
}

void user_login_dlg::onm_new_login_fail(QString path, QString status_code)
{
    if(path == "/r_user_property"  && status_code == "500")
        QMessageBox::information(this,"消息提示 ","账户或密码错误  无法登录服务器");
}

void user_login_dlg::on_login_pb_clicked()
{
    QJsonObject obj;
    QString http_server;
    obj.insert("account",ui->account_cb->lineEdit()->text());
    //老化房
    if(ui->comboBox->currentIndex() == 0)
    {
        http_server = "http://47.97.180.36:38700";
    }
    else if(ui->comboBox->currentIndex() == 1)
    {
        http_server = "http://1.117.152.46:38700";
    }
    else if(ui->comboBox->currentIndex() == 2)
    {
        http_server = "http://localhost:38700";
    }

    emit s_login(5000,"/r_user_property",obj,http_server,ui->account_cb->lineEdit()->text(),ui->password_edt->text());
}


void user_login_dlg::on_exit_pb_clicked()
{
    reject();
}


void user_login_dlg::on_account_cb_currentIndexChanged(int index)
{
    ui->password_edt->setText(m_account_password.value(ui->account_cb->lineEdit()->text()));
}


void user_login_dlg::on_account_cb_currentTextChanged(const QString &arg1)
{
    ui->password_edt->setText(m_account_password.value(ui->account_cb->lineEdit()->text()));
}

