#include <iostream>

#include "Literal.h"
#include "../../global.h"

Literal::Literal(int p_value)
{
    typeIndicator = 0;
    value = p_value;
}

Literal::Literal(char p_value)
{
    typeIndicator = 1;
    value = p_value;
}

Literal::Literal(bool p_value)
{
    std::cout << "# bool constructor\n";
    typeIndicator = 3;
    value = p_value;
}

Literal::Literal(char* p_value)
{
    typeIndicator = 2;
    value = st.insertMessage(std::string(p_value));
}

Register Literal::emit()
{
    Register r = rp.getRegister();
    std::cout << "# typeIndicator: " << typeIndicator << "\n";
    if (typeIndicator == 0 || typeIndicator == 1 || typeIndicator == 3) std::cout << "li " << r.getName() << " " << value << "\n";
    else if (typeIndicator == 2) std::cout << "la " << r.getName() << " message" << value << "   # loaded a string literal\n";
    else std::cout << "Error: attempting to load an expression that is not an integer, character, bool, or string.\n";
    return r;
}

int Literal::getTypeIndicator()
{
    return typeIndicator;
}


