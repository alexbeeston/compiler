//
// Created by abeeston on 3/7/20.
//

#ifndef COMPILERS_LVALUEWITHEXPRESSION_H
#define COMPILERS_LVALUEWITHEXPRESSION_H

#include "LValueBase.h"
#include "expressions/Expression.h"

struct LValueWithExpression:LValueBase
{
    Expression* expression;
    LValueWithExpression(Expression*);
    void print() override;
};
#endif //COMPILERS_LVALUEEXPRESSION_H
