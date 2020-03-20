#include <iostream>

#include "Multiply.h"

Multiply::Multiply(Expression* p_l, Expression* p_r):BinaryOp(p_l, p_r)
{
    typeIndicator = 0;
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
    Register r = rp.getRegister();
    std::cout << "mult " << opRegs[0].getName() << " " << opRegs[1].getName() << "\n";
    std::cout << "mflo " << r.getName() << "\n";
    returnRegisters(opRegs);
    return r;
}
