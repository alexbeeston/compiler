#include <iostream>
#include "Program.h"
#include "prelude/constants/Constant.h"

Program::Program()
{

}

void Program::prettyPrint()
{
    std::cout << "CONST" << std::endl;
    for (Constant* item : *(prelude->constants)) { item->print(); }
    std::cout << "\nTYPE" << std::endl;
    for (BaseType* item : *(prelude->types))
    {
        std::cout << item->ident << " = [fill in later, idk if it is a record, array, or simple yet" << std::endl;
    }

    std::cout << "\nVAR" << std::endl;
    for (TypedList* item : *(prelude->vars))
    {
        std::cout << "Identifiers in this typelist:";
        item->print();
        std::cout << std::endl;
    }
}

