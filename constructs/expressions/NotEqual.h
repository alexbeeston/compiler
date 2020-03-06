//
// Created by abeeston on 3/6/20.
//

#ifndef COMPILERS_NOTEQUAL_H
#define COMPILERS_NOTEQUAL_H

#include "Expression.h"

struct NotEqual:Expression
{
    Expression* left;
    Expression* right;
    NotEqual(Expression*, Expression*);
    void print() override;
};
#endif //COMPILERS_NOTEQUAL_H
