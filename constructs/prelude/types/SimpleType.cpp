#include <iostream>
#include <stdexcept>

#include "SimpleType.h"

SimpleType::SimpleType(std::string* p_ident)
{
    ident = p_ident;
    if (ident->compare("integer") == 0) typeIndicator = 0;
    else if (ident->compare("INTEGER") == 0) typeIndicator = 0;
    else if (ident->compare("char") == 0) typeIndicator = 1;
    else if (ident->compare("CHAR") == 0) typeIndicator = 1;
    else if (ident->compare("string") == 0) typeIndicator = 2;
    else if (ident->compare("STRING") == 0) typeIndicator = 2;
    else if (ident->compare("boolean") == 0) typeIndicator = 3;
    else if (ident->compare("BOOLEAN") == 0) typeIndicator = 3;
    else throw std::runtime_error("Error: it was attempted to construct a SimpleType with the identifier" + *ident + ", which is not a primitive type");
    size = 4;
}

void SimpleType::print()
{
    std::cout << *ident;
}
