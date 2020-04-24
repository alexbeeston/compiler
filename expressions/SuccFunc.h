//
// Created by abeeston on 3/7/20.
//

#ifndef COMPILERS_SUCCFUNC_H
#define COMPILERS_SUCCFUNC_H

#include "Expression.h"

struct SuccFunc:Expression
{
    Expression* expression;
    SuccFunc(Expression*);
    void print() override;
    Register emit() override;
};
#endif //COMPILERS_SUCCFUNC_H
