cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

ADD_STATIC_LIB(LexerLib lexer.cpp lexer.hpp)

target_link_libraries(
		LexerLib 

		PUBLIC
			StructLib
)