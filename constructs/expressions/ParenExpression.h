//
// Created by abeeston on 3/7/20.
//

#ifndef COMPILERS_PARENEXPRESSION_H
#define COMPILERS_PARENEXPRESSION_H

#include "Expression.h"

struct ParenExpression:Expression
{
    Expression* expression;
    ParenExpression(Expression*);
    void print() override;
    Register emit() override;
    int getValue() override;
};
#endif //COMPILERS_PARENEXPRESSION_H
