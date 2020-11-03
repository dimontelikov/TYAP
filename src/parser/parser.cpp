/* Эта реализация не реализует составные функции, функции с переменным числом аргументов и унарные операторы. */ 
//3 4 2 × 1 5 − 2 3 ^ ^ ÷ +
#include "parser.hpp"
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

bool Parser::is_oper(Token& token)
{
	switch (token.get_token_type())
	{
		case Token::Words::Plus:
		case Token::Words::Minus:
		case Token::Words::Asterisk:
		case Token::Words::Slash:
		case Token::Words::Degree:
			return true;
		default:
			return false;
	}
}

bool Parser::is_oper_str(string ch)
{
	if (ch == "+" || ch == "-" || ch == "*" || ch == "/" || ch == "^")
		return true;
	return false;
}

bool Parser::check_correct_arithmetic_expression(vector<string> v)
{
	int index = 0;
	Parser P;
	while (!v.empty())
	{
		for (index = 0; index < v.size(); index++) 
		{
			if (P.is_oper_str(v[index]))
			{
				int index_delete = index - 2;
				if (index_delete < 0) 
				{
					return false;
				}
				//cout << "index_delete = " << index_delete << endl;
				P.vector_str_change(v, index_delete);
				//P.print_vector(v, "check_correct");
				if (v.size() == 2) 
				{
					return false;
				}

				break;
			}
		}
		
	}
	//P.print_vector(v, "check_correct");

	return true;
}

int Parser::check_node(vector<string> const& v, int index_delete)
{
	for (int i = 0; i < index_delete; i++)
	{
		if (v[i] == variable_str) return i;
	}
	return -1;
}

void Parser::print_ast(unique_ptr<AstNode> const& node)
{
	cout << "AstTree:" << endl;
	node->print();
	cout << endl;
}

void Parser::print_ast(unique_ptr<AstBinOper> const& node)
{
	cout << "AstTree:" << endl;
	node->print();
	cout << endl;
}

void Parser::print_vector(vector<string> const& vector, char const* vector_name)
{	
	cout << endl << vector_name << endl;
	for (auto x: vector)
	{
		cout << x << " ";
	}
	cout << endl;
}

//Shunting-yard
vector<string> Parser::parsing_token_vector(vector<Token>& VectorToken)
{
	stack<string> stack_output;
	stack<string> stack_oper;
	vector<string> vector_result;
	string oper;
	Token ob;
	int index = 0;

	while (index < VectorToken.size())
	{ 
	    //прочитать токен. 
		if ((VectorToken[index].get_token_type() == Token::Words::Number) || (VectorToken[index].get_token_type() == Token::Words::Identifier))
		{
			stack_output.push(VectorToken[index].get_string()); // поместите его в очередь вывода. 
		}
	    else if (is_oper(VectorToken[index])) 
	    {
	        while ((!stack_oper.empty()) 
	        		&& 
	        	  (stack_oper.top() != "(")
	               	&& 
	              (
	              	(ob.get_oper_precedence(stack_oper.top()) > ob.get_oper_precedence(VectorToken[index].get_string()))
	                  ||
	    		  	(
	    		  		ob.get_oper_precedence(stack_oper.top()) == ob.get_oper_precedence(VectorToken[index].get_string()) 
	    		  		  && 
	    		  		VectorToken[index].get_string() != "^")
	    		  	)
	              ) 
	        {
	        	oper = stack_oper.top();
	        	stack_oper.pop();
	            stack_output.push(oper); //вставлять операторы из стека операторов в очередь вывода . 
	        }
	        oper = VectorToken[index].get_string();
	        stack_oper.push(oper);
	    }
	    else if (VectorToken[index].get_string() == "(") 
	    {
	        oper = VectorToken[index].get_string();
	        stack_oper.push(oper);
	    }
	    else if (VectorToken[index].get_string() == ")")
	    {
	        while (!stack_oper.empty() && stack_oper.top() != "(")
	    	{
	            oper = stack_oper.top();
	        	stack_oper.pop();
	        	stack_output.push(oper); //поместить оператора из стека операторов в очередь вывода. 
	        }
	        /* Если стек исчерпывается, а левая скобка не найдена, значит, скобки не совпадают. */ 
	        if (!stack_oper.empty() && stack_oper.top() == "(") 
	        {
	        	stack_oper.pop(); //извлечь оператор из стека операторов и отбросить его 
	        }
	        else 
	        {
	        	cout << "error ( )" << endl;
	        	return vector_result;
	        }
	        /* После цикла while, если стек оператора не равен нулю, поместить все в очередь вывода */
	    }
	    index++;
	}

	if (!stack_oper.empty())
	{
		while (!stack_oper.empty())
		{
			/* Если оператор фишку на вершине стека является скобка, то есть несоответствующие скобки. */
	        //поместить оператора из стека операторов в очередь вывода. 
	        if (oper == "(" || oper == ")")
	        {
	        	cout << "error ( )" << endl;
	        	return vector_result;
	        }
	        oper = stack_oper.top();
	        stack_oper.pop();
	        stack_output.push(oper); //поместить оператора из стека операторов в очередь вывода. 
		}  
	}

	while (!stack_output.empty())
	{
		vector_result.push_back(stack_output.top());
		stack_output.pop();
	}

	return vector_result; 
}
  
