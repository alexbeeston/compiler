#ifndef COMPILERS_SIMPLETYPE_H
#define COMPILERS_SIMPLETYPE_H

struct BaseType
{
    char* ident;
    int test;
    BaseType();
    void setIdent(char*);
};

#endif //COMPILERS_SIMPLETYPE_H
