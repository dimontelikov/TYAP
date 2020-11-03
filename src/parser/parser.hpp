#pragma once

#include "struct.hpp"
#include <stack>

class Parser
{
	std::string variable_str = "node_str"; //Reserved variable
	std::unique_ptr<AstRoot> AstRootN = nullptr;
	std::stack<std::string> StackOutput;
	std::stack<std::string> StackExp;
	std::stack<std::unique_ptr<AstNode>> StackAst;

public:
	Parser() = default;
	~Parser() = default;

	//Check 
	bool is_oper(Token& token);
	bool is_oper_str(std::string ch);
	bool check_correct_StackOutput();

	void parsing_token_vector(std::vector<Token>& VectorToken);
	std::unique_ptr<AstNode> build_ast_tree_bottom_up();
	std::stack<std::string> const& get_StackOutput(){ return StackOutput; }
	std::unique_ptr<AstRoot> const& get_AstRoot(){ return AstRootN; }
	void set_AstRoot(std::unique_ptr<AstRoot> Ast){ AstRootN = move(Ast); }

	//print
	void print_ast(std::unique_ptr<AstBinOper> const& node);
	void print_ast(std::unique_ptr<AstNode> const& node);
};