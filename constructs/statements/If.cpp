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

    // first if
    std::cout << "# If - first test\n";
    Register test = ifBlock->expression->emit();
    if (elseIfBlocks->size() != 0) std::cout << "beq " << test.getName() << " $zero " << elseIfLabels[0] << "\n";
    else if (elseBlock != nullptr) std::cout << "beq " << test.getName() << " $zero " << elseLabel << "\n";
    else std::cout << "beq " << test.getName() << " $zero " << nextLabel << "\n";
    rp.returnRegister(test);

    // first if body
    std::cout << "\n# If - first body\n";
    for (Statement* statement : *ifBlock->statements) statement->emit();
    std::cout << "j " << nextLabel << "\n";

    // else ifs

    // else
    if (elseBlock != nullptr)
    {
        std::cout << "\n# If - else block\n";
        std::cout << elseLabel << ":\n";
        for (Statement* statement : *elseBlock) statement->emit();
    }

    // next
    std::cout << "\n# If - next\n";
    std::cout << nextLabel << ":\n";
}
