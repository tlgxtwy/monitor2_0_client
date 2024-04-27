#ifndef BYM_FOUR_H
#define BYM_FOUR_H
#include "bym_base.h"

class bym_four:public bym_base
{
    Q_OBJECT
public:
    bym_four(QString name,QObject *parent = nullptr);
    ~bym_four(){};
    static QStringList power_mim_err_chinese(QString mim_err_code,uint8_t mim_id);
    static QStringList power_mis_err_chinese(QString mis_err_code);
};

#endif // BYM_FOUR_H
