#include <vector>
#include "Prelude.h"
#include "routines/Method.h"
#include "routines/Block.h"

struct Program
{
    Prelude* prelude;
    std::vector<Method*>* methods;
    Block* block;
    Program(Prelude*, std::vector<Method*>*, Block*);
    void prettyPrint();
    void emit();
};

