#pragma once

#include "struct.hpp"

class Parser
{
	std::string variable_str = "node_str"; //Reserved variable
	std::unique_ptr<AstRoot> AstRootN = nullptr;

public:
	Parser() = default;
	~Parser() = default;

	//Check 
	bool is_oper(Token& token);
	bool is_oper_str(std::string ch);
	bool check_correct_arithmetic_expression(std::vector<std::string> v);
	int check_node(std::vector<std::string> const& v, int index_delete);

	std::vector<std::string> parsing_token_vector(std::vector<Token>& VectorToken);
	std::unique_ptr<AstNode> build_ast_tree(std::vector<std::string> &vector_result);
	std::unique_ptr<AstNode> build_ast_tree_bottom_up(std::vector<std::string> &vector_result, std::unique_ptr<AstNode> AstSubNode);
	std::vector<std::string> search_v_sub_node(std::vector<std::string> &v, int index_sub_node);
	std::unique_ptr<AstRoot> const& get_AstRoot(){ return AstRootN; }
	void vector_str_change(std::vector<std::string> &vector_result, int index_delete, std::string temp_str = "node_str");	
	void set_AstRoot(std::unique_ptr<AstRoot> Ast){ AstRootN = move(Ast); }

	//print
	void print_vector(std::vector<std::string> const& vector, char const* vector_name);
	void print_ast(std::unique_ptr<AstBinOper> const& node);
	void print_ast(std::unique_ptr<AstNode> const& node);
};