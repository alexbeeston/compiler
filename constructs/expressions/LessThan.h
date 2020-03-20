//
// Created by abeeston on 3/6/20.
//

#ifndef COMPILERS_LESSTHAN_H
#define COMPILERS_LESSTHAN_H

#include "BinaryOp.h"

struct LessThan:BinaryOp
{
    LessThan(Expression*, Expression*);
    void print() override;
    Register emit() override;
};
#endif //COMPILERS_LESSTHAN_H
