//
// Created by abeeston on 2/26/20.
//

#ifndef COMPILERS_SIMPLETYPE_H
#define COMPILERS_SIMPLETYPE_H

#include <string>

#include "BaseType.h"

struct SimpleType:BaseType
{
    std::string name;
    SimpleType(std::string*);
    void print() override;
    bool isPrimitive() override;
    PrimitiveType getPrimitiveType() override;
    int computeSize() override;
};
#endif //COMPILERS_SIMPLETYPE_H
