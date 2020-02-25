//
// Created by abeeston on 2/24/20.
//

#ifndef COMPILERS_ROUTINE_H
#define COMPILERS_ROUTINE_H

struct Routine
{
    char* ident;
    virtual void print();
    Routine(char*);
};
#endif //COMPILERS_ROUTINE_H
