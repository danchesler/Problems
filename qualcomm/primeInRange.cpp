using namespace std;

bool checkPrime (int num)
{
	if (num == 1) return 0;

	for (int i = 2; i < sqrt(num); i++)
	{
		if (num % i == 0) return 0;
	}

	return 1;
}

int main() {
    int t;
	cin >> t;

	int m, n;

	while (t--)
	{
		cin >> m;
		cin >> n;

		while (m <= n)
		{
			if (checkPrime(m))
			{
				cout << m << " ";
			}
			m++;
		}
		cout << endl;
	}

	return 0;
}