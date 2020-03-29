//
// Created by abeeston on 2/26/20.
//

#ifndef COMPILERS_SIMPLETYPE_H
#define COMPILERS_SIMPLETYPE_H

#include <string>

#include "BaseType.h"

struct SimpleType:BaseType
{
    std::string* name; // think of this as a pointer to another type in the symbol table; used for arrays and records as shorthand; when we come across it, we'll look up the referenced type in the symbol table. See syntax/type_decl.cpsl
    SimpleType(std::string*, bool p_isRedeclarable = false);
    void print() override;
    int computeSize() override;
    int getTypeIndicator() override;
    int getLValueType() override;
    bool isPrimitive();
};
#endif //COMPILERS_SIMPLETYPE_H
