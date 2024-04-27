#include "bridge.h"

// 静态成员初始化放到类外部处理
bridge* bridge::m_ins = new bridge;



void bridge::start()
{
    m_mes_client_thd->start();
    m_client_thd->start();
    m_core_thd->start();
}

bridge *bridge::ins()
{
    return m_ins;
}

cs_client *bridge::csclient()
{
    return m_client;
}

mes_client *bridge::mesclient()
{
    return m_mes_client;
}

core_mg *bridge::core()
{
    return m_core;
}
