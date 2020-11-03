cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

##################################GTest##############################

# Now simply link against gtest or gtest_main as needed. Eg
add_executable(test_LexerLib test_lex.cpp)
add_executable(test_ParserLib test_pars.cpp)

target_link_libraries(
	test_LexerLib 
		
		PRIVATE
			gtest_main
			LexerLib
			StructLib
)

target_link_libraries(
	test_ParserLib

		PRIVATE
			gtest_main
			ParserLib
			StructLib
)

add_test(NAME example_test_one COMMAND test_LexerLib)
add_test(NAME example_test_two COMMAND test_ParserLib)
