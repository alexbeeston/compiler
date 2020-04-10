#include <iostream>
#include <string>

#include "For.h"
#include "../../global.h"

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
    // init
    std::cout << "\n# For - init\n";
    Register bound = left->emit();
    int addressOfIterator;
    if (st.containsEntry(*ident)) addressOfIterator = st.retrieveEntry(*ident).offset;
    else
    {
        addressOfIterator = st.getNextAvailableAddress();
        st.incrementNextAvailableAddress(4);
    }
    std::cout << "sw " << bound.getName() << " " << addressOfIterator << "($gp)\n";
    bound = right->emit();
    std::cout << "addi " << bound.getName() << " " << bound.getName() << " ";
    if (location == 0) std::cout << "-1\n";
    else std::cout << "1\n";


}
