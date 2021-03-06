#include <iostream>
#include "Add.h"
#include "../global.h"

Add::Add(Expression* p_l, Expression* p_r):BinaryOp(p_l, p_r)
{
    primitiveType = INTEGER;
}

void Add::print()
{
    left->print();
    std::cout << " + ";
    right->print();
}

Register Add::emit()
{
    std::vector<Register> opRegs = emitOperands(INTEGER);
    Register left = opRegs[0];
    Register right = opRegs[1];
    std::cout << "add " << left.getName() << " " << left.getName() << " " << right.getName() << "\n";
    rp.returnRegister(right);
    return left;
}

int Add::getValue()
{
   if (isCTV()) return left->getValue() + right->getValue();
   else throw std::runtime_error("Add::getValue() - Can't add if both left and right operands are not CTV");
}

