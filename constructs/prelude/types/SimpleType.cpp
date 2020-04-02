#include <iostream>
#include <stdexcept>

#include "SimpleType.h"
#include "../../../global.h"

SimpleType::SimpleType(std::string* p_name, bool p_isRedeclarable)
{
    name = p_name;
    identifier = *p_name; // if the simple type is the name of an array or record, it will be picked up and modified in the parser
    isRedeclarable = p_isRedeclarable;
    typeIndicator = ALIAS; // can I get rid of this?
    lValueType = SIMPLE_TYPE;
    size = 4; // assume it's a primitive, then if it's not, change the size to negative one,
    if (name->compare("integer") == 0) typeIndicator = INTEGER;
    else if (name->compare("INTEGER") == 0) typeIndicator = INTEGER;
    else if (name->compare("char") == 0) typeIndicator = CHAR;
    else if (name->compare("CHAR") == 0) typeIndicator = CHAR;
    else if (name->compare("string") == 0) typeIndicator = STRING;
    else if (name->compare("STRING") == 0) typeIndicator = STRING;
    else if (name->compare("boolean") == 0) typeIndicator = BOOLEAN;
    else if (name->compare("BOOLEAN") == 0) typeIndicator = BOOLEAN;
    else size = -1;
}

void SimpleType::print()
{
    std::cout << *name;
}

int SimpleType::computeSize()
{
//    std::cout << "# SimpleType::computeSize()\n";
//    return 1;
    if (isPrimitive()) return 4;
    else return st.retrieveType(*name)->computeSize();
}

TypeIndicator SimpleType::getTypeIndicator()
{
    if (isPrimitive()) return typeIndicator;
    else return st.retrieveType(identifier)->getTypeIndicator();
}

LValueType SimpleType::getLValueType()
{
    if (isPrimitive()) return PRIMITIVE_TYPE;
    else return st.retrieveType(identifier)->getLValueType();
}

bool SimpleType::isPrimitive()
{
   if (typeIndicator == INTEGER || typeIndicator == CHAR || typeIndicator == STRING || typeIndicator == BOOLEAN) return true;
   else return false;
}
