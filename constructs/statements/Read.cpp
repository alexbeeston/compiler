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
    std::cout << "# read\n";
    for (LValue* lValue : *lValues)
    {
        std::cout << "li $v0 ";
        Entry v = st.retrieveEntry(lValue->getKey());
        if (v.type->getTypeIndicator() == INTEGER) std::cout << " 5   # 5 = code to read an integer\n";
        else if (v.type->getTypeIndicator() == CHAR) std::cout << " 12   # 12 = code to read a character\n";
        else throw "attempting to read a non-integer or character lValue\n";
        std::cout << "syscall\n";
        Register r = rp.getRegister();
        std::cout << "move " << r.getName() << " $v0\n";
        Register baseRegister = lValue->loadBaseRegister();
        std::cout << "sw " << r.getName() << " " << v.offset << "(" << baseRegister.getName() << ")\n\n";
        rp.returnRegister(r);
        rp.returnRegister(baseRegister);
    }
}