#ifndef BASIC_BYM_FACTORY_H
#define BASIC_BYM_FACTORY_H

#include <QObject>
#include "bym_base.h"


class basic_bym_factory : public QObject
{
    Q_OBJECT
public:
    explicit basic_bym_factory(QObject *parent = nullptr): QObject{parent}
    {

    };
    ~basic_bym_factory(){};
    bym_base *create_bym(QString name);


signals:

};

#endif // BASIC_BYM_FACTORY_H
