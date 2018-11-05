##### Configuration

cmake_minimum_required(VERSION 3.9.0)
project(${PROJECT_NAME}_test)

##### Target

add_executable(${PROJECT_NAME}
	${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/test_board.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/test_nim.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/test_minmax.cpp
	${CMAKE_SOURCE_DIR}/source/src/board.cpp
	${CMAKE_SOURCE_DIR}/source/src/nim.cpp
	${CMAKE_SOURCE_DIR}/source/ai/minmax_base.cpp
	${CMAKE_SOURCE_DIR}/source/ai/minmax.cpp
	${CMAKE_SOURCE_DIR}/source/ai/minmax_parallel.cpp
	${CMAKE_SOURCE_DIR}/source/ai/evaluate.cpp)
	
##### Includes

target_include_directories(${PROJECT_NAME}
	PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}/inc
	${CMAKE_SOURCE_DIR}/source/inc
	${CMAKE_SOURCE_DIR}/source/ai)

##### 3rd party

add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/catch)

##### Link

target_link_libraries(
	${PROJECT_NAME}
	Catch
	pthread
)

##### Compile options

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

##### Test

add_test(NAME all COMMAND ${PROJECT_NAME})
