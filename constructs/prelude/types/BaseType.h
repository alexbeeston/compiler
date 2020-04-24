#ifndef COMPILERS_BASETYPE_H
#define COMPILERS_BASETYPE_H

#include <string>
#include "../../../Enums.h"

struct BaseType
{
    Style style;
    TypeIndicator typeIndicator;
    BaseType();
    int size; // set by the symbol table
    virtual bool isPrimitive();
    virtual bool isAlias();
    virtual int computeSize();
    virtual void print();
    virtual TypeIndicator getTypeIndicator();
};

#endif //COMPILERS_SIMPLETYPE_H
