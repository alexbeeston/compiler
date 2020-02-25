#include <iostream>

#include "ParameterSet.h"

ParameterSet::ParameterSet(int p_passBy, std::vector<char *>* p_identList, BaseType* p_type)
{
    passBy = p_passBy;
    identList = p_identList;
    type = p_type;
}

void ParameterSet::print()
{
    std::cout << "here is a parameter set";
}