//
// Created by abeeston on 3/7/20.
//

#ifndef COMPILERS_LVALUEEXPRESSION_H
#define COMPILERS_LVALUEEXPRESSION_H

#include "Expression.h"
#include "../LValue.h"

struct LValueExpression:Expression
{
   LValue* lValue;
   LValueExpression(LValue*);
   void print() override;
   std::string emit() override;
};
#endif //COMPILERS_LVALUEEXPRESSION_H
