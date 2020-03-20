#include <iostream>

#include "Sub.h"

Sub::Sub(Expression* p_l, Expression* p_r):BinaryOp(p_l, p_r)
{
}

void Sub::print()
{
    left->print();
    std::cout << " - ";
    right->print();
}

Register Sub::emit()
{
    std::vector<Register> opRegs = emitOperands();
    Register r = rp.getRegister();
    std::cout << "sub " << r.getName() << " " << opRegs[0].getName() << " " << opRegs[1].getName() << "\n";
    returnRegisters(opRegs);
    return r;
}
