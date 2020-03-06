//
// Created by abeeston on 3/6/20.
//

#ifndef COMPILERS_OR_H
#define COMPILERS_OR_H

#include "Expression.h"

struct Or:Expression
{
    Expression* left;
    Expression* right;
    Or(Expression*, Expression*);
    void print() override;
};
#endif //COMPILERS_OR_H
