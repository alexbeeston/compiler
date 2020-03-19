#include <iostream>
#include <string>

#include "Scope.h"
#include "../constructs/prelude/types/SimpleType.h"
#include "../constructs/expressions/Expression.h"
#include "../RegisterPool.h"

extern RegisterPool rp;

Scope::Scope(Prelude topLevelPrelude)
{
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

    // add true and false (variable for now so satisfy my assumption that everything is a variable in the symbol table)
    int address = 0;
    std::string booleans[] = {"false", "true"};
    for (int i = 0; i < 2; ++i) initializeBool(booleans[i], address, i);

    // add other variables
    if (topLevelPrelude.vars != nullptr)
    {
        for (Variable* var : *topLevelPrelude.vars) address = addVariable(*var, address) ;
    }
}

int Scope::initializeBool(std::string name, int &address, int semanticValue) // check to make sure the address is valued by reference so that it maintains a cummulative total
{
    Variable booleanVar = Variable(name, SimpleType(new std::string("boolean")));
    addVariable(booleanVar, address);
    variables[name] = booleanVar; // provide key to booleanVar that is capitalized too, will be easy, look at docs
    Register r = rp.getRegister();
    std::cout << "# create the " << name << " variable\n";
    std::cout << "li " << r.name << " " << semanticValue << "\n";
    std::cout << "sw " << r.name << " " << booleanVar.offset << "(" << booleanVar.baseRegister << ")   # loaded " << name << "\n\n";
    rp.returnRegister(r);
}

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
