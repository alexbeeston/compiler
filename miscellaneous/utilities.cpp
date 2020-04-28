//
// Created by abeeston on 4/25/20.
//

#include "utilities.h"
#include "../global.h"

void copyContinuousMemory(int leftOffsetStart, int rightOffsetStart, int size, Register leftBase, Register rightBase)
{
    Register staging = rp.getRegister();
    static int WORD_SIZE = 4;
    std::cout << "# begin continuous memory block copy\n";
    for (int i = 0; i < size; i += WORD_SIZE)
    {
        std::cout << "lw " << staging.getName() << " " << rightOffsetStart + i << "(" << rightBase.getName() << ")\n";
        std::cout << "sw " << staging.getName() << " " << leftOffsetStart + i << "(" << leftBase.getName() << ")\n";
    }
    rp.returnRegister(staging);
    std::cout << "# end continuous memory block copy\n";
}
