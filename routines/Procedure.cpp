#include <iostream>
#include <vector>

#include "Procedure.h"

Procedure::Procedure(char* p_ident, std::vector<ParameterSet*>* p_parameters, Body* p_body):Routine(p_ident, p_parameters, p_body)
{
}

void Procedure::print()
{
    std::cout << "PROCEDURE " << ident << "(";
    printParameters();
    std::cout << ")\n";
    if (body != nullptr) { body->print(); };
    std::cout << std::endl;
}