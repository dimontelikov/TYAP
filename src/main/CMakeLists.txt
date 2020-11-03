cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

list(APPEND LibList StructLib)
list(APPEND LibList LexerLib)
list(APPEND LibList ParserLib)
list(APPEND LibList cxxopts)

if(CXXOPTS_BUILD_EXAMPLES)

	message("INPUT!!!")
	add_executable(Compiler main.cpp)

	target_link_libraries(
		Compiler 

		PUBLIC
			${LibList}
	)

	target_include_directories(
		Compiler

		PUBLIC 
			${PROJECT_BINARY_DIR}
		
		INTERFACE 
			${CMAKE_CURRENT_SOURCE_DIR}
	)
endif()