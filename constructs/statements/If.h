//
// Created by abeeston on 2/26/20.
//

#ifndef COMPILERS_IF_H
#define COMPILERS_IF_H

#include <vector>

#include "ConditionalSequence.h"
#include "Statement.h"

struct If:Statement
{
    ConditionalSequence* ifBlock;
    std::vector<ConditionalSequence*>* elseIfBlocks;
    std::vector<Statement*>* elseBlock;

    If(ConditionalSequence*, std::vector<ConditionalSequence*>*, std::vector<Statement*>*);
    void print() override;
    void emit() override;
};
#endif //COMPILERS_IF_H
