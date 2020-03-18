//
// Created by abeeston on 2/21/20.
//

#ifndef COMPILERS_NUMERICLIT_H
#define COMPILERS_NUMERICLIT_H

#include "Expression.h"

struct NumericLit : Expression
{
    int numericLitValue;
    NumericLit(int);
    void print() override;
    Register emit() override;
};
#endif //COMPILERS_NUMERICLIT_H
