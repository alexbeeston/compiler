#include <iostream>

#include "NotEqual.h"

NotEqual::NotEqual(Expression* p_left, Expression* p_right): LogicalBinaryOp(p_left, p_right)
{
    typeIndicator = BOOLEAN;
}

void NotEqual::print()
{
    left->print();
    std::cout << " <> ";
    right->print();
}

Register NotEqual::emit()
{
    auto registers = checkAndEmitOperands();
    auto leftReg = registers[0];
    auto rightReg = registers[1];
    std::cout << "subu " << leftReg.getName() << " " << leftReg.getName() << " " << rightReg.getName() << "\n";
    std::cout << "sltu " << leftReg.getName() << " $zero " << leftReg.getName() << "\n";
    rp.returnRegister(rightReg);
    leftReg.containsAddress = false;
    return leftReg;
}

int NotEqual::getValue()
{
    if (isCTV())
    {
        if (left->getValue() != right->getValue()) return 1;
        else return 0;
    }
    else throw std::runtime_error("NotEqual::getValue() - Can't get value if both operands are not CTV");
}