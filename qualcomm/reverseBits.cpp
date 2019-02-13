#include <iostream>
#include <bitset>

using namespace std;

/*
Given a 32 bit number x, reverse its binary form and print the answer in decimal.
*/

unsigned int reverseBits(int num)
{
	bitset<32> rev(num);
	int l = 0, r = rev.size() - 1;
	int temp = 0;

	while (l < r)
	{
		temp = rev[l];
		rev[l] = rev[r];
		rev[r] = temp;
		l++;
		r--;
	}

	unsigned int reversed_num = (int)(rev.to_ulong());

	return reversed_num;
}

int main() {
	
	unsigned int t, n;
	cin >> t;

	while (t--)
	{
		cin >> n;
		cout << reverseBits(n) << endl;
	}

	return 0;
}