//
// Created by abeeston on 2/20/20.
//

#ifndef COMPILERS_EXPRESSION_H
#define COMPILERS_EXPRESSION_H
struct Expression
{
    char* prettyPrintValue; // band-aid: it's a ch
    Expression(char*);
    Expression(int);
    virtual void print();
};
#endif //COMPILERS_EXPRESSION_H
