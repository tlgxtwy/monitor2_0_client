#include "basic_bry_factory.h"

#include "bry_general.h"
#include "bry1000.h"
#include "bry2000.h"

bry_base *basic_bry_factory::create_bry(QString name)
{
    bry_base *ptr = nullptr;

    //bry_type type = bry_base::analysis_bry_type(name);
    bry_type type = bry_type::bry_general_type;

    switch (type) {
    case bry_type::bry_1000_type:
        ptr = new bry1000(name);
        break;
    case bry_type::bry_general_type:
        ptr = new bry_general(name);
        break;
    case bry_type::bry_2000_type:
        ptr = new bry2000(name);
        break;
    default:
        break;
    }

    return ptr;
}
