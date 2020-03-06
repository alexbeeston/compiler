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

set(calc_srcs
  main.cpp
  symbol_table.hpp
  symbol_table.cpp
  ${BISON_Parser_OUTPUTS}
  ${FLEX_Scanner_OUTPUTS}
		constructs/
		constructs/Program.cpp
		constructs/LValue.cpp
		constructs/expressions/StringLit.cpp
		constructs/expressions/Expression.cpp
		constructs/expressions/CharLit.cpp
		constructs/expressions/NumericLit.cpp
		constructs/expressions/Or.cpp
		constructs/expressions/And.cpp
		constructs/expressions/NotEqual.cpp
		constructs/expressions/LessThanEqual.cpp
		constructs/expressions/GreaterThanEqual.cpp
		constructs/expressions/GreaterThan.cpp
		constructs/expressions/LessThan.cpp


		constructs/prelude/types/BaseType.cpp
		constructs/prelude/types/SimpleType.cpp
		constructs/prelude/types/ArrayType.cpp
		constructs/prelude/types/RecordType.cpp
		constructs/prelude/types/TypeDeclItem.cpp
		constructs/prelude/constants/Constant.cpp
		constructs/prelude/Prelude.cpp
		constructs/prelude/TypedList.cpp
        	constructs/routines/Routine.cpp
		constructs/routines/Procedure.cpp
		constructs/routines/Function.cpp
		constructs/routines/ParameterSet.cpp
		constructs/routines/Body.cpp
		constructs/routines/Block.cpp
		constructs/statements/Statement.cpp
		constructs/statements/Assignment.cpp
		constructs/statements/If.cpp
		constructs/statements/ConditionalSequence.cpp
		constructs/statements/While.cpp
		constructs/statements/Repeat.cpp
		constructs/statements/For.cpp
		constructs/statements/Stop.cpp
		constructs/statements/Return.cpp
		constructs/statements/Read.cpp
		constructs/statements/Write.cpp
		constructs/statements/ProcedureCall.cpp
		constructs/statements/NullStatement.cpp
		)
source_group("Calc" FILES ${calc_srcs})

add_executable(calc ${calc_srcs})
target_link_libraries(calc ${FLEX_LIBRARIES} ${BISON_LIBRARIES})
target_include_directories(calc PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

