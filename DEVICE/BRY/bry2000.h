#ifndef BRY2000_H
#define BRY2000_H

#include "bry_base.h"

class bry2000 : public bry_base
{
    Q_OBJECT
public:
    explicit bry2000(QString name,QObject *parent = nullptr)
        :bry_base(name,bry_type::bry_2000_type,parent)
    {

    };
    ~bry2000(){

    };
signals:

};

#endif // BRY2000_H
