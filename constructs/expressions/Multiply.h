//
// Created by abeeston on 3/6/20.
//

#ifndef COMPILERS_MULTIPLY_H
#define COMPILERS_MULTIPLY_H

#include "Expression.h"

struct Multiply:Expression
{
    Expression* left;
    Expression* right;
    Multiply(Expression*, Expression*);
    void print() override;
};
#endif //COMPILERS_MULTIPLY_H
