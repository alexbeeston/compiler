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
    bool isDeclaredEntry;
    bool passByReference;

    // init
    Entry();
    Entry(std::string, Expression*, bool, bool); // called by constants
    Entry(std::string, BaseType*, int, bool, bool, bool); // called by variables

    // other functions
    virtual void print();
    private: void setRegister(bool);
};

#endif //COMPILERS_LOOKUPITEM_H
