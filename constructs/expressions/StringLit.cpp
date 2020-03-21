#include <iostream>
#include <string>
#include "StringLit.h"
#include "../../global.h"

StringLit::StringLit(char* p_value):Expression()
{
    typeIndicator = 2;
    stringLitValue = std::string(p_value);
    value = st.insertMessage(stringLitValue);
}

void StringLit::print()
{
    std::cout << stringLitValue;
}

Register StringLit::emit()
{
    Register r = rp.getRegister();
    std::cout << "la " << r.getName() << " message" << value << "   # loaded a string literal\n";
    return r;
}

