#include <iostream>

#include "If.h"

If::If(ConditionalSequence* p_ifBlock, std::vector<ConditionalSequence*>* p_elseIfBlocks, std::vector<Statement*>* p_elseBlock)
{
    ifBlock = p_ifBlock;
    elseIfBlocks = p_elseIfBlocks;
    elseBlock = p_elseBlock;
}

void If::print()
{
    std::cout << "if";
    ifBlock->print();
    for (ConditionalSequence* elseIfBlock : *elseIfBlocks)
    {
        std::cout << " else";
        elseIfBlock->print();
    }
    std::cout << " else ";
    for (Statement* statement : *elseBlock) statement->print();
}
