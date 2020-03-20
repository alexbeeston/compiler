#include <iostream>

#include "Divide.h"

Divide::Divide(Expression* p_l, Expression* p_r):BinaryOp(p_l, p_r)
{
    typeIndicator = 0;
}

void Divide::print()
{
    left->print();
    std::cout << " / ";
    right->print();
}

Register Divide::emit()
{
    std::vector<Register> opRegs = emitOperands();
    Register r = rp.getRegister();
    std::cout << "div " << r.getName() << " " << opRegs[0].getName() << " " << opRegs[1].getName() << "\n";
    returnRegisters(opRegs);
    return r;
}
