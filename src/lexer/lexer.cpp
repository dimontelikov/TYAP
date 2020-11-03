#include "lexer.hpp"

using namespace std;

void Lexer::line_processing(std::string Line, int line_number, int flag_end, std::vector<Token> &VectorToken)
{
	size_t line_identifier = 0;

	if (flag_end) return;

	//cout << "str num:" << line_number << endl;
	while (Line.size() > line_identifier)
	{
		if (strchr("+-/*()^", Line[line_identifier]))
		{
			auto znak = znak_processing(Line, line_identifier);
			znak.set_str_number(line_number);
			znak.set_col_number(line_identifier);
			VectorToken.push_back(znak);
			// 1 обработка знаков
		}
		else if (is_letter(Line[line_identifier]))
		{	
			auto word = word_processing(Line, line_identifier);
			word.set_str_number(line_number);
			word.set_col_number(line_identifier);
			VectorToken.push_back(word);
			// 2 обработка ключевых слов, id
		}
		else if (is_digit(Line[line_identifier]))
		{
			auto digit = digit_processing(Line, line_identifier);
			digit.set_str_number(line_number);
			digit.set_col_number(line_identifier);
			VectorToken.push_back(digit);
			// 3 обработка чисел
		}
		else if (line_identifier < Line.size() && Line[line_identifier] == ' '); // space skip
		else
		{
			auto unexpected = unexpected_processing(Line, line_identifier);
			unexpected.set_str_number(line_number);
			unexpected.set_col_number(line_identifier);
			VectorToken.push_back(unexpected);

			// 6 обработка неизвестного токена 
		}
		//cout << "line_identifier = " << line_identifier << endl;
		line_identifier++;
	}
}

Token Lexer::unexpected_processing(string& Line, size_t& line_identifier)
{
	Token unexpected;
	string str = "";

	size_t size_str = 0;
	size_t start_str = line_identifier;

	if (Line.size() == 1)
	{
		unexpected.set_token_type(Token::Words::Unexpected);
		unexpected.set_string(Line.substr(0, 1));
		return unexpected;
	}

	while(line_identifier < Line.size() && Line[line_identifier] != ' ')
	{
		line_identifier++;
		size_str++;
	}

	if (line_identifier != Line.size())
		line_identifier--;// because read last symbol 

	str = Line.substr(start_str, size_str);
	unexpected.set_token_type(Token::Words::Unexpected);
	unexpected.set_string(str);
	return unexpected;
}

Token Lexer::digit_processing(string& Line, size_t& line_identifier)
{
	Token digit;
	string str = "";
	size_t size_str = 0;
	size_t start_str = line_identifier;
	bool flag_notint = false;

	if (Line.size() == 1)
	{
		digit.set_token_type(Token::Words::Number);
		digit.set_string(Line.substr(0, 1));
		return digit;
	}

	while(line_identifier < Line.size() && is_digit(Line[line_identifier]))
	{
		line_identifier++;
		size_str++;
		if (line_identifier < Line.size() && !flag_notint && Line[line_identifier] == '.')
		{
			line_identifier++;
			size_str++;
			flag_notint = true;
		}
	}

	line_identifier--;// because read last symbol 

	str = Line.substr(start_str, size_str);
	digit.set_token_type(Token::Words::Number);
	digit.set_string(str);
	return digit;
}

Token Lexer::word_processing(string& Line, size_t& line_identifier)
{
	Token word;
	string str = "";
	size_t size_str = 0;
	size_t start_str = line_identifier;


	if (Line.size() == 1)
	{
		word.set_token_type(Token::Words::Identifier);
		word.set_string(Line.substr(0, 1));
		return word;
	}

	while(line_identifier < Line.size() && is_letter(Line[line_identifier]))
	{
		line_identifier++;
		size_str++;
	}

	line_identifier--;// because read last symbol 

	str = Line.substr(start_str, size_str);
	word.set_token_type(Token::Words::Identifier);
	word.set_string(str);
	return word;
}

void Lexer::processing_of_complex_znak(Token &znak, string& Line, size_t& line_identifier, Token::Words token_complex_type, Token::Words token_type)
{
	string oper = "";
	oper += Line[line_identifier];

	if (line_identifier < Line.size() - 1 && Line[line_identifier + 1] == '=')
	{
		// обработка +=
		znak.set_token_type(token_complex_type);
		znak.set_string(oper + "=");
	}
	else 
	{
		znak.set_token_type(token_type);
		znak.set_string(oper);
	}
}

Token Lexer::znak_processing(string& Line, size_t& line_identifier)
{
	Token znak;

	switch(Line[line_identifier])
	{
		case '+':
			processing_of_complex_znak(znak, Line, line_identifier, Token::Words::AddAssign, Token::Words::Plus);
			break;
		case '-':
			processing_of_complex_znak(znak, Line, line_identifier, Token::Words::SubAssign, Token::Words::Minus);
			break;
		case '/':
			processing_of_complex_znak(znak, Line, line_identifier, Token::Words::DivAssign, Token::Words::Slash);
			break;
		case '*':
			processing_of_complex_znak(znak, Line, line_identifier, Token::Words::MultAssign, Token::Words::Asterisk);
			break;
		case '^':
			znak.set_token_type(Token::Words::Degree);
			znak.set_string("^");
			break;
		case '(':
			znak.set_token_type(Token::Words::LeftParen);
			znak.set_string("(");
			break;
		case ')':
			znak.set_token_type(Token::Words::RightParen);
			znak.set_string(")");
			break;
	}
	return znak;
}