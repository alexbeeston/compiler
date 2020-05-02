#include <iostream>
#include "BinaryOp.h"

BinaryOp::BinaryOp(Expression* p_left, Expression* p_right)
{
    left = p_left;
    right = p_right;
}

void BinaryOp::print()
{
    std::cout << "[binary Op]";
}

std::vector<Register> BinaryOp::emitOperands(PrimitiveType requiredPrimitiveType)
{
    // validate
    if (!(left->resolvePrimitiveType() == requiredPrimitiveType && right->resolvePrimitiveType() == requiredPrimitiveType)) throw std::runtime_error("BinaryOp::emitOperands() - required primitiveType of both operands is " + std::to_string(requiredPrimitiveType) + " but left is " + std::to_string(
                left->resolvePrimitiveType()) + " and right is " + std::to_string(
                right->resolvePrimitiveType()) + ".");

    // continue
    auto registers = std::vector<Register>();
    registers.push_back(processExpression(left, "left"));
    registers.push_back(processExpression(right, "right"));
    return registers;
}

Register BinaryOp::processExpression(Expression* expression, std::string operand)
{
   // validate
   Register reg = expression->emit();
   if (reg.containsAddress) if (reg.space > WORD_SIZE) throw std::runtime_error("BinaryOp::processExpression() - register for " + operand + " operand contains address, but word size is " + std::to_string(reg.space) + ". Expected 4 (the word size)");

   // continue
   if (reg.containsAddress) std::cout << "lw " << reg.getName() << " 0(" << reg.getName() << ")\n";
   reg.containsAddress = false;
   return reg;
}
void BinaryOp::returnRegisters(std::vector <Register> registers)
{
    for (Register r : registers) rp.returnRegister(r);
}

bool BinaryOp::isCTV()
{
    return left->isCTV() && right->isCTV();
}