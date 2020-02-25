#include <iostream>
#include <vector>

#include "Procedure.h"

Procedure::Procedure(char* p_ident, std::vector<ParameterSet*>* p_parameters):Routine(p_ident, p_parameters)
{
}

void Procedure::print()
{
    std::cout << "PROCEDURE " << ident << "(";
    printParameters();
    std::cout << ")";
    std::cout << "print the optional body.";
    std::cout << std::endl;
}