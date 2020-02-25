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
    for (TypeDeclItem* item : *(prelude->types)) { item->print(); }
    std::cout << "\nVAR" << std::endl;
    for (TypedList* item : *(prelude->vars))
    {
        std::cout << "Identifiers in this typelist:";
        item->print();
        std::cout << std::endl;
    }
}

