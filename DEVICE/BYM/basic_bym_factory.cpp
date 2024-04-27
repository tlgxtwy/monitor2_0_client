#include "basic_bym_factory.h"

#include "bym_one.h"
#include "bym_two.h"
#include "bym_four.h"



bym_base *basic_bym_factory::create_bym(QString name)
{
    bym_base *ptr = nullptr;
    bym_type type = bym_base::analysis_type(name);

    switch (type) {
    case bym_type::bym_one_type:
        ptr = new bym_one(name);
        break;
    case bym_type::bym_two_type:
        ptr = new bym_two(name);
        break;
    case bym_type::bym_four_type:
        ptr = new bym_four(name);
        break;
    default:
        break;
    }

    return ptr;

}
