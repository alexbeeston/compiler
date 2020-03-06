#include <iostream>

#include "Or.h"

Or::Or(Expression* p_left, Expression* p_right)
{
    left = p_left;
    right = p_right;
}

void Or::print()
{
    left->print();
    std::cout << " | ";
    right->print();
}
