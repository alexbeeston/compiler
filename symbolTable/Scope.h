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

    // used to handle LookUpItems (variables and constants)
    int nextAddress = 0;
    std::map<std::string, Variable> variables;
    std::map<std::string, Constant> constants;
    LookUpItem getLookUpItem(std::string);
    int addVariable(Variable&); // returns the next available offset from the base register

    // used to handle types
    std::map<std::string, BaseType> types;

    // validation
    void prettyPrint();
};
#endif //COMPILERS_SCOPE_H
