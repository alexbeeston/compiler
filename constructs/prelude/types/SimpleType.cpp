#include <iostream>
#include <stdexcept>

#include "SimpleType.h"
#include "../../../global.h"

SimpleType::SimpleType(std::string* p_name)
{
    name = *p_name;
    style = SIMPLE_TYPE;
    typeIndicator = ALIAS;
    if (name.compare("integer") == 0) typeIndicator = INTEGER;
    else if (name.compare("INTEGER") == 0) typeIndicator = INTEGER;
    else if (name.compare("char") == 0) typeIndicator = CHAR;
    else if (name.compare("CHAR") == 0) typeIndicator = CHAR;
    else if (name.compare("string") == 0) typeIndicator = STRING;
    else if (name.compare("STRING") == 0) typeIndicator = STRING;
    else if (name.compare("boolean") == 0) typeIndicator = BOOLEAN;
    else if (name.compare("BOOLEAN") == 0) typeIndicator = BOOLEAN;
}

void SimpleType::print()
{
    std::cout << name;
}

int SimpleType::computeSize()
{
    if (isPrimitive()) return 4;
    else return st.retrieveType(name)->computeSize();
}

TypeIndicator SimpleType::getTypeIndicator()
{
    return st.retrieveType(name)->typeIndicator;
}

bool SimpleType::isPrimitive()
{
    if (
           name.compare("integer") == 0 ||
           name.compare("INTEGER") == 0 ||
           name.compare("char") == 0 ||
           name.compare("CHAR") == 0 ||
           name.compare("string") == 0 ||
           name.compare("STRING") == 0 ||
           name.compare("boolean") == 0 ||
           name.compare("BOOLEAN") == 0
       ) return true;
    else return false;
}

bool SimpleType::isAlias()
{
    throw std::runtime_error("SimpleType::isAlias() - not implemented");
}
