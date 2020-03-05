#include <iostream>

#include "Return.h"

Return::Return() { expression = nullptr; }
Return::Return(Expression* p_expression) { expression = p_expression; }

void Return::print()
{
    std::cout << "Return Statement";
    if (expression != nullptr) { std::cout << ": expression - "; expression->print(); };
}