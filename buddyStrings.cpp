/*
Given two strings A and B of lowercase letters, 
return true if and only if we can swap two letters in A so that the result equals B.
*/

bool buddyStrings(string A, string B)
{
	if (A.size() != B.size() || A.size() <= 1 || B.size() <= 1) 
		return false;

	bool diff_flag = false;
	bool dupe = false;
	vector<int> index;
	vector<char> chars_used;

	// add two indices to index vector
	for (int i = 0; i < A.size(); i++)
	{
		if (A[i] != B[i])
			index.push_back(i);
		else
		{
			for (int p = 0; p < chars_used.size(); p++)
			{
				if (A[i] == chars_used[p])
					dupe = true;
			}
			chars_used.push_back(A[i]);
		}
			
		// if more than two numbers in vector then cannot swap
		if (index.size() > 2) 
			return false;

		if (i < A.size() - 1)
		{
			if (A[i] != A[i + 1])
				diff_flag = true;
			if (A[i] == B[i] && A[i] == A[i + 1] && B[i] == B[i + 1])
				dupe = true;
		}

	}

	if (index.size() != 0)
	{
		if (A[index[0]] == B[index[1]] && A[index[1]] == B[index[0]])
			return true;
	}
	if (diff_flag && dupe)
		return true;
	if (diff_flag)
		return false;
	else
		return true;
}

int main()
{
	string A, B;

	// true
	A = "ab";
	B = "ba";
	cout << buddyStrings(A, B) << endl;

	// false
	A = "ab";
	B = "ab";
	cout << buddyStrings(A, B) << endl;

	// true
	A = "aa";
	B = "aa";
	cout << buddyStrings(A, B) << endl;

	// true
	A = "aaaabc";
	B = "aaaacb";
	cout << buddyStrings(A, B) << endl;

	// false
	A = "";
	B = "aa";
	cout << buddyStrings(A, B) << endl;

	// true
	A = "abca";
	B = "abca";
	cout << buddyStrings(A, B) << endl;

	// true
	A = "fghaa";
	B = "fghaa";
	cout << buddyStrings(A, B) << endl;
	return 1;
}


// solution by coderr0r on LeetCode
bool buddyStrings(string A, string B) {
	int alen = A.size();
	int blen = B.size();
	if (alen != blen || alen < 2)
		return false;

	array<int, 2> diffpos{};
	int didx{}; // same as didx = 0

	// find diffs
	for (int i{}; i < alen; ++i) {
		if (A[i] != B[i]) {
			diffpos[didx] = i;
			didx++;
			if (didx > 2) {				// too many diffs
				return false;
			}
		}
	}

	// no diffs, but if any char is repeated, it can be swapped
	if (didx == 0) {
		array<int, 26> histogrm{};
		for (int ch : A) {
			int chidx = ch - 'a';
			if (histogrm[chidx] > 0) {
				return true;
			}
			histogrm[chidx]++;
		}
	}
	if (didx == 2) {           // 2 diffs found, see if swappable
		swap(A[diffpos[0]], A[diffpos[1]]);
		if (A == B) {
			return true;
		}
	}
	return false;
}