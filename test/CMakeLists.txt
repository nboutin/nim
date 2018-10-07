##### Coniguration

cmake_minimum_required(VERSION 3.0.0)
project(nim_test)

##### 3rd party

# Prepare "Catch" library for other executables
set(CATCH_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/catch)
add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE ${CATCH_INCLUDE_DIR})

##### Includes

include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}/inc
	${CMAKE_SOURCE_DIR}/source/inc
	${CMAKE_SOURCE_DIR}/source/ai
)

##### Sources

set(SOURCE 
	${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/test_board.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/test_nim.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/test_minmax.cpp
	${CMAKE_SOURCE_DIR}/source/src/board.cpp
	${CMAKE_SOURCE_DIR}/source/src/nim.cpp
	${CMAKE_SOURCE_DIR}/source/ai/minmax.cpp
	${CMAKE_SOURCE_DIR}/source/ai/minmax_parallel.cpp
	${CMAKE_SOURCE_DIR}/source/ai/evaluate.cpp
)

##### Compilation

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=gnu++17")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")

##### Target

add_executable(${PROJECT_NAME} ${SOURCE})

target_link_libraries(
	${PROJECT_NAME}
	Catch
	pthread
)
