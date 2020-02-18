#ifndef  TYPES_H
#define  TYPES_H


#include <iostream>

struct Type
{
    virtual void print() {std::cout << "Type toString() function" << std::endl;}
};


struct SimpleType : Type
{
    char* ident;
    SimpleType(char* p_indent) { ident = p_indent; };
    void print() {std::cout << ident << std::endl;}
};


#endif