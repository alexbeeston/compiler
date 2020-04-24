//
// Created by abeeston on 3/7/20.
//

#ifndef COMPILERS_PREDFUNC_H
#define COMPILERS_PREDFUNC_H

#include "Expression.h"

struct PredFunc:Expression
{
   Expression* expression;
   PredFunc(Expression*);
   void print() override;
};
#endif //COMPILERS_PREDFUNC_H
