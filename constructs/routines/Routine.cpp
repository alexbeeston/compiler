#include <iostream>
#include <vector>

#include "Routine.h"
#include "ParameterSet.h"
#include "Body.h"

Routine::Routine(char* p_ident, std::vector<ParameterSet*>* p_formalParameters, Body* p_body)
{
    ident = p_ident;
    formalParameters = p_formalParameters;
    body = p_body;
}

void Routine::print()
{
    std::cout << "This should be overriden" << std::endl;
}

void Routine::printParameters()
{
    for (ParameterSet* parameterSet: *formalParameters)
    {
        if (parameterSet->passBy == 0) std::cout << "var ";
        else if (parameterSet->passBy == 1) std::cout << "ref ";
        else std::cout << "Error: passBy value in Routine::printParameters() is not a 0 or 1, meaning, it is not passed by reference or value.";
        for (char* identifier : *(parameterSet->identList)) std::cout << identifier << ", ";
        std::cout << " : ";
        parameterSet->type->print();
        std::cout << " ; ";
    }
}

