#include <iostream>

#include "ArrayType.h"
#include "../../../global.h"

ArrayType::ArrayType(Expression* p_low, Expression* p_high, BaseType* p_type)
{
    low = p_low;
    high = p_high;
    type = p_type;
    typeIndicator = p_type->typeIndicator; // contains the typeIndicator of the contained type about the type the array holds
    isRedeclarable = false;
    identifier = std::string("[declared inline]");
}

int ArrayType::computeSize()
{
    int multiplier = type->computeSize();
    int length = high->getValue() - low->getValue();
    return length * multiplier;
}
void ArrayType::print()
{
    std::cout << "array[";
    low->print();
    std::cout << ":";
    high->print();
    std::cout << "] of ";
    type->print();
}
