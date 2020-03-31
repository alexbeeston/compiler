#include <iostream>

#include "Entry.h"
#include "types/SimpleType.h"
#include "../../global.h"

Entry::Entry() {}

// Called by constants
Entry::Entry(std::string p_ident, Expression* p_expression, bool p_isRedeclarable)
{
    ident = p_ident;
    value = p_expression;
    isRedeclarable = p_isRedeclarable;
    offset = -1;
    type = generateBaseType();
    lValueType = PRIMITIVE_TYPE;
}

// Called by variables
Entry::Entry(std::string p_ident, BaseType* p_type, int p_offset)
{
    ident = p_ident;
    type = p_type;
    isRedeclarable = false;
    offset = p_offset;
    baseRegister = rp.getGlobalPointer(); // assumes all variables are offset from the global pointer, for now
    lValueType = p_type->getLValueType();
}

void Entry::print()
{
    std::cout << "[Look Up Item print, this should be overriden]\n";
}

BaseType* Entry::generateBaseType()
{
    // error here: before, calling getTypeIndicator() resulted in an error. Try again to see if it works next time you see this.
    if (value->typeIndicator == INTEGER) return new SimpleType(new std::string("integer"));
    else if (value->typeIndicator == CHAR) return new SimpleType(new std::string("char"));
    else if (value->typeIndicator == STRING) return new SimpleType(new std::string("string"));
    else if (value->typeIndicator == BOOLEAN) return new SimpleType(new std::string("boolean"));
    else
    {
        std::cout << "Error constructing a BaseType from a constant (since it inherits from Entry, which needs a BaseType), and the expression isn't of a primitive type\n";
        return new BaseType();
    }
}

