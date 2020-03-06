//
// Created by abeeston on 3/6/20.
//

#ifndef COMPILERS_GREATERTHANEQUAL_H
#define COMPILERS_GREATERTHANEQUAL_H

#include "Expression.h"

struct GreaterThanEqual:Expression
{
    Expression* left;
    Expression* right;
    GreaterThanEqual(Expression*, Expression*);
    void print() override;
};
#endif //COMPILERS_GREATERTHANEQUAL_H
