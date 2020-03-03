#include <iostream>

#include "If.h"

If::If(ConditionalSequence* p_ifBlock, std::vector<ConditionalSequence*>* p_elseIfBlocks)
{
    ifBlock = p_ifBlock;
    elseIfBlocks = p_elseIfBlocks;
}

void If::print()
{
    std::cout << "If Statement. If Block: ";
    ifBlock->print();
    std::cout << " Else If Blocks:";
    for (ConditionalSequence* elseIfBlock : *elseIfBlocks) elseIfBlock->print();
}
