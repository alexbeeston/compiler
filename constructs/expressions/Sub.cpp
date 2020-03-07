#include <iostream>

#include "Sub.h"

Sub::Sub(Expression* p_l, Expression* p_r):BinaryOp(p_l, p_r)
{
}

void Sub::print()
{
    left->print();
    std::cout << " - ";
    right->print();
}
