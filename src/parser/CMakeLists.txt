cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

ADD_STATIC_LIB(ParserLib parser.cpp parser.hpp)

target_link_libraries(
		ParserLib 

		PUBLIC
			StructLib
)