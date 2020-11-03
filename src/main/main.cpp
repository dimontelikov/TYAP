#include <fstream>
#include <algorithm>
#include "lexer.hpp"
#include "parser.hpp"
#include "cxxopts.hpp"

using namespace std;

int main(int argc, char** argv)
{
	cxxopts::Options options("test", "A brief description");

    options.add_options()
        ("f, file", "Input file", cxxopts::value<string>())
        ("h, help", "Print usage")
    ;

    auto result = options.parse(argc, argv);

    if (result.count("help"))
    {
		cout << options.help() << endl;
		exit(0);
    } 

    string FileName = "ex.txt";

    if (result.count("file"))
    {
    	FileName = result["file"].as<string>();
    }

	ifstream FileInput(FileName, ios::in);

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
		Pars.parsing_token_vector(VectorToken);
		if (!Pars.get_StackOutput().empty() && Pars.check_correct_StackOutput())
		{
			// Build ast tree
			auto Root = make_unique<AstRoot>(Pars.build_ast_tree_bottom_up());
			Pars.set_AstRoot(move(Root));
			Pars.get_AstRoot()->print();
		}
	}
	else
	{
		cerr << "Error: Unknown token found" << endl;
	}
	
	return 0;
}