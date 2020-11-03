
#include "parser.hpp"
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

TEST(LibPars, check_correct_StackOutput)
{
	Parser Pars;
	vector<Token> VectorToken;
	string op = "";
	Token T;
	T.set_token_type(Token::Words::Plus);
	op = "+";
	T.set_string(op);
	VectorToken.push_back(T);

	T.set_token_type(Token::Words::Minus);
	op = "-";
	T.set_string(op);
	VectorToken.push_back(T);

	T.set_token_type(Token::Words::Number);
	op = "4";
	T.set_string(op);
	VectorToken.push_back(T);

	Pars.parsing_token_vector(VectorToken);
	bool check_correct = Pars.check_correct_StackOutput();
	
	ASSERT_TRUE(check_correct == false);
}

TEST(LibPars, check_correct_StackOutput_two)
{
	Parser Pars;
	vector<Token> VectorToken;
	string op = "";
	Token T;
	T.set_token_type(Token::Words::Number);
	op = "1";
	T.set_string(op);
	VectorToken.push_back(T);

	T.set_token_type(Token::Words::Minus);
	op = "-";
	T.set_string(op);
	VectorToken.push_back(T);

	T.set_token_type(Token::Words::Number);
	op = "4";
	T.set_string(op);
	VectorToken.push_back(T);

	Pars.parsing_token_vector(VectorToken);
	bool check_correct = Pars.get_StackOutput().empty();
	
	ASSERT_TRUE(check_correct == false);
}

TEST(LibPars, search_v_sub_node)
{
	Parser Pars;
	vector<Token> VectorToken;
	string op = "";
	Token T;
	T.set_token_type(Token::Words::Number);
	op = "node_str";
	T.set_string(op);
	VectorToken.push_back(T);

	T.set_token_type(Token::Words::Minus);
	op = "-";
	T.set_string(op);
	VectorToken.push_back(T);

	T.set_token_type(Token::Words::Number);
	op = "4";
	T.set_string(op);
	VectorToken.push_back(T);

	T.set_token_type(Token::Words::Minus);
	op = "*";
	T.set_string(op);
	VectorToken.push_back(T);

	T.set_token_type(Token::Words::Number);
	op = "2";
	T.set_string(op);
	VectorToken.push_back(T);

	T.set_token_type(Token::Words::RightParen);
	op = ")";
	T.set_string(op);
	VectorToken.push_back(T);

	Pars.parsing_token_vector(VectorToken);
	bool check_correct = Pars.get_StackOutput().empty();
	
	ASSERT_TRUE(check_correct == true);
}