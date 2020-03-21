#include <iostream>
#include <string>

#include "Scope.h"
#include "../constructs/prelude/types/SimpleType.h"
#include "../constructs/expressions/Expression.h"
#include "../RegisterPool.h"

extern RegisterPool rp;

// used during initialization
Scope::Scope(Prelude topLevelPrelude)
{
    // add user defined constants
    for (Constant* i : *topLevelPrelude.constants) if (constants.count(i->ident) == 0) constants[i->ident] = *i;

    // initialize with primitive types
    std::string primitives[] = {"integer", "char", "string", "boolean"};
    for (std::string primitive : primitives)
    {
        types[std::string(primitive)] = SimpleType(new std::string(primitive));
    }

    // add types
    if (topLevelPrelude.types != nullptr)
    {
        for (TypeDeclItem* type: *topLevelPrelude.types)
        {
            types[*type->ident] = *type->type;
        }
    }

    // add other variables
    int address = 0;
    if (topLevelPrelude.vars != nullptr)
    {
        for (Variable* var : *topLevelPrelude.vars)
        {
            addVariable(*var, address);
        }
    }
}

int Scope::initializeBool(std::string name, int &address, int semanticValue)
{
    Variable booleanVar = Variable(name, SimpleType(new std::string("boolean")));
    addVariable(booleanVar, address);
    variables[name] = booleanVar; // provide key to booleanVar that is capitalized too, will be easy, look at docs
    Register r = rp.getRegister();
    std::cout << "# create the " << name << " variable\n";
    std::cout << "li " << r.getName() << " " << semanticValue << "\n";
    std::cout << "sw " << r.getName() << " " << booleanVar.offset << "(" << booleanVar.baseRegister << ")   # loaded " << name << "\n\n";
    rp.returnRegister(r);
}

// used to handle LookUpItems (variables and constants)
int Scope::addVariable(Variable &var, int &address)
{
    // check to make sure the type is in the symbol table
   var.offset = address;
   variables[var.ident] = var;
   address += var.type.size;
}

Variable Scope::lookUpVariable(std::string key)
{
   // do something like variables.find(key) !-= variables.end();
   return variables[key]; // assumes that the key exists
}

// used to handle types

// validation
void Scope::prettyPrint()
{
    std::cout << "\t Types:\n";
    for( std::pair<std::string, BaseType> type: types)
    {
        std::cout << "\t\t" << type.first << " : " << "\n";
    }

    std::cout << "\t Constants/Variables, which have an expression:\n";
    for (std::pair<std::string, Variable> item: variables )
    {
        std::cout << "\t\t" << "Identifier: " << item.first << "  Address: " << item.second.offset << "\n";
    }

    std::cout << "\t Functions:\n";
    std::cout << "\t\t[placeholder]\n";
}
