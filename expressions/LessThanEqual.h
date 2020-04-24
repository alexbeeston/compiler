//
// Created by abeeston on 3/6/20.
//

#ifndef COMPILERS_LESSTHANEQUAL_H
#define COMPILERS_LESSTHANEQUAL_H

#include "BinaryOp.h"

struct LessThanEqual:BinaryOp
{
    LessThanEqual(Expression*, Expression*);
    void print() override;
    Register emit() override;
    int getValue() override;
};
#endif //COMPILERS_LESSTHANEQUAL_H
