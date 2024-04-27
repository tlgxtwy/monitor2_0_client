#ifndef MES_CLIENT_H
#define MES_CLIENT_H

#include <QObject>

#include <QNetworkReply>
#include <QTimer>

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QMutex>
#include <QNetworkRequest>

/*
    接入的是李洲权的 微逆工序扫码系统(目的是用于获取他那边服务器的工单数据)
*/


class mes_client : public QObject
{
    Q_OBJECT
public:
    explicit mes_client(QObject *parent = nullptr);
    ~mes_client();

    bool is_busy();  //是否繁忙

private:
    QNetworkAccessManager *m_network_mg = nullptr;  //网络数据管理对象
    QNetworkReply * m_reply = nullptr;
    bool m_busy_status = false;

    QTimer *m_timer = nullptr;

    //QString m_url_head = "http://localhost:38700";
    //quint8 m_min_timeout = 5;   //最小超时时间  s
    quint32 m_max_timeout = 20000;  //最大超时时间  ms
public slots:
    void onm_post(quint32 timeout,QNetworkRequest req,QByteArray body);
    void onm_get(quint32 timeout,QNetworkRequest req);

    void onm_recv(QNetworkReply *reply);           //数据处理
    void onm_stop();
    void onm_timer_callback();
    void onm_start();  //在线程内部初始化
signals:
    void s_cs_test(qint64 tt);
    void s_cs_request_new_msg(QString path,QJsonObject obj);
    void s_cs_request_error(QString path);
    void s_cs_request_timeout();
    void s_cs_request_busy();
    void s_cs_request_err_status(QString url,QString status_code);
};

#endif // MES_CLIENT_H
