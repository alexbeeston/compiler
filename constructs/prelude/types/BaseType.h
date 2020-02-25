#ifndef COMPILERS_SIMPLETYPE_H
#define COMPILERS_SIMPLETYPE_H

struct BaseType
{
    char* ident;
    char* identAsType;
    int test;
    BaseType(char*);
};

#endif //COMPILERS_SIMPLETYPE_H
