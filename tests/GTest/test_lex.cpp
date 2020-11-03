
#include "lexer.hpp"
#include <iostream>
#include <gtest/gtest.h>
#include <utility>

using namespace std;

TEST(LibLex, znak_processing)
{
	Lexer Lex;
	string Znak = "+";
	size_t i = 0;
	auto TokenZnak = Lex.znak_processing(Znak, i);
	Znak = TokenZnak.get_string();
	ASSERT_EQ(Znak, "+");
}

TEST(LibLex, word_processing)
{
	Lexer Lex;
	size_t i = 0;
	string Word = "word";
	auto TokenWord = Lex.word_processing(Word, i);
	Word = TokenWord.get_string();
	ASSERT_EQ(Word, "word");
}

TEST(LibLex, digit_processing)
{
	Lexer Lex;
	string Digit = "1";
	size_t i = 0;
	auto TokenDigit = Lex.digit_processing(Digit, i);
	Digit = TokenDigit.get_string();
	ASSERT_EQ(Digit, "1");
}

TEST(LibLex, unexpected_processing)
{
	Lexer Lex;
	size_t i = 0;
	string Unexpected = "неизвестныйтокен";
	auto TokenUnex = Lex.unexpected_processing(Unexpected, i);
	Unexpected = TokenUnex.get_string();
	ASSERT_EQ(Unexpected, "неизвестныйтокен");
}