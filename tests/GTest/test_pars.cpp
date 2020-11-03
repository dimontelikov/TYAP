
#include "parser.hpp"
#include <iostream>
#include <gtest/gtest.h>
#include <utility>
#include <algorithm>

using namespace std;

TEST(LibPars, Shunting_yard)
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

	vector<string> VectorStrOper(Pars.parsing_token_vector(VectorToken));
	bool check_correct = Pars.check_correct_arithmetic_expression(VectorStrOper);
	
	ASSERT_TRUE(check_correct == false);
}

TEST(LibPars, vector_str_change)
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

	vector<string> VectorStrOper(Pars.parsing_token_vector(VectorToken));
	Pars.vector_str_change(VectorStrOper, 0);

	int size = VectorStrOper.size();
	
	ASSERT_TRUE(size == 0);
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

	vector<string> VectorStrOper(Pars.parsing_token_vector(VectorToken));
	reverse(VectorStrOper.begin(), VectorStrOper.end());
	vector<string> v = Pars.search_v_sub_node(VectorStrOper, 0);
	int size = v.size();
	
	ASSERT_TRUE(size == 5);
}