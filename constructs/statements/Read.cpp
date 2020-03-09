#include <iostream>

#include "Read.h"

Read::Read(LValue* p_lValue, std::vector<LValue*>* p_lvals)
{
    lValues = new std::vector<LValue*> {p_lValue};
    for (LValue* lVal : *p_lvals) lValues->push_back(lVal);
}

void Read::print()
{
    std::cout << "read(";
    for (LValue* lVal : *lValues)
    {
        lVal->print();
        std::cout << ",";
    }
    std::cout << ")";
}