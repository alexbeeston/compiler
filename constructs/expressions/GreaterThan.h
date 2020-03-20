//
// Created by abeeston on 3/6/20.
//

#ifndef COMPILERS_GREATTHAN_H
#define COMPILERS_GREATTHAN_H

#include "BinaryOp.h"

struct GreaterThan:BinaryOp
{
    GreaterThan(Expression*, Expression*);
    void print() override;
    Register emit() override;
};
#endif //COMPILERS_GREATTHAN_H
