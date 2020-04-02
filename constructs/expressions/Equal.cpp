#include <iostream>

#include "Equal.h"

Equal::Equal(Expression* p_l, Expression* p_r):BinaryOpUndeterministicOperands(p_l, p_r)
{
    typeIndicator = BOOLEAN;
    if (!operandsAreOfSameType()) throw std::runtime_error("Equal::Equal() - operands are not both of same type");
    if (operandsAreBothCTV())
    {
        if (left->value == right->value) value = 1;
        else value = 0;
    }

}

Register Equal::emit()
{
    Register r = rp.getRegister();
    if (operandsAreBothCTV()) std::cout << "li " << r.getName() << " " << value << "  # loaded a CTV\n";
    else
    {
        std::vector<Register> opRegs = checkAndEmitOperands();
        std::cout << "subu " << r.getName() << " " << opRegs[0].getName() << " " << opRegs[1].getName() << "\n";
        std::cout << "sltu " << r.getName() << " $zero " << r.getName() << "\n";
        std::cout << "xori " << r.getName() << " " << r.getName() << " 1\n";
        returnRegisters(opRegs);
    }
    return r;
}
