#include <iostream>

#include "Return.h"

Return::Return() { expression = nullptr; }
Return::Return(Expression* p_expression) { expression = p_expression; }

void Return::print()
{
    std::cout << "return ";
    if (expression != nullptr) expression->print();
}