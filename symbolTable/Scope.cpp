#include <iostream>
#include <string>

#include "Scope.h"
#include "../constructs/prelude/types/SimpleType.h"
#include "../constructs/prelude/types/DeclaredType.h"
#include "../constructs/expressions/Literal.h"
#include "../constructs/expressions/LValueExpression.h"
#include "../global.h"

extern RegisterPool rp;

// used during initialization
Scope::Scope()
{
    // if things are still breaking, maybe give types and entries a constructor call; not sure if it would work though
    // also could try giving the st a construcotr call in main
}

void Scope::addConstructs(Prelude topLevelPrelude)
{
    // add boolean constants, implemented as redeclarable constants; they can't be variables because we need to pull their semantic value in const_declarations, but they can't be constants because we over write their value in badidea.cpsl
    int NUM_BOOLS = 2;
    std::string booleans[] = {"false", "true"};
    bool booleanLiterals[] = {false, true};
    for (int i = 0; i < NUM_BOOLS; ++i) entries[booleans[i]] = Entry(booleans[i], new Literal(booleanLiterals[i]));

    // add user defined constants
    for (Constant* i : *topLevelPrelude.constants) entries[i->ident] = Entry(i->ident, i->value);

    // initialize with primitive types
    std::string primitives[] = {"integer", "char", "string", "boolean"};
    for (std::string primitive : primitives)
    {
        types[primitive] = new SimpleType(&primitive); // todo: add a key for uppercase
    }

    // add declared types
    for (DeclaredType* declaredType : *topLevelPrelude.declaredTypes)
    {
        declaredType->type->size = computeSize(declaredType->type);
        types[declaredType->identifier] = declaredType->type;
        std::cout << "# the size is " << declaredType->type->size << "\n";
    }

    // add variables, which are all user defined
    for (TypedList* list: *topLevelPrelude.vars)
    {
        for (std::string* name: *list->identList)
        {
            entries[*name] = Entry(*name, list->type, nextAddress);
            nextAddress += computeSize(list->type);
        }
    }
}

int Scope::computeSize(BaseType* type)
{
    if (type->lValueType == SIMPLE_TYPE)
    {
        SimpleType* temp = dynamic_cast<SimpleType*>(type);
        if (types.count(*temp->name) == 1) return types[*temp->name]->size;
        else throw std::runtime_error("Can't find an SIMPLE_TYPE in the symbol table, and we need to know its size.");
    }
    else if (type->lValueType == ARRAY_TYPE) return computeSize_Array(dynamic_cast<ArrayType*>(type));
    else if (type->lValueType == RECORD_TYPE) return computeSize_Record(dynamic_cast<RecordType*>(type));
    else throw std::runtime_error("lValueType of type unknown\n");
}

int Scope::computeSize_Array(ArrayType* array)
{
//    int lower =
//    if (array->low->typeIndicator == INTEGER || array->low->typeIndicator == CHAR) lower = array->low->value;
//    else if (array->low->typeIndicator == ALIAS)
//    {
//        LValueExpression* temp = dynamic_cast<LValueExpression*>(array->low);
//        lower = entries[temp->lValue->getKey()].value->value;
//    }
    int length = array->high->getValue() - array->low->getValue() + 1;
    int size = length * computeSize(array->underlyingType);
    array->size = size;
    return size;
}

int Scope::computeSize_Record(RecordType* record)
{
    int offset = 0;
    BaseType* type;
    for (TypedList* list : *record->typedLists)
    {
        type = list->type;
        for (std::string* identifier : *list->identList)
        {
            record->types[*identifier] = type;
            record->offsets[*identifier] = offset;
            offset += computeSize(type);
        }
    }
    record->size = offset;
    return offset;
}

BaseType* Scope::getBaseType(std::string key)
{
    if (types.count(key) == 1) return types[key];
    else throw std::runtime_error("Type not found in symbol table");
}

Entry Scope::getEntry(std::string key)
{
    if (entries.count(key) == 1) return entries[key];
    else throw std::runtime_error("Entry not found in symbol table");
}