/*
	Implement merge function for merge sort
*/

void merge(int arr[], int l, int m, int r)
{
	int lc = l, mr = m + 1;
	int tsize = r - 1 + 1, tc = 0;
	int *temp = new int[tsize+1];

	for (int i = l; i <= r; i++)
	{
		// left side is exhausted so append right side
		if (lc > m)
			temp[tc++] = arr[mr++];
		// right side is exhausted so append left side
		else if (mr > r)
			temp[tc++] = arr[lc++];

		// left side less than right side
		else if (arr[lc] < arr[mr])
			temp[tc++] = arr[lc++];
		// right side less than or equal to left side
		else
			temp[tc++] = arr[mr++];
	}

	// copy temp array into original array
	for (lc = l, tc = 0; tc < tsize && lc <= r; lc++, tc++)
	{
		arr[lc] = temp[tc];
	}

	delete[] temp;
}

void mergeSort(int arr[], int l, int r) {
	if (l < r) {
		int m = l + (r - l) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}