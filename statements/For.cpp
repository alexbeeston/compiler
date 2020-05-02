#include <iostream>
#include <string>

#include "For.h"
#include "../global.h"
#include "../miscellaneous/utilities.h"

For::For(char* p_ident, Expression* p_left, int p_location, Expression* p_right, std::vector<Statement*>* p_statements)
{
    ident = new std::string(p_ident);
    left = p_left;
    location = p_location;
    right = p_right;
    statements = p_statements;
}

void For::print()
{
    std::cout << "FOR " << *ident << " := ";
    left->print();
    std::cout << " ";
    if (location == 0) std::cout << "down to ";
    else std::cout << "to ";
    right->print();
    std::cout << "  ";
    for (Statement* statement : *statements)
    {
        statement->print();
        std::cout << "  ; ";
    }
}

void For::emit()
{
//    st.pushScope_iterator(*ident);

    // init
    std::cout << "\n# For - init\n";
    Register leftBound = left->emit();
    dereferencePointer(leftBound);
    Entry iterator = st.retrieveEntry(*ident);
    std::cout << "sw " << leftBound.getName() << " " << iterator.offset << "(" << iterator.baseRegister.getName() << ")\n";
    rp.returnRegister(leftBound);
    Register rightBound = right->emit();
    dereferencePointer(rightBound);
    std::cout << "addi " << rightBound.getName() << " " << rightBound.getName() << " ";
    if (location == 0) std::cout << "-1\n";
    else std::cout << "1\n";

    // test
    std::string testLabel = st.getNextForLabel();
    std::string nextLabel = st.getNextNextLabel();
    Register iteratorValue = rp.getRegister();
    std::cout << "\n# For - test\n";
    std::cout << testLabel << ":\n";
    std::cout << "lw " << iteratorValue.getName() << " " << iterator.offset << "(" << iterator.baseRegister.getName() << ")\n";
    std::cout << "beq " << iteratorValue.getName() << " " << rightBound.getName() << " " << nextLabel << "\n";
    rp.returnRegister(iteratorValue);

    // body
    std::cout << "\n# For - body\n";
    for (Statement* statement : *statements) statement->emit();

    // update
    std::cout << "\n# For - update\n";
    Register iteratorValue_again = rp.getRegister();
    std::cout << "lw " << iteratorValue_again.getName() << " " << iterator.offset << "(" << iterator.baseRegister.getName() << ")\n";
    std::cout << "addi " << iteratorValue_again.getName() << " " << iteratorValue_again.getName() << " ";
    if (location == 0) std::cout << "-1\n";
    else std::cout << "1\n";
    std::cout << "sw " << iteratorValue_again.getName() << " " << iterator.offset << "(" << iterator.baseRegister.getName() << ")\n";
    std::cout << "j " << testLabel << "\n";
    rp.returnRegister(iteratorValue_again);
    rp.returnRegister(rightBound);

    // next
    std::cout << "\n# For - next\n";
    std::cout << nextLabel << ":\n";
//    st.popScope();
}
