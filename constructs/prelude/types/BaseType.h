#ifndef COMPILERS_BASETYPE_H
#define COMPILERS_BASETYPE_H

struct BaseType
{
    int typeIndicator;
    BaseType();
    int size;
    virtual void print();
};

#endif //COMPILERS_SIMPLETYPE_H
