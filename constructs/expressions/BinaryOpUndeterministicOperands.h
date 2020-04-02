//
// Created by abeeston on 3/20/20.
//

#ifndef COMPILERS_BINARYOPBOOLEAN_H
#define COMPILERS_BINARYOPBOOLEAN_H

#include "BinaryOp.h"

struct BinaryOpUndeterministicOperands:BinaryOp
{
    BinaryOpUndeterministicOperands(Expression*, Expression*);
    std::vector<Register> checkAndEmitOperands(); // checks to make sure that both left and right operands are of the same type
    bool operandsAreOfSameType();
};
#endif //COMPILERS_BINARYOPBOOLEAN_H
