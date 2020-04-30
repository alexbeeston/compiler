#include <iostream>
#include <vector>

#include "Routine.h"
#include "ParameterSet.h"
#include "Body.h"
#include "../global.h"

Routine::Routine(char* p_ident, std::vector<ParameterSet*>* p_formalParameters, Body* p_body)
{
    ident = std::string(p_ident);
    formalParameters = p_formalParameters;
    if (p_body == nullptr) forwardDeclared = true;
    else
    {
        forwardDeclared = false;
        body = p_body;
    }
}

void Routine::computeOffsets_internal(int nextOffset)
{
    for (auto set : *formalParameters)
    {
        for (auto parameter : *set->identList)
        {
            offsets.push_back(nextOffset);
            nextOffset += set->type->computeSize();
        }
    }
    stackSize = nextOffset;
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
        for (char* identifier : *(parameterSet->identList)) std::cout << identifier << ", ";
        std::cout << " : ";
        parameterSet->type->print();
        std::cout << " ; ";
    }
}

void Routine::emit()
{
    st.pushScope(*body->prelude);
    // scope.addParams();

    // something to add the parameters to the scope too
    // std::cout << "ori $fp $sp 0\n";
    for (Statement* statement : *body->block->statementSequence) statement->emit();
    // std::cout << "jr $ra\n";
    st.popScope();
}
