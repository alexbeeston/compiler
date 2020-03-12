//
// Created by abeeston on 3/10/20.
//

#ifndef COMPILERS_SCOPE_H
#define COMPILERS_SCOPE_H

#include <map>
#include <string>


#include "../constructs/expressions/Expression.h"
#include "../constructs/prelude/types/BaseType.h"
#include "../constructs/routines/Routine.h"

struct Scope
{
    std::map<std::string, Expression> expressions;
    std::map<std::string, BaseType> types;
    std::map<std::string, Routine> routines;
    Scope(Prelude);
    void prettyPrint();
    void printTab();
};
#endif //COMPILERS_SCOPE_H
