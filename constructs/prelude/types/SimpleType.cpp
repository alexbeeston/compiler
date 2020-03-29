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

int SimpleType::getTypeIndicator()
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
   if (typeIndicator == 0 || typeIndicator == 1 || typeIndicator == 2 || typeIndicator == 3) return true;
   else return false;
}
