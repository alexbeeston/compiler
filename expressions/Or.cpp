#include <iostream>

#include "Or.h"

Or::Or(Expression* p_left, Expression* p_right):BinaryOp(p_left, p_right)
{
    primitiveType = BOOLEAN;
}

void Or::print()
{
    left->print();
    std::cout << " | ";
    right->print();
}
