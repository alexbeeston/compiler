#include <iostream>
#include <string>
#include <utility>

#include "Constant.h"
#include "../expressions/Expression.h"
#include "../types/SimpleType.h"
#include "../types/BaseType.h"

Constant::Constant() {}

Constant::Constant(char* p_identifier, Expression* p_value)
{
    ident = std::string(p_identifier);
    value = p_value;
}

Constant::Constant(std::string p_identifier, Expression* p_value)
{
    ident = p_identifier;
    value = p_value;
}

void Constant::print()
{
    std::cout << ident << " = ";
    value->print();
    std::cout << ";" << std::endl;
}
