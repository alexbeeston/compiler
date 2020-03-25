//
// Created by abeeston on 3/20/20.
//

#ifndef COMPILERS_LOOKUPITEM_H
#define COMPILERS_LOOKUPITEM_H

#include "types/BaseType.h"
#include "../../Register.h"
#include "../expressions/Expression.h"

struct LookUpItem
{
    // fields
    int offset; // -1 for constants (set by symbol table)
    bool isRedeclarable; // false for everything except the true/false mutable constants
    std::string baseRegister; // for variables only
    std::string ident;
    Expression* value; // used by constants only
    BaseType type;

    // init
    LookUpItem();
    LookUpItem(std::string, Expression*, bool);
    LookUpItem(std::string, BaseType, int);
    BaseType generateBaseType();

    // other functions
    virtual void print();
    Register emit();
};

#endif //COMPILERS_LOOKUPITEM_H