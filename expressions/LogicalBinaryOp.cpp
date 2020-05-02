#include <iostream>

#include "LogicalBinaryOp.h"

LogicalBinaryOp::LogicalBinaryOp(Expression* p_l, Expression* p_r): BinaryOp(p_l, p_r)
{
    primitiveType = BOOLEAN;
}

std::vector<Register> LogicalBinaryOp::checkAndEmitOperands()
{
    // validate
    PrimitiveType leftPrimitiveType = left->resolvePrimitiveType();
    PrimitiveType rightPrimitiveType = right->resolvePrimitiveType();
    if (leftPrimitiveType != rightPrimitiveType) throw std::runtime_error("LogicalBinaryOp::checkAndEmitOperands() - operand types don't match. Left is " + std::to_string(leftPrimitiveType) + " and right is " + std::to_string(rightPrimitiveType) + ".");
    if (!(leftPrimitiveType == INTEGER || leftPrimitiveType == BOOLEAN)) throw std::runtime_error("LogicalBinaryOp::emit() - operands are of same primitive type, but not INTEGER nor BOOLEAN. They are " + std::to_string(leftPrimitiveType) + ".");

    // continue
    return emitOperands(leftPrimitiveType);
}
