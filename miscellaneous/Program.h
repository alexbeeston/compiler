#include <vector>
#include "Prelude.h"
#include "routines/Routine.h"
#include "routines/Block.h"

struct Program
{
    Prelude* prelude;
    std::vector<Routine*>* routines;
    Block* block;
    Program(Prelude*, std::vector<Routine*>*, Block*);
    void prettyPrint();
    void emit();
};

