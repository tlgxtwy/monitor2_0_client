#ifndef BYM_ONE_H
#define BYM_ONE_H
#include "bym_base.h"

class bym_one:public bym_base
{
    Q_OBJECT
public:
    explicit bym_one(QString name,QObject *parent = nullptr)
        :bym_base(name,bym_one_type,parent)
    {

    };
    ~bym_one(){};
    static QStringList power_mim_err_chinese(QString mim_err_code);
    static QStringList power_mis_err_chinese(QString mis_err_code);

};

#endif // BYM_ONE_H
