#include <iostream>

#include "Entry.h"
#include "../types/SimpleType.h"
#include "../global.h"

Entry::Entry() {}

// Called by constants
Entry::Entry(std::string p_ident, Expression* p_expression)
{
    ident = p_ident;
    value = p_expression;
    label = CONSTANT;
}

// Called by variables
Entry::Entry(std::string p_ident, BaseType* p_type, int p_offset)
{
    ident = p_ident;
    type = p_type;
    offset = p_offset;
    label = VARIABLE;
    baseRegister = rp.getGlobalPointer(); // assumes all variables are offset from the global pointer, for now
}

void Entry::print()
{
    std::cout << "[Look Up Item print function]\n";
}
