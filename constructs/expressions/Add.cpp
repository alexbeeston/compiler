#include <iostream>

#include "Add.h"

Add::Add(Expression* p_l, Expression* p_r):BinaryOp(p_l, p_r)
{
}

void Add::print()
{
    left->print();
    std::cout << " + ";
    right->print();
}
