#include <iostream>

#include "LessThan.h"

LessThan::LessThan(Expression* p_l, Expression* p_r):BinaryOp(p_l, p_r)
{
    typeIndicator = 3;
}

void LessThan::print()
{
    left->print();
    std::cout << " < ";
    right->print();
}

Register LessThan::emit()
{
    int INT = 0;
    std::vector<Register> opRegs = emitOperands(INT);
    Register r = rp.getRegister();
    std::cout << "sltu " << r.getName() << " " << opRegs[0].getName() << " " << opRegs[1].getName() << "\n";
    returnRegisters(opRegs);
    return r;
}