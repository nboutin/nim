
# Add catch target
add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE external/catch2)
target_compile_features(Catch INTERFACE cxx_std_11)

# Create library for business logic
add_library(business_logic SHARED
	${CMAKE_SOURCE_DIR}/source/src/board.cpp
	${CMAKE_SOURCE_DIR}/source/src/nim.cpp
	${CMAKE_SOURCE_DIR}/source/ai/minmax_base.cpp
	${CMAKE_SOURCE_DIR}/source/ai/minmax.cpp
	${CMAKE_SOURCE_DIR}/source/ai/minmax_parallel.cpp
	${CMAKE_SOURCE_DIR}/source/ai/evaluate.cpp)

if(ENABLE_COVERAGE)
	# TODO check that we use build_type = Debug
	target_compile_options(business_logic PRIVATE -g -O0 -fprofile-arcs -ftest-coverage --coverage)
	target_link_libraries(business_logic PRIVATE gcov)
endif()

target_include_directories(business_logic
	PUBLIC
	${CMAKE_SOURCE_DIR}/source/inc
	${CMAKE_SOURCE_DIR}/source/ai)
set_target_properties(business_logic PROPERTIES LINKER_LANGUAGE CXX)
target_compile_features(business_logic PUBLIC cxx_std_17)
target_link_libraries(business_logic PRIVATE pthread)

# arg: name test
function(make_test arg)
	add_executable(test_${arg} src/main.cpp src/test_${arg}.cpp)
	target_link_libraries(test_${arg} PRIVATE Catch business_logic)
	add_test(NAME test_${arg} COMMAND test_${arg})
endfunction()

# Add test
make_test(board)
make_test(minmax)
make_test(nim)
