//
// Created by abeeston on 3/6/20.
//

#ifndef COMPILERS_SUB_H
#define COMPILERS_SUB_H

#include "Expression.h"

struct Sub:Expression
{
    Expression* left;
    Expression* right;
    Sub(Expression*, Expression*);
    void print() override;
};
#endif //COMPILERS_SUB_H
