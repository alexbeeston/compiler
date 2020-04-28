//
// Created by abeeston on 4/25/20.
//

#include "utilities.h"
#include "../global.h"

void copyContinuousMemory(int leftOffsetStart, int rightOffsetStart, int size, Register leftBase, Register rightBase)
{
    Register staging = rp.getRegister();
    std::cout << "# begin continuous memory block copy\n";
    for (int i = 0; i < size; i += WORD_SIZE)
    {
        std::cout << "lw " << staging.getName() << " " << rightOffsetStart + i << "(" << rightBase.getName() << ")\n";
        std::cout << "sw " << staging.getName() << " " << leftOffsetStart + i << "(" << leftBase.getName() << ")\n";
    }
    rp.returnRegister(staging);
    std::cout << "# end continuous memory block copy\n";
}

std::map<std::string, int> spillRegisters()
{
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
    return spilledRegisters;
}

void restoreRegisters(std::map<std::string, int> registers)
{
    std::cout << "# restore spilled registers\n";
    for (auto & iterator : registers)
    {
        std::cout << "lw " << iterator.first << " " << iterator.second << "($sp)\n";
    }
    std::cout << "addi $sp $sp " << registers.size() * WORD_SIZE << "\n";
}

