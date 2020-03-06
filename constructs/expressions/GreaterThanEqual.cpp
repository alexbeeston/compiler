#include <iostream>

#include "GreaterThanEqual.h"

GreaterThanEqual::GreaterThanEqual(Expression* p_l, Expression* p_r)
{
    left = p_l;
    right = p_r;
}

void GreaterThanEqual::print()
{
    left->print();
    std::cout << " >= ";
    right->print();
}
