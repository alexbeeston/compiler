#include <iostream>

#include "Block.h"
#include "../statements/Statement.h"

Block::Block(std::vector<Statement*>* p_statementSequence)
{
    statementSequence = p_statementSequence;
}

void Block::print()
{
    std::cout << "BEGIN\n";
    for (Statement* item : *statementSequence)
    {
        item->print();
        std::cout << std::endl;
    }
    std::cout << "END\n";
}
