#include <iostream>

#include "GreaterThan.h"

GreaterThan::GreaterThan(Expression* p_l, Expression* p_r):BinaryOp(p_l, p_r)
{
    typeIndicator = BOOLEAN;
}

void GreaterThan::print()
{
    left->print();
    std::cout << " > ";
    right->print();
}

Register GreaterThan::emit()
{
    int INT = 0;
    std::vector<Register> opRegs = emitOperands(INT);
    Register r = rp.getRegister();
    std::cout << "sgtu " << r.getName() << " " << opRegs[0].getName() << " " << opRegs[1].getName() << "\n";
    returnRegisters(opRegs);
    return r;
}

int GreaterThan::getValue()
{
   if (isCTV())
   {
       if (left->getValue() > right->isCTV()) return 1;
       else return 0;
   }
   else throw std::runtime_error("GreaterThan::getValue() - Can't get value if both operands are not CTV");
}
