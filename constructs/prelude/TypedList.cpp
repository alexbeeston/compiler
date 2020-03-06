#include <vector>
#include <iostream>
#include <string>

#include "TypedList.h"
#include "types/BaseType.h"

TypedList::TypedList(std::vector<char*>* p_identList, BaseType* p_type)
{
    identList = new std::vector<std::string*>;
    for (char* p_ident : *p_identList)
    {
        identList->push_back(new std::string(p_ident));
    }
    type = p_type;
}

void TypedList::print()
{
    for (std::string* identifier : *identList)
    {
        std::cout << *identifier << ", ";
    }
    std::cout << " : ";
    type->print();
    std::cout << std::endl;
}