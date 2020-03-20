#include <iostream>

#include "GreaterThanEqual.h"

GreaterThanEqual::GreaterThanEqual(Expression* p_l, Expression* p_r):BinaryOp(p_l, p_r)
{
}

void GreaterThanEqual::print()
{
    left->print();
    std::cout << " >= ";
    right->print();
}

Register GreaterThanEqual::emit()
{
    int INT = 0;
    std::vector<Register> opRegs = emitOperands(INT);
    Register r = rp.getRegister();
    std::cout << "sge " << r.getName() << " " << opRegs[0].getName() << " " << opRegs[1].getName() << "\n";
    returnRegisters(opRegs);
    return r;
}
