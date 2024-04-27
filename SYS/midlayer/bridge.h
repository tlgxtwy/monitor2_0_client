#ifndef BRIDGE_H
#define BRIDGE_H

#include <QObject>
#include <QThread>

#include "mes_client.h"
#include "cs_client.h"
#include "core_mg.h"

class bridge : public QObject
{
    Q_OBJECT
public:
    explicit bridge(QObject *parent = nullptr): QObject{parent}
    {
        m_client = new cs_client;
        m_client_thd = new QThread;

        m_mes_client = new mes_client;
        m_mes_client_thd = new QThread;

        m_core = new core_mg;
        m_core_thd = new QThread;

        connect(m_core_thd,&QThread::started,m_core,&core_mg::onm_start);
        connect(m_client_thd,&QThread::started,m_client,&cs_client::onm_start);
        connect(m_mes_client_thd,&QThread::started,m_mes_client,&mes_client::onm_start);

        connect(m_client,&cs_client::s_cs_request_new_msg,m_core,&core_mg::onm_deal_http_msg);

        m_core->moveToThread(m_core_thd);
        m_client->moveToThread(m_client_thd);
        m_mes_client->moveToThread(m_mes_client_thd);

    };
    ~bridge()
    {
        m_client_thd->quit();
        m_client_thd->exit();

        m_mes_client_thd->quit();
        m_mes_client_thd->exit();

        m_core_thd->quit();
        m_core_thd->exit();

        delete m_client_thd;
        delete m_client;

        delete m_mes_client_thd;
        delete m_mes_client;

        delete m_core_thd;
        delete m_core;
    };

    void start();
    static bridge *ins();
    cs_client *csclient();
    mes_client *mesclient();

    core_mg *core();
private:
    static bridge* m_ins;

    cs_client *m_client = nullptr;       //与服务器通讯客户端
    QThread *m_client_thd = nullptr;

    mes_client *m_mes_client = nullptr;  //与李洲权的服务器通讯客户端
    QThread *m_mes_client_thd = nullptr;

    core_mg *m_core = nullptr;           //业务逻辑 核心处理 （发起通讯请求）
    QThread *m_core_thd = nullptr;

signals:

};

#endif // BRIDGE_H
