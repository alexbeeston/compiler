#include <iostream>

#include "LValue.h"
#include "../global.h"
#include "../constructs/prelude/types/ArrayType.h"
#include "../constructs/prelude/types/RecordType.h"

LValue::LValue() {}
LValue::LValue(std::vector<LValueBase*>* p_sequence)
{
    sequence = p_sequence;
}

std::string LValue::getKey()
{
    return (*sequence)[0]->keyString;
}

Register LValue::loadBaseRegister()
{
    LookUpItem item = st.retrieveItem(getKey());
    if (item.lValueType == PRIMITIVE_TYPE) return rp.getGlobalPointer();
    else if (item.lValueType == ARRAY_TYPE)
    {
        ArrayType* array = dynamic_cast<ArrayType*>(item.type);
        Register rLower = rp.getRegister();
        std::cout << "li " << rLower.getName() << " " << array->low->getValue() << "   # lower bound of array\n";
        Register rIndex = rp.getRegister();
        std::cout << "# li " << rIndex.getName() << " " << " [index]" << "  # index of item in array\n";
        return rLower;
    }
    else if (item.lValueType == RECORD_TYPE) std::cout << "# about to load a record type\n";
    else throw std::runtime_error("LValueType not known. Inside LValue::loadBaseRegister\n");
    return Register();
}

void LValue::print()
{
    for (LValueBase* item : *sequence) item->print();
}

