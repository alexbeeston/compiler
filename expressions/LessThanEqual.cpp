#include <iostream>

#include "LessThanEqual.h"

LessThanEqual::LessThanEqual(Expression* p_l, Expression* p_r):BinaryOp(p_l, p_r)
{
    typeIndicator = BOOLEAN;
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
    Register left = opRegs[0];
    Register right = opRegs[1];
    std::cout << "sle " << left.getName() << " " << left.getName() << " " << right.getName() << "\n";
    rp.returnRegister(right);
    left.containsAddress = false;
    return left;
}

int LessThanEqual::getValue()
{
    if (isCTV())
    {
        if (left->getValue() <= right->getValue()) return 1;
        else return 0;
    }
    else throw std::runtime_error("LessThanEqual::getValue() - Can't get value if both operands are not CTV");
}
