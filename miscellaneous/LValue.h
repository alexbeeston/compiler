//
// Created by abeeston on 3/3/20.
//

#ifndef COMPILERS_LVALUE_H
#define COMPILERS_LVALUE_H

#include <vector>

#include "LValueBase.h"
#include "../registerPool/Register.h"
#include "../types/ArrayType.h"

struct LValue
{
    std::vector<LValueBase*>* sequence;
    LValue();
    LValue(std::vector<LValueBase*>*);
    void print();
    std::string getKey();
    Register getBaseRegister();
    int getOffset();
    bool isPrimitive();
    TypeStyle getStyle();
    PrimitiveType getPrimitiveType();
    BaseType* getInnerMostType();
};
#endif //COMPILERS_LVALUE_H
