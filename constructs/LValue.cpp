#include <iostream>

#include "LValue.h"
#include "../global.h"
#include "../constructs/prelude/types/ArrayType.h"
#include "../constructs/prelude/types/RecordType.h"
#include "../constructs/prelude/types/SimpleType.h"

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
    BaseType* type = st.retrieveEntry(getKey()).type;



    if (type->style == ALIAS_TYPE)
    {
        SimpleType* temp = dynamic_cast<SimpleType*>(type);
        type = st.retrieveType(*temp->name);
    }
    if ( (type->style == PRIMITIVE_TYPE) || (type->style == RECORD_TYPE) ) return rp.getGlobalPointer();
    else if (type->style == ARRAY_TYPE)
    {
        Register base = rp.getRegister();
        LValueBase* accessor;
        int accessorIndex = 1;
        std::cout << "add " << base.getName() << " $gp $zero\n";
        while (type->style != PRIMITIVE_TYPE)
        {
            accessor = (*sequence)[accessorIndex];
            if (type->style == ARRAY_TYPE)
            {
                ArrayType* array = dynamic_cast<ArrayType*>(type);
                getBaseRegister_Array(array, accessor->index, base);
                type = array->underlyingType;
            }
            else if (type->style == RECORD_TYPE)
            {
                type = dynamic_cast<RecordType*>(type);
            }
            ++accessorIndex;
        }
        return base;
    }
    else throw std::runtime_error("LValueType not known. Inside LValue::getBaseRegister\n");
}

void LValue::getBaseRegister_Array(ArrayType* array, Expression* index, Register baseRegister)
{
    Register r1 = rp.getRegister();
    Register r2 = index->emit();
    std::cout << "li " << r1.getName() << " " << array->low->getValue() << "   # lower bound of array\n";
    std::cout << "sub " << r1.getName() << " " << r2.getName() << " " << r1.getName() << "   # number of elements offset from lower bound\n";
    std::cout << "li " << r2.getName() << " " << array->underlyingType->computeSize() << "   # loaded size of underlying type of array\n";
    std::cout << "mult " << r1.getName() << " " << r2.getName() << "\n";
    std::cout << "mflo " << r1.getName() << "\n";
    std::cout << "add " << baseRegister.getName() << " " << baseRegister.getName() << " " << r1.getName() << "\n";
    rp.returnRegister(r1);
    rp.returnRegister(r2);
}

int LValue::getOffset()
{
    Entry entry = st.retrieveEntry(getKey());
    if ( (entry.type->style == PRIMITIVE_TYPE) || (entry.type->style == ARRAY_TYPE) ) return entry.offset;
    else if (entry.type->style == RECORD_TYPE)
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

