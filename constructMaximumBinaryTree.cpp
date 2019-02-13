#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

/*
Given array make a maximum tree based on the following properties:
	1) Root is the max number in array
	2) Left subtree is the max tree made from left subarray divided by max number
	3) Right subtree is the max tree made from right subarray divided by max number
*/

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int getMax(vector<int>& nums)
{
	int maxIndex = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] > nums[maxIndex])
		{
			maxIndex = i;
		}
	}
	return maxIndex;
}

TreeNode* constructMaximumBinaryTree(vector<int>& nums)
{
	// if size == 1 then it is max
	if (nums.size() == 1)
	{
		TreeNode* root = new TreeNode(nums[0]);
		return root;
	}

	// insert max into node
	int max_index = getMax(nums);
	TreeNode* root = new TreeNode(nums[max_index]);

	// check if the max index is at leftmost index
	if (max_index == 0)
	{
		vector<int> right_array;
		for (int right_count = 1; right_count < nums.size(); right_count++)
		{
			right_array.push_back(nums[right_count]);
		}

		root->right = constructMaximumBinaryTree(right_array);
	}
	// check if max index is at rightmost index
	else if (max_index == nums.size() - 1)
	{
		vector<int> left_array;
		for (int left_count = 0; left_count < max_index; left_count++)
		{
			left_array.push_back(nums[left_count]);
		}
		root->left = constructMaximumBinaryTree(left_array);
	}
	// max index is not at leftmost or rightmost index so make left and right
	else
	{
		vector<int> left_array;
		for (int left_count = 0; left_count < max_index; left_count++)
		{
			left_array.push_back(nums[left_count]);
		}

		vector<int> right_array;
		for (int right_count = max_index + 1; right_count < nums.size(); right_count++)
		{
			right_array.push_back(nums[right_count]);
		}

		root->left = constructMaximumBinaryTree(left_array);
		root->right = constructMaximumBinaryTree(right_array);
	} 

	return root;
}

int main()
{
	vector<int> nums;
	nums.push_back(3);
	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(6);
	nums.push_back(0);
	nums.push_back(5);
	
	TreeNode* maxTree = constructMaximumBinaryTree(nums);
	cout << "Left side\n";
	cout << maxTree->left->val;
	cout << maxTree->left->right->val;
	cout << maxTree->left->right->right->val << endl;

	cout << "Right side\n";
	cout << maxTree->right->val;
	cout << maxTree->right->left->val;


	return 1;
}
