//
// Created by abeeston on 2/25/20.
//

#ifndef COMPILERS_TYPEDITEM_H
#define COMPILERS_TYPEDITEM_H

#include <string>

#include "BaseType.h"

struct TypeDeclItem
{
    std::string* ident;
    BaseType* type;
    TypeDeclItem(std::string*, BaseType*);
    void print();
};
#endif //COMPILERS_TYPEDITEM_H
