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
    // Scopes
    std::vector<Scope> scopes;
    void pushScope(Prelude);
    void pushScope_iterator(std::string);
    void popScope();
    bool addingGlobals;
    int nextAddress;
    Entry retrieveEntry(std::string);
    BaseType* retrieveType(std::string);
    std::vector<std::string> strings;
    int insertMessage(std::string);

    // routines
    std::map<std::string, Routine*> routines;
    void addRoutines(std::vector<Routine*>*);
    Routine* retrieveRoutine(std::string);

    // control elements
    int repeatLabelCounter;
    std::string getRepeatLabel();
    int whileLabelCounter;
    std::string getWhileLabel();
    int nextLabelCounter;
    std::string getNextNextLabel();
    int nextForLabel;
    std::string getNextForLabel();
    int nextIfLabel;
    std::string getNextIfLabel();

    // init
    SymbolTable();
};
#endif //COMPILERS_SYMBOLTABLE_H
