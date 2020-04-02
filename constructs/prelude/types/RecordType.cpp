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
//    int offset  = 0;
//    BaseType* type;
//    for (TypedList* list : *typedLists)
//    {
//        type = list->type;
//        for (std::string* identifier : *list->identList)
//        {
//            types[*identifier] = type;
//            offsets[*identifier] = offset;
//            offset += type->computeSize();
//        }
//    }
//    std::cout << "# size of record: " << offset << "\n";
//    return offset;
    std::cout << "# RecordType::ComputeSize()\n";
    return 10;
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