#ifndef STATION_H
#define STATION_H

#include <QObject>
#include <QHash>
#include <QMap>
#include "bym_base.h"
#include "bry_base.h"


class station : public QObject
{
    Q_OBJECT
public:
    explicit station(QString name,QObject *parent = nullptr): QObject{parent}
    {
        m_name = name;
    };
    ~station()
    {
        for(QMap<QString,bry_base *>::const_iterator it = m_bry.cbegin(), end = m_bry.cend(); it != end; ++it)
        {
            if(it.value() != nullptr)
            {
                delete it.value();
            }
        }
//        for(QHash<QString,bym_base *>::const_iterator it = m_bym.cbegin(), end = m_bym.cend(); it != end; ++it)
//        {
//            if(it.value() != nullptr)
//            {
//                delete it.value();
//            }
//        }
    };

    void set_name(QString name)
    {
        m_name = name;
    };
    void set_position(QString position)
    {
        m_position = position;
    };

    QString name()
    {
        return m_name;
    }
    QString position()
    {
        return m_position;
    }

    QMap<QString,bry_base *> get_bry()
    {
        return m_bry;
    };

    void append_bry(bry_base *bry)
    {
        delete m_bry.value(bry->name(),nullptr);
        m_bry.insert(bry->name(),bry);

    };
    void remove_bry(QString name)
    {
        delete m_bry.value(name,nullptr);
        m_bry.remove(name);
    };
    void clear_bry()
    {
        for(QMap<QString,bry_base *>::const_iterator it = m_bry.cbegin(), end = m_bry.cend(); it != end; ++it)
        {
            if(it.value() != nullptr)
            {
                delete it.value();
            }
        }
        m_bry.clear();
    };

//    void append_bym(bym_base *bym)
//    {
//        delete m_bym.value(bym->name(),nullptr);
//        m_bym.insert(bym->name(),bym);
//    };

//    void remove_bym(QString name)
//    {
//        delete m_bym.value(name,nullptr);
//        m_bym.remove(name);
//    }

//    void clear_bym()
//    {
//        for(QHash<QString,bym_base *>::const_iterator it = m_bym.cbegin(), end = m_bym.cend(); it != end; ++it)
//        {
//            if(it.value() != nullptr)
//            {
//                delete it.value();
//            }
//        }
//        m_bym.clear();
//    };

public slots:
    //重置bry
    void onm_restart_bry(QJsonArray emu_array);
    //更新当前设备的数据
    void onm_update_bry(QMap<QString,QJsonObject> mi_power_hash);
private:
    QString m_name;     //电站名称
    QString m_position; //电站所在位置

    QMap<QString,bry_base *> m_bry;  //绑定的网关
    //QHash<QString,bym_base *> m_bym;  //绑定的微逆(wifi版)


signals:

};

#endif // STATION_H
