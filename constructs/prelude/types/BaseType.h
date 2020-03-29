#ifndef COMPILERS_BASETYPE_H
#define COMPILERS_BASETYPE_H

#include <string>

struct BaseType
{
    std::string identifier;
    bool isRedeclarable;
    int lValueType;
    int typeIndicator;
    BaseType();
    virtual int computeSize();
    virtual void print();
    virtual int getTypeIndicator();
    virtual int getLValueType();
};

#endif //COMPILERS_SIMPLETYPE_H
