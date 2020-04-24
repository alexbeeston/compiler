#include <vector>
#include "../miscellaneous/Prelude.h"
#include "Routine.h"
#include "Block.h"

struct Program
{
    Prelude* prelude;
    std::vector<Routine*>* routines;
    Block* block;
    Program(Prelude*, std::vector<Routine*>*, Block*);
    void prettyPrint();
    void emit();
};

