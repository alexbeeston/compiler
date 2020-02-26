//
// Created by abeeston on 2/25/20.
//

#ifndef COMPILERS_BODY_H
#define COMPILERS_BODY_H

#include "../prelude/Prelude.h"
#include "Block.h"

struct Body
{
    Prelude* prelude;
    Block* block;
    Body(Prelude*);
    void print();
};
#endif //COMPILERS_BODY_H
