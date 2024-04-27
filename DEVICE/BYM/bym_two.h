#ifndef BYM_TWO_H
#define BYM_TWO_H

#include "bym_base.h"

class bym_two : public bym_base
{
    Q_OBJECT
public:
    explicit bym_two(QString name,QObject *parent = nullptr)
        :bym_base(name,bym_two_type,parent)
    {

    };
    ~bym_two(){};
    static QStringList power_mim_err_chinese(QString mim_err_code);
    static QStringList power_mis_err_chinese(QString mis_err_code);
signals:

};

#endif // BYM_TWO_H
