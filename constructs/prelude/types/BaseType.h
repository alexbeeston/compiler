#ifndef COMPILERS_BASETYPE_H
#define COMPILERS_BASETYPE_H

#include <string>
#include "../../../Enums.h"

struct BaseType
{
    LValueType lValueType;
    TypeIndicator typeIndicator;
    BaseType();
    int size; // set by the symbol table
    virtual int computeSize();
    virtual void print();
    virtual TypeIndicator getTypeIndicator();
    virtual LValueType getLValueType();
};

#endif //COMPILERS_SIMPLETYPE_H
