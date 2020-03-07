//
// Created by abeeston on 3/6/20.
//

#ifndef COMPILERS_ADD_H
#define COMPILERS_ADD_H

#include "BinaryOp.h"

struct Add:BinaryOp
{
    Add(Expression*, Expression*);
    void print() override;
};
#endif //COMPILERS_ADD_H
