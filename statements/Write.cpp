#include <iostream>
#include "../global.h"
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
    std::cout << "# write\n";
    for (Expression* expression : *expressions)
    {
        if (expression->getTypeIndicator() == INTEGER || expression->getTypeIndicator() == BOOLEAN) std::cout << "li $v0 1   # 1 = system call to print an integer; used for ints and bools\n";
        else if (expression->getTypeIndicator() == CHAR) std::cout << "li $v0 11   # 11 = system call to print an char\n";
        else if (expression->getTypeIndicator() == STRING) std::cout << "li $v0 4   # 4 = system call to print a label to a string\n";
        else throw std::runtime_error("Write::emit() - The expression doesn't know if its an int, char, or string");
        Register r = expression->emit();
        std::cout << "la $a0 (" << r.getName() << ")\n";
        std::cout << "syscall\n";
        rp.returnRegister(r);
    }
}
