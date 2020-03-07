//
// Created by abeeston on 3/6/20.
//

#ifndef COMPILERS_MULTIPLY_H
#define COMPILERS_MULTIPLY_H

#include "BinaryOp.h"

struct Multiply:BinaryOp
{
    Multiply(Expression*, Expression*);
    void print() override;
};
#endif //COMPILERS_MULTIPLY_H
