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
    return (*sequence)[0]->ident;
}

Register LValue::getBaseRegister()
{
    BaseType* type = st.retrieveEntry(getKey()).type;
    Register baseRegister = rp.getRegister();
    std::cout << "add " << baseRegister.getName() << " $gp $zero   # about to load an LValue\n";
    for (int accessorIndex = 0; accessorIndex < sequence->size() - 1; accessorIndex++)
    {
        // resolve an alias type
        if (type->style == ALIAS_TYPE) type = st.retrieveType(*(dynamic_cast<SimpleType*>(type))->name);

        // iterate over the type for records and arrays
        if (type->style == RECORD_TYPE)
        {
            RecordType* record = dynamic_cast<RecordType*>(type);
            type = record->types[(*sequence)[accessorIndex + 1]->ident];
        }
        else if (type->style == ARRAY_TYPE)
        {
            ArrayType* array = dynamic_cast<ArrayType*>(type);
            Expression* index = (*sequence)[accessorIndex + 1]->indexer;
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
            type = array->underlyingType;
        }
        else if (type->style == PRIMITIVE_TYPE) throw std::runtime_error("LValue::getBaseRegister() - type->style in the loop is simple, which I think is an error since it shouldn't iterate over the last item in the sequence of LValueBase items");
        else throw std::runtime_error("LValue::getBaseRegister() - style of type unresolved\n");
    }
    return baseRegister;
}

int LValue::getOffset()
{
    Entry entry = st.retrieveEntry(getKey());
    int offset = entry.offset;
    BaseType* type = entry.type;
    for (int accessorIndex = 0; accessorIndex < sequence->size() - 1; accessorIndex++)
    {
        // resolve an alias type
        if (type->style == ALIAS_TYPE) type = st.retrieveType(*(dynamic_cast<SimpleType*>(type))->name);

        // iterate over the type for records and arrays
        if (type->style == RECORD_TYPE)
        {
            std::string accessor = (*sequence)[accessorIndex + 1]->ident;
            RecordType* record = dynamic_cast<RecordType*>(type);
            offset += record->offsets[accessor];
            type = record->types[accessor];
        }
        else if (type->style == ARRAY_TYPE) type = dynamic_cast<ArrayType*>(type)->underlyingType;
        else if (type->style == PRIMITIVE_TYPE) throw std::runtime_error("LValue::getOffSet() - type->style in the loop is simple, which I think is an error since it shouldn' iterate over the last item in the sequence");
        else throw std::runtime_error("LValue::getBaseRegister() - style of type unresolved\n");
    }
    return offset;
}

void LValue::print()
{
    for (LValueBase* item : *sequence) item->print();
}

Style LValue::getStyle()
{
    BaseType* type = getInnerMostType();
    if (type->style == ALIAS_TYPE) return st.retrieveType(*(dynamic_cast<SimpleType*>(type))->name)->style;
    else return type->style;
}

TypeIndicator LValue::getTypeIndicator() { return getInnerMostType()->getTypeIndicator(); }

BaseType* LValue::getInnerMostType()
{
    BaseType* type = st.retrieveEntry(getKey()).type;
    if (type->style == ALIAS_TYPE || type->style == PRIMITIVE_TYPE) type = st.retrieveType(*(dynamic_cast<SimpleType*>(type))->name);
    for (int accessorIndex = 0; accessorIndex < sequence->size() - 1; accessorIndex++)
    {
        // resolve an alias type
        if (type->style == ALIAS_TYPE) type = st.retrieveType(*(dynamic_cast<SimpleType*>(type))->name);

        // resolve standard types
        if (type->style == RECORD_TYPE)
        {
            RecordType* record = dynamic_cast<RecordType*>(type);
            std::string accessor = (*sequence)[accessorIndex + 1]->ident;
            type = record->types[accessor];
        }
        else if (type->style == ARRAY_TYPE) type = (dynamic_cast<ArrayType*>(type))->underlyingType;
        else throw std::runtime_error("LValue::getBaseRegister() - style of type unresolved\n");
    }
    return type;
}