#include <iostream>

#include "Mod.h"

Mod::Mod(Expression* p_left, Expression* p_right):BinaryOp(p_left, p_right)
{
    typeIndicator = INTEGER;
}

void Mod::print()
{
    left->print();
    std::cout << " % ";
    right->print();
}

Register Mod::emit()
{
    int INT = 0;
    std::vector<Register> opRegs = emitOperands(INT);
    Register r = rp.getRegister();
    std::cout << "div " << opRegs[0].getName() << " " << opRegs[1].getName() << "\n";
    std::cout << "mfhi " << r.getName() << "\n";
    returnRegisters(opRegs);
    return r;
}
