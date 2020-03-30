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
    return (*sequence)[0]->accessor;
}

Register LValue::loadBaseRegister()
{
    LookUpItem item = st.retrieveItem(getKey());
    if (item.lValueType == PRIMITIVE_TYPE) return rp.getGlobalPointer();
    else if (item.lValueType == ARRAY_TYPE)
    {
        ArrayType* array = dynamic_cast<ArrayType*>(item.type);
        Register r1 = rp.getRegister();
        std::cout << "li " << r1.getName() << " " << array->low->getValue() << "   # lower bound of array\n";
        Register r2 = rp.getRegister();
        std::cout << "li " << r2.getName() << " " << (*sequence)[1]->index->getValue()  << "  # index of item in array\n"; // assumes that the second item (index 1) of the LValueBase array refers to an index.
        std::cout << "sub " << r1.getName() << " " << r2.getName() << " " << r1.getName() << "   # number of elements offset from lower bound\n";
        std::cout << "li " << r2.getName() << " " << array->type->computeSize() << "   # loaded size of underlying type of array\n";
        std::cout << "mult " << r1.getName() << " " << r2.getName() << "\n";
        rp.returnRegister(r2);
        std::cout << "mflo " << r1.getName() << "\n";
        std::cout << "add " << r1.getName() << " " << item.baseRegister.getName() << " " << r1.getName() << "\n";
        return r1;
    }
    else if (item.lValueType == RECORD_TYPE) std::cout << "# about to load a record type\n";
    else throw std::runtime_error("LValueType not known. Inside LValue::loadBaseRegister\n");
    return Register();
}

void LValue::print()
{
    for (LValueBase* item : *sequence) item->print();
}

