//
// Created by abeeston on 3/6/20.
//

#ifndef COMPILERS_LESSTHANEQUAL_H
#define COMPILERS_LESSTHANEQUAL_H

#include "Expression.h"

struct LessThanEqual:Expression
{
    Expression* left;
    Expression* right;
    LessThanEqual(Expression*, Expression*);
    void print() override;
};
#endif //COMPILERS_LESSTHANEQUAL_H
