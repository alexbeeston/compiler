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

Register LValue::getBaseRegister()
{
    Entry entry = st.retrieveEntry(getKey());
    if ( (entry.lValueType == PRIMITIVE_TYPE) || (entry.lValueType == RECORD_TYPE) ) return entry.baseRegister;
    else if (entry.lValueType == ARRAY_TYPE)
    {
        ArrayType* array = dynamic_cast<ArrayType*>(entry.type);
        Register r1 = rp.getRegister();
        std::cout << "li " << r1.getName() << " " << array->low->getValue() << "   # lower bound of array\n";
        Register r2 = rp.getRegister();
        Register r3 = (*sequence)[1]->index->emit();
        std::cout << "la " << r2.getName() << " (" << r3.getName()  << ")  # index of item in array\n"; // assumes that the second item (index 1) of the LValueBase array refers to an index.
        rp.returnRegister(r3);
        std::cout << "sub " << r1.getName() << " " << r2.getName() << " " << r1.getName() << "   # number of elements offset from lower bound\n";
        std::cout << "li " << r2.getName() << " " << array->type->computeSize() << "   # loaded size of underlying type of array\n";
        std::cout << "mult " << r1.getName() << " " << r2.getName() << "\n";
        rp.returnRegister(r2);
        std::cout << "mflo " << r1.getName() << "\n";
        std::cout << "add " << r1.getName() << " " << entry.baseRegister.getName() << " " << r1.getName() << "\n";
        return r1;
    }
    else throw std::runtime_error("LValueType not known. Inside LValue::loadBaseRegister\n");
}

int LValue::getOffset()
{
    Entry entry = st.retrieveEntry(getKey());
    if ( (entry.lValueType == PRIMITIVE_TYPE) || (entry.lValueType == ARRAY_TYPE) ) return entry.offset;
    else if (entry.lValueType == RECORD_TYPE)
    {
        RecordType* record = dynamic_cast<RecordType*>(entry.type);
        std::string accessor = (*sequence)[1]->accessor;
        int offset = entry.offset + record->offsets[accessor];
        return offset;
    }
    else throw std::runtime_error("LValueType not known. Inside LValue::loadBaseRegister\n");

}

void LValue::print()
{
    for (LValueBase* item : *sequence) item->print();
}

