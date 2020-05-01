#include <iostream>

#include "Literal.h"
#include "../global.h"

Literal::Literal() {}

Literal::Literal(int p_value)
{
    typeIndicator = INTEGER;
    value = p_value;
}

Literal::Literal(char p_value)
{
    typeIndicator = CHAR;
    value = p_value;
}

Literal::Literal(bool p_value)
{
    typeIndicator = BOOLEAN;
    value = p_value;
}

Literal::Literal(char* p_value)
{
    typeIndicator = STRING;
    value = st.insertMessage(std::string(p_value));
}

Register Literal::emit()
{
    Register reg = rp.getRegister();
    if (typeIndicator == INTEGER || typeIndicator == CHAR || typeIndicator == BOOLEAN) std::cout << "li " << reg.getName() << " " << value << "\n";
    else if (typeIndicator == STRING) std::cout << "la " << reg.getName() << " message" << value << "\n";
    else std::cout << "Error: attempting to load an expression that is not an integer, character, bool, or string.\n";
    reg.containsAddress = false;
    return reg;
}

bool Literal::isCTV() { return true; }

int Literal::getValue() { return value;}
