#include <iostream>

#include "Entry.h"
#include "types/SimpleType.h"
#include "../../global.h"

Entry::Entry() {}

// Called by constants
Entry::Entry(std::string p_ident, Expression* p_expression)
{
    ident = p_ident;
    value = p_expression;
    label = CONSTANT;
    type = generateBaseType();
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
    std::cout << "[Look Up Item print, this should be overriden]\n";
}

BaseType* Entry::generateBaseType()
{
    if (value->getTypeIndicator() == INTEGER) return new SimpleType(new std::string("integer"));
    else if (value->getTypeIndicator() == CHAR) return new SimpleType(new std::string("char"));
    else if (value->getTypeIndicator() == STRING) return new SimpleType(new std::string("string"));
    else if (value->getTypeIndicator() == BOOLEAN) return new SimpleType(new std::string("boolean"));
    else throw std::runtime_error("Entry::generateBaseType() - Error constructing a BaseType from a constant (since it inherits from Entry, which needs a BaseType), and the expression isn't of a primitive type\n");
}

