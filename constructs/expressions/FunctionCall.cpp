#include <iostream>
#include <string>

#include "FunctionCall.h"

FunctionCall::FunctionCall(char* p_ident, std::vector<Expression*>* p_params)
{
    ident = new std::string(p_ident);
    params = p_params;
}

void FunctionCall::print()
{
    std::cout << *ident << "(";
    for (Expression* item : *params)
    {
        item->print();
        std::cout << ",";
    }
    std::cout << ")";
}
