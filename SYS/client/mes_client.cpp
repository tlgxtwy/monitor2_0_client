#include "mes_client.h"

#include "common.h"

mes_client::mes_client(QObject *parent)
    : QObject{parent}
{

}

mes_client::~mes_client()
{
    delete m_timer;
    delete m_network_mg;
}

bool mes_client::is_busy()
{
    return m_busy_status;
}

void mes_client::onm_post(quint32 timeout, QNetworkRequest req, QByteArray body)
{
    //如果上条指令未处理完
    if(m_busy_status)
    {
        emit s_cs_request_busy();
        return ;
    }
    //如果超过最大限制时
    if(timeout > m_max_timeout)
        m_timer->setInterval(m_max_timeout);
    else
        m_timer->setInterval(timeout);
    m_timer->setSingleShot(true);  //设置单次模式
    //开始记时
    m_timer->start();
    m_busy_status = true;

    //connect(m_network_mg,&QNetworkAccessManager::finished,this,&cs_client::onm_recv);
    m_reply = m_network_mg->post(req,body);
}

void mes_client::onm_get(quint32 timeout, QNetworkRequest req)
{
    //如果上条指令未处理完
    if(m_busy_status)
    {
        emit s_cs_request_busy();
        return ;
    }
    //如果超过最大限制时
    if(timeout > m_max_timeout)
        m_timer->setInterval(m_max_timeout);
    else
        m_timer->setInterval(timeout);
    m_timer->setSingleShot(true);  //设置单次模式
    //开始记时
    m_timer->start();
    m_busy_status = true;

    //connect(m_network_mg,&QNetworkAccessManager::finished,this,&cs_client::onm_recv);
    m_reply = m_network_mg->get(req);
}

void mes_client::onm_recv(QNetworkReply *reply)
{
    m_timer->stop();

    if(reply->error() == QNetworkReply::NoError)
    {
        int statusCode = 0;

        QJsonObject obj;
        //获取状态码
        statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
        //状态码处理
        if(statusCode == 200)
        {
            obj = common::qbytearray_to_js(reply->readAll());

            emit s_cs_request_new_msg(reply->url().path(),obj);
        }
        else
        {

            emit s_cs_request_err_status(reply->url().path(),QString::number(statusCode));
        }
    }
    else
    {
        //请求错误处理
        emit s_cs_request_error(reply->url().toString());
    }

    reply->abort();
    reply->deleteLater();
    m_busy_status = false;
}

void mes_client::onm_stop()
{
    //disconnect(m_network_mg,&QNetworkAccessManager::finished,this,&cs_client::onm_recv);
    m_timer->stop();
    if(m_busy_status)
    {
        m_reply->abort();
        m_reply->deleteLater();
        m_busy_status = false;
    }
}

void mes_client::onm_timer_callback()
{
    onm_stop();
    //超时处理
    emit s_cs_request_timeout();
}

void mes_client::onm_start()
{
    m_timer = new QTimer();
    connect(m_timer,&QTimer::timeout,this,&mes_client::onm_timer_callback);

    m_network_mg = new QNetworkAccessManager();
    connect(m_network_mg,&QNetworkAccessManager::finished,this,&mes_client::onm_recv);
}





