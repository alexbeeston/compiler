#include <iostream>

#include "GreaterThan.h"

GreaterThan::GreaterThan(Expression* p_l, Expression* p_r):BinaryOp(p_l, p_r)
{
}

void GreaterThan::print()
{
    left->print();
    std::cout << " > ";
    right->print();
}
