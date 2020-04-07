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
    int INT = 0;
    std::vector<Register> opRegs = emitOperands(INT);
    Register r = rp.getRegister();
    std::cout << "div " << opRegs[0].getName() << " " << opRegs[1].getName() << "\n";
    std::cout << "mflo " << r.getName() << "\n";
    returnRegisters(opRegs);
    return r;
}

int Divide::getValue()
{
    if (isCTV()) return left->getValue() / right->getValue();
    else throw std::runtime_error("Divide::getValue() - can't get value is both left and right operands are not CTV");
}
