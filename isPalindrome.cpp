bool isPalindrome(string s)
{
	if (s.size() == 0 || s.size() == 1) return true;

	int lcount = 0;
	int rcount = s.size() - 1;

	while (lcount <= rcount)
	{
		// if we exhaust the symbols and we finish counting it's a palindrome
		// this covers the string of only symbols case
		while (!isalnum(s[lcount]) && lcount <= rcount) lcount++;
		while (!isalnum(s[rcount]) && lcount <= rcount) rcount--;

		// check if the pair is uppercase/lowercase version of each other
		if (isalpha(s[lcount]) && isalpha(s[rcount]))
		{
			if ((s[lcount] - s[rcount] == 32) || (s[rcount] - s[lcount] == 32))
			{
				lcount++;
				rcount--;
				continue;
			}
		}
		// otherwise check if equal
		if (s[lcount] == s[rcount])
		{
			lcount++;
			rcount--;
		}
		// if neither check out and we're not done yet then it's not a palindrome
		else if (lcount <= rcount) return false;
	}

	return true;
}