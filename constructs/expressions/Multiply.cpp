#include <iostream>

#include "Multiply.h"

Multiply::Multiply(Expression* p_l, Expression* p_r):BinaryOp(p_l, p_r)
{
}

void Multiply::print()
{
    left->print();
    std::cout << " * ";
    right->print();
}

Register Multiply::emit()
{
    std::vector<Register> opRegs = emitOperands();
    Register r = rp.getRegister();
    std::cout << "mult " << r.getName() << " " << opRegs[0].getName() << " " << opRegs[1].getName() << "\n";
    returnRegisters(opRegs);
    return r;
}
