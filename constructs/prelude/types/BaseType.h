#ifndef COMPILERS_BASETYPE_H
#define COMPILERS_BASETYPE_H

struct BaseType
{
    char* ident;
    BaseType();
    virtual void print();
};

#endif //COMPILERS_SIMPLETYPE_H
