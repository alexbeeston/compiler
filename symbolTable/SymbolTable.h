//
// Created by abeeston on 3/10/20.
//

#ifndef COMPILERS_SYMBOLTABLE_H
#define COMPILERS_SYMBOLTABLE_H

#include <vector>
#include <string>

#include "Scope.h"
#include "routines/Method.h"

struct SymbolTable
{
    // Scopes
    std::vector<Scope> scopes;
    void pushScope(BaseType*, std::vector<ParameterSet*>, Prelude);
    void popScope();

    // methods
    std::map<std::string, Method*> routines;
    void addRoutines(std::vector<Method*>*);

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
    Method* retrieveRoutine(std::string);
    int sizeOfLocalVars;

     // legacy; will throw errors; needs updating
     void pushScope_iterator(std::string);
};
#endif //COMPILERS_SYMBOLTABLE_H
