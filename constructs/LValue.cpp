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
//        ArrayType* array = dynamic_cast<ArrayType*>(entry.type);
//        Register r1 = rp.getRegister();
//        std::cout << "li " << r1.getName() << " " << array->low->getValue() << "   # lower bound of array\n";
//        Register r3 = (*sequence)[1]->index->emit(); // change this part!
//        std::cout << "# just loaded the index into r3\n";
//        std::cout << "sub " << r1.getName() << " " << r3.getName() << " " << r1.getName() << "   # number of elements offset from lower bound\n";
//        std::cout << "li " << r3.getName() << " " << array->type->computeSize() << "   # loaded size of underlying type of array\n";
//        std::cout << "mult " << r1.getName() << " " << r3.getName() << "\n";
//        rp.returnRegister(r3);
//        std::cout << "mflo " << r1.getName() << "\n";
//        std::cout << "add " << r1.getName() << " " << entry.baseRegister.getName() << " " << r1.getName() << "\n";

        Register base = rp.getRegister();
        std::cout << "add " << base.getName() << " $gp $zero\n";
        getBaseRegister_Array(dynamic_cast<ArrayType*>(entry.type), 0, base);
        return base;
    }
    else throw std::runtime_error("LValueType not known. Inside LValue::loadBaseRegister\n");
}

void LValue::getBaseRegister_Array(ArrayType* array, int currentLValue, Register baseRegister)
{
    Register r1 = rp.getRegister();
    Register r2 = (*sequence)[currentLValue + 1]->index->emit();
    std::cout << "li " << r1.getName() << " " << array->low->getValue() << "   # lower bound of array\n";
    std::cout << "sub " << r1.getName() << " " << r2.getName() << " " << r1.getName() << "   # number of elements offset from lower bound\n";
    std::cout << "li " << r2.getName() << " " << array->type->computeSize() << "   # loaded size of underlying type of array\n";
    std::cout << "mult " << r1.getName() << " " << r2.getName() << "\n";
    std::cout << "mflo " << r1.getName() << "\n";
    std::cout << "add " << baseRegister.getName() << " " << baseRegister.getName() << " " << r1.getName() << "\n";
    rp.returnRegister(r1);
    rp.returnRegister(r2);
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

