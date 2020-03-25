#include <string>

#include "Prelude.h"

Prelude::Prelude(std::vector<Constant*>* p_constants, std::vector<BaseType*>* p_types, std::vector<TypedList*>* p_vars)
{
   constants = p_constants;
   types = p_types;
   if (p_vars != nullptr)
   {
       vars = new std::vector<Variable*>;
       for (TypedList* typedList : *p_vars)
       {
           for (std::string* identifier : *typedList->identList)
           {
               // yes, please, construct the LookUpItem here, once and for all. #include the symbol table and let's stop doing intermediate constructions. Then, maybe, we can get rid of the variable class altogether! Less is more. We've elimiated TypeDeclItem and Variable!
               vars->push_back(new Variable(*identifier, *typedList->type)); // don't modify for now, run the code first since so many changes were made to the parser.
           }
       }
   }
   else
   {
       vars = nullptr;
   }
}

void Prelude::print()
{
    if (constants != nullptr)
    {
        std::cout << "CONST\n";
        for (Constant* item : *constants) { item->print(); }
        std::cout << std::endl;
    }
    if (types != nullptr)
    {
        std::cout << "TYPE" << std::endl;
        for (BaseType* item : *types) { item->print(); }
        std::cout << std::endl;
    }
    if (vars != nullptr)
    {
        std::cout << "VAR" << std::endl;
        for (Variable* item : *vars) { item->print(); std::cout << "\n"; }
        std::cout << std::endl;
    }
}
