#ifndef COMPILERS_BASETYPE_H
#define COMPILERS_BASETYPE_H

#include <string>
#include "../Enums.h"

struct BaseType
{
    TypeStyle style;
    PrimitiveType typeIndicator;
    BaseType();
    int size; // might be able to delete
    virtual bool isPrimitive();
    virtual int computeSize();
    virtual void print();
    virtual PrimitiveType getPrimitiveType();
};

#endif //COMPILERS_SIMPLETYPE_H
