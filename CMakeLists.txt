##### Configuration

cmake_minimum_required(VERSION 3.0.0)
project(nim)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/output)

##### Configure

set(MAJOR 1)
set(MINOR 0)
set(PATCH 0)

configure_file(
	${CMAKE_CURRENT_SOURCE_DIR}/conf/VERSION
	${CMAKE_CURRENT_SOURCE_DIR}/VERSION
)

##### Source

add_subdirectory(source)

##### Test

add_subdirectory(test)

##### Continuous Integration

include(cmake/cppcheck.cmake)
include(cmake/clang_tidy.cmake)
include(cmake/google_sanitizers.cmake)
