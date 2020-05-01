#include <iostream>
#include <vector>

#include "Routine.h"
#include "ParameterSet.h"
#include "Body.h"
#include "../global.h"
#include "../types/SimpleType.h"

Routine::Routine(char* p_ident, std::vector<ParameterSet*>* p_formalParameters, BaseType* p_returnType, Body* p_body)
{
    ident = std::string(p_ident);
    formalParameters = p_formalParameters;
    if (p_body == nullptr) isForwardDeclared = true;
    else
    {
        isForwardDeclared = false;
        body = p_body;
    }
    type_temp = p_returnType;
}

void Routine::computeOffsets_internal(int nextOffset)
{
    for (auto set : *formalParameters)
    {
        int size = set->type->computeSize();
        for (auto parameter : set->identList)
        {
            offsets.push_back(nextOffset);
            nextOffset += size;
        }
    }
    sizeOfParametersAndReturnType = nextOffset + type_temp->computeSize();
}

void Routine::computeOffsets()
{
    static int RETURN_TYPE_SIZE = 0;
    computeOffsets_internal(RETURN_TYPE_SIZE);
}

void Routine::print()
{
    std::cout << "This should be overriden" << std::endl;
}

void Routine::printParameters()
{
    for (ParameterSet* parameterSet: *formalParameters)
    {
        if (parameterSet->passBy == 0) std::cout << "var ";
        else if (parameterSet->passBy == 1) std::cout << "ref ";
        else std::cout << "Error: passBy value in Routine::printParameters() is not a 0 or 1, meaning, it is not passed by reference or value.";
        for (std::string identifier : parameterSet->identList) std::cout << identifier << ", ";
        std::cout << " : ";
        parameterSet->type->print();
        std::cout << " ; ";
    }
}

void Routine::emit()
{
    // validate
    if (isForwardDeclared)
    {
        if (body == nullptr) throw std::runtime_error("Routine::computeSizeOnStack() - can not emit a forward declared function");
        else throw std::runtime_error("Routine::computeSizeOnStack(0 - there are two errors: 1) can not emit a forward declared function. 2) The function is forward declared, yet the body is not null. Bodies should not be null if and only if the function is not forward declared.");
    }
    if (body == nullptr) throw std::runtime_error("Routine::computeSizeOnStack() - the body is null, yet the function is not forward declared. Bodies should be null if and only if the function is forward declared");

    // continue
    int sizeOfLocalVars = body->prelude->computeSize();
    st.pushScope(type_temp, *formalParameters, *body->prelude);
    std::cout << ident << ":\n";
    std::cout << "ori $fp $sp 0\n";
    std::cout << "addi $sp $sp -" << sizeOfLocalVars << "\n";
    for (auto statement : *body->block->statementSequence) statement->emit();
    std::cout << "addi $sp $sp " << sizeOfLocalVars << "\n";
    std::cout << "jr $ra\n";
    std::cout << std::endl;

    st.popScope();
}
