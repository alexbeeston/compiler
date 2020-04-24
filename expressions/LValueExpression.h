//
// Created by abeeston on 3/7/20.
//

#ifndef COMPILERS_LVALUEEXPRESSION_H
#define COMPILERS_LVALUEEXPRESSION_H

#include "Expression.h"
#include "../miscellaneous/LValue.h"

struct LValueExpression:Expression
{
   LValue* lValue;
   LValueExpression(LValue*);
   void print() override;
   Register emit() override;
   TypeIndicator getTypeIndicator() override;
   bool isCTV() override;
   int getValue() override;
   Style getStyle() override;
};
#endif //COMPILERS_LVALUEEXPRESSION_H
