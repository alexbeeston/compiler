#include <iostream>
#include <string>

#include "Expression.h"

Expression::Expression(char* p_value)
{
    prettyPrintValue = p_value;
}
Expression::Expression(int p_value)
{
    // taken from https://stackoverflow.com/questions/347949/how-to-convert-a-stdstring-to-const-char-or-char
    std::string temp = std::to_string(p_value).c_str();
    char * writable = new char[temp.size() + 1];
    std::copy(temp.begin(), temp.end(), writable);
    writable[temp.size()] = '\0';
    prettyPrintValue = writable;
}

void Expression::print()
{
    std::cout << "Base Expression print()";
}




