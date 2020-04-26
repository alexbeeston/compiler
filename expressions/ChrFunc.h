//
// Created by abeeston on 3/7/20.
//

#ifndef COMPILERS_CHRFUNC_H
#define COMPILERS_CHRFUNC_H

#include "Expression.h"

struct ChrFunc:Expression
{
    Expression* expression;
    ChrFunc(Expression*);
    void print() override;
    Register emit() override;
    PrimitiveType getPrimitiveType() override;
};
#endif //COMPILERS_CHRFUNC_H
