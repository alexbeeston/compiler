#include <iostream>

#include "BinaryOpUndeterministicOperands.h"

BinaryOpUndeterministicOperands::BinaryOpUndeterministicOperands(Expression* p_l, Expression* p_r):BinaryOp(p_l, p_r)
{
    typeIndicator = 3;
}

std::vector<Register> BinaryOpUndeterministicOperands::checkAndEmitOperands()
{
   // verify that operands are the same type
   if (left->typeIndicator != right->typeIndicator)
   {
       std::cout << "Error: Binary Boolean operation attempted with operands of different types. left.typeIndicator = " << left->typeIndicator;
       std::cout << ", right.typeIndicator = " << right->typeIndicator << ". They must be the same.\n";
       return std::vector<Register>();
   }
   // verify that the operands are the correct type (integer or boolean)
   if (!(left->typeIndicator == 0 || left->typeIndicator == 3))
   {
       std::cout << "Error: Binary Boolean operation attempted with operands of the same type, but the wrong type. Their type is " << left->typeIndicator << ". Expected 0 or 3.\n";
       return std::vector<Register>();
   }
   // emit the operands. If they are integers, the registers will hold their integer values, if they are booleans, then they will hold 0 or 1, which are also integers, suitable for comparison
   return emitOperands(left->typeIndicator);
}

