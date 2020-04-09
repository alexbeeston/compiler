//
// Created by abeeston on 3/10/20.
//

#ifndef COMPILERS_SYMBOLTABLE_H
#define COMPILERS_SYMBOLTABLE_H

#include <vector>
#include <string>

#include "Scope.h"
#include "../constructs/routines/Routine.h"

struct SymbolTable
{
    std::vector<Scope> levels;
    std::vector<std::string> strings;
    int insertMessage(std::string);

    Entry retrieveEntry(std::string);
    BaseType* retrieveType(std::string);

    int repeatLabelCounter;
    std::string getRepeatLabel();

    // init
    SymbolTable();
    void addStuff(Prelude);
    void prettyPrint();
    void testPrint();

};
#endif //COMPILERS_SYMBOLTABLE_H
