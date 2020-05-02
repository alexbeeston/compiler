#include <iostream>

#include "LessThan.h"

LessThan::LessThan(Expression* p_l, Expression* p_r):BinaryOp(p_l, p_r)
{
    primitiveType = BOOLEAN;
}

void LessThan::print()
{
    left->print();
    std::cout << " < ";
    right->print();
}

Register LessThan::emit()
{
    std::vector<Register> opRegs = emitOperands(INTEGER);
    Register left = opRegs[0];
    Register right = opRegs[1];
    std::cout << "slt " << left.getName() << " " << left.getName() << " " << right.getName() << "\n";
    rp.returnRegister(right);
    return left;
}

int LessThan::getValue()
{
    if (isCTV())
    {
        if (left->getValue() < right->getValue()) return 1;
        else return 0;
    }
    else throw std::runtime_error("LessThan::getValue() - Can't get value if both operands are not CTV");
}