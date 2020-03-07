#include <iostream>

#include "Multiply.h"

Multiply::Multiply(Expression* p_l, Expression* p_r):BinaryOp(p_l, p_r)
{
}

void Multiply::print()
{
    left->print();
    std::cout << " * ";
    right->print();
}
