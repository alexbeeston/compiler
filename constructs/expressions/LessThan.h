//
// Created by abeeston on 3/6/20.
//

#ifndef COMPILERS_LESSTHAN_H
#define COMPILERS_LESSTHAN_H

#include "Expression.h"

struct LessThan:Expression
{
    Expression* left;
    Expression* right;
    LessThan(Expression*, Expression*);
    void print() override;
};
#endif //COMPILERS_LESSTHAN_H
