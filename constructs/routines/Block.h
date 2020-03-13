//
// Created by abeeston on 2/25/20.
//

#ifndef COMPILERS_BLOCK_H
#define COMPILERS_BLOCK_H

#include <vector>

#include "../statements/Statement.h"
struct Block
{
    std::vector<Statement*>* statementSequence;
    Block(std::vector<Statement*>*);
    void print();
    void emit();
};
#endif //COMPILERS_BLOCK_H
