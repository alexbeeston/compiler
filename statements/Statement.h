//
// Created by abeeston on 2/25/20.
//

#ifndef COMPILERS_STATEMENT_H
#define COMPILERS_STATEMENT_H

struct Statement
{
    Statement();
    virtual void emit();
    virtual void print();
};
#endif //COMPILERS_STATEMENT_H
