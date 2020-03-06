#include <iostream>

#include "Sub.h"

Sub::Sub(Expression* p_l, Expression* p_r)
{
    left = p_l;
    right = p_r;
}

void Sub::print()
{
    left->print();
    std::cout << " - ";
    right->print();
}
