#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <memory>
#include <utility>

class Token 
{

public:
	enum class Words {
		Identifier,  	//[a-z] || [A-Z]    
		LeftParen,   	// (
		RightParen,  	// )   
		LessThan,    	// < 
		GreaterThan, 	// >
	    Equal,		 	// ==     
	    Plus, 	     	// +
	    Minus,       	// -   
	    Asterisk,    	// *
	    Slash,			// /
	    Degree,         // ^
	    //Semicolon,      // ; 
	    //DoubleQuote, 	// :
	    //Comma,          // ,
	    //String,         // Type string
	    //Single,			// Type single
	    //Int,		    // Type int 		 
	    //string,         // "expr"
	    End,	         
	    Unexpected,     
	    Assignment,     // = 
	    //KeyWordIf,      // if
	    //KeyWordIfThen,  // then
	    //KeyWordElse,    // else
	    //KeyWordIfEnd,   // endif
	    //KeyWordWhile,   // while
	    //KeyWordWhileEnd,// wend 
	    NotEqual,       // !=
	    LessOrEqual,    // <=
	    MoreOrEqual,    // >=
	    AddAssign,      // +=
	    SubAssign,      // -=
	    MultAssign,     // *=
	    DivAssign,      // /=
	    //Point,          // .
	    Conjunction,    // and
	    Disjunction,    // or
	    //KeyWordAs,      // as
	    //KeyWordDim,     // dim
	    Number,         //[0-9]
	};

	void set_token_type(Words Token) { TokenType = Token; }
	void set_string(std::string Str) { Line = Str; }
	void set_str_number(int i) { StrNum = i; }
	void set_col_number(int i) { ColNum = i; }

	Words get_token_type() noexcept { return TokenType; }
	std::string get_string() { return Line; }
	int get_str_num() { return StrNum; }
	int get_col_num() { return ColNum; }
	int get_oper_precedence(std::string str_key) { return oper_precedence[str_key]; }

	Token() 
	{ 
		set_token_type(Words::End);
		oper_precedence["+"] = 1;
		oper_precedence["-"] = 1;
		oper_precedence["*"] = 2;
		oper_precedence["/"] = 2;
		oper_precedence["^"] = 3;
	};
	~Token() = default;

private:
	std::map<std::string, int> oper_precedence;
	Words TokenType{};
	std::string Line = "";
	int StrNum = -1;
	int ColNum = -1;
};

std::ostream& operator << (std::ostream& os, const Token::Words& kind);
void print_space(size_t space);

class AstNode
{
	std::string name = "";
	std::unique_ptr<AstNode> node = nullptr;
public:
	AstNode() = default;
	virtual ~AstNode() = default;
	virtual void print(size_t space = 0, size_t arg = 0) {}
	virtual void set_param() {}
	virtual std::string get_name() { return name; }
	virtual std::unique_ptr<AstNode> const& get_operand(){ return node; }
};

class AstRoot : public AstNode
{
	std::string name = "";
	std::unique_ptr<AstNode> AstTreeRoot = nullptr;
public:
	AstRoot(std::unique_ptr<AstNode> Node) : AstTreeRoot(move(Node)) {};
	void print(size_t space = 0, size_t arg = 0) 
	{
		std::cout << std::endl << "JSON" << std::endl;
		AstTreeRoot->print(0);
		std::cout << std::endl;
	}
	void set_param(std::unique_ptr<AstNode> Node) 
	{
		AstTreeRoot = move(Node);
	}
	std::string get_name() { return name; }
	std::unique_ptr<AstNode> const& get_operand(){ return AstTreeRoot; }
};

class AstBinOper : public AstNode
{
	std::string name_oper = "";
	std::unique_ptr<AstNode> left_operand = nullptr;
	std::unique_ptr<AstNode> right_operand = nullptr;
public:
	AstBinOper() {}
	AstBinOper(std::unique_ptr<AstNode> left_op, std::unique_ptr<AstNode> right_op, std::string name_op) : left_operand(move(left_op)), right_operand(move(right_op)), name_oper(name_op) {}
	~AstBinOper() = default;
	//std::unique_ptr<AstNode> const& get_operand(){ return node; }

	void set_param(std::unique_ptr<AstNode> left_op, std::unique_ptr<AstNode> right_op, std::string name_op) 
	{
		left_operand = move(left_op);
		right_operand = move(right_op);
		name_oper = name_op;
	}
	std::unique_ptr<AstNode> const& get_left_operand() { return left_operand; }
	std::unique_ptr<AstNode> const& get_right_operand() { return right_operand; }
	std::string get_name(){return name_oper;}
	void print(size_t space = 0, size_t arg = 0)
	{
		bool check_one_arg = false; // arg = str
		bool check_two_arg = false;

		std::cout << std::endl;
		if (left_operand->get_operand() != nullptr)
		{
			check_one_arg = true; // arg = opnode
		}

		if (right_operand->get_operand() != nullptr)
		{
			check_two_arg = true; // arg = opnode
		}

		//std::cout << std::endl;
		print_space(space);
		std::cout << "{" << std::endl;
		print_space(space + 1);
		std::cout << "\"" << name_oper << "\": [";

		if (!check_one_arg && check_two_arg)
		{
			std::cout << std::endl;
			print_space(space + 4);
		}

		left_operand->print(space + 2, 1);
		if (check_one_arg && !check_two_arg)
		{
			std::cout << std::endl;
			print_space(space + 4);
		}	

		right_operand->print(space + 2, 2);
		
		if (check_one_arg || check_two_arg)
		{
			std::cout << std::endl;
			print_space(space + 2);
		}
		std::cout << "]" << std::endl;
		print_space(space);
		std::cout << "}";
			
	}
};

class AstOperand : public AstNode
{
	std::string name_operand = "";
	std::unique_ptr<AstNode> operand = nullptr;
public:
	AstOperand() {}
	AstOperand(std::unique_ptr<AstNode> op, std::string name_op) : operand(move(op)), name_operand(name_op) {}
	~AstOperand() = default;
	std::unique_ptr<AstNode> const& get_operand(){ return operand; }

	void set_param(std::unique_ptr<AstNode> op, std::string name_op)
	{
		name_operand = name_op;
		operand = move(op);
	}
	std::string get_name() { return name_operand; }
	//std::unique_ptr<AstNode> const& get_operand() { return operand; }
	void print(size_t space = 0, size_t arg = 0)
	{
		if (operand)
		{
			operand->print(space + 2);
		}
		else
		{
			std::cout << name_operand;
		}

		if (arg == 1)
		{
			std::cout << ", ";
		}
	} 
};