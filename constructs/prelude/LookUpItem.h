//
// Created by abeeston on 3/20/20.
//

#ifndef COMPILERS_LOOKUPITEM_H
#define COMPILERS_LOOKUPITEM_H

#include "types/BaseType.h"

struct LookUpItem
{
    std::string ident;
    BaseType type;
    LookUpItem();
    LookUpItem(std::string, BaseType);
    virtual void print();
};

#endif //COMPILERS_LOOKUPITEM_H
