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
    // validate
    if (expression->resolvePrimitiveType() == STRING) throw std::runtime_error("SuccFunc::emit() - not defined for strings");
    else if (expression->resolvePrimitiveType() == NOT_PRIMITIVE) throw std::runtime_error("SuccFunc::emit() - not defined for non-primitive types");

    // continue
    if (expression->resolvePrimitiveType() == INTEGER || expression->resolvePrimitiveType() == CHAR)
    {
        Register result = expression->emit();
        std::cout << "addi " << result.getName() << " " << result.getName() << " 1\n";
        result.containsAddress = false;
        return result;
    }
    else if (expression->resolvePrimitiveType() == BOOLEAN)
    {
        throw std::runtime_error("SuccFun::emit() - not yet implemented for booleans");
    }
}
