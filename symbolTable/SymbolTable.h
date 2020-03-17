//
// Created by abeeston on 3/10/20.
//

#ifndef COMPILERS_SYMBOLTABLE_H
#define COMPILERS_SYMBOLTABLE_H

#include <vector>
#include <string>

#include "Scope.h"
#include "../constructs/prelude/variables/Variable.h"
#include "../constructs/prelude/types/BaseType.h"
#include "../constructs/routines/Routine.h"

struct SymbolTable
{
    std::vector<Scope> levels;

    Variable retrieveVariable(std::string);

    SymbolTable(Prelude);
    SymbolTable();
    void prettyPrint();
    void testPrint();

};
#endif //COMPILERS_SYMBOLTABLE_H
