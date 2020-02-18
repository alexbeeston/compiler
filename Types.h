#ifndef  TYPES_H
#define  TYPES_H


#include <iostream>

struct Type
{
};

struct SimpleType : Type
{
    char* ident;
    public: SimpleType(char* p_indent) { ident = p_indent; };
};

#endif