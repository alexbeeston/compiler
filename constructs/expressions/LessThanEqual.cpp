#include <iostream>

#include "LessThanEqual.h"

LessThanEqual::LessThanEqual(Expression* p_l, Expression* p_r):BinaryOp(p_l, p_r)
{
}

void LessThanEqual::print()
{
    left->print();
    std::cout << " <= ";
    right->print();
}
