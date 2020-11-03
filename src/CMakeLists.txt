cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

function(ADD_STATIC_LIB NAMELIB NAMEBIN NAMEZ)
	add_library(${NAMELIB} STATIC ${NAMEBIN} ${NAMEZ})

	target_include_directories(
		${NAMELIB} 

		INTERFACE
			${CMAKE_CURRENT_SOURCE_DIR}
	)
endfunction()

add_subdirectory(struct)
add_subdirectory(lexer)
add_subdirectory(parser)
add_subdirectory(main)