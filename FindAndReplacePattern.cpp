

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

//  Find and replace pattern
//	Given a list of words and a pattern, want to know which words in the list matches the pattern
//	E.g. Given words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
//		Output = ["mee", "aqq"]

// Solution implements a hash table provided by the unordered_map in STL

// Generates a generic pattern with numbers based on the parameter 'pattern'
vector<int> findPattern(string pattern)
{
	unordered_map<char, int> symbol_map;
	vector<int> generic_pattern;

	// Go through the string elements
	for (unsigned int pattern_count = 0; pattern_count < pattern.length(); pattern_count++) 
	{

		if (symbol_map.find(pattern[pattern_count]) == symbol_map.end()) /* symbol not in map */
		{
			/* add symbol and current count to map */
			symbol_map.insert(make_pair(pattern[pattern_count], pattern_count));

			/* store count in generic_pattern */
			generic_pattern.push_back(pattern_count);
		}
		else /* symbol in map */
		{
			/* append to generic_pattern */
			generic_pattern.push_back(symbol_map[pattern[pattern_count]]);
		}
	}

	return generic_pattern;
}

vector<string> findAndReplacePattern(vector<string> &words ,string pattern) // change back to pattern
{
	unordered_map<char, int> symbol_map;
	vector<int> generic_pattern;
	vector<int> base_generic_pattern;
	vector<string> returned_patterns;


	base_generic_pattern = findPattern(pattern);

	// Go through vector of words
	for (unsigned int vector_count = 0; vector_count < words.size(); vector_count++) 
	{
		generic_pattern = findPattern(words[vector_count]);

		// Check if generic pattern matches base pattern
		if (generic_pattern == base_generic_pattern)
		{
			// Append to returned_patterns if they match
			returned_patterns.push_back(words[vector_count]);
		}
	}

	return returned_patterns;
}


int main()
{
	vector<string> strInput;
	vector<string> returned_patterns;

	strInput.push_back("abcdabc");
	strInput.push_back("deqdabc");
	strInput.push_back("meemabc");
	strInput.push_back("aqqaabc");
	strInput.push_back("dkddabc");
	strInput.push_back("cccdabc");
	strInput.push_back("dggddgl");
	strInput.push_back("wppwwpo");

	string pattern = "abbaabc";

	returned_patterns = findAndReplacePattern(strInput, pattern);

	for (unsigned int pattern_count = 0; pattern_count < returned_patterns.size(); pattern_count++)
	{
		cout << returned_patterns[pattern_count] << " ";
	}

	return 0;
}
