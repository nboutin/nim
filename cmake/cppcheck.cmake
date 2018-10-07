
if(ENABLE_CPPCHECK)
	include(ExternalProject)
	find_package(Git REQUIRED)
	
	list(APPEND CPPCHECK_CMAKE_ARGS
	        "-DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}"
	)
	
	ExternalProject_Add(
	    cppcheck
	    GIT_REPOSITORY      https://github.com/danmar/cppcheck.git
	    GIT_TAG             1.84
	    GIT_SHALLOW         1
	    CMAKE_ARGS          ${CPPCHECK_CMAKE_ARGS}
	    PREFIX              ${CMAKE_BINARY_DIR}/external/cppcheck/prefix
	    TMP_DIR             ${CMAKE_BINARY_DIR}/external/cppcheck/tmp
	    STAMP_DIR           ${CMAKE_BINARY_DIR}/external/cppcheck/stamp
	    DOWNLOAD_DIR        ${CMAKE_BINARY_DIR}/external/cppcheck/download
	    SOURCE_DIR          ${CMAKE_BINARY_DIR}/external/cppcheck/src
	    BINARY_DIR          ${CMAKE_BINARY_DIR}/external/cppcheck/build
	)
	
	list(APPEND CPPCHECK_ARGS
	    --enable=warning,style,performance,portability,unusedFunction
	    --std=c++11
	    --verbose
	    --error-exitcode=1
	    --language=c++
	    -DMAIN=main
	    -I ${CMAKE_SOURCE_DIR}/source/*
	    # ${CMAKE_SOURCE_DIR}/test/*
	)
	
	add_custom_target(
	    check
	    COMMAND ${CMAKE_BINARY_DIR}/bin/cppcheck ${CPPCHECK_ARGS}
	    COMMENT "running cppcheck"
	)
endif()

