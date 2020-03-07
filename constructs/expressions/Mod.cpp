#include <iostream>

#include "Mod.h"

Mod::Mod(Expression* p_left, Expression* p_right):BinaryOp(p_left, p_right)
{

}

void Mod::print()
{
    left->print();
    std::cout << " % ";
    right->print();
}
