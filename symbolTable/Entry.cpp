#include <iostream>

#include "Entry.h"
#include "../types/SimpleType.h"
#include "../global.h"

Entry::Entry() {}

// Called by constants
Entry::Entry(std::string p_ident, Expression* p_expression, bool p_isGlobal)
{
    ident = p_ident;
    value = p_expression;
    label = CONSTANT;
    isGlobal = p_isGlobal;
}

// Called by variables
Entry::Entry(std::string p_ident, BaseType* p_type, int p_offset, bool p_isGlobal)
{
    ident = p_ident;
    type = p_type;
    offset = p_offset;
    label = VARIABLE;
    isGlobal = p_isGlobal;
}

void Entry::print()
{
    std::cout << "[Look Up Item print function]\n";
}
