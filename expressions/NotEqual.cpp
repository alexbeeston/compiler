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
    std::vector<Register> opRegs = checkAndEmitOperands();
    Register r = rp.getRegister();
    std::cout << "subu " << r.getName() << " " << opRegs[0].getName() << " " << opRegs[1].getName() << "\n";
    std::cout << "sltu " << r.getName() << " $zero " << r.getName() << "\n";
    returnRegisters(opRegs);
    r.containsAddress = false;
    return r;
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