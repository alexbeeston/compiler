#include <iostream>

#include "Entry.h"
#include "../types/SimpleType.h"
#include "../global.h"

Entry::Entry() {}

// Called by constants
Entry::Entry(std::string p_ident, Expression* p_expression, bool isGlobal)
{
    ident = p_ident;
    value = p_expression;
    label = CONSTANT;
    setRegister(isGlobal);
}

// Called by variables
Entry::Entry(std::string p_ident, BaseType* p_type, int p_offset, bool isGlobal)
{
    ident = p_ident;
    type = p_type;
    offset = p_offset;
    label = VARIABLE;
    setRegister(isGlobal);
}

void Entry::print()
{
    std::cout << "[Look Up Item print function]\n";
}

void Entry::setRegister(bool isGlobal)
{
    if (isGlobal) baseRegister = rp.getGlobalPointer();
    else baseRegister = rp.getFramePointer();
}
