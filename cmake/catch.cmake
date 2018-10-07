
	include(ExternalProject)
	find_package(Git REQUIRED)
	
	list(APPEND CATCH_CMAKE_ARGS
	    "-DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}"
	)
	
	ExternalProject_Add(
	    catch
	    GIT_REPOSITORY      https://github.com/catchorg/Catch2.git
	    GIT_TAG             v2.4.1
	    GIT_SHALLOW         1
	    CMAKE_ARGS          ${CATCH_CMAKE_ARGS}
	    PREFIX              ${CMAKE_BINARY_DIR}/external/catch/prefix
	    TMP_DIR             ${CMAKE_BINARY_DIR}/external/catch/tmp
	    STAMP_DIR           ${CMAKE_BINARY_DIR}/external/catch/stamp
	    DOWNLOAD_DIR        ${CMAKE_BINARY_DIR}/external/catch/download
	    SOURCE_DIR          ${CMAKE_BINARY_DIR}/external/catch/src
	    BINARY_DIR          ${CMAKE_BINARY_DIR}/external/catch/build
	)
