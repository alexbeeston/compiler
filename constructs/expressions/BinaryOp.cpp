#include <iostream>
#include "BinaryOp.h"

BinaryOp::BinaryOp(Expression* p_left, Expression* p_right)
{
    left = p_left;
    right = p_right;
}

void BinaryOp::print()
{
    std::cout << "[binary Op]";
}

std::vector<Register> BinaryOp::emitOperands()
{
    if (!(left->getTypeIndicator() == 0 && right->getTypeIndicator() == 0))
    {
        std::cout << "# ERROR: binary operation attempted on left operand of typeIndicator " << left->getTypeIndicator();
        std::cout << " and right operand typeIndicator " << right->getTypeIndicator();
        std::cout << ". They should both be 0.\n";
        return std::vector<Register>();
    }
    else
    {
        Register r1 = left->emit();
        Register r2 = right->emit();
        std::vector<Register> temp = std::vector<Register>();
        temp.push_back(r1);
        temp.push_back(r2);
        return temp;
    }
}

void BinaryOp::returnRegisters(std::vector <Register> registers)
{
    for (Register r : registers) rp.returnRegister(r);
}