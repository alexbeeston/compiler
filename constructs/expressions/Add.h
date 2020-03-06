//
// Created by abeeston on 3/6/20.
//

#ifndef COMPILERS_ADD_H
#define COMPILERS_ADD_H

#include "Expression.h"

struct Add:Expression
{
    Expression* left;
    Expression* right;
    Add(Expression*, Expression*);
    void print() override;
};
#endif //COMPILERS_ADD_H
