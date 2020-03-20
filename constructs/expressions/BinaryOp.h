//
// Created by abeeston on 3/7/20.
//

#ifndef COMPILERS_BINARYOP_H
#define COMPILERS_BINARYOP_H

#include "Expression.h"
#include "../../Register.h"
#include "../../global.h"
#include <vector>

struct BinaryOp:Expression
{
    Expression* left;
    Expression* right;
    BinaryOp(Expression*, Expression*);
    void print() override;
    std::vector<Register> emitOperands();
    void returnRegisters(std::vector<Register>);
};
#endif //COMPILERS_BINARYOP_H
