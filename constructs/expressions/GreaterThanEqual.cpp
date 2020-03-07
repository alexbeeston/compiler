#include <iostream>

#include "GreaterThanEqual.h"

GreaterThanEqual::GreaterThanEqual(Expression* p_l, Expression* p_r):BinaryOp(p_l, p_r)
{
}

void GreaterThanEqual::print()
{
    left->print();
    std::cout << " >= ";
    right->print();
}
