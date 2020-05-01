#include <iostream>

#include "Divide.h"

Divide::Divide(Expression* p_l, Expression* p_r):BinaryOp(p_l, p_r)
{
    typeIndicator = INTEGER;
}

void Divide::print()
{
    left->print();
    std::cout << " / ";
    right->print();
}

Register Divide::emit()
{
    std::vector<Register> opRegs = emitOperands(INTEGER);
    Register left = opRegs[0];
    Register right = opRegs[1];
    std::cout << "div " << left.getName() << " " << right.getName() << "\n";
    rp.returnRegister(right);
    std::cout << "mflo " << left.getName() << "\n";
    return left;
}

int Divide::getValue()
{
    if (isCTV()) return left->getValue() / right->getValue();
    else throw std::runtime_error("Divide::getValue() - can't get value is both left and right operands are not CTV");
}
