#include <iostream>

#include "Function.h"

Function::Function(char* p_ident, std::vector<ParameterSet*>* p_parameters, Body* p_body, BaseType* p_type):Routine(p_ident, p_parameters, p_body)
{
    type = p_type;
}

void Function::print()
{
    std::cout << "FUNCTION " << ident << "(";
    printParameters();
    std::cout << ")";
    type->print();
    std::cout << "\n";
    if (body != nullptr) { body->print(); }
    std::cout << std::endl;
}

void Function::computeOffsets() { computeOffsets_internal(type->computeSize()); }
