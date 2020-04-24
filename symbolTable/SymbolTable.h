//
// Created by abeeston on 3/10/20.
//

#ifndef COMPILERS_SYMBOLTABLE_H
#define COMPILERS_SYMBOLTABLE_H

#include <vector>
#include <string>

#include "Scope.h"
#include "../routines/Routine.h"

struct SymbolTable
{
    // containers
    std::vector<Scope> scopes;
    void pushScope(Prelude);
    void popScope();
    int topScope;
    int nextAddress;
    Entry retrieveEntry(std::string);
    BaseType* retrieveType(std::string);
    std::vector<std::string> strings;
    int insertMessage(std::string);

    // control elements
    int repeatLabelCounter;
    std::string getRepeatLabel();
    int whileLabelCounter;
    std::string getWhileLabel();
    int nextLabelCounter;
    std::string getNextLabel();
    int nextForLabel;
    std::string getNextForLabel();
    int nextIfLabel;
    std::string getNextIfLabel();

    // init
    SymbolTable();
    void prettyPrint();
    void testPrint();
};
#endif //COMPILERS_SYMBOLTABLE_H
