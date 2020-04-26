//
// Created by abeeston on 3/3/20.
//

#ifndef COMPILERS_RECORDTYPE_H
#define COMPILERS_RECORDTYPE_H

#include <vector>
#include <map>

#include "BaseType.h"
#include "../miscellaneous/TypedList.h"

struct RecordType:BaseType
{
    std::vector<TypedList*>* typedLists;
    std::map<std::string, BaseType*> types;
    std::map<std::string, int> offsets;
    RecordType(std::vector<TypedList*>*);
    void print() override;
    bool isPrimitive() override;
    int computeSize() override;
    PrimitiveType getPrimitiveType();
};
#endif //COMPILERS_RECORDTYPE_H
