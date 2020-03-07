#include <iostream>

#include "And.h"

And::And(Expression* p_left, Expression* p_right):BinaryOp(p_left, p_right)
{
}

void And::print()
{
    left->print();
    std::cout << " & ";
    right->print();
}
