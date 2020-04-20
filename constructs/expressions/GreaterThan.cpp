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
    Register left = opRegs[0];
    Register right = opRegs[1];
    std::cout << "slt " << left.getName() << " " << right.getName() << " " << left.getName() << "\n";
    rp.returnRegister(right);
    return left;
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
