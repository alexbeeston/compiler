#include <iostream>
#include <string>

#include "StringLit.h"
#include "../../symbolTable/SymbolTable.h"

extern SymbolTable st;

StringLit::StringLit(char* p_value):Expression()
{
    type = 2;
    stringLitValue = std::string(p_value);
}

void StringLit::print()
{
    std::cout << stringLitValue;
}

std::string StringLit::emit()
{
    int offset = st.insertMessage(stringLitValue);
    std::cout << "la $t0 message" << std::to_string(offset) << "   # loaded a string label\n";
    return "$t0";
}

