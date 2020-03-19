//
// Created by abeeston on 3/10/20.
//

#ifndef COMPILERS_SCOPE_H
#define COMPILERS_SCOPE_H

#include <map>
#include <string>

#include "../constructs/prelude/variables/Variable.h"
#include "../constructs/prelude/types/BaseType.h"
#include "../constructs/routines/Routine.h"

struct Scope
{
    std::map<std::string, Variable> variables;
    std::map<std::string, BaseType> types;
    int initializeBool(std::string, int&, int);
    int addVariable(Variable&, int&); // returns the next available offset from the base register

    Variable lookUpVariable(std::string);
    Scope(Prelude);
    void prettyPrint();
    void printTab();
};
#endif //COMPILERS_SCOPE_H
