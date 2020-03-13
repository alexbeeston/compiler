#include <iostream>

#include "Write.h"

Write::Write(Expression* p_expression1, std::vector<Expression*>* p_expressions)
{
    expressions = new std::vector<Expression*> { p_expression1};
    for (Expression* express : *p_expressions) expressions->push_back(express);

}

void Write::print()
{
    std::cout << "write(";
    for (Expression* express : *expressions)
    {
        express->print();
        std::cout << ", ";
    }
    std::cout << ")";
}

void Write::emit()
{
    // for each expression, create a label to be used in the system call
    std::cout << "\n# declare labels for write statement\n";
    std::cout << ".data\n";
    int counter = 0;
    for (Expression* expression : *expressions)
    {
        std::cout << "message" + std::to_string(counter) + ": ";
        expression->emitLabel();
        std::cout << "\n";
        counter++;
    }

    // for each expression, make a system call using the labels
    std::cout << "\n# print labels for write statement\n";
    std::cout << ".text\n";
    for (int i = 0; i < counter; i++)
    {
       std::cout << "li \t $v0, 4\n";
       std::cout << "la \t $a0, message" + std::to_string(i) + "\n";
       std::cout << "syscall\n";
    }
}
