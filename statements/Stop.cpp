#include <iostream>

#include "Stop.h"

Stop::Stop()
{

}

void Stop::print()
{
    std::cout << "stop";
}

void Stop::emit()
{
    std::cout << "# stop\n";
    std::cout << "li $v0 10\n";
    std::cout << "syscall\n\n";
}
