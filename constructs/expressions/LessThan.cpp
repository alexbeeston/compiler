#include <iostream>

#include "LessThan.h"

LessThan::LessThan(Expression* p_l, Expression* p_r):BinaryOp(p_l, p_r)
{
}

void LessThan::print()
{
    left->print();
    std::cout << " < ";
    right->print();

}