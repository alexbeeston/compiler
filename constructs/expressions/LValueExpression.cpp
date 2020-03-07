#include <iostream>

#include "LValueExpression.h"

LValueExpression::LValueExpression(LValue* p_lValue)
{
    lValue = p_lValue;
}

void LValueExpression::print()
{
    lValue->print();
}