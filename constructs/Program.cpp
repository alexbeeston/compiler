#include <iostream>
#include "Program.h"

Program::Program(Prelude* p_prelude, std::vector<Routine*>* p_routines, Block* p_block)
{
    prelude = p_prelude;
    routines = p_routines;
    block = p_block;
}

void Program::prettyPrint()
{
    prelude->print();
    std::cout << std::endl;
    for (Routine* routine : *routines) routine->print();
    block->print();
}

void Program::emit()
{
//    prelude->emit();
    // emit each function declaration
    block->emit();
}