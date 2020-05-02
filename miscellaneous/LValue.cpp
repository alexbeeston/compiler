#include <iostream>

#include "LValue.h"
#include "../global.h"
#include "../types/ArrayType.h"
#include "../types/RecordType.h"
#include "../types/SimpleType.h"

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
    // validation
    Entry entry = st.retrieveEntry(getKey());
    if (entry.baseRegister.getName() == "$gp" && !entry.isDeclaredEntry) throw std::runtime_error("LValue::getBaseRegister() - entry's base register is the global pointer, but the entry is not a declared entry. Entries at global scope shouldn't be non-declared since we can't pass parameters to the global scope");

    // continue
    if (entry.type->isPrimitive()) return entry.baseRegister;
    BaseType* type = entry.type;
    Register baseRegister = rp.getRegister();
    std::cout << "add " << baseRegister.getName() << " " << entry.baseRegister.getName() << " $zero   # about to load an LValue\n";
    for (int accessorIndex = 0; accessorIndex < sequence->size() - 1; accessorIndex++)
    {
        // resolve a simple type
        if (type->style == SIMPLE) type = st.retrieveType((dynamic_cast<SimpleType*>(type))->name);

        // iterate over the type for records and arrays
        if (type->style == RECORD)
        {
            auto* record = dynamic_cast<RecordType*>(type);
            type = record->types[(*sequence)[accessorIndex + 1]->ident];
        }
        else if (type->style == ARRAY)
        {
            auto* array = dynamic_cast<ArrayType*>(type);
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
        else if (type->style == SIMPLE) throw std::runtime_error("LValue::getBaseRegister() - type->style in the loop is simple, which I think is an error since it shouldn't iterate over the last item in the sequence of LValueBase items");
        else throw std::runtime_error("LValue::getBaseRegister() - style of type unresolved. Type is " + std::to_string(type->style));
    }
    return baseRegister;
}

int LValue::getOffset()
{
    Entry entry = st.retrieveEntry(getKey());
    if (entry.label == CONSTANT) throw std::runtime_error("LValue::getOffset() - trying to get the offset of a constant");
    int offset = entry.offset;
    BaseType* type = entry.type;
    for (int accessorIndex = 0; accessorIndex < sequence->size() - 1; accessorIndex++)
    {
        // resolve a simple type
        if (type->style == SIMPLE) type = st.retrieveType((dynamic_cast<SimpleType*>(type))->name);

        // iterate over the type for records and arrays
        if (type->style == RECORD)
        {
            std::string accessor = (*sequence)[accessorIndex + 1]->ident;
            RecordType* record = dynamic_cast<RecordType*>(type);
            offset += record->offsets[accessor];
            type = record->types[accessor];
        }
        else if (type->style == ARRAY) type = dynamic_cast<ArrayType*>(type)->underlyingType;
        else if (type->style == SIMPLE) throw std::runtime_error("LValue::getOffSet() - type->style in the loop is simple, which I think is an error since it shouldn' iterate over the last item in the sequence");
        else throw std::runtime_error("LValue::getOffset() - style of type unresolved. Type is " + std::to_string(type->style));
    }
    return offset;
}

TypeStyle LValue::getStyle()
{
    BaseType* type = getInnerMostType();
    if (type->style == SIMPLE) return st.retrieveType((dynamic_cast<SimpleType*>(type))->name)->style;
    else return type->style;
}

PrimitiveType LValue::getPrimitiveType()
{
    Entry entry = st.retrieveEntry(getKey());
    if (entry.label == CONSTANT) return entry.value->getPrimitiveType();
    else return getInnerMostType()->typeIndicator;
}

BaseType* LValue::getInnerMostType()
{
    BaseType* type = st.retrieveEntry(getKey()).type;
    if (type->style == SIMPLE) type = st.retrieveType((dynamic_cast<SimpleType*>(type))->name);
    for (int accessorIndex = 0; accessorIndex < sequence->size() - 1; accessorIndex++)
    {
        // resolve an simple type
        if (type->style == SIMPLE) type = st.retrieveType((dynamic_cast<SimpleType*>(type))->name);

        // resolve standard types
        if (type->style == RECORD)
        {
            RecordType* record = dynamic_cast<RecordType*>(type);
            std::string accessor = (*sequence)[accessorIndex + 1]->ident;
            type = record->types[accessor];
        }
        else if (type->style == ARRAY) type = (dynamic_cast<ArrayType*>(type))->underlyingType;
        else throw std::runtime_error("LValue::getInnerMostType() - style of type unresolved. Type is " + std::to_string(type->style));
    }
    return type;
}

bool LValue::isPrimitive()
{
    return getInnerMostType()->isPrimitive();
}

void LValue::print()
{
    for (LValueBase* item : *sequence) item->print();
}