#include <iostream>
#include <string>

using namespace std;

/*
 Implement the function strstr. 
 The function takes two strings as arguments (s,x) and locates the occurrence of the string x in the string s. 
 The function returns and integer denoting the first occurrence of the string x in s.
*/

int mystrstr(string s, string x)
{
	for (int is = 0; is < s.size(); is++)
	{
		if (s[is] == x[0])
		{
			int start = is;
			int ix;
			for (ix = 1; ix < x.size(); ix++)
			{
				is++;
				if (s[is] != x[ix]) break;
			}

			if (ix == x.size()) return start;
		}
	}

	return -1;
}

int main()
{
	//cout << mystrstr("GeeksForGeeks", "Fr") << endl;
	cout << mystrstr("GeeksForGeeks", "For") << endl;

	return 0;
}
