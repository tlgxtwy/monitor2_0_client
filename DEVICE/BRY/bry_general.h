#ifndef BRY_GENERAL_H
#define BRY_GENERAL_H

#include "bry_base.h"

class bry_general : public bry_base
{
    Q_OBJECT
public:
    explicit bry_general(QString name,QObject *parent = nullptr)
        :bry_base(name,bry_type::bry_general_type,parent)
    {

    };
    ~bry_general()
    {

    };

signals:

};

#endif // BRY_GENERAL_H
