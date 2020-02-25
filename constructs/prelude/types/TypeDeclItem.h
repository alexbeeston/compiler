//
// Created by abeeston on 2/25/20.
//

#ifndef COMPILERS_TYPEDITEM_H
#define COMPILERS_TYPEDITEM_H

#include "BaseType.h"

struct TypeDeclItem
{
    char* ident;
    BaseType* type;
    TypeDeclItem(char*, BaseType*);
    void print();
};
#endif //COMPILERS_TYPEDITEM_H
