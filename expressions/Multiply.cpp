#include <iostream>

#include "Multiply.h"

Multiply::Multiply(Expression* p_l, Expression* p_r):BinaryOp(p_l, p_r)
{
    typeIndicator = INTEGER;
}

void Multiply::print()
{
    left->print();
    std::cout << " * ";
    right->print();
}

Register Multiply::emit()
{
    int INT = 0;
    std::vector<Register> opRegs = emitOperands(INT);
    Register left = opRegs[0];
    Register right = opRegs[1];
    std::cout << "mult " << left.getName() << " " << right.getName() << "\n";
    rp.returnRegister(right);
    std::cout << "mflo " << left.getName() << "\n";
    return left;
}

int Multiply::getValue()
{
    if (isCTV()) return left->getValue() * right->getValue();
    else throw std::runtime_error("Multiply::getValue() -Can't get value if both operands are not CTV");
}
