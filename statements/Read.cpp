#include <iostream>
#include "../global.h"
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
        BaseType* entryType = st.retrieveEntry(lValue->getKey()).type;
        if (entryType->getTypeIndicator() == INTEGER) std::cout << " 5   # 5 = code to read an integer\n";
        else if (entryType->getTypeIndicator() == CHAR) std::cout << " 12   # 12 = code to read a character\n";
        else throw "attempting to read a non-integer or character lValue\n";
        std::cout << "syscall\n";
        Register r = rp.getRegister();
        std::cout << "move " << r.getName() << " $v0\n";
        int offset = lValue->getOffset();
        Register baseRegister = lValue->getBaseRegister();
        std::cout << "sw " << r.getName() << " " << offset << "(" << baseRegister.getName() << ")\n\n";
        rp.returnRegister(r);
        if (baseRegister.getName().compare("$gp") != 0) rp.returnRegister(baseRegister);
    }
}