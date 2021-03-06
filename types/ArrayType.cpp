#include <iostream>

#include "ArrayType.h"
#include "../global.h"

ArrayType::ArrayType(Expression* p_low, Expression* p_high, BaseType* p_type)
{
    style = ARRAY;
    low = p_low;
    high = p_high;
    underlyingType = p_type;
}

int ArrayType::computeSize()
{
    int multiplier = underlyingType->computeSize();
    int length = high->getValue() - low->getValue() + 1;
    return multiplier * length;
}

PrimitiveType ArrayType::getPrimitiveType()
{
    return underlyingType->getPrimitiveType();
}

void ArrayType::print()
{
    std::cout << "array[";
    low->print();
    std::cout << ":";
    high->print();
    std::cout << "] of ";
    underlyingType->print();
}

bool ArrayType::isPrimitive() { return false; }
