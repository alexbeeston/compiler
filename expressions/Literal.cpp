#include <iostream>

#include "Literal.h"
#include "../global.h"

Literal::Literal() {}

Literal::Literal(int p_value)
{
    primitiveType = INTEGER;
    value = p_value;
}

Literal::Literal(char p_value)
{
    primitiveType = CHAR;
    value = p_value;
}

Literal::Literal(bool p_value)
{
    primitiveType = BOOLEAN;
    value = p_value;
}

Literal::Literal(char* p_value)
{
    primitiveType = STRING;
    value = st.insertMessage(std::string(p_value));
}

Register Literal::emit()
{
    Register reg = rp.getRegister();
    if (primitiveType == INTEGER || primitiveType == CHAR || primitiveType == BOOLEAN) std::cout << "li " << reg.getName() << " " << value << "\n";
    else if (primitiveType == STRING) std::cout << "la " << reg.getName() << " message" << value << "\n";
    else std::cout << "Error: attempting to load an expression that is not an integer, character, bool, or string.\n";
    reg.containsAddress = false;
    return reg;
}

bool Literal::isCTV() { return true; }

int Literal::getValue() { return value;}
