#ifndef CS_CLIENT_H
#define CS_CLIENT_H

#include <QObject>
#include <QNetworkReply>
#include <QTimer>

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QMutex>

/*
    用于http 请求的 通讯链路
*/

class cs_client : public QObject
{
    Q_OBJECT
public:
    explicit cs_client(QObject *parent = nullptr);
    ~cs_client();

    void set_user(QString account,QString password); //设置账户密码
    bool is_busy();  //是否繁忙

    QString analysis_server();//获取老化房中文名
private:

    QNetworkAccessManager *m_network_mg = nullptr;  //网络数据管理对象
    QNetworkReply * m_reply = nullptr;
    bool m_busy_status = false;

    QTimer *m_timer = nullptr;
    QString m_url_head = "http://1.117.152.46:38700";
    //QString m_url_head = "http://localhost:38700";
    //quint8 m_min_timeout = 5;   //最小超时时间  s
    quint32 m_max_timeout = 120000;  //最大超时时间  ms

    /*                   */
    QString m_account = "";
    QString m_password = "s";

public slots:
    void onm_send(quint32 timeout,QString url,QJsonObject param);  //数据发送
    void onm_send_user(quint32 timeout,QString url,QJsonObject param,QString server,QString account,QString password);
    void onm_recv(QNetworkReply *reply);           //数据处理
    void onm_stop();
    void onm_timer_callback();

    void onm_start();  //在线程内部初始化
    void onm_set_account_password(QString account,QString password);

signals:
    void s_cs_test(qint64 tt);
    void s_cs_request_new_msg(QString path,QJsonObject obj);
    void s_cs_request_timeout();
    void s_cs_request_busy();
    void s_cs_request_err_status(QString url,QString status_code);
};

#endif // CS_CLIENT_H
