#include <iostream>

#include "Function.h"

Function::Function(char* p_ident, std::vector<ParameterSet*>* p_parameters):Routine(p_ident, p_parameters)
{
}

void Function::print()
{
    std::cout << "FUNCTION " << ident << "(";
    printParameters();
    std::cout << ")";
    std::cout << "print the return type here and optional body.";
    std::cout << std::endl;
}