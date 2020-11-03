#include "parser.hpp"
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

bool Parser::check_correct_StackOutput()
{
	stack<string> StackCheck(StackOutput);
	int number_operand = 0;

	while (!StackCheck.empty())
	{
		if (!is_oper_str(StackCheck.top()))
		{
			number_operand++;
		}
		else
		{
			number_operand--;
		}

		StackCheck.pop();
	}

	if (number_operand != 1)
	{
		cerr << endl << "Error: an arithmetic expression is set incorrectly" << endl;
		return false;
	}

	return true;
}

//Shunting-yard
void Parser::parsing_token_vector(vector<Token>& VectorToken)
{
	stack<string> stack_output;
	stack<string> stack_oper;
	//vector<string> vector_result;
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
	        	return;
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
	        	return;
	        }
	        oper = stack_oper.top();
	        stack_oper.pop();
	        stack_output.push(oper); //поместить оператора из стека операторов в очередь вывода. 
		}  
	}

	cout << endl << "Shunting-yard: ";
	while (!stack_output.empty())
	{
		
		StackOutput.push(stack_output.top());
		cout << StackOutput.top() << " ";
		stack_output.pop();
	}
}
  
std::unique_ptr<AstNode> Parser::build_ast_tree_bottom_up()
{
	string LeftOperStr = "";
	string RightOperStr = "";
	string OperationStr = "";
	int number_operand = 0;
	unique_ptr<AstNode> Root = nullptr;

	while (!StackOutput.empty())
	{
		number_operand = 0;
		while (!is_oper_str(StackOutput.top()))
		{
			StackExp.push(StackOutput.top());
			number_operand++;
			StackOutput.pop();
		}

		//cout << endl << "number_operand = " << number_operand << endl;
		if (is_oper_str(StackOutput.top()))
		{
			OperationStr = StackOutput.top();
			StackOutput.pop();

			if (StackExp.size() >= 2 && number_operand >= 2)
			{
				//cout << "varik1" << endl;
				RightOperStr = StackExp.top();
				StackExp.pop();
				LeftOperStr = StackExp.top();
				StackExp.pop();

				auto LeftOperNode = make_unique<AstOperand>(nullptr, LeftOperStr);
				auto RightOperNode = make_unique<AstOperand>(nullptr, RightOperStr);
				auto OperationNode = make_unique<AstBinOper>(move(LeftOperNode), move(RightOperNode), OperationStr);
				
				StackAst.push(move(OperationNode));
			}
			else if (number_operand == 0 && StackAst.size() == 1)
			{
				//cout << "varik2" << endl;
				LeftOperStr = StackExp.top();
				StackExp.pop();
				RightOperStr = "";

				auto LeftOperNode = make_unique<AstOperand>(nullptr, LeftOperStr);
				auto RightOperNode = make_unique<AstOperand>(move(StackAst.top()), RightOperStr);
				StackAst.pop();
				auto OperationNode = make_unique<AstBinOper>(move(LeftOperNode), move(RightOperNode), OperationStr);
				
				StackAst.push(move(OperationNode));
			}
			else if (number_operand == 1 && !StackAst.empty() && !StackExp.empty())
			{
				//cout << "varik3" << endl;
				LeftOperStr = "";
				RightOperStr = StackExp.top();
				StackExp.pop();

				auto LeftOperNode = make_unique<AstOperand>(move(StackAst.top()), LeftOperStr);
				auto RightOperNode = make_unique<AstOperand>(nullptr, RightOperStr);
				StackAst.pop();
				auto OperationNode = make_unique<AstBinOper>(move(LeftOperNode), move(RightOperNode), OperationStr);
				
				StackAst.push(move(OperationNode));
			}
			else
			{
				//cout << "varik4" << endl;
				LeftOperStr = "";
				RightOperStr = "";

				auto RightOperNode = make_unique<AstOperand>(move(StackAst.top()), LeftOperStr);
				StackAst.pop();
				auto LeftOperNode = make_unique<AstOperand>(move(StackAst.top()), RightOperStr);
				StackAst.pop();
				auto OperationNode = make_unique<AstBinOper>(move(LeftOperNode), move(RightOperNode), OperationStr);
				
				StackAst.push(move(OperationNode));
			}

		}
		else
		{
			break;
		}
	}
	Root = move(StackAst.top());
	StackAst.pop();

	return move(Root);
}
