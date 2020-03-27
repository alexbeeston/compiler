#include <iostream>
#include <stdexcept>

#include "SimpleType.h"

SimpleType::SimpleType(std::string* p_identifier, bool p_isRedeclarable)
{
    // symbol table consolation may be necessary here. See line when we set the size.
    name = p_identifier;
    identifier = *p_identifier; // this assumes that the type is not declared inline and that its identifier is the same as the name. If it is not, the identifier will be changed in the parser.
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
    return 4;
}
