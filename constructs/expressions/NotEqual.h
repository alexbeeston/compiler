//
// Created by abeeston on 3/6/20.
//

#ifndef COMPILERS_NOTEQUAL_H
#define COMPILERS_NOTEQUAL_H

#include "BinaryOpUndeterministicOperands.h"

struct NotEqual:BinaryOpUndeterministicOperands
{
    NotEqual(Expression*, Expression*);
    void print() override;
    Register emit() override;
    int getValue() override;
};
#endif //COMPILERS_NOTEQUAL_H
