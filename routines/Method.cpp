#include <iostream>
#include <vector>

#include "Method.h"
#include "ParameterSet.h"
#include "Body.h"
#include "../global.h"
#include "../types/SimpleType.h"
#include "../miscellaneous/utilities.h"

Method::Method(char* p_ident, std::vector<ParameterSet*>* p_formalParameters, BaseType* p_returnType, Body* p_body)
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

void Method::computeOffsets()
{
    int nextOffset;
    if (type_temp != nullptr) nextOffset = type_temp->computeSize();
    else nextOffset = 0;
    for (auto set : *formalParameters)
    {
        int size = set->type->computeSize();
        for (auto parameter : set->identList)
        {
            offsets.push_back(nextOffset);
            nextOffset += size;
        }
    }
    sizeOfParametersAndReturnType = nextOffset;
}

void Method::print()
{
    std::cout << "This should be overriden" << std::endl;
}

void Method::printParameters()
{
    for (ParameterSet* parameterSet: *formalParameters)
    {
        if (parameterSet->passBy == 0) std::cout << "var ";
        else if (parameterSet->passBy == 1) std::cout << "ref ";
        else std::cout << "Error: passBy value in Method::printParameters() is not a 0 or 1, meaning, it is not passed by reference or value.";
        for (std::string identifier : parameterSet->identList) std::cout << identifier << ", ";
        std::cout << " : ";
        parameterSet->type->print();
        std::cout << " ; ";
    }
}

void Method::emit()
{
    // validate
    if (isForwardDeclared)
    {
        if (body == nullptr) throw std::runtime_error("Method::computeSizeOnStack() - can not emit a forward declared function");
        else throw std::runtime_error("Method::computeSizeOnStack(0 - there are two errors: 1) can not emit a forward declared function. 2) The function is forward declared, yet the body is not null. Bodies should not be null if and only if the function is not forward declared.");
    }
    if (body == nullptr) throw std::runtime_error("Method::computeSizeOnStack() - the body is null, yet the function is not forward declared. Bodies should be null if and only if the function is forward declared");

    // continue
    st.pushScope(type_temp, *formalParameters, *body->prelude);
    st.sizeOfLocalVars = body->prelude->computeSize();
    std::cout << ident << ":\n";
    std::cout << "ori $fp $sp 0\n";
    if (st.sizeOfLocalVars != 0) moveStackPointerDown(st.sizeOfLocalVars);
    for (auto statement : *body->block->statementSequence) statement->emit();
    if (st.sizeOfLocalVars != 0) moveStackPointerUp(st.sizeOfLocalVars);
    st.sizeOfLocalVars = 0;
    std::cout << "jr $ra\n";
    std::cout << std::endl;
    st.popScope();
}
