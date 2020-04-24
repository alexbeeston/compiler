cmake_minimum_required(VERSION 2.8)
project(calc)

find_package(BISON)
find_package(FLEX)

bison_target(Parser parser.y ${CMAKE_CURRENT_BINARY_DIR}/parser.cpp)
flex_target(Scanner scanner.l ${CMAKE_CURRENT_BINARY_DIR}/scanner.cpp)
add_flex_bison_dependency(Scanner Parser)

set(EXTRA_COMPILE_FLAGS "-g3 -std=c++14")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${EXTRA_COMPILE_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS}")

set(
		calc_srcs
		main.cpp

		routines/Program.cpp
		miscellaneous/LValue.cpp
		miscellaneous/LValueBase.cpp

        expressions/Literal.cpp
        expressions/Expression.cpp
        expressions/BinaryOp.cpp
        expressions/Or.cpp
        expressions/And.cpp
        expressions/NotEqual.cpp
        expressions/LessThanEqual.cpp
        expressions/GreaterThanEqual.cpp
        expressions/GreaterThan.cpp
        expressions/LessThan.cpp
        expressions/Add.cpp
        expressions/Sub.cpp
        expressions/FunctionCall.cpp
        expressions/Multiply.cpp
        expressions/Divide.cpp
        expressions/Mod.cpp
        expressions/Negate.cpp
        expressions/Negative.cpp
        expressions/ParenExpression.cpp
        expressions/ChrFunc.cpp
        expressions/OrdFunc.cpp
        expressions/PredFunc.cpp
        expressions/SuccFunc.cpp
        expressions/LValueExpression.cpp
        expressions/Equal.cpp
        expressions/BinaryOpUndeterministicOperands.cpp

		types/BaseType.cpp
		types/SimpleType.cpp
		types/ArrayType.cpp
		types/RecordType.cpp
		types/DeclaredType.cpp
		miscellaneous/Constant.cpp
		miscellaneous/Prelude.cpp
		miscellaneous/TypedList.cpp
		symbolTable/Entry.cpp

		routines/Routine.cpp
		routines/Procedure.cpp
		routines/Function.cpp
		routines/ParameterSet.cpp
		routines/Body.cpp
		routines/Block.cpp

		statements/Statement.cpp
		statements/Assignment.cpp
		statements/If.cpp
		statements/ConditionalSequence.cpp
		statements/While.cpp
		statements/Repeat.cpp
		statements/For.cpp
		statements/Stop.cpp
		statements/Return.cpp
		statements/Read.cpp
		statements/Write.cpp
		statements/ProcedureCall.cpp
		statements/NullStatement.cpp

		symbolTable/SymbolTable.cpp
		symbolTable/Scope.cpp

		registerPool/Register.cpp
		registerPool/RegisterPool.cpp

  		${BISON_Parser_OUTPUTS}
		${FLEX_Scanner_OUTPUTS}
		)

source_group("Calc" FILES ${calc_srcs})

add_executable(calc ${calc_srcs})
target_link_libraries(calc ${FLEX_LIBRARIES} ${BISON_LIBRARIES})
target_include_directories(calc PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

