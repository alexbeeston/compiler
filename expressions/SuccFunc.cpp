#include <iostream>

#include "SuccFunc.h"
#include "../global.h"

SuccFunc::SuccFunc(Expression* p_expression)
{
    expression = p_expression;
}

void SuccFunc::print()
{
    std::cout << "succ(";
    expression->print();
    std::cout << ")";
}

Register SuccFunc::emit()
{
    if (expression->getTypeIndicator() == STRING) throw std::runtime_error("SuccFunc::emit() - not defined for strings");
    else if (expression->getTypeIndicator() == BOOLEAN)
    {
        throw std::runtime_error("SuccFunc::emit() - not yet implemented for boolean expression");
    }
    else if (expression->getTypeIndicator() == INTEGER)
    {
        Register result = expression->emit();
        std::cout << "addi " << result.getName() << " " << result.getName() << " 1\n";
        return result;
    }
    else throw std::runtime_error("SuccFunc::emit() - expression is not string, boolean, or integer");
}
