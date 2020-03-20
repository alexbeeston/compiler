#include <iostream>

#include "LessThanEqual.h"

LessThanEqual::LessThanEqual(Expression* p_l, Expression* p_r):BinaryOp(p_l, p_r)
{
}

void LessThanEqual::print()
{
    left->print();
    std::cout << " <= ";
    right->print();
}

Register LessThanEqual::emit()
{
    int INT = 0;
    std::vector<Register> opRegs = emitOperands(INT);
    Register r = rp.getRegister();
    std::cout << "sle " << r.getName() << " " << opRegs[0].getName() << " " << opRegs[1].getName() << "\n";
    returnRegisters(opRegs);
    return r;
}
