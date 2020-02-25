#include <iostream>
#include "Program.h"
#include "prelude/constants/Constant.h"

Program::Program()
{

}

void Program::prettyPrint()
{
    std::cout << "const" << std::endl;
    for (Constant* item : *(prelude->constants))
    {
        std::cout << item->identifier << " = " << item->value->prettyPrintValue << ";" << std::endl;
    }
    std::cout << "type" << std::endl;
    for (BaseType* item : *(prelude->types))
    {
        std::cout << item->ident << " type item " << std::endl;
    }
   
}

