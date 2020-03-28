//
// Created by abeeston on 3/3/20.
//

#ifndef COMPILERS_RECORDTYPE_H
#define COMPILERS_RECORDTYPE_H

#include <vector>

#include "BaseType.h"
#include "../TypedList.h"

struct RecordType:BaseType
{
    std::vector<TypedList*>* typedLists;
    RecordType(std::vector<TypedList*>*);
    void print() override;
    int computeSize() override;
};
#endif //COMPILERS_RECORDTYPE_H
