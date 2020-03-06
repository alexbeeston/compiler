//
// Created by abeeston on 3/6/20.
//

#ifndef COMPILERS_AND_H
#define COMPILERS_AND_H

#include "Expression.h"

struct And:Expression
{
    Expression* left;
    Expression* right;
    And(Expression*, Expression*);
    void print() override;
};
#endif //COMPILERS_AND_H
