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

std::vector<Register> BinaryOp::emitOperands(int requiredType)
{
    if (!(left->getPrimitiveType() == requiredType && right->getPrimitiveType() == requiredType))
    {
        std::cout << "# ERROR: binary operation attempted on left operand of typeIndicator " << left->getPrimitiveType();
        std::cout << " and right operand typeIndicator " << right->getPrimitiveType();
        std::cout << ". They should both be " << requiredType << ".\n";
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

bool BinaryOp::isCTV()
{
    if ( left->isCTV() && right->isCTV()) return true;
    else return false;
}