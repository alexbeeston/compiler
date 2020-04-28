#ifndef COMPILERS_GLOBALS_H
#define COMPILERS_GLOBALS_H

#include "registerPool/RegisterPool.h"
#include "symbolTable/SymbolTable.h"

extern int lineNumber;
extern RegisterPool rp;
extern SymbolTable st;
static int WORD_SIZE = 4;

#endif // COMPILERS_GLOBALS_H
