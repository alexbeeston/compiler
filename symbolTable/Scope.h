//
// Created by abeeston on 3/10/20.
//

#ifndef COMPILERS_SCOPE_H
#define COMPILERS_SCOPE_H

#include <map>
#include <string>
#include <vector>
#include "../types/BaseType.h"
#include "../types/ArrayType.h"
#include "../types/RecordType.h"
#include "../miscellaneous/Prelude.h"
#include "Entry.h"
#include "../routines/ParameterSet.h"

struct Scope
{
    // inserting into the scope
    void addLocalPrelude(Prelude);
    void addParameters(std::vector<ParameterSet*> parameterSets);
    void accommodateReturnType(BaseType*);
    void updateNextAddress(int);


    // general stuff
    Scope();
    int nextAddress;
    int getSize();

    // used to handle Entries (variables and constants)
    std::map<std::string, Entry> entries;
    Entry getEntry(std::string);
    bool containsEntry(std::string);

    // used to handle types
    std::map<std::string, BaseType*> types;
    bool containsType(std::string);
    BaseType* getType(std::string);
};
#endif //COMPILERS_SCOPE_H
