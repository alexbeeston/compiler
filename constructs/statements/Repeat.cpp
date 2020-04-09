#include <iostream>

#include "Repeat.h"
#include "../../global.h"

Repeat::Repeat(Expression* p_expression, std::vector<Statement*>* p_statements)
{
    expression = p_expression;
    statements = p_statements;
}

void Repeat::print()
{
    std::cout << "repeat ";
    for (Statement* statement : *statements)
    {
        statement->print();
        std::cout << "; ";
    }
    std::cout << " until ";
    expression->print();
}

void Repeat::emit()
{
    if (expression->getTypeIndicator() != BOOLEAN) throw std::runtime_error("Repeat::emit() - expression is not boolean");
    std::string bodyLabel = st.getRepeatLabel();
    std::cout << bodyLabel + ":\n\n";
    for (Statement* statement : *statements) statement->emit();
    std::cout << "#- Repeat test expression\n";
    Register testResult = expression->emit();
    std::cout << "beq " << testResult.getName() << " $zero " << bodyLabel << "\n";
    rp.returnRegister(testResult);
}

