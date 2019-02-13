/*
    Implement the partition function for quick sort
*/

int partition (int arr[], int low, int high)
{
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (arr[j] > arr[high]) continue;
        else swap(arr[++i], arr[j]);
    }
    
    swap(arr[i+1], arr[high]);
    
    return i+1;
}

void quickSort(int arr[], int low, int high) {
	if (low < high) {
		// pi is partitioning index, arr[p] is now  at right place
		int pi = partition(arr, low, high);
		// Separately sort elements before / partition and after partition
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}