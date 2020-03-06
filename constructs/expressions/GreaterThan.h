//
// Created by abeeston on 3/6/20.
//

#ifndef COMPILERS_GREATTHAN_H
#define COMPILERS_GREATTHAN_H

#include "Expression.h"

struct GreaterThan:Expression
{
    Expression* left;
    Expression* right;
    GreaterThan(Expression*, Expression*);
    void print() override;
};
#endif //COMPILERS_GREATTHAN_H
