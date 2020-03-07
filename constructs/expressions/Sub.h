//
// Created by abeeston on 3/6/20.
//

#ifndef COMPILERS_SUB_H
#define COMPILERS_SUB_H

#include "BinaryOp.h"

struct Sub:BinaryOp
{
    Sub(Expression*, Expression*);
    void print() override;
};
#endif //COMPILERS_SUB_H
