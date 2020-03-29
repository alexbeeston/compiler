#include <iostream>

#include "RecordType.h"

RecordType::RecordType(std::vector<TypedList*>* p_typedLists)
{
    lValueType = RECORD_TYPE;
    typedLists = p_typedLists;
    isRedeclarable = false;
    identifier = std::string("[declared inline]");
}
int RecordType::computeSize()
{
    std::cout << "inside recordType::computeSize()\n";
}

void RecordType::print()
{
    std::cout << "record ";
    for (TypedList* list : *typedLists) list->print();
}