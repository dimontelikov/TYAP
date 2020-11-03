#include "struct.hpp"

using namespace std;

std::ostream& operator << (std::ostream& os, const Token::Words& kind) 
{
	static const char* const names[]
	{
	   "Identifier",      
	   "LeftParen",   
	   "RightParen",     
	   "LessThan",     
	   "GreaterThan",
	   "Equal",		      
	   "Plus", 	     
	   "Minus",          
	   "Asterisk",     
	   "Slash",
	   "Degree",
	   //"Semicolon",       
	   //"DoubleQuote", 
	   //"Comma",          
	   //"String",       
	   //"Single",
	   //"Int",		      
	   //"string",      
	   "End",	           
	   "Unexpected",   
	   "Assignment",
	   //"KeyWordIf",
	   //"KeyWordIfThen",       
	   //"KeyWordElse", 
	   //"KeyWordIfEnd",   
	   //"KeyWordWhile",
	   //"KeyWordWhileEnd", 
	   "NotEqual",    
	   "LessOrEqual",    
	   "MoreOrEqual",  
	   "AddAssign",   
	   "SubAssign",       
	   "MultAssign",  
	   "DivAssign",      
	   //"Point",        	 
	   "Сonjunction",
	   "Disjunction",
	   //"KeyWordAs",
	   //"KeyWordDim",
	   "Number",
 	};
	return os << names[static_cast<int>(kind)];
}

void print_space(size_t space)
{
	while (space)
	{
		std::cout << " ";
		space--;
	}
}