//
// Created by abeeston on 3/10/20.
//

#ifndef COMPILERS_SYMBOLTABLE_H
#define COMPILERS_SYMBOLTABLE_H

#include <vector>
#include <string>

#include "Scope.h"
#include "../constructs/expressions/Expression.h"
#include "../constructs/prelude/types/BaseType.h"
#include "../constructs/routines/Routine.h"

struct SymbolTable
{
    std::vector<Scope> levels;

    Expression* lookUpExpression(std::string);
    BaseType* lookUpType(std::string);
    Routine* lookUpRoutine(std::string);

    SymbolTable(Prelude);
    void prettyPrint();

};
#endif //COMPILERS_SYMBOLTABLE_H
