#include <iostream>

#include "Sub.h"

Sub::Sub(Expression* p_l, Expression* p_r):BinaryOp(p_l, p_r)
{
    typeIndicator = INTEGER;
}

void Sub::print()
{
    left->print();
    std::cout << " - ";
    right->print();
}

Register Sub::emit()
{
    int INT = 0;
    std::vector<Register> opRegs = emitOperands(INT);
    Register r = rp.getRegister();
    std::cout << "sub " << r.getName() << " " << opRegs[0].getName() << " " << opRegs[1].getName() << "\n";
    returnRegisters(opRegs);
    return r;
}

int Sub::getValue()
{
    if (isCTV()) return left->getValue() - right->getValue();
    else throw std::runtime_error("Sub::getValue() - Can't get value if both operands are not CTV");
}
