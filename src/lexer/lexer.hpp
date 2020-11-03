#pragma once

#include <iostream>
#include <string>
#include <string.h>
#include "struct.hpp"

class Lexer
{

public:
	Lexer() = default;
	~Lexer() = default;

	void line_processing(std::string Line, int line_number, int flag_end, std::vector<Token>& VectorToken);

	//processing operator
	void processing_of_complex_znak(Token &znak, std::string& Line, size_t& line_identifier, Token::Words token_complex_type, Token::Words token_type);
	Token znak_processing(std::string& Line, size_t& line_identifier);

	//processing sybmol
	bool is_letter(char ch)
	{
		char symbol = std::tolower(ch);
		if ('a' <= symbol && symbol <= 'z') return true;
		return false;
	}
	Token word_processing(std::string& Line, size_t& line_identifier);
	Token::Words check_keyword(std::string& str);

	//processing digit
	bool is_digit(char ch)
	{
		if ('0' <= ch && ch <= '9') return true;
		return false;
	}
	Token digit_processing(std::string& Line, size_t& line_identifier);

	//processing unexpected
	Token unexpected_processing(std::string& Line, size_t& line_identifier);
};