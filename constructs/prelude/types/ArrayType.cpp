#include <iostream>

#include "ArrayType.h"
#include "../../../global.h"

ArrayType::ArrayType(Expression* p_low, Expression* p_high, BaseType* p_type)
{
    lValueType = ARRAY_TYPE;
    low = p_low;
    high = p_high;
    underlyingType = p_type;
    typeIndicator = p_type->getTypeIndicator();
    isRedeclarable = false;
    identifier = std::string("[declared inline]");
}

int ArrayType::computeSize()
{
    int multiplier = underlyingType->computeSize();
    int length = high->getValue() - low->getValue() + 1;
    return multiplier * length;
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
