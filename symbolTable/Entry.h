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
    int offset;
    std::string ident;
    Expression* value;
    BaseType* type;
    EntryStyle label;
    Register baseRegister;
    void setRegister(bool);

    // init
    Entry();
    Entry(std::string, Expression*, bool); // called by constants
    Entry(std::string, BaseType*, int, bool); // called by variables

    // other functions
    virtual void print();
    Register emit();
};

#endif //COMPILERS_LOOKUPITEM_H
