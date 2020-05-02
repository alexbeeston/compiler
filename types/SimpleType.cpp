#include <iostream>
#include <stdexcept>

#include "SimpleType.h"
#include "../global.h"

SimpleType::SimpleType(std::string* p_name)
{
    name = *p_name;
    style = SIMPLE;
    typeIndicator = NOT_PRIMITIVE;
    if (name == "integer") typeIndicator = INTEGER;
    else if (name == "INTEGER") typeIndicator = INTEGER;
    else if (name == "char") typeIndicator = CHAR;
    else if (name == "CHAR") typeIndicator = CHAR;
    else if (name == "string") typeIndicator = STRING;
    else if (name == "STRING") typeIndicator = STRING;
    else if (name == "boolean") typeIndicator = BOOLEAN;
    else if (name == "BOOLEAN") typeIndicator = BOOLEAN;
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

PrimitiveType SimpleType::getPrimitiveType()
{
    return st.retrieveType(name)->typeIndicator;
}

bool SimpleType::isPrimitive()
{
    return name == "integer" ||
           name.compare("INTEGER") == 0 ||
           name.compare("char") == 0 ||
           name.compare("CHAR") == 0 ||
           name.compare("string") == 0 ||
           name.compare("STRING") == 0 ||
           name.compare("boolean") == 0 ||
           name.compare("BOOLEAN") == 0;
}
