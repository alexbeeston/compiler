#include <iostream>
#include <string>
#include <map>
#include "FunctionCall.h"
#include "../global.h"

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

Register FunctionCall::emit()
{

}

PrimitiveType FunctionCall::getPrimitiveType()
{
    return INTEGER; // must be replaced by consulting the st for the return type of the
}
