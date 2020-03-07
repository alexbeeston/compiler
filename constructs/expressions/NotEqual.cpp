#include <iostream>

#include "NotEqual.h"

NotEqual::NotEqual(Expression* p_left, Expression* p_right):BinaryOp(p_left, p_right)
{
}

void NotEqual::print()
{
    left->print();
    std::cout << " <> ";
    right->print();
}
