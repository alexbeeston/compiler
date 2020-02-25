#include <vector>
#include "prelude/Prelude.h"
#include "routines/Routine.h"

struct Program
{
    Prelude* prelude;
    std::vector<Routine*>* routines;
    Program(Prelude*, std::vector<Routine*>*);
    void prettyPrint();
};

