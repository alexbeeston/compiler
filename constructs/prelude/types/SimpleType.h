//
// Created by abeeston on 2/24/20.
//

#ifndef COMPILERS_SIMPLETYPE_H
#define COMPILERS_SIMPLETYPE_H

#include "BaseType.h"

struct SimpleType : BaseType
{
    char* identAsType;
    SimpleType(char*);
};
#endif //COMPILERS_SIMPLETYPE_H
