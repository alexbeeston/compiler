#include <iostream>

#include "Body.h"
#include "../prelude/Prelude.h"
#include "Block.h"

Body::Body(Prelude* p_prelude, Block* p_block)
{
    prelude = p_prelude;
    block = p_block;
}

void Body::print()
{
    prelude->print();
    block->print();
}