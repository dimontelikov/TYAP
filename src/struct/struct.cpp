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
	   "End",	           
	   "Unexpected",   
	   "Assignment",
	   "NotEqual",    
	   "LessOrEqual",    
	   "MoreOrEqual",  
	   "AddAssign",   
	   "SubAssign",       
	   "MultAssign",  
	   "DivAssign",            	 
	   "Сonjunction",
	   "Disjunction",
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

bool is_oper_str(string ch)
{
	if (ch == "+" || ch == "-" || ch == "*" || ch == "/" || ch == "^")
		return true;
	return false;
}