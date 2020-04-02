#include <iostream>

#include "RecordType.h"

RecordType::RecordType(std::vector<TypedList*>* p_typedLists)
{
    typedLists = p_typedLists;
    style = RECORD_TYPE;
}

int RecordType::computeSize()
{
    int offset = 0;
    BaseType* type;
    for (TypedList* list : *typedLists)
    {
        type = list->type;
        for (std::string* identifier : *list->identList)
        {
            types[*identifier] = type;
            offsets[*identifier] = offset;
            offset += type->computeSize();
        }
    }
    return offset;
}

TypeIndicator RecordType::getTypeIndicator()
{
    throw std::runtime_error("RecordType::getTypeIndicator; doesn't have a single type");
}

void RecordType::print()
{
    std::cout << "record ";
    for (TypedList* list : *typedLists) list->print();
}