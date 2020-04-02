#include <iostream>

#include "Literal.h"
#include "../../global.h"

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
    Register r = rp.getRegister();
    if (typeIndicator == INTEGER || typeIndicator == CHAR || typeIndicator == BOOLEAN) std::cout << "li " << r.getName() << " " << value << "   # loaded an integer (used for a integer, char, or bool)\n";
    else if (typeIndicator == STRING) std::cout << "la " << r.getName() << " message" << value << "   # loaded a string literal\n";
    else std::cout << "Error: attempting to load an expression that is not an integer, character, bool, or string.\n";
    return r;
}

bool Literal::isCTV() { return true; }
