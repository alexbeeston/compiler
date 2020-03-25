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
    std::cout << "# write\n";
    for (Expression* expression : *expressions)
    {
        if (expression->getTypeIndicator() == 0 || expression->getTypeIndicator() == 3) std::cout << "li $v0 1   # 1 = system call to print an integer; used for ints and bools\n";
        else if (expression->getTypeIndicator() == 1) std::cout << "li $v0 11   # 11 = system call to print an char\n";
        else if (expression->getTypeIndicator() == 2) std::cout << "li $v0 4   # 4 = system call to print a label to a string\n";
        else std::cout << "error: the expression doesn't know if its an int, char, or string (Inside Write::emit(); check the typeIndicator for an expression or one of its derived structs): VALUE: " << expression->typeIndicator << "\n";
        Register r = expression->emit();
        std::cout << "la $a0 (" << r.getName() << ")\n";
        std::cout << "syscall\n\n";
        rp.returnRegister(r);
    }
}
