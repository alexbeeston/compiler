//
// Created by abeeston on 3/7/20.
//

#ifndef COMPILERS_LVALUEEXPRESSION_H
#define COMPILERS_LVALUEEXPRESSION_H

#include "LValue.h"
#include "expressions/Expression.h"

struct LValueExpression:LValue
{
    Expression* expression;
    LValueExpression(Expression*);
    void print() override;
};
#endif //COMPILERS_LVALUEEXPRESSION_H
