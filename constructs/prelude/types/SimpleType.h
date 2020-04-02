//
// Created by abeeston on 2/26/20.
//

#ifndef COMPILERS_SIMPLETYPE_H
#define COMPILERS_SIMPLETYPE_H

#include <string>

#include "BaseType.h"

struct SimpleType:BaseType
{
    std::string* name;
    SimpleType(std::string*);
    void print() override;

    // the following functions are necessary because a simple type is a string, which could be a primitive type or the name of an array or record type
    bool isPrimitive();
    TypeIndicator getTypeIndicator() override;
    LValueType getLValueType() override;
    int computeSize() override;
};
#endif //COMPILERS_SIMPLETYPE_H
