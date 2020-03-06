//
// Created by abeeston on 3/6/20.
//

#ifndef COMPILERS_DIVIDE_H
#define COMPILERS_DIVIDE_H

#include "Expression.h"

struct Divide:Expression
{
    Expression* left;
    Expression* right;
    Divide(Expression*, Expression*);
    void print() override;
};
#endif //COMPILERS_DIVIDE_H
