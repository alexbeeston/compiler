//
// Created by abeeston on 3/10/20.
//

#ifndef COMPILERS_SCOPE_H
#define COMPILERS_SCOPE_H

#include <map>
#include <string>

#include "../constructs/prelude/variables/Variable.h"
#include "../constructs/prelude/constants/Constant.h"
#include "../constructs/prelude/types/BaseType.h"
#include "../constructs/routines/Routine.h"
#include "../constructs/prelude/LookUpItem.h"

struct Scope
{
    // used during initialization
    Scope(Prelude);
    int initializeBool(std::string, int&, int);

    // used to handle LookUpItems (variables and constants)
    std::map<std::string, Variable> variables;
    std::map<std::string, Constant> constants;
    LookUpItem getLookUpItem(std::string);
    Variable lookUpVariable(std::string); // about to be replaced by getLookUpItem()
    int addVariable(Variable&, int&); // returns the next available offset from the base register

    // used to handle types
    std::map<std::string, BaseType> types;

    // validation
    void prettyPrint();
};
#endif //COMPILERS_SCOPE_H
