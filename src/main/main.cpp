#include <fstream>
#include <algorithm>
#include "lexer.hpp"
#include "parser.hpp"

using namespace std;

int main()
{

	ifstream FileInput("ex.txt", ios::in);

	if (!FileInput)
	{
		cerr << "File opening error" << endl;
		return -1; 
	}

	//Lexer
	vector<Token> VectorToken;
	vector<int> NumberUnexToken;
	Lexer Lex;
	string Line;
	int line_number = 1;
	bool check_Lex = true;
	
	//Reading a file
	while (!FileInput.eof()) {
		getline(FileInput, Line);
		Lex.line_processing(Line, line_number, 0, VectorToken);
		line_number++;
	}
	Lex.line_processing(Line, line_number, 1, VectorToken);
	FileInput.close();

	cout << "Vector:" << endl;
	for (int i = 0; i < VectorToken.size(); i++)
	{
		cout << "Loc<" << VectorToken[i].get_str_num() << ":" << VectorToken[i].get_col_num() << "> " << VectorToken[i].get_token_type() << " '" << VectorToken[i].get_string() << "'" << endl; // << " " << i << endl;
		if (VectorToken[i].get_token_type() == Token::Words::Unexpected) check_Lex = false;
	}
	cout << endl;

	if (check_Lex) // Check Lex
	{
		// Parsing
		Parser Pars;
		// Shunting-yard
		vector<string> VectorStrOper(Pars.parsing_token_vector(VectorToken));
		reverse(VectorStrOper.begin(), VectorStrOper.end());

		if (!VectorStrOper.empty() && Pars.check_correct_arithmetic_expression(VectorStrOper)) // Сhecking for correctness of an arithmetic expression
		{
			//Pars.print_vector(VectorStrOper, "mainv");
			// Build ast tree
			auto Root = make_unique<AstRoot>(Pars.build_ast_tree(VectorStrOper));
			Pars.set_AstRoot(move(Root));
			Pars.get_AstRoot()->print();
		}
		else
		{
			cerr << "Incorrect arithmetic expression" << endl;
		}
	}
	else
	{
		cerr << "Error: Unknown token found" << endl;
	}
	
	return 0;
}