#include <iostream>
#include <string>
#include "StringLit.h"
#include "../../global.h"

StringLit::StringLit(char* p_value):Expression()
{
    typeIndicator = 2;
    stringLitValue = std::string(p_value);
}

void StringLit::print()
{
    std::cout << stringLitValue;
}

Register StringLit::emit()
{
    Register r = rp.getRegister();
    int offset = st.insertMessage(stringLitValue);
    std::cout << "la " << r.name << " message" << std::to_string(offset) << "   # loaded a string label\n";
    return r;
}

