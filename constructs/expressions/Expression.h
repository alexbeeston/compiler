//
// Created by abeeston on 2/20/20.
//

#ifndef COMPILERS_EXPRESSION_H
#define COMPILERS_EXPRESSION_H

enum Contents {NUMBER, CHARACTER, STRING};

struct Expression
{
    Contents* contents;
    virtual void print();
    virtual void emitLabel();
};
#endif //COMPILERS_EXPRESSION_H
