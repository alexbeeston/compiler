#include <iostream>
#include "Return.h"
#include "../miscellaneous/utilities.h"
#include "../global.h"

Return::Return() { expression = nullptr; }

Return::Return(Expression* p_expression) { expression = p_expression; }

void Return::emit()
{
    Register expressionRegister = expression->emit();
    Register framePointer = rp.getFramePointer();
    if (expressionRegister.containsAddress) copyContinuousMemory(0, expressionRegister, 0, framePointer, expressionRegister.space);
    else std::cout << "sw " << expressionRegister.getName() << " 0(" << framePointer.getName() << ")\n";
    if (st.sizeOfLocalVars != 0) moveStackPointerUp(st.sizeOfLocalVars);
    std::cout << "jr $ra\n";
    rp.returnRegister(expressionRegister);
}

void Return::print()
{
    std::cout << "return ";
    if (expression != nullptr) expression->print();
}