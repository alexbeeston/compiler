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
    bool isRedeclarable;
    TypeDeclItem();
    TypeDeclItem(std::string*, BaseType*, bool p_isRedeclarable = false);
    void print();
};
#endif //COMPILERS_TYPEDITEM_H
