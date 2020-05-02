#include <iostream>

#include "Sub.h"

Sub::Sub(Expression* p_l, Expression* p_r):BinaryOp(p_l, p_r)
{
    primitiveType = INTEGER;
}

void Sub::print()
{
    left->print();
    std::cout << " - ";
    right->print();
}

Register Sub::emit()
{
    std::vector<Register> opRegs = emitOperands(INTEGER);
    Register left = opRegs[0];
    Register right = opRegs[1];
    std::cout << "sub " << left.getName() << " " << left.getName() << " " << right.getName() << "\n";
    rp.returnRegister(right);
    return left;
}

int Sub::getValue()
{
    if (isCTV()) return left->getValue() - right->getValue();
    else throw std::runtime_error("Sub::getValue() - Can't get value if both operands are not CTV");
}
