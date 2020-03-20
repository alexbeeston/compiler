#include <iostream>
#include "Add.h"

Add::Add(Expression* p_l, Expression* p_r):BinaryOp(p_l, p_r)
{
    typeIndicator = 0;
}

void Add::print()
{
    left->print();
    std::cout << " + ";
    right->print();
}

Register Add::emit()
{
    std::vector<Register> opRegs = emitOperands();
    std::cout << "# add expression\n";
    Register r = rp.getRegister();
    std::cout << "add " << r.getName() << " " << opRegs[0].getName() << " " << opRegs[1].getName() << " #   end add binary operator\n";
    returnRegisters(opRegs);
    return r;
}
