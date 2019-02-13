/*
You are given an array A containing 2*N+2 positive numbers, 
	out of which 2*N numbers exist in pairs whereas the other two number occur exactly once and are distinct. 
You need to find the other two numbers and print them in ascending order.
*/
/*
What the question ACTUALLY asked was to return the numbers that occured in odds
	and print them in ascending order.
*/

void findingTheNumbers(int A[], int size)
{
	map<int, int> numsInA;

	// iterate thru array A
	for (int i{}; i < size; i++)
	{
		auto itr = numsInA.find(A[i]);

		// key not in map so insert
		if (itr == numsInA.end())
		{
			numsInA.insert(pair<int, int>(A[i], 1));
		}
		// key found so increment value to illustrate new instance
		else
		{
			itr->second++;
		}
	}

	vector<int> keys;

	// iterate thru hash map
	map<int, int>::iterator itr;
	for (itr = numsInA.begin(); itr != numsInA.end(); itr++)
	{
		if (itr->second == 1)
		{
			keys.push_back(itr->first); // second is the value
		}
	}

	// print keys in ascending order
	if (keys[0] < keys[1])
	{
		cout << keys[0] << " " << keys[1] << endl;
	}
	else
	{
		cout << keys[1] << " " << keys[0] << endl;
	}

}


int main() {
	int A[4] = { 2,1,3,2 };
	int size = sizeof(A) / sizeof(A[0]);

	findingTheNumbers(A, size);

	return 0;
}

// Cleaned up
void findingTheNumbers(int A[], int size)
{
	map<int, int> numsInA;

	// iterate thru A and increment value in the map to mark an instance
	for (int i{}; i < size; i++)
	{
		numsInA[A[i]]++;
	}

	vector<int> keys;

	// iterate thru hash map
	map<int, int>::iterator itr;
	for (itr = numsInA.begin(); itr != numsInA.end(); itr++)
	{
		if (itr->second % 2 != 0)
		{
			keys.push_back(itr->first);
		}
	}

	// print keys in ascending order
	sort(keys.begin(), keys.end());

	for (int i = 0; i < keys.size(); i++)
	{
		cout << keys[i] << " ";
	}
}