#include <iostream>
#include "Program.h"
#include "global.h"

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
    // add global prelude
    st.pushScope(nullptr, std::vector<ParameterSet*>(), *prelude);
    st.addingGlobals = false;

    // handle routines
    st.addRoutines(routines);
    std::cout << "j main\n\n";
    for (auto iterator : st.routines) iterator.second->emit();

    // main block
    std::cout << "main:\n";
    block->emit();
    std::cout << "li $v0 10\n";
    std::cout << "syscall\n";

    // strings
    std::cout << "\n\n .data\n";
    std::cout << ".asciiz\n";
    int counter = 0;
    for (const std::string& message : st.strings)
    {
        std::cout << "message" << std::to_string(counter) << ":  " << message << "\n";
        ++counter;
    }
}