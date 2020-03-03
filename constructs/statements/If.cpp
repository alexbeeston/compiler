#include <iostream>

#include "If.h"

If::If(ConditionalSequence* p_ifBlock)
{
    ifBlock = p_ifBlock;
}

void If::print()
{
    std::cout << "If Statement. If Block:   ";
    ifBlock->print();
}
