#include <iostream>

#include "Block.h"
#include "../statements/StatementSequence.h"

Block::Block(StatementSequence* p_statementSequence)
{
    statementSequence = p_statementSequence;
}

void Block::print()
{
    std::cout << "BEGIN\n";
    for (Statement* statement: *(statementSequence->statements))
    {
        statement->print();
        std::cout << ";\n";
    }
    std::cout << "END\n";
}
