#include <iostream>

#include "ParameterSet.h"

ParameterSet::ParameterSet(int p_passBy, std::vector<char*>* p_identList, BaseType* p_type)
{
    if (p_passBy == 0) passBy = VALUE;
    else if (p_passBy == 1) passBy = REFERENCE;
    else throw std::runtime_error("ParameterSet constructor - p_passBy is not a valid. Expected 0 or 1, got " + std::to_string(p_passBy) + ".");
    for (auto ident : *p_identList) identList.push_back(std::string(ident));
    type = p_type;
}

void ParameterSet::print()
{
    std::cout << "here is a parameter set";
}