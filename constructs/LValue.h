//
// Created by abeeston on 3/3/20.
//

#ifndef COMPILERS_LVALUE_H
#define COMPILERS_LVALUE_H

#include <vector>

#include "LValueBase.h"
#include "../Register.h"
#include "../constructs/prelude/types/ArrayType.h"

struct LValue
{
    std::vector<LValueBase*>* sequence;
    LValue();
    LValue(std::vector<LValueBase*>*);
    void print();
    std::string getKey();
    Register getBaseRegister();
    int getOffset();
    Style getStyle();
    TypeIndicator getTypeIndicator();
};
#endif //COMPILERS_LVALUE_H
