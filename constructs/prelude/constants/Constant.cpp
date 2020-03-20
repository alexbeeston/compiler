#include <iostream>
#include <string>

#include "Constant.h"
#include "../../expressions/Expression.h"
#include "../types/SimpleType.h"
#include "../types/BaseType.h"

Constant::Constant(char* p_identifier, Expression* p_value):LookUpItem(std::string(p_identifier), generateBaseType(*p_value))
{
    value = p_value;
}

BaseType Constant::generateBaseType(Expression e)
{
    if (e.typeIndicator == 0) return SimpleType(new std::string("integer"));
    else if (e.typeIndicator == 1) return SimpleType(new std::string("char"));
    else if (e.typeIndicator == 2) return SimpleType(new std::string("string"));
    else if (e.typeIndicator == 3) return SimpleType(new std::string("boolean"));
    else
    {
        std::cout << "Error constructing a BaseType from a constant (since it inherits from LookUpItem, which needs a BaseType), and the expression isn't of a primitive type\n";
        return BaseType();
    }
}

//LookUpItem(std::string, BaseType);
void Constant::print()
{
    std::cout << ident << " = ";
    value->print();
    std::cout << ";" << std::endl;
}
