
if(ENABLE_CLANG_TIDY)
	find_program(CLANG_TIDY_BIN clang-tidy-6.0)
	find_program(RUN_CLANG_TIDY_BIN run-clang-tidy-6.0.py)

	if(CLANG_TIDY_BIN STREQUAL "CLANG_TIDY_BIN-NOTFOUND")
	    message(FATAL_ERROR "unable to locate clang-tidy-6.0")
	endif()

	if(RUN_CLANG_TIDY_BIN STREQUAL "RUN_CLANG_TIDY_BIN-NOTFOUND")
	    message(FATAL_ERROR "unable to locate run-clang-tidy-6.0.py")
	endif()

	list(APPEND RUN_CLANG_TIDY_BIN_ARGS
	    -clang-tidy-binary ${CLANG_TIDY_BIN}
	    -header-filter=.*
	    -checks=clan*,cert*,misc*,perf*,cppc*,read*,mode*,-cert-err58-cpp,-misc-noexcept-move-constructor
	)

	add_custom_target(
	    tidy
	    COMMAND ${RUN_CLANG_TIDY_BIN} ${RUN_CLANG_TIDY_BIN_ARGS}
	    COMMENT "running clang tidy"
	)
endif()
