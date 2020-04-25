//
// Created by abeeston on 4/2/20.
//

#ifndef COMPILERS_DECLAREDTYPE_H
#define COMPILERS_DECLAREDTYPE_H

#include "BaseType.h"
#include <string>

struct DeclaredType
{
    std::string identifier;
    BaseType* type;
    DeclaredType(char*, BaseType*);
    DeclaredType(std::string, BaseType*);
    void print();
};
#endif //COMPILERS_DECLAREDTYPE_H
