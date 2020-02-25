#include <vector>
#include "prelude/Prelude.h"
#include "routines/Routine.h"

struct Program
{
    Prelude* prelude;
    std::vector<Routine*>* routines;
public:
    Program();
    void prettyPrint();
};

