#include <iostream>

#include "LValue.h"

LValue::LValue(std::vector<LValueBase*>* p_sequence)
{
    sequence = p_sequence;
}

void LValue::print()
{
    for (LValueBase* item : *sequence) item->print();
}
