//
// Created by abeeston on 3/7/20.
//

#ifndef COMPILERS_BINARYOP_H
#define COMPILERS_BINARYOP_H

#include "Expression.h"

struct BinaryOp:Expression
{
    Expression* left;
    Expression* right;
    BinaryOp(Expression*, Expression*);
    void print() override;
};
#endif //COMPILERS_BINARYOP_H
