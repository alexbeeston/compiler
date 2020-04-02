#include <iostream>

#include "ArrayType.h"
#include "../../../global.h"

ArrayType::ArrayType(Expression* p_low, Expression* p_high, BaseType* p_type)
{
    lValueType = ARRAY_TYPE;
    low = p_low;
    high = p_high;
    underlyingType = p_type;
    isRedeclarable = false;
    identifier = std::string("[declared inline]");
    lValueType == ARRAY_TYPE;
}

int ArrayType::computeSize()
{
    int multiplier = underlyingType->computeSize();
    int length = high->getValue() - low->getValue() + 1; // offending code
    std::cout << "# ArrayType::computeSize(); size is " + multiplier * length << "\n";
    return multiplier * length;
}

TypeIndicator ArrayType::getTypeIndicator()
{
    return underlyingType->getTypeIndicator();
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
