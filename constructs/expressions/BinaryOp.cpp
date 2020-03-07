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