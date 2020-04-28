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
    if (expression->getPrimitiveType() == STRING) throw std::runtime_error("SuccFunc::emit() - not defined for strings");
    else if (expression->getPrimitiveType() == BOOLEAN)
    {
        throw std::runtime_error("SuccFunc::emit() - not yet implemented for boolean expression");
    }
    else if (expression->getPrimitiveType() == INTEGER)
    {
        Register result = expression->emit();
        std::cout << "addi " << result.getName() << " " << result.getName() << " 1\n";
        result.containsAddress = false;
        return result;
    }
    else throw std::runtime_error("SuccFunc::emit() - expression is not string, boolean, or integer");
}
