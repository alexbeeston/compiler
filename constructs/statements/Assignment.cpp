#include <iostream>
#include <string>

#include "../../global.h"
#include "Assignment.h"

Assignment::Assignment(LValue* p_lValue, Expression* p_expression)
{
    lValue = p_lValue;
    expression = p_expression;
}

void Assignment::print()
{
    lValue->print();
    std::cout << ":=";
    expression->print();
}

void Assignment::emit()
{
    // load the Entry
    Entry entry = st.retrieveEntry(lValue->getKey());
    if (entry.offset == -1) throw std::runtime_error("Can not assign to a constant\n");
    if (lValue->getStyle() != expression->getStyle()) throw std::runtime_error("Assignment::emit() - styles of LValue and Expression in an assignment do not match.");
    std::cout << "# assignment\n";
    int offset = lValue->getOffset();
    Register baseRegister = lValue->getBaseRegister();

    // emit for a primitive type (check type indicators later, now that we've established they're both primitive types
    Register r = expression->emit();
    std::cout << "sw " << r.getName() << " " << offset << "(" << baseRegister.getName() << ")\n\n";
    rp.returnRegister(r);
    if (baseRegister.getName().compare("$gp") != 0) rp.returnRegister(baseRegister);

    // emit for an array type
}

