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
    typeIndicator = UNDEFINED;
    if (name->compare("integer") == 0) typeIndicator = INTEGER;
    else if (name->compare("INTEGER") == 0) typeIndicator = INTEGER;
    else if (name->compare("char") == 0) typeIndicator = CHAR;
    else if (name->compare("CHAR") == 0) typeIndicator = CHAR;
    else if (name->compare("string") == 0) typeIndicator = STRING;
    else if (name->compare("STRING") == 0) typeIndicator = STRING;
    else if (name->compare("boolean") == 0) typeIndicator = BOOLEAN;
    else if (name->compare("BOOLEAN") == 0) typeIndicator = BOOLEAN;
}

void SimpleType::print()
{
    std::cout << *name;
}

int SimpleType::computeSize()
{
    if (isPrimitive()) return 4;
    else return st.retrieveType(*name)->computeSize();
}

TypeIndicator SimpleType::getTypeIndicator()
{
    if (isPrimitive()) return typeIndicator;
    else return st.retrieveType(identifier)->getTypeIndicator();
}

int SimpleType::getLValueType()
{
    if (isPrimitive()) return 0;
    else return st.retrieveType(identifier)->getLValueType();
}

bool SimpleType::isPrimitive()
{
   if (typeIndicator == INTEGER || typeIndicator == CHAR || typeIndicator == STRING || typeIndicator == BOOLEAN) return true;
   else return false;
}
