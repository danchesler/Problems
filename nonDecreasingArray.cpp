#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

/*
Given: array with n integers
Task: Check if it could become non-decreasing by modifying AT MOST 1 element
Non-decreasing array: array[i] <= array[i+1]
*/

// want to:
// go through array
// if array[i] >= array[i+1]

bool checkPossibility(vector<int>& nums)
{
	int count = 0; 
	int max = 0;
	int max_count = 0;
	int max_next = 0;
	int max_index = 0;
	int max_before = 0;

	if (nums.size() == 1) return true;

	for (int i = 0; i < nums.size() - 1; i++)
	{
		if (nums[i] >= max)
		{
			if (i > 0) max_before = nums[i - 1];
			max = nums[i];
			max_count++;
			max_index = i;
			max_next = nums[i + 1];
		}

		// initialize max if negative
		else if (i == 0 && nums[i] < 0) max = nums[i];

		// can't have an undefined max_before
		if (max_index > 0) max_before = nums[max_index - 1];

		// nums[i] is greater than nums[i+1] and nums[i+1] is less than current max
		if (nums[i] > nums[i + 1] && nums[i + 1] < max)
			count++;

		/*	continue statements for checking if numbers after max_index follow the non-decreasing rule
			while also being greater than the number before max.
			continue because the rule is maintained at the current index
		*/
		// this one is for if the numbers after max are the same
		else if (nums[i] == nums[i + 1] && nums[i] < max && nums[i] > max_before)
			continue;

		// this one is for if the numbers increment
		else if (nums[i] < nums[i + 1] && nums[i] > max_before && nums[i + 1] > max_before && nums[i + 1] < max)
			continue;

		// nums[i] is equal to nums[i+1] and nums[i] is less than max
		// i.e. at least two equal numbers after max have been found
		else if (nums[i] == nums[i + 1] && nums[i] < max)
			count++;
		else if (max_count > 1 && nums[i + 1] < max)
			count++;

	}
	return (count > 1 ? false : true);
}

int main()
{
	vector<int> nums; 
	
	//// true
	//nums.push_back(2);
	//nums.push_back(3);
	//nums.push_back(3);
	//nums.push_back(2);
	//nums.push_back(4); 
	//cout << checkPossibility(nums) << endl;
	//nums.clear(); 

	//// true
	//nums.push_back(4);
	//nums.push_back(2);
	//nums.push_back(3);
	//cout << checkPossibility(nums) << endl;
	//nums.clear();

	//// false
	//nums.push_back(4);
	//nums.push_back(2);
	//nums.push_back(1);
	//cout << checkPossibility(nums) << endl;
	//nums.clear(); 


	//// false
	//nums.push_back(3);
	//nums.push_back(3);
	//nums.push_back(2);
	//nums.push_back(2);
	//cout << checkPossibility(nums) << endl;
	//nums.clear();

	//// false
	//nums.push_back(5);
	//nums.push_back(4);
	//nums.push_back(2);
	//nums.push_back(4);
	//cout << checkPossibility(nums) << endl;
	//nums.clear(); 

	//
	//// false
	//nums.push_back(3);
	//nums.push_back(4);
	//nums.push_back(2);
	//nums.push_back(3);
	//cout << checkPossibility(nums) << endl;
	//nums.clear();

	//// true
	//nums.push_back(1);
	//nums.push_back(2);
	//nums.push_back(5);
	//nums.push_back(3);
	//nums.push_back(3);
	//cout << checkPossibility(nums) << endl;
	//nums.clear();

	//// true
	//nums.push_back(1);
	//nums.push_back(2);
	//nums.push_back(5);
	//nums.push_back(3);
	//nums.push_back(4);
	//cout << checkPossibility(nums) << endl;
	//nums.clear();

	// false
	nums.push_back(-1);
	nums.push_back(-1);
	nums.push_back(-1);
	nums.push_back(-1);
	nums.push_back(-1);
	cout << checkPossibility(nums) << endl;
	nums.clear();

	return 1;
}
