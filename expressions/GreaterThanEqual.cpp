#include <iostream>

#include "GreaterThanEqual.h"

GreaterThanEqual::GreaterThanEqual(Expression* p_l, Expression* p_r):BinaryOp(p_l, p_r)
{
    typeIndicator = BOOLEAN;
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
    Register left = opRegs[0];
    Register right = opRegs[1];
    std::cout << "sle " << left.getName() << " " << right.getName() << " " << left.getName() << "\n";
    rp.returnRegister(right);
    return left;
}

int GreaterThanEqual::getValue()
{
    if (isCTV())
    {
        if (left->getValue() >= right->getValue()) return 1;
        else return 0;
    }
    else throw std::runtime_error("GreaterThanEqual::getValue() - Can't get value if both operands are not CTV");
}
