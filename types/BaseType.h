#ifndef COMPILERS_BASETYPE_H
#define COMPILERS_BASETYPE_H

#include <string>
#include "../Enums.h"

struct BaseType
{
    TypeStyle style;
    PrimitiveType typeIndicator;
    BaseType();
    int size; // set by the symbol table
    virtual bool isPrimitive();
    virtual bool isAlias();
    virtual int computeSize();
    virtual void print();
    virtual PrimitiveType getPrimitiveType();
};

#endif //COMPILERS_SIMPLETYPE_H
