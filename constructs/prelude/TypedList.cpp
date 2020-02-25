#include <vector>
#include <iostream>

#include "TypedList.h"
#include "types/BaseType.h"

TypedList::TypedList(std::vector<char*>* p_identList, BaseType* p_type)
{
    identList = p_identList;
    type = p_type;
}

void TypedList::print()
{
    for (char* identifier : *identList)
    {
        std::cout << identifier << ", ";
    }
    std::cout << " : ";
    type->print();
    std::cout << std::endl;
}