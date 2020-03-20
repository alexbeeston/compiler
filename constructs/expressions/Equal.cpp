#include <iostream>

#include "Equal.h"

Equal::Equal(Expression* p_l, Expression* p_r):BinaryOpUndeterministicOperands(p_l, p_r)
{
    typeIndicator = 3;
}

Register Equal::emit()
{
//    std::vector<Register> opRegs = checkAndEmitOperands();
//    Register r = rp.getRegister();
//    std::cout << "sub " << r.getName() << opRegs[0].getName() << " " << opRegs[1].getName()
    std::cout << "# Testing for equality not supported yet\n";
    return Register();
}

