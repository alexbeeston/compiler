#ifndef COMPILERS_BASETYPE_H
#define COMPILERS_BASETYPE_H

#include <string>

struct BaseType
{
    std::string identifier;
    bool isRedeclarable;
    int typeIndicator;
    BaseType();
    virtual int computeSize();
    virtual void print();
    virtual int getTypeIndicator();
};

#endif //COMPILERS_SIMPLETYPE_H
