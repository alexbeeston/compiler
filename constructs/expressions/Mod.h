//
// Created by abeeston on 3/7/20.
//

#ifndef COMPILERS_MOD_H
#define COMPILERS_MOD_H

#include "BinaryOp.h"

struct Mod:BinaryOp
{
    Mod(Expression*, Expression*);
    void print() override;
    Register emit() override;
};
#endif //COMPILERS_MOD_H
