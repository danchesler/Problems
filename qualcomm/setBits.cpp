#include <iostream>
using namespace std;

/*
Given a positive integer N, print count of set bits in it. 
For example, if the given number is 6(binary: 110), output should be 2 as there are two set bits in it.
*/

int setBits(int num)
{
	int bits = 0;
	int r;

	while (num > 0)
	{
		r = num % 2;
		if (r) bits++;
		num /= 2;
	}

	return bits;
}

int main() {
    int t;
    cin >> t;
    
    while (t--)
    {
        int n;
        cin >> n;
        cout << setBits(n) << endl;
    }
    
	return 0;
}