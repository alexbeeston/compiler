#include <iostream>
#include "Program.h"
#include "../symbolTable/SymbolTable.h"

extern SymbolTable st;

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
    std::cout << "# ===== assembly.asm =====\n";
//    prelude->emit();
    // emit each function declaration
    block->emit();

    // emit the string declarations
    std::cout << "\n\n .data\n";
    std::cout << ".asciiz\n";
    int counter = 0;
    for (std::string message : st.strings)
    {
        std::cout << "message" << std::to_string(counter) << ":  " << message << "\n";
        ++counter;
    }

    // terminate the program
    std::cout << "\nli $v0 10\n   # 10 = system call to terminate\n";
    std::cout << "syscall\n";
}