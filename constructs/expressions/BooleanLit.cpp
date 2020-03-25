#include <iostream>

#include "BooleanLit.h"
#include "../../global.h"

BooleanLit::BooleanLit(int p_value)
{
    typeIndicator = 3;
    value = p_value;
}

Register BooleanLit::emit()
{
    Register r = rp.getRegister();
    std::cout << "li " << r.getName() << " " << value << "\n";
    return r;
}