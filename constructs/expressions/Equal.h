//
// Created by abeeston on 3/20/20.
//

#ifndef COMPILERS_EQUAL_H
#define COMPILERS_EQUAL_H

#include "BinaryOpUndeterministicOperands.h"

struct Equal:BinaryOpUndeterministicOperands
{
    Equal(Expression*, Expression*);
    Register emit() override;
};
#endif //COMPILERS_EQUAL_H
