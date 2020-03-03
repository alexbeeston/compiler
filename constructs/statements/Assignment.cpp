#include <iostream>

#include "Assignment.h"

Assignment::Assignment(LValue* p_lValue, Expression* p_expression)
{
    lValue = p_lValue;
    expression = p_expression;
}

void Assignment::print()
{
    std::cout << "Assignment Statement with LValue ";
    lValue->print();
    std::cout << " and expression ";
    expression->print();
}