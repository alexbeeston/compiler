//
// Created by abeeston on 4/25/20.
//

#include "utilities.h"
#include "../global.h"

void dereferencePointer(Register reg)
{
    if (reg.containsAddress)
    {
        std::cout << "lw " << reg.getName() << " 0(" << reg.getName() << ")\n";
        reg.containsAddress = false;
    }
}
void copyContinuousMemory(int targetOffsetStart, int sourceOffsetStart, int size, Register targetBase, Register sourceBase)
{
    Register staging = rp.getRegister();
    std::cout << "# begin continuous memory block copy\n";
    for (int i = 0; i < size; i += WORD_SIZE)
    {
        std::cout << "lw " << staging.getName() << " " << sourceOffsetStart + i << "(" << sourceBase.getName() << ")\n";
        std::cout << "sw " << staging.getName() << " " << targetOffsetStart + i << "(" << targetBase.getName() << ")\n";
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
    std::cout << "# Spill Registers\n";
    moveStackPointerDown(spillRegSize);
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
    return spilledRegisters;
}

void restoreSpilledRegisters(std::map<std::string, int> registers)
{
    std::cout << "# Restore Spilled Registers\n";
    for (auto & iterator : registers)
    {
        std::cout << "lw " << iterator.first << " " << iterator.second << "($sp)\n";
    }
    moveStackPointerUp(registers.size() * WORD_SIZE);
    std::cout << std::endl;
}

void addParametersToStack(std::string routineName, std::vector<Expression*> expressions)
{
    // validate
    auto routine = st.retrieveRoutine(routineName);
    if (routine->offsets.size() != expressions.size()) throw std::runtime_error("addParametersToStack() - expected " + std::to_string(routine->offsets.size()) + " parameters, received " + std::to_string(expressions.size()) + " parameters");
    int numParameters = expressions.size();

    // continue
    std::cout << "# Add Parameters To Stack\n";
    moveStackPointerDown(routine->sizeOfParametersAndReturnType);
    for (int i = 0; i < numParameters; ++i)
    {
        // assume that everything is passed by value for now
        // if pass by reference, (validate something)
        // la staging.getName() offset(base)
        Register staging = expressions[i]->emit();
        std::cout << "sw " << staging.getName() << " " << routine->offsets[i] << "($sp)\n";
        rp.returnRegister(staging);
    }
    std::cout << std::endl;
}

void moveStackPointerUp(int size)
{
    std::cout << "addi $sp $sp " << size << "\n";
}

void moveStackPointerDown(int size)
{
    std::cout << "addi $sp $sp -" << size << "\n";
}
