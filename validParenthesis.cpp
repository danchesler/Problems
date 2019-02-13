#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
Given a string S of '(' and ')' parentheses, 
we add the minimum number of parentheses ( '(' or ')', and in any positions ) 
so that the resulting parentheses string is valid.
*/

int minAddToMakeValid(string S)
{
	vector<char> charStack;

	for (int stringCount = 0; stringCount < S.size(); stringCount++)
	{ 
		if (S[stringCount] == '(')
		{
			charStack.push_back(S[stringCount]);
		}
		else if (S[stringCount] == ')')
		{
			if (charStack.size() == 0 || charStack.back() != '(')
			{
				charStack.push_back(S[stringCount]);
			}

			// The stack is not empty and the top of stack is '('
			else 
			{
				charStack.pop_back();
			}
		}
	}

	return charStack.size();
}

int main()
{
	cout << minAddToMakeValid(")))(((") << endl;

	return 0;
}

// Other method using only variables

int minAddToMakeValid(string S)
{
	int open = 0; // keep track of unused open parenthesis
	int closed = 0; // keep track of extra close parenthesis

	for (int stringCount = 0; stringCount < S.size(); stringCount++)
	{ 
		if (S[stringCount] == '(')
		{
			open++;
		}
		else if (S[stringCount] == ')')
		{	
			if (open == 0) // there is an extra ')'
			{
				closed++;
			}
			else 
			{
				open--;
			}
		}
	}

	return open+closed;
}

int main()
{
	cout << minAddToMakeValid(")))((()") << endl;

	return 0;
}
