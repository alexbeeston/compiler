#include <iostream>

#include "Equal.h"

Equal::Equal(Expression* p_l, Expression* p_r): LogicalBinaryOp(p_l, p_r)
{
    typeIndicator = BOOLEAN;
}

Register Equal::emit()
{
    if (isCTV())
    {
        Register r = rp.getRegister();
        std::cout << "li " << r.getName() << " " << getValue() << "  # loaded a CTV\n";
        r.containsAddress = false;
        return r;
    }
    else
    {
        auto registers = checkAndEmitOperands();
        auto leftReg = registers[0];
        auto rightReg = registers[1];
        std::cout << "subu " << leftReg.getName() << " " << leftReg.getName() << " " << rightReg.getName() << "\n";
        std::cout << "sltu " << leftReg.getName() << " $zero " << leftReg.getName() << "\n";
        std::cout << "xori " << leftReg.getName() << " " << leftReg.getName() << " 1\n";
        rp.returnRegister(rightReg);
        leftReg.containsAddress = false;
        return leftReg;
    }
}

int Equal::getValue()
{
    if (isCTV())
    {
        if (left->value == right->value) return 1;
        else return 0;
    }
    else throw std::runtime_error("Equal::getValue() - operands are not both compile time known");
}
