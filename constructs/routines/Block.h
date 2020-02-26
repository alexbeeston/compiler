//
// Created by abeeston on 2/25/20.
//

#ifndef COMPILERS_BLOCK_H
#define COMPILERS_BLOCK_H

#include "../statements/StatementSequence.h"
struct Block
{
    StatementSequence* statementSequence;
    Block(StatementSequence*);
    void print();
};
#endif //COMPILERS_BLOCK_H
