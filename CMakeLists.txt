##### Configuration

cmake_minimum_required(VERSION 3.9.0)
project(nim 
	VERSION 1.0.0
	DESCRIPTION	"Nim board game"
	LANGUAGES CXX
)

##### Configure

configure_file(
	${CMAKE_CURRENT_SOURCE_DIR}/conf/VERSION
	${CMAKE_CURRENT_SOURCE_DIR}/VERSION
)

##### Compile options

add_compile_options(-Wall -Wextra -Wpedantic -Werror)

##### Source

add_subdirectory(source)

##### Test

add_subdirectory(test)

##### Continuous Integration

include(cmake/catch.cmake)
include(cmake/cppcheck.cmake)
include(cmake/clang_tidy.cmake)
include(cmake/google_sanitizers.cmake)
