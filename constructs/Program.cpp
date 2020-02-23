#include <iostream>
#include "Program.h"
#include "Constant.h"

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
}
