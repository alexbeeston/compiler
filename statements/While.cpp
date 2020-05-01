#include <iostream>

#include "While.h"
#include "../global.h"
#include "../miscellaneous/utilities.h"

While::While(Expression* p_expression, std::vector<Statement*>* p_statements)
{
    expression = p_expression;
    statements = p_statements;
}

void While::print()
{
    std::cout << "while ";
    expression->print();
    std::cout << " do ";
    for (Statement* statement : *statements)
    {
        statement->print();
        std::cout << "; ";
    }
}

void While::emit()
{
    std::string testLabel = st.getWhileLabel();
    std::string nextLabel = st.getNextNextLabel();
    std::cout << "\n#While - test\n";
    std::cout << testLabel + ":\n";
    Register testResult = expression->emit();
    dereferencePointer(testResult);
    std::cout << "beq " << testResult.getName() << " $zero " << nextLabel << "\n";
    std::cout << "\n#while - Body\n";
    for (Statement* statement : *statements) statement->emit();
    std::cout << "\n# While - update\n";
    std::cout << "j " << testLabel << "\n";
    std::cout << "\n# While - next\n";
    std::cout << nextLabel + ":\n";
}