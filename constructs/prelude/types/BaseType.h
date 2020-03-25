#ifndef COMPILERS_BASETYPE_H
#define COMPILERS_BASETYPE_H

#include <string>

struct BaseType
{
    std::string identifier;
    bool isRedeclarable;
    int typeIndicator;
    BaseType();
    int size;
    virtual void print();
};

#endif //COMPILERS_SIMPLETYPE_H
