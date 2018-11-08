##### Configuration

cmake_minimum_required(VERSION 3.9.0)
project(nim 
	VERSION 1.0.0
	DESCRIPTION	"Nim board game"
	LANGUAGES CXX)

##### Configure

configure_file(conf/VERSION ${CMAKE_SOURCE_DIR}/VERSION.md)

##### Compile options

add_compile_options(-Wall -Werror -Wextra -Wpedantic -Wnon-virtual-dtor -Wshadow -Weffc++ -Wold-style-cast)

add_compile_options(-Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2
	-Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wnoexcept
	-Woverloaded-virtual -Wredundant-decls -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel
	-Wswitch-default -Wundef -Wno-unused -Wfatal-errors)

##### Source

add_subdirectory(source)

##### Test

if(ENABLE_TEST)
	enable_testing()
	include(CTest)
	add_subdirectory(test)
endif()

##### Continuous Integration

include(cmake/cppcheck.cmake)
include(cmake/clang_tidy.cmake)
include(cmake/google_sanitizers.cmake)
