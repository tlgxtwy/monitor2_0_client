#include "cs_client.h"

#include <QNetworkAccessManager>
#include <QNetworkRequest>
//#include <QNetworkReply>
#include <QUrl>
#include <QUrlQuery>

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#include "common.h"

cs_client::cs_client(QObject *parent)
    : QObject{parent}
{
}

cs_client::~cs_client()
{
    delete m_timer;
    delete m_network_mg;
}

bool cs_client::is_busy()
{
    return m_busy_status;
}

QString cs_client::analysis_server()
{
    if(m_url_head == "http://1.117.152.46:38700")
    {
        return "(测试)";
    }
    else if(m_url_head == "http://47.97.180.36:38700")
    {
        return "(老化房)";
    }
    else if(m_url_head == "http://localhost:38700")
    {
        return "本机";
    }
    return "";
}

void cs_client::onm_send(quint32 timeout, QString url, QJsonObject param)
{
    QNetworkRequest tmp_request;
    QUrl tmp_url(m_url_head + url);
    QUrlQuery tmp_url_quy;

    //如果上条指令未处理完
    if(m_busy_status)
    {
        emit s_cs_request_busy();
        return ;
    }
    //上传用户名 密码参数
    tmp_url_quy.addQueryItem("account",m_account);
    tmp_url_quy.addQueryItem("password",m_password);
    tmp_url.setQuery(tmp_url_quy);

    tmp_request.setUrl(tmp_url);

    //如果超过最大限制时
    if(timeout > m_max_timeout)
        m_timer->setInterval(m_max_timeout);
    else
        m_timer->setInterval(timeout);
    m_timer->setSingleShot(true);  //设置单次模式
    //开始记时
    m_timer->start();
    m_busy_status = true;

    tmp_request.setHeader(QNetworkRequest::ContentTypeHeader, ("charset=utf-8"));
    //发送
    m_reply = m_network_mg->post(tmp_request,common::js_to_qbytearray(param));

}

void cs_client::onm_send_user(quint32 timeout, QString url, QJsonObject param, QString server, QString account, QString password)
{
    QNetworkRequest tmp_request;
    QUrl tmp_url;
    QUrlQuery tmp_url_quy;

    m_url_head = server;
    tmp_url.setUrl(m_url_head + url);
    //如果上条指令未处理完
    if(m_busy_status)
    {
        emit s_cs_request_busy();
        return ;
    }
    //上传用户名 密码参数
    tmp_url_quy.addQueryItem("account",account);
    tmp_url_quy.addQueryItem("password",password);
    tmp_url.setQuery(tmp_url_quy);

    tmp_request.setUrl(tmp_url);

    //如果超过最大限制时
    if(timeout > m_max_timeout)
        m_timer->setInterval(m_max_timeout);
    else
        m_timer->setInterval(timeout);
    m_timer->setSingleShot(true);  //设置单次模式
    //开始记时
    m_timer->start();
    m_busy_status = true;

    tmp_request.setHeader(QNetworkRequest::ContentTypeHeader, ("charset=utf-8"));
    //发送
    m_reply = m_network_mg->post(tmp_request,common::js_to_qbytearray(param));

}

void cs_client::onm_recv(QNetworkReply *reply)
{
    int statusCode = 0;

    m_timer->stop();

    statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    if(reply->error() == QNetworkReply::NoError)
    {
        QJsonObject obj;
        //获取状态码

        //状态码处理
        if(statusCode == 200)
        {
            obj = common::qbytearray_to_js(reply->readAll());

            emit s_cs_request_new_msg(reply->url().path(),obj);
        }
    }
    else
    {
        emit s_cs_request_err_status(reply->url().path(),QString::number(statusCode));
    }

    reply->abort();
    reply->deleteLater();
    m_busy_status = false;
}

void cs_client::onm_stop()
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

void cs_client::onm_timer_callback()
{
    onm_stop();
    //超时处理
    emit s_cs_request_timeout();
}

void cs_client::onm_start()
{
    m_timer = new QTimer();
    connect(m_timer,&QTimer::timeout,this,&cs_client::onm_timer_callback);

    m_network_mg = new QNetworkAccessManager();
    connect(m_network_mg,&QNetworkAccessManager::finished,this,&cs_client::onm_recv);
}

void cs_client::onm_set_account_password(QString account, QString password)
{
    m_account = account;
    m_password = password;
}

