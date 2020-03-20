#include <iostream>

#include "NotEqual.h"

NotEqual::NotEqual(Expression* p_left, Expression* p_right):BinaryOpUndeterministicOperands(p_left, p_right)
{
    typeIndicator = 3;
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
    return r;
}