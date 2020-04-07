//
// Created by abeeston on 3/7/20.
//

#ifndef COMPILERS_NEGATIVE_H
#define COMPILERS_NEGATIVE_H

#include "Expression.h"

struct Negative:Expression
{
    Expression* originalExpression;
    Negative(Expression*);
    void print() override;
    Register emit() override;

};
#endif //COMPILERS_NEGATIVE_H
