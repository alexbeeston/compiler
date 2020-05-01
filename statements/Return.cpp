#include <iostream>

#include "Return.h"
#include "../miscellaneous/utilities.h"
#include "../global.h"

Return::Return() { expression = nullptr; }
Return::Return(Expression* p_expression) { expression = p_expression; }

void Return::emit()
{
    Register value = expression->emit();
    Register framePointer = rp.getFramePointer();
    if (!value.containsAddress) std::cout << "sw " << value.getName() << " 0(" << framePointer.getName() << ")\n";
    else { throw std::runtime_error("return::emit() - not implemented if it contains an address"); }
}

void Return::print()
{
    std::cout << "return ";
    if (expression != nullptr) expression->print();
}