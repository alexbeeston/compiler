//
// Created by abeeston on 3/20/20.
//

#ifndef COMPILERS_BINARYOPBOOLEAN_H
#define COMPILERS_BINARYOPBOOLEAN_H

#include "BinaryOp.h"

struct LogicalBinaryOp: BinaryOp
{
    LogicalBinaryOp(Expression*, Expression*);
    std::vector<Register> checkAndEmitOperands();
};
#endif //COMPILERS_BINARYOPBOOLEAN_H
