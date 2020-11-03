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
	    End,	         
	    Unexpected,     
	    Assignment,     // = 
	    NotEqual,       // !=
	    LessOrEqual,    // <=
	    MoreOrEqual,    // >=
	    AddAssign,      // +=
	    SubAssign,      // -=
	    MultAssign,     // *=
	    DivAssign,      // /=
	    Conjunction,    // and
	    Disjunction,    // or
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
bool is_oper_str(std::string ch);

class AstNode
{
	std::string Name = "";
	std::unique_ptr<AstNode> node = nullptr;
public:
	AstNode() = default;
	virtual ~AstNode() = default;
	virtual void print(size_t space = 0, size_t arg = 0) {}
	virtual void set_param() {}
	virtual std::string get_name() { return Name; }
	virtual std::unique_ptr<AstNode> const& get_operand(){ return node; }
};

class AstRoot : public AstNode
{
	std::string Name = "";
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
	std::string get_name() { return Name; }
	std::unique_ptr<AstNode> const& get_operand(){ return AstTreeRoot; }
};

class AstBinOper : public AstNode
{
	std::string OperationName = "";
	std::unique_ptr<AstNode> LeftOperand = nullptr;
	std::unique_ptr<AstNode> RightOperand = nullptr;
public:
	AstBinOper() {}
	AstBinOper(std::unique_ptr<AstNode> left_op, std::unique_ptr<AstNode> right_op, std::string op_name) : LeftOperand(move(left_op)), RightOperand(move(right_op)), OperationName(op_name) {}
	~AstBinOper() = default;
	//std::unique_ptr<AstNode> const& get_operand(){ return node; }

	void set_param(std::unique_ptr<AstNode> left_op, std::unique_ptr<AstNode> right_op, std::string op_name) 
	{
		LeftOperand = move(left_op);
		RightOperand = move(right_op);
		OperationName = op_name;
	}
	std::unique_ptr<AstNode> const& get_LeftOperand() { return LeftOperand; }
	std::unique_ptr<AstNode> const& get_RightOperand() { return RightOperand; }
	std::string get_name(){return OperationName;}
	void print(size_t space = 0, size_t arg = 0)
	{

		std::cout << std::endl;

		//std::cout << std::endl;
		print_space(space);
		std::cout << "{" << std::endl;
		print_space(space + 1);
		std::cout << "\"" << OperationName << "\": [";

		if ((LeftOperand->get_name() != "" && !is_oper_str(LeftOperand->get_name())) && (RightOperand->get_name() == "" || is_oper_str(RightOperand->get_name())))
		{
			std::cout << std::endl;
			print_space(space + 4);
		}

		LeftOperand->print(space + 2, 1);
		
		std::cout << ", ";
		if ((LeftOperand->get_name() == "" || is_oper_str(LeftOperand->get_name())) && (RightOperand->get_name() != "" && !is_oper_str(RightOperand->get_name())))
		{
			std::cout << std::endl;
			print_space(space + 2);
		}	

		RightOperand->print(space + 2, 2);

		if (LeftOperand->get_name() == "" || is_oper_str(LeftOperand->get_name()) || RightOperand->get_name() == "" || is_oper_str(RightOperand->get_name()))
		{
			std::cout << std::endl;
			print_space(space + 1);
		}

		std::cout << "]" << std::endl;
		print_space(space);
		std::cout << "}";
			
	}
};

class AstOperand : public AstNode
{
	std::string NameOperand = "";
	std::unique_ptr<AstNode> Operand = nullptr;
public:
	AstOperand() {}
	AstOperand(std::unique_ptr<AstNode> op, std::string op_name) : Operand(move(op)), NameOperand(op_name) {}
	~AstOperand() = default;
	std::unique_ptr<AstNode> const& get_operand(){ return Operand; }
	void set_param(std::unique_ptr<AstNode> op, std::string op_name)
	{
		NameOperand = op_name;
		Operand = move(op);
	}
	std::string get_name() { return NameOperand; }
	void print(size_t space = 0, size_t arg = 0)
	{
		if (Operand)
		{
			Operand->print(space + 2);
		}
		else
		{
			std::cout << NameOperand;
		}
	} 
};