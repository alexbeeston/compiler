//
// Created by abeeston on 3/6/20.
//

#ifndef COMPILERS_DIVIDE_H
#define COMPILERS_DIVIDE_H

#include "BinaryOp.h"

struct Divide:BinaryOp
{
    Divide(Expression*, Expression*);
    void print() override;
    Register emit() override;
    int getValue() override;
};
#endif //COMPILERS_DIVIDE_H
