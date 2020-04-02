#include <iostream>
#include <stdexcept>

#include "SimpleType.h"
#include "../../../global.h"

SimpleType::SimpleType(std::string* p_name)
{
    name = p_name;
    style = PRIMITIVE_TYPE;
    typeIndicator = ALIAS;
    if (name->compare("integer") == 0) typeIndicator = INTEGER;
    else if (name->compare("INTEGER") == 0) typeIndicator = INTEGER;
    else if (name->compare("char") == 0) typeIndicator = CHAR;
    else if (name->compare("CHAR") == 0) typeIndicator = CHAR;
    else if (name->compare("string") == 0) typeIndicator = STRING;
    else if (name->compare("STRING") == 0) typeIndicator = STRING;
    else if (name->compare("boolean") == 0) typeIndicator = BOOLEAN;
    else if (name->compare("BOOLEAN") == 0) typeIndicator = BOOLEAN;
    else style = ALIAS_TYPE;
}

void SimpleType::print()
{
    std::cout << *name;
}

int SimpleType::computeSize()
{
    if (style == ALIAS_TYPE) return st.retrieveType(*name)->computeSize();
    else return 4; // only works because although, in badidea.cpsl, integer is an alias, it's type is also 4, just like char, so we're good
}

TypeIndicator SimpleType::getTypeIndicator()
{
    return typeIndicator;
}
