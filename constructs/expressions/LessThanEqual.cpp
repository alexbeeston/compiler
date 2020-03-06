#include <iostream>

#include "LessThanEqual.h"

LessThanEqual::LessThanEqual(Expression* p_l, Expression* p_r)
{
    left = p_l;
    right = p_r;
}

void LessThanEqual::print()
{
    left->print();
    std::cout << " <= ";
    right->print();
}
