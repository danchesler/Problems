/*
Given a sorted array A[]  ( 0 based index ) and a key "k"  you need to complete the function bin_search to 
	determine the position of the key if the key is present in the array. 
If the key is not  present then you have to return -1. 
The arguments left and right denotes the left most index and right most index of the array A[] .
There are multiple test cases. 
For each test case, this function will be called individually.
*/

int bin_search(int A[], int left, int right, int k)
{
	int size = right - left + 1;
	int middle = left + size/2;
	int position = 0;

	// found it in middle
	if (A[middle] == k) 
		return middle;

	// reached minimum size but no match
	else if (size == 0 && A[middle != k])
		return -1;

	// key less than middle so go left;
	else if (k < A[middle])
		position = bin_search(A, left, middle - 1, k);

	// key greater than middle so go right
	else // k > A[middle]
		position = bin_search(A, middle + 1, right, k);

	return position;
}

// Cleaner version
int bin_search(int A[], int left, int right, int k)
{
	int size = right - left + 1;
	int middle = left + size/2;

	if (right >= left)
	{
		// found it in middle
		if (A[middle] == k)
			return middle;

		// key less than middle so go left;
		else if (k < A[middle])
			return bin_search(A, left, middle - 1, k);

		// key greater than middle so go right
		else // k > A[middle]
			return bin_search(A, middle + 1, right, k);
	}
	else
		return -1;
}