#include "pch.h"
#include <iostream>
#include <vector>
#include <array>
#include <queue>

using namespace std;


/*
Given a sorted array A[]  ( 0 based index ) and a key "k"  you need to complete the function bin_search to 
	determine the position of the key if the key is present in the array. 
If the key is not  present then you have to return -1. 
The arguments left and right denotes the left most index and right most index of the array A[] .
There are multiple test cases. 
For each test case, this function will be called individually.
*/

struct Node
{
	int data;
	Node* left;
	Node* right;

	Node(int d)
	{
		data = d;
		left = nullptr;
		right = nullptr;
	}
};

/*
A binary search tree's properties
	binary tree so two children
	everything on the left is less than its parent
	everything on the right is greater than its parent
	this applies to every node in the tree
Need to check if this property holds true for the tree
*/


Node* insertRightmost(Node* root, int data)
{
	if (root->right != nullptr)
		insertRightmost(root->right, data);
	else
	{
		Node* node = new Node(data);
		root->right = node;
	}

	return root;
}

Node* insertLeftAtRightmost(Node* root, int data)
{
	if (root->right != nullptr)
	{
		insertLeftAtRightmost(root->right, data);
	}
	else 
	{
		Node* node = new Node(data);
		root->left = node;
	}

	return root;
}

Node* insertLeftmost(Node* root, int data)
{
	if (root->left != nullptr)
		insertLeftmost(root->left, data);
	else
	{
		Node* node = new Node(data);
		root->left = node;
	}

	return root;
}

Node* insertRightAtLeftmost(Node* root, int data)
{
	if (root->left != nullptr)
	{
		insertRightAtLeftmost(root->left, data);
	}
	else
	{
		Node* node = new Node(data);
		root->right = node;
	}

	return root;
}

// Solution using a global flag
/*
	A BST has different traversal options: In-Order, Pre-Order, Post-Order
	Traversing through In-Order should return an ascending sequence of numbers
	If the array is not in order then it's not a BST.
*/
/****************************************/
bool checkBst = 1;
void isBstInOrder(Node* root, vector<int> &array)
{
	if (root == nullptr) return;

	isBstInOrder(root->left, array);

	array.push_back(root->data);
	if (array.size() > 1)
	{
		if (array[array.size() - 1] < array[array.size() - 2])
			checkBst = 0;
	}
	isBstInOrder(root->right, array);
}

bool isBst(Node* root)
{
	vector<int> array;
	isBstInOrder(root, array);

	return checkBst;
}
/****************************************/

int main() {

	// not bst
	Node* root3 = new Node(1);
	root3 = insertRightmost(root3, 2);
	root3 = insertRightmost(root3, 4);
	root3 = insertRightmost(root3, 5);
	root3 = insertRightmost(root3, 6);
	root3 = insertRightmost(root3, 7);
	root3 = insertLeftAtRightmost(root3, 8);

	// not bst
	/*Node* root3 = new Node(20);
	root3 = insertLeftmost(root3, 10);
	root3 = insertLeftmost(root3, 5);
	root3 = insertLeftmost(root3, 1);
	root3 = insertRightAtLeftmost(root3, 50);
*/
	cout << isBst(root3) << endl;
	
	return 0;
}
