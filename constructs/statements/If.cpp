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
    std::cout << "If Statement. If Block: ";
    ifBlock->print();
    std::cout << " Else If Blocks:";
    for (ConditionalSequence* elseIfBlock : *elseIfBlocks) elseIfBlock->print();
    std::cout << " Else Block: ";
    for (Statement* statement : *elseBlock) statement->print();
}
