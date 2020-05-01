//
// Created by abeeston on 3/20/20.
//

#ifndef COMPILERS_EQUAL_H
#define COMPILERS_EQUAL_H

#include "LogicalBinaryOp.h"

struct Equal:LogicalBinaryOp
{
    Equal(Expression*, Expression*);
    Register emit() override;
    int getValue() override;
};
#endif //COMPILERS_EQUAL_H
