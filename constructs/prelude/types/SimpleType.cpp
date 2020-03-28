#include <iostream>
#include <stdexcept>

#include "SimpleType.h"
#include "../../../global.h" // used to lookup the size of simple types that are names of array or record types

SimpleType::SimpleType(std::string* p_name, bool p_isRedeclarable)
{
    // if the simple type is not a primitive, but rather a string that references another type in the symbol table, the identifier field will be over-written in the parser
    name = p_name;
    identifier = *p_name;
    isRedeclarable = p_isRedeclarable;
    if (name->compare("integer") == 0) typeIndicator = 0;
    else if (name->compare("INTEGER") == 0) typeIndicator = 0;
    else if (name->compare("char") == 0) typeIndicator = 1;
    else if (name->compare("CHAR") == 0) typeIndicator = 1;
    else if (name->compare("string") == 0) typeIndicator = 2;
    else if (name->compare("STRING") == 0) typeIndicator = 2;
    else if (name->compare("boolean") == 0) typeIndicator = 3;
    else if (name->compare("BOOLEAN") == 0) typeIndicator = 3;
    else typeIndicator = 6;
}

void SimpleType::print()
{
    std::cout << *name;
}

int SimpleType::computeSize()
{
    if (typeIndicator == 6) return st.retrieveType(*name)->computeSize(); // the simple type is actually a string that refers to another type in the symbol table, so consult its size function
    else if (typeIndicator == 0 || typeIndicator == 1 || typeIndicator == 2 || typeIndicator == 3) return 4; // the simple type is a primitive
    else throw std::runtime_error("Attempting to get the size of a simple type that does have a typeIndicator of 0, 1, 2, 3, or 6");
}
