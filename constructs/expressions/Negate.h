//
// Created by abeeston on 3/7/20.
//

#ifndef COMPILERS_NEGATE_H
#define COMPILERS_NEGATE_H

#include "Expression.h"

struct Negate:Expression
{
    Expression* expression;
    Negate(Expression*);
    void print() override;
    int getValue() override;
};
#endif //COMPILERS_NEGATE_H
