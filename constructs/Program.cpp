#include <iostream>
#include "Program.h"
#include "../global.h"

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

    // emit the string declarations
    std::cout << "# size of string table: " << st.strings.size() << "\n";
    std::cout << "\n\n .data\n";
    std::cout << ".asciiz\n";
    int counter = 0;
    for (std::string message : st.strings)
    {
        std::cout << "message" << std::to_string(counter) << ":  " << message << "\n";
        ++counter;
    }
}