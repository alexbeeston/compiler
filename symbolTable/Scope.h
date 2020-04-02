//
// Created by abeeston on 3/10/20.
//

#ifndef COMPILERS_SCOPE_H
#define COMPILERS_SCOPE_H

#include <map>
#include <string>

#include "../constructs/prelude/types/BaseType.h"
#include "../constructs/prelude/types/ArrayType.h"
#include "../constructs/prelude/types/RecordType.h"
#include "../constructs/prelude/Prelude.h"
#include "../constructs/prelude/Entry.h"

struct Scope
{
    // used during initialization
    Scope(Prelude);
    int computeSize(BaseType*);
    int computeSize_Array(ArrayType*);
    int computeSize_Record(RecordType*);

    // used to handle Entries (variables and constants)
    int nextAddress = 0;
    std::map<std::string, Entry> entries;
    Entry getEntry(std::string);
    bool addEntry(Entry);

    // used to handle types
    std::map<std::string, BaseType*> types;
    bool addType(BaseType*);
    BaseType* getBaseType(std::string);
};
#endif //COMPILERS_SCOPE_H
