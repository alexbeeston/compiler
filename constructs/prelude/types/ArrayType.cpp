#include <iostream>

#include "ArrayType.h"
#include "../../../global.h"

ArrayType::ArrayType(Expression* p_low, Expression* p_high, BaseType* p_type)
{
    low = p_low;
    high = p_high;
    type = p_type;
    typeIndicator = 4;
    isRedeclarable = false;
    identifier = std::string("[declared inline]");

//    // compute the size of the array in memory
//    int multiplier = st.retrieveType(type->identifier).size;
//
//
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
