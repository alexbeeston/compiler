#include <iostream>

#include "Equal.h"

Equal::Equal(Expression* p_l, Expression* p_r):BinaryOpUndeterministicOperands(p_l, p_r)
{
    typeIndicator = BOOLEAN;
}

Register Equal::emit()
{
    // validate
    if (!operandsAreOfSameType()) throw std::runtime_error("Equal::Equal() - operands are not both of same type");

    // emit
    Register r = rp.getRegister();
    if (isCTV()) std::cout << "li " << r.getName() << " " << getValue() << "  # loaded a CTV\n";
    else
    {
        std::vector<Register> opRegs = checkAndEmitOperands();
        std::cout << "subu " << r.getName() << " " << opRegs[0].getName() << " " << opRegs[1].getName() << "\n";
        std::cout << "sltu " << r.getName() << " $zero " << r.getName() << "\n";
        std::cout << "xori " << r.getName() << " " << r.getName() << " 1\n";
        returnRegisters(opRegs);
    }
    r.containsAddress = false;
    return r;
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
