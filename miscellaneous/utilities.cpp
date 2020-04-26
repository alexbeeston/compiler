//
// Created by abeeston on 4/25/20.
//

#include "utilities.h"
#include "../global.h"

void copyContinuousMemory(int leftAddress, int rightAddress, int size, Register leftBase, Register rightBase)
{
    Register staging = rp.getRegister();
    static int WORD_SIZE = 4;
    for (int i = 0; i < size; i += WORD_SIZE)
    {
        std::cout << "lw " << staging.getName() << " " << rightAddress + i << "(" << rightBase.getName() << ")   # load continuous memory block\n";
        std::cout << "sw " << staging.getName() << " " << leftAddress + i << "(" << leftBase.getName() << ")   # store continuous memory block\n";
    }
    rp.returnRegister(staging);
    std::cout << "# end continuous memory block copy\n\n";
}
