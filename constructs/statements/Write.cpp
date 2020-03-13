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
    std::cout << ".data\n";
    // for each expression, write out the data
    int counter = 0;
    for (Expression* expression : *expressions)
    {
        std::cout << "message" + std::to_string(counter) + ": .asciiz \"String literal, assuming it's a string type\"\n";
    }
}
