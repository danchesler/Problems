/*
Given two binary strings, return their sum (also a binary string).
The input strings are both non-empty and contains only characters 1 or 0.
*/

string addBin(string a, string b)
{
	string sum = "";
	bool carry = 0;
	int bi = b.size() - 1;

	// if a and b are same size it will produce the sum
	for (int ai = a.size() - 1; ai >= 0; ai--)
	{
		if (bi >= 0)
		{
			// both either 0 or 1
			if (a[ai] == b[bi])
			{
				// both are 1
				if (a[ai] == '1')
				{
					// 1 + 1 + 1
					if (carry)
					{
						sum.append("1");
					}
					// 1 + 1 + 0
					else
					{
						sum.append("0");
					}
					carry = 1;
				}
				// both are 0 so just check carry
				else
				{	// 0 + 0 + 1
					if (carry)
						sum.append("1");
					// 0 + 0 + 0
					else
						sum.append("0");
					carry = 0;
				}
			}
			// a and b are different
			else
			{	// 1 + 0 + 1
				if (carry)
				{
					sum.append("0");
					carry = 1;
				}
				// 1 + 0 + 0
				else
				{
					sum.append("1");
				}
			}

			bi--;
		}
		else
		{
			if (a[ai] == '1')
			{
				// 1 + 1
				if (carry)
				{
					sum.append("0");
					carry = 1;
				}
				// 1 + 0
				else
				{
					sum.append("1");
					carry = 0;
				}
			}
			else
			{
				// 0 + 1
				if (carry)
				{
					sum.append("1");
					carry = 0;
				}
				// 0 + 0
				else
				{
					sum.append("0");
				}
			}
		}
	}
	
	if (carry)
		sum.append("1");

	return sum;
}


string addBinary(string a, string b)
{
	string sum = "";

	if (a.size() >= b.size())
	{
		sum = addBin(a, b);
	}
	else
	{
		sum = addBin(b, a);
	}

	int i = 0, j = sum.size()-1;
	char temp;

	while (i < j)
	{
		swap(sum[i], sum[j]);
		i++;
		j--;
	}

	return sum;
}

int main()
{
	string sum = addBinary("1010", "1011");
	for (int i = 0; i < sum.size(); i++)
	{
		cout << sum[i];
	}

	return 0;
}
