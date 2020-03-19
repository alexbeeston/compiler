#include <iostream>
#include "../../global.h"
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
    for (Expression* expression : *expressions)
    {
        if (expression->type == 0) std::cout << "li $v0 1   # 1 = system call to print an integer\n";
        else if (expression->type == 1) std::cout << "li $v0 11   # 11 = system call to print an char\n";
        else if (expression->type == 2)std::cout << "li $v0 4   # 4 = system call to print a (label to a) string\n";
        else std::cout << "error: the expression doesn't know if it's an int, char, or string\n";
        Register r = expression->emit();
        std::cout << "la $a0 (" << r.name << ")\n";
        std::cout << "syscall\n\n";
        rp.returnRegister(r);
    }
}
