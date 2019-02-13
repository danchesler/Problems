/*
Given two arrays: arr1[0..m-1] of size m and arr2[0..n-1] of size n. 
Task is to check whether arr2[] is a subset of arr1[] or not. 
Both the arrays can be both unsorted or sorted. It may be assumed that elements in both array are distinct.
*/


#include <iostream>
using namespace std;

bool arraySubset(int arr1[], int s1, int arr2[], int s2)
{
    bool match;
    
    for (int i2{}; i2 < s2; i2++)
    {
        match = false;
        
        for (int i1{}; i1 < s1; i1++)
        {
            if (arr2[i2] == arr1[i1])
            {
                match = true;
            }
        }
        
        if (!match) return match;
    }
    
    return match;
}

int main() {
	int t;
	cin >> t;
	
	int m, n;
	
	while (t--)
	{
	    cin >> m >> n;
	    int arr1[m], arr2[n];
	    
	    for (int i = 0; i < m; i++)
	    {
	        cin >> arr1[i];
	    }
	    
	    for (int j = 0; j < n; j++)
	    {
	        cin >> arr2[j];
	    }
	    
	    int s1 = sizeof(arr1)/sizeof(arr1[0]);
	    int s2 = sizeof(arr2)/sizeof(arr2[0]);
	    
	    if (arraySubset(arr1, s1, arr2, s2))
	    {
	        cout << "Yes" << endl;
	    }
	    else
	    {
	        cout << "No" << endl;
	    }
	    
	}
	   
	return 0;
}