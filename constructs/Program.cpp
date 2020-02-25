#include <iostream>
#include "Program.h"
#include "prelude/constants/Constant.h"

Program::Program()
{

}

void Program::prettyPrint()
{
    std::cout << "CONST" << std::endl;
    for (Constant* item : *(prelude->constants))
    {
        std::cout << item->identifier << " = " << item->value->prettyPrintValue << ";" << std::endl;
    }
    std::cout << "TYPE" << std::endl;
    std::cout << " items in the TYPES list" << std::endl;
    for (BaseType* item : *(prelude->types))
    {
        std::cout << "here is a type" << std::endl;
    }

}

