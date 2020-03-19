#include <iostream>
#include "../../global.h"
#include "Read.h"

Read::Read(LValue* p_lValue, std::vector<LValue*>* p_lvals)
{
    lValues = new std::vector<LValue*> {p_lValue};
    for (LValue* lVal : *p_lvals) lValues->push_back(lVal);
}

void Read::print()
{
    std::cout << "read(";
    for (LValue* lVal : *lValues)
    {
        lVal->print();
        std::cout << ",";
    }
    std::cout << ")";
}

void Read::emit()
{
    for (LValue* lValue : *lValues)
    {
        std::cout << "li $v0 ";
        Variable v = st.retrieveVariable(lValue->getKey());
        if (v.expression.type == 0) std::cout << " 5   # 5 = code to read an integer\n";
        else if (v.expression.type == 1) std::cout << " 12   # 12 = code to read a character\n";
        else throw "attempting to read a non-integer or character lValue\n";
        std::cout << "syscall\n";
        Register r = rp.getRegister();
        std::cout << "move " << r.name << " $v0\n";
        std::cout << "sw " << r.name << " " << v.offset << "(" << v.baseRegister << ")\n\n";
    }
}