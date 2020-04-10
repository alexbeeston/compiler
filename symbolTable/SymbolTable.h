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
    // containers
    std::vector<Scope> levels;

    // data fields and methods
    Entry retrieveEntry(std::string);
    BaseType* retrieveType(std::string);
    std::vector<std::string> strings;
    int insertMessage(std::string);
    bool containsEntry(std::string);
    int nextAvailableAddress;
    int getNextAvailableAddress();
    void incrementNextAvailableAddress(int);


    // control elements
    int repeatLabelCounter;
    std::string getRepeatLabel();
    int whileLabelCounter;
    std::string getWhileLabel();
    int nextLabelCounter;
    std::string getNextLabel();

    // init
    SymbolTable();
    void addStuff(Prelude);
    void prettyPrint();
    void testPrint();

};
#endif //COMPILERS_SYMBOLTABLE_H
