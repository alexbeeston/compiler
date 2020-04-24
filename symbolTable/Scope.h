//
// Created by abeeston on 3/10/20.
//

#ifndef COMPILERS_SCOPE_H
#define COMPILERS_SCOPE_H

#include <map>
#include <string>

#include "../types/BaseType.h"
#include "../types/ArrayType.h"
#include "../types/RecordType.h"
#include "../miscellaneous/Prelude.h"
#include "Entry.h"

struct Scope
{
    // used during initialization
    Scope();
    int size;
    int getSize();
    int addConstructs(Prelude, int);
    int computeSize(BaseType*);
    int computeSize_Array(ArrayType*);
    int computeSize_Record(RecordType*);

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
