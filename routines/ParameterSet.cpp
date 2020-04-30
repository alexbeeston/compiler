#include <iostream>

#include "ParameterSet.h"

ParameterSet::ParameterSet(int p_passBy, std::vector<char*>* p_identList, BaseType* p_type)
{
    passBy = p_passBy;
    for (auto ident : *p_identList) identList.push_back(std::string(ident));
    type = p_type;
}

void ParameterSet::print()
{
    std::cout << "here is a parameter set";
}