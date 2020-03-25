#include <iostream>
#include <stdexcept>

#include "SimpleType.h"

// used to instantiate "pointer" types, which just reference another type in the symbol table
SimpleType::SimpleType(std::string* p_ident)
{
    ident = p_ident;
    size = 4; // here, we might need to reference the st for the size of the referred type
    isRedeclarable = false;
    typeIndicator = 6;
}

// used to instantiate the primitive types, which you can over write because of badidea.cpsl
SimpleType::SimpleType(std::string* p_ident, std::string p_identifier, bool p_isRedeclarable)
{
    ident = p_ident;
    identifier = p_identifier;
    isRedeclarable = p_isRedeclarable;
    size = 4;
    if (ident->compare("integer") == 0) typeIndicator = 0;
    else if (ident->compare("INTEGER") == 0) typeIndicator = 0;
    else if (ident->compare("char") == 0) typeIndicator = 1;
    else if (ident->compare("CHAR") == 0) typeIndicator = 1;
    else if (ident->compare("string") == 0) typeIndicator = 2;
    else if (ident->compare("STRING") == 0) typeIndicator = 2;
    else if (ident->compare("boolean") == 0) typeIndicator = 3;
    else if (ident->compare("BOOLEAN") == 0) typeIndicator = 3;
    else throw std::runtime_error("Error: it was attempted to construct a primitive type with the \"pointer\" " +  *ident + ".\n");
}

void SimpleType::print()
{
    std::cout << *ident;
}
