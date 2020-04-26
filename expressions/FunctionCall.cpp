#include <iostream>
#include <string>
#include <map>
#include "FunctionCall.h"
#include "../global.h"

FunctionCall::FunctionCall(char* p_ident, std::vector<Expression*>* p_params)
{
    ident = new std::string(p_ident);
    params = p_params;
}

void FunctionCall::print()
{
    std::cout << *ident << "(";
    for (Expression* item : *params)
    {
        item->print();
        std::cout << ",";
    }
    std::cout << ")";
}

Register FunctionCall::emit()
{
    // spill registers
    static int WORD_SIZE = 4;
    static int NUM_RESERVED_REGISTERS = 2;
    int spillRegSize = WORD_SIZE * (rp.registersInUse.size() + NUM_RESERVED_REGISTERS);
    auto spilledRegisters = std::map<std::string, int>();
    int spillRegOffset = 0;
    std::cout << "# spill registers\n";
    std::cout << "addi $sp $sp -" << spillRegSize << "\n";
    for (Register reg : rp.registersInUse)
    {
        std::cout << "sw " << reg.getName() << " " << spillRegOffset << "($sp)\n";
        spilledRegisters[reg.getName()] = spillRegOffset;
        spillRegOffset += WORD_SIZE;
    }
    std::string ra_registerName = "$ra";
    std::cout << "sw " << ra_registerName << " " << spillRegOffset << "($sp)\n";
    spilledRegisters[ra_registerName] = spillRegOffset;
    spillRegOffset += WORD_SIZE;

    std::string fp_registerName = "$fp";
    std::cout << "sw " << fp_registerName << " " << spillRegOffset << "($sp)\n";
    spilledRegisters[fp_registerName] = spillRegOffset;

    std::cout << std::endl;
    return rp.getRegister();
}

PrimitiveType FunctionCall::getPrimitiveType()
{
    return INTEGER; // must be replaced by consulting the st for the return type of the
}
