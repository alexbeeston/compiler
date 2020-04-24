//
// Created by abeeston on 3/20/20.
//

#ifndef COMPILERS_LOOKUPITEM_H
#define COMPILERS_LOOKUPITEM_H

#include "../types/BaseType.h"
#include "../registerPool/Register.h"
#include "../expressions/Expression.h"
#include "../Enums.h"

struct Entry
{
    // fields
    int offset; // -1 for constants (set by symbol table)
    Register baseRegister; // for variables only
    std::string ident;
    Expression* value = nullptr; // used by constants only
    BaseType* type;
    Label label;

    // init
    Entry();
    Entry(std::string, Expression*);
    Entry(std::string, BaseType*, int);

    // other functions
    virtual void print();
    Register emit();
};

#endif //COMPILERS_LOOKUPITEM_H
