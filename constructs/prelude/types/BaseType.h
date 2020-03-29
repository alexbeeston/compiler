#ifndef COMPILERS_BASETYPE_H
#define COMPILERS_BASETYPE_H

#include <string>
#include "../../../Enums.h"

struct BaseType
{
    std::string identifier;
    bool isRedeclarable;
    int lValueType;
    TypeIndicator typeIndicator;
    BaseType();
    virtual int computeSize();
    virtual void print();
    virtual TypeIndicator getTypeIndicator();
    virtual int getLValueType();
};

#endif //COMPILERS_SIMPLETYPE_H
