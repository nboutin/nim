##### Configuration

cmake_minimum_required(VERSION 3.0.0)
project(nim)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/output)

##### Configure

set(MAJOR 0)
set(MINOR 3)
set(PATCH 0)

configure_file(
	${CMAKE_CURRENT_SOURCE_DIR}/conf/VERSION
	${CMAKE_CURRENT_SOURCE_DIR}/VERSION
)

##### Source

add_subdirectory(source)

##### Test

add_subdirectory(test)
