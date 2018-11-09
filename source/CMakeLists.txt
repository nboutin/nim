##### Configuration

cmake_minimum_required(VERSION 3.9.0)

##### Target

add_executable(${PROJECT_NAME}
	${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/menu_view.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/nim.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/board.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/view_ascii.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/ai/minmax_base.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/ai/minmax.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/ai/minmax_parallel.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/ai/evaluate.cpp)

##### Include

target_include_directories(${PROJECT_NAME}
	PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}/inc
	${CMAKE_CURRENT_SOURCE_DIR}/ai)

##### 3rd party

##### Configure

configure_file(
	${CMAKE_CURRENT_SOURCE_DIR}/conf/version
	${CMAKE_CURRENT_SOURCE_DIR}/inc/version.h)

##### Link

target_link_libraries(${PROJECT_NAME} pthread ncurses)

##### Compile options

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

##### Install

#install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

