#ifndef BASIC_BRY_FACTORY_H
#define BASIC_BRY_FACTORY_H

#include <QObject>

#include "bry_base.h"

class basic_bry_factory : public QObject
{
    Q_OBJECT
public:
    explicit basic_bry_factory(QObject *parent = nullptr):QObject{parent}
    {

    };
    ~basic_bry_factory(){};

    bry_base *create_bry(QString name);



signals:

};

#endif // BASIC_BRY_FACTORY_H
