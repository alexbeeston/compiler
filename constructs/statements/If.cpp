#include <iostream>

#include "If.h"
#include "../../global.h"

If::If(ConditionalSequence* p_ifBlock, std::vector<ConditionalSequence*>* p_elseIfBlocks, std::vector<Statement*>* p_elseBlock)
{
    ifBlock = p_ifBlock;
    elseIfBlocks = p_elseIfBlocks;
    elseBlock = p_elseBlock;
}

void If::print()
{
    std::cout << "if";
    ifBlock->print();
    for (ConditionalSequence* elseIfBlock : *elseIfBlocks)
    {
        std::cout << " else";
        elseIfBlock->print();
    }
    std::cout << " else ";
    for (Statement* statement : *elseBlock) statement->print();
}

void If::emit()
{
    // validation and label preparation
    if (ifBlock->expression->getTypeIndicator() != BOOLEAN) throw std::runtime_error("If::emit() - if block has expression of type " + ifBlock->expression->getTypeIndicator());
    std::vector<std::string> elseIfLabels = std::vector<std::string>();
    for (ConditionalSequence* sequence : *elseIfBlocks) elseIfLabels.push_back(st.getNextIfLabel());
    std::string elseLabel = st.getNextIfLabel();
    std::string nextLabel = st.getNextLabel();

    // if test
    std::cout << "# If - if block (test)\n";
    Register test = ifBlock->expression->emit();
    if (elseIfBlocks->size() != 0) std::cout << "beq " << test.getName() << " $zero " << elseIfLabels[0] << "\n";
    else if (elseBlock != nullptr) std::cout << "beq " << test.getName() << " $zero " << elseLabel << "\n";
    else std::cout << "beq " << test.getName() << " $zero " << nextLabel << "\n";
    rp.returnRegister(test);

    // if body
    std::cout << "\n# If - if block (body)\n";
    for (Statement* statement : *ifBlock->statements) statement->emit();
    std::cout << "j " << nextLabel << "\n";

    // else ifs
    for (int i = 0; i < elseIfBlocks->size(); i ++)
    {
        // else if test
        if (elseIfBlocks->at(i)->expression->getTypeIndicator() != BOOLEAN) throw std::runtime_error("If::emit() - conditional expression for else if block not boolean");
        std::cout << "\n# If - elseif (test) \n";
        std::cout << elseIfLabels[i] << ":\n";
        test = elseIfBlocks->at(i)->expression->emit();
        std::cout << "beq " << test.getName() << " $zero ";
        if ( i != elseIfBlocks->size() - 1) std::cout << elseIfLabels[i + 1] << "\n";
        else
        {
            if (elseBlock != nullptr) std::cout << elseLabel << "\n";
            else std::cout << nextLabel << "\n";
        }
        rp.returnRegister(test);

        // else if body
        std::cout << "\n# If - elseif (body)\n";
        for (Statement* statement : *elseIfBlocks->at(i)->statements) statement->emit();
        std::cout << "j " << nextLabel << "\n";
    }

    // else
    if (elseBlock != nullptr)
    {
        std::cout << "\n# If - else block (body)\n";
        std::cout << elseLabel << ":\n";
        for (Statement* statement : *elseBlock) statement->emit();
    }

    // next
    std::cout << "\n# If - next\n";
    std::cout << nextLabel << ":\n";
}
