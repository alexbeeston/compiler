#include <iostream>

#include "RecordType.h"

RecordType::RecordType(std::vector<TypedList*>* p_typedLists)
{
    typedLists = p_typedLists;
    typeIndicator = 5;
    isRedeclarable = false;
    identifier = std::string("junk");
}

void RecordType::print()
{
    std::cout << "record ";
    for (TypedList* list : *typedLists) list->print();
}