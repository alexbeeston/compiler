//
// Created by abeeston on 3/10/20.
//

#ifndef COMPILERS_SCOPE_H
#define COMPILERS_SCOPE_H

#include <map>
#include <string>

#include "../constructs/prelude/types/BaseType.h"
#include "../constructs/prelude/Prelude.h"
#include "../constructs/prelude/LookUpItem.h"
#include "../constructs/prelude/variables/Variable.h"

struct Scope
{
    // used during initialization
    Scope(Prelude);

    // used to handle LookUpItems (variables and constants)
    int nextAddress = 0;
    std::map<std::string, LookUpItem> lookUpItems;
    LookUpItem getLookUpItem(std::string);
    bool addItem(LookUpItem);
//    int addVariable(Variable&); // returns the next available offset from the base register

    // used to handle types
    std::map<std::string, BaseType> types;

    // validation
//    void prettyPrint();
};
#endif //COMPILERS_SCOPE_H