vector<string> Parser::search_v_sub_node(vector<string> &v, int index_sub_node)
{
	vector<string> v_two(v);
	int index = index_sub_node;
	int index_finish;
	int operand_num = 0;
	int oper_num = 0;
	Parser P;

	while (index < v_two.size())
	{
		oper_num = 0;
		if (!P.is_oper_str(v_two[index]))
		{
			operand_num++;
		}
		else
		{
			oper_num = 1;
			if (operand_num == 2)
			{
				break;
			}
			operand_num--;
		}
		index++;
	}
	
	index_finish = index + 1;
	index = index_sub_node;

	v_two.erase(v_two.begin() + index_finish, v_two.end());
	v_two.erase(v_two.begin(), v_two.begin() + index_sub_node);
	//P.print_vector(v_two, "v_two");

	v.erase(v.begin() + index_sub_node, v.begin() + index_finish - 1);
	if (v.size() != 1) 
	{
		v[index_sub_node] = "node_str";
	}
	else 
	{
		v.erase(v.begin());
	}
	//P.print_vector(v, "v");

	return v_two;
}

void Parser::vector_str_change(vector<string> &vector_result, int index_delete, string temp_str)
{
	int i = 0;
	transform(vector_result.begin(), vector_result.end(), vector_result.begin(), 
		[index_delete, &i](string x)
		{ 
			if (i == index_delete || i == (index_delete + 1) || i == (index_delete + 2))
			{
				i++;
				return x = " ";
			}
			i++;
			return x;
		}
	);
	
	vector<string>::iterator it = vector_result.begin(), it_zapas;
	for(; it != vector_result.end(); it++)
	{
		if (*it == " ")
		{
			if (it - vector_result.begin() == index_delete)
			{
				*it = temp_str;
			}
			else
			{
				vector_result.erase(it);
				it = it_zapas;
			}
		}
		it_zapas = it;
	}

	if (vector_result.size() == 1) vector_result.erase(vector_result.begin());

	/*cout << endl << "vector_str_change:";
	for (auto x: vector_result)
	{
		cout << x << " ";
	}*/
}

unique_ptr<AstNode> Parser::build_ast_tree_bottom_up(vector<string> &vector_result, unique_ptr<AstNode> AstSubNode)
{
	int index = 0;
	if (vector_result.empty()) return move(AstSubNode);

	while (!is_oper_str(vector_result[index]) && (index < vector_result.size()))
	{
		index++;
	}

	if (index != vector_result.size())
	{
		int index_delete = index - 2;
		int index_sub_node = check_node(vector_result, index_delete);
		string clear_str = "";
		string name_oper = vector_result[index_delete + 2];	
		unique_ptr<AstBinOper> OperNode(new AstBinOper());

		if (index_sub_node != -1) // ...t, ..., operand, operand, op, ...
		{
			//cout << "...t, ..., operand, operand, op, ..." << endl;
			vector<string> vector_with_subnode = search_v_sub_node(vector_result, index_sub_node); // [node_str, ..., op]
			vector<string> vector_sub_node(vector_with_subnode);// [node_str, [..., op], op]
			vector_sub_node.erase(vector_sub_node.begin()); // [[..., op], op]
			vector_sub_node.pop_back(); // [..., op]

			//print_vector(vector_with_subnode, "vector_with_subnode");
			//print_vector(vector_sub_node, "vector_sub_node");

			auto SubLeftOperand = make_unique<AstOperand>(move(AstSubNode), clear_str);
			auto SubRightOperand = make_unique<AstOperand>(build_ast_tree(vector_sub_node), clear_str);// create node = [..., op]
			OperNode->set_param(move(SubLeftOperand), move(SubRightOperand), vector_with_subnode[vector_with_subnode.size() - 1]); // create node = node_str and [..., op] op
		
		}
		else if (vector_result[index_delete + 1] == variable_str) // ..., operand, t, op ... 
		{
			//cout << "..., operand, t, op ..." << endl;
			auto LeftOperand = make_unique<AstOperand>(nullptr, vector_result[index_delete]);
			auto RightOperand = make_unique<AstOperand>(move(AstSubNode), clear_str);
			OperNode->set_param(move(LeftOperand), move(RightOperand), vector_result[index]);
			vector_str_change(vector_result, index_delete);
		}
		else // ..., t, operand, op, ...
		{	
			//cout << "..., t, operand, op, ..." << endl;
			auto LeftOperand = make_unique<AstOperand>(move(AstSubNode), clear_str);
			auto RightOperand = make_unique<AstOperand>(nullptr, vector_result[index_delete + 1]);
			OperNode->set_param(move(LeftOperand), move(RightOperand), vector_result[index]);
			vector_str_change(vector_result, index_delete);
		}
		
		//cout << endl;
		//OperNode->print();
		//cout << endl;
		return build_ast_tree_bottom_up(vector_result, move(OperNode));
	}

	return nullptr;
}

//Build ast tree
unique_ptr<AstNode> Parser::build_ast_tree(vector<string> &vector_result)
{
	int index = 0;
	
	while ((!is_oper_str(vector_result[index])) && (index < vector_result.size()))
	{
		index++;
	}

	if (index != vector_result.size())
	{
		int index_delete = index - 2;
		auto LeftOperand = make_unique<AstOperand>(nullptr, vector_result[index_delete]);
		auto RightOperand = make_unique<AstOperand>(nullptr, vector_result[index_delete + 1]);
		auto OperNode = make_unique<AstBinOper>(move(LeftOperand), move(RightOperand), vector_result[index_delete + 2]);

		vector_str_change(vector_result, index_delete);
		if (!vector_result.empty())
		{
			auto NodeAstReturn = build_ast_tree_bottom_up(vector_result, move(OperNode));
			//print_ast(NodeAstReturn);
			return move(NodeAstReturn);
		}
		else
		{
			//print_ast(OperNode);
			return move(OperNode);
		}
	}
	
	return nullptr;
}
