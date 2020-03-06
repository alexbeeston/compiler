#include <iostream>

#include "Divide.h"

Divide::Divide(Expression* p_l, Expression* p_r)
{
    left = p_l;
    right = p_r;
}

void Divide::print()
{
    left->print();
    std::cout << " / ";
    right->print();
}
