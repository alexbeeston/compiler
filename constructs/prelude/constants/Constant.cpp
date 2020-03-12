#include <iostream>
#include <string>

#include "Constant.h"
#include "../../expressions/Expression.h"

Constant::Constant(char* p_identifier, Expression* p_value)
{
    identifier = new std::string(p_identifier);
    value = p_value;
}

void Constant::print()
{
    std::cout << identifier << " = ";
    value->print();
    std::cout << ";" << std::endl;
}
