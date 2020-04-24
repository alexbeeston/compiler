//
// Created by abeeston on 3/7/20.
//

#ifndef COMPILERS_BINARYOP_H
#define COMPILERS_BINARYOP_H

#include "Expression.h"
#include "../registerPool/Register.h"
#include "../global.h"
#include <vector>

struct BinaryOp:Expression
{
    Expression* left;
    Expression* right;
    BinaryOp(Expression*, Expression*);
    void print() override;
    std::vector<Register> emitOperands(int);
    void returnRegisters(std::vector<Register>);
    bool isCTV() override;
};
#endif //COMPILERS_BINARYOP_H
