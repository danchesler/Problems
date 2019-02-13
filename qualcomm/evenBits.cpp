/*
Given a number, change all bits at even positions to 0.
*/

int evenBits(int n)
{
    int e = 0;
    while (e <= 8*sizeof(int))
    {
        n &= ~(1 << e);
        e += 2;
    }
    return n;
}

int main() {
	int t, n;
	cin >> t;
	
	while (t--)
	{
	    cin >> n;
	    cout << evenBits(n) << endl;
	}
	
	return 0;
}