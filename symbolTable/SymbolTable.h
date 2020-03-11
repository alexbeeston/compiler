//
// Created by abeeston on 3/10/20.
//

#ifndef COMPILERS_SYMBOLTABLE_H
#define COMPILERS_SYMBOLTABLE_H

#include <vector>

#include "Scope.h"

struct SymbolTable
{
    std::vector<Scope> levels;
};
#endif //COMPILERS_SYMBOLTABLE_H
