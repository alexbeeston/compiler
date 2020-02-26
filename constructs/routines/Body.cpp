#include <iostream>

#include "Body.h"
#include "../prelude/Prelude.h"
#include "Block.h"

Body::Body(Prelude* p_prelude)
{
    prelude = p_prelude;
}

void Body::print()
{
    prelude->print();
    block->print();
}