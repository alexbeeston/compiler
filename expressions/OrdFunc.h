//
// Created by abeeston on 3/7/20.
//

#ifndef COMPILERS_ORDFUNC_H
#define COMPILERS_ORDFUNC_H

#include "Expression.h"

struct OrdFunc:Expression
{
    Expression* expression;
    OrdFunc(Expression*);
    void print() override;
    Register emit() override;
    TypeIndicator getTypeIndicator() override;
};
#endif //COMPILERS_ORDFUNC_H
