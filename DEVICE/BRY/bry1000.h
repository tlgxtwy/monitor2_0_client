#ifndef BRY1000_H
#define BRY1000_H

#include "bry_base.h"

class bry1000 : public bry_base
{
    Q_OBJECT
public:
    explicit bry1000(QString name,QObject *parent = nullptr)
        :bry_base(name,bry_type::bry_1000_type,parent)
    {

    };
    ~bry1000()
    {

    };

signals:

};

#endif // BRY1000_H
