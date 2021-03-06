#include <iostream>

#include "Mod.h"

Mod::Mod(Expression* p_left, Expression* p_right):BinaryOp(p_left, p_right)
{
    primitiveType = INTEGER;
}

void Mod::print()
{
    left->print();
    std::cout << " % ";
    right->print();
}

Register Mod::emit()
{
    std::vector<Register> opRegs = emitOperands(INTEGER);
    Register left = opRegs[0];
    Register right = opRegs[1];
    std::cout << "div " << left.getName() << " " << right.getName() << "\n";
    rp.returnRegister(right);
    std::cout << "mfhi " << left.getName() << "\n";
    return left;
}

int Mod::getValue()
{
    if (isCTV()) return left->getValue() % right->getValue();
    else throw std::runtime_error("Mod::getValue() -Can't get value if both operands are not CTV ");
}
