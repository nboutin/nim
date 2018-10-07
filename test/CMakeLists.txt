##### Coniguration

cmake_minimum_required(VERSION 3.0.0)
project(nim_test)

##### 3rd party

##### Compilation

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=gnu++17")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")

##### Includes

include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}/inc
	${CMAKE_SOURCE_DIR}/source/inc
	${CMAKE_SOURCE_DIR}/source/ai
	${CMAKE_BINARY_DIR}/include/catch2
)

##### Sources

set(SOURCE 
	${CMAKE_SOURCE_DIR}/source/src/board.cpp
	${CMAKE_SOURCE_DIR}/source/src/nim.cpp
	${CMAKE_SOURCE_DIR}/source/ai/minmax_base.cpp
	${CMAKE_SOURCE_DIR}/source/ai/minmax.cpp
	${CMAKE_SOURCE_DIR}/source/ai/minmax_parallel.cpp
	${CMAKE_SOURCE_DIR}/source/ai/evaluate.cpp
)

##### Target

enable_testing()
include(CTest)

add_library(test_catch STATIC ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)
add_dependencies(test_catch catch)

add_library(business_logic STATIC ${SOURCE})
# add_dependencies(business_logic gsl)
# target_compile_definitions(business_logic PRIVATE VIRTUAL=virtual MAIN=unittest_main)

macro(do_test str)
    add_executable(test_${str} ${CMAKE_CURRENT_SOURCE_DIR}/src/test_${str}.cpp)
    add_test(test_${str} test_${str})
    target_link_libraries(test_${str} test_catch)
    target_link_libraries(test_${str} business_logic pthread)
    # add_dependencies(test_${str} gsl)
    add_dependencies(test_${str} catch)
    # add_dependencies(test_${str} hippomocks)
    target_compile_definitions(test_${str} PRIVATE VIRTUAL=virtual)
endmacro(do_test)

do_test(board)
do_test(nim)
do_test(minmax)

