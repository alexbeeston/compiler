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
    void pushScope(BaseType*, std::vector<ParameterSet*>, Prelude);
    void popScope();

    // routines
    std::map<std::string, Routine*> routines;
    void addRoutines(std::vector<Routine*>*);

    // control elements
    int repeatLabelCounter;
    std::string getRepeatLabel();
    int whileLabelCounter;
    std::string getWhileLabel();
    int nextNextLabelCounter;
    std::string getNextNextLabel();
    int nextForLabel;
    std::string getNextForLabel();
    int nextIfLabel;
    std::string getNextIfLabel();

    // general
    SymbolTable();
    bool addingGlobals;
    Entry retrieveEntry(std::string);
    BaseType* retrieveType(std::string);
    std::vector<std::string> strings;
    int insertMessage(std::string);
    Routine* retrieveRoutine(std::string);

     // legacy; will throw errors; needs updating
     void pushScope_iterator(std::string);
};
#endif //COMPILERS_SYMBOLTABLE_H
