#include <iostream>

#include "LValue.h"

LValue::LValue(std::vector<LValueBase*>* p_sequence)
{
    sequence = p_sequence;
}

std::string LValue::getKey()
{
    return (*sequence)[0]->keyString;
}

void LValue::print()
{
    for (LValueBase* item : *sequence) item->print();
}
