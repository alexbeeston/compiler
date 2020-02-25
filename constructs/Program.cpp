#include <iostream>
#include "Program.h"

Program::Program(Prelude* p_prelude, std::vector<Routine*>* p_routines)
{
    prelude = p_prelude;
    routines = p_routines;
}

void Program::prettyPrint()
{
    prelude->print();
    std::cout << std::endl;
    for (Routine* routine : *routines) { routine->print(); }
}

