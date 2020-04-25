#include <iostream>

#include "BinaryOpUndeterministicOperands.h"

BinaryOpUndeterministicOperands::BinaryOpUndeterministicOperands(Expression* p_l, Expression* p_r):BinaryOp(p_l, p_r)
{
    typeIndicator = BOOLEAN;
}

std::vector<Register> BinaryOpUndeterministicOperands::checkAndEmitOperands()
{
   // verify that operands are the same type
   if (!operandsAreOfSameType())
   {
       std::cout << "Error: Binary Boolean operation attempted with operands of different types. left.typeIndicator = " << left->getTypeIndicator();
       std::cout << ", right.typeIndicator = " << right->getTypeIndicator() << ". They must be the same.\n";
       return std::vector<Register>();
   }
   // verify that the operands are the correct type (integer or boolean)
   if (!(left->getTypeIndicator() == INTEGER || left->typeIndicator == BOOLEAN))
   {
       std::cout << "Error: Binary Boolean operation attempted with operands of the same type, but the wrong type. Their type is " << left->getTypeIndicator() << ". Expected INTEGER or BOOLEAN\n";
       return std::vector<Register>();
   }
   // emit the operands. If they are integers, the registers will hold their integer values, if they are booleans, then they will hold 0 or 1, which are also integers, suitable for comparison
   return emitOperands(left->getTypeIndicator());
}

bool BinaryOpUndeterministicOperands::operandsAreOfSameType()
{
    if (left->getTypeIndicator() == right->getTypeIndicator()) return true;
    else return false;
}
