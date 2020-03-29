#include <iostream>

#include "Equal.h"

Equal::Equal(Expression* p_l, Expression* p_r):BinaryOpUndeterministicOperands(p_l, p_r)
{
    typeIndicator = BOOLEAN;
}

Register Equal::emit()
{
    std::vector<Register> opRegs = checkAndEmitOperands();
    Register r = rp.getRegister();
    std::cout << "subu " << r.getName() << " " << opRegs[0].getName() << " " << opRegs[1].getName() << "\n";
    std::cout << "sltu " << r.getName() << " $zero " << r.getName() << "\n";
    std::cout << "xori " << r.getName() << " " << r.getName() << " 1\n";
    returnRegisters(opRegs);
    return r;
}
