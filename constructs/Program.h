#include <vector>
#include "prelude/Prelude.h"
#include "Routine.h"
#include "Statement.h"

struct Program
{
    Prelude* prelude;
    std::vector<Routine*>* routines;
    std::vector<Statement*>* block;
public:
    Program();
    void prettyPrint();
};

