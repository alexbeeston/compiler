#include <iostream>
#include <stdexcept>

#include "SimpleType.h"
#include "../../../global.h"

SimpleType::SimpleType(std::string* p_name)
{
    name = p_name;
    lValueType = SIMPLE_TYPE;
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
    if (isPrimitive()) return 4; // only works on bad idea because INTEGER and CHAR are both 4
    else return st.retrieveType(*name)->computeSize();
}

TypeIndicator SimpleType::getTypeIndicator()
{
    return st.retrieveType(*name)->typeIndicator;
}

LValueType SimpleType::getLValueType()
{
    if (isPrimitive()) return PRIMITIVE_TYPE;
    else return st.retrieveType(*name)->getLValueType();
}

bool SimpleType::isPrimitive()
{
   if (typeIndicator == INTEGER || typeIndicator == CHAR || typeIndicator == STRING || typeIndicator == BOOLEAN) return true;
   else return false;
}
