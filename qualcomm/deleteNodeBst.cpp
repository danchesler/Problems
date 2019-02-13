#include "pch.h"
#include <iostream>


using namespace std;

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

Node* Insert(Node* root, int data)
{
	if (root == nullptr)
	{
		root = new Node(data);
	}
	else if (data <= root->data)
	{
		root->left = Insert(root->left, data);
	}
	else
	{
		root->right = Insert(root->right, data);
	}
	return root;
}

/* 
	Write a program to delete a node in a BST
	We need traverse the tree to find the node we want to delete.
	Check if number exists first
	If num < root we traverse left, if num > root we go right
	We'll go thru the BST until we reach the number or a nullptr
	if the number exists we delete, if not then we return something to tell us it doesnt exist

	If we find the number
*/

bool searchBst(Node* root, int x)
{
	if (root == nullptr)
	{
		return false;
	}
	// x > root so go right
	else if (x > root->data)
	{
		return searchBst(root->right, x);
	}
	// x < root so go left
	else if (x < root->data)
	{
		return searchBst(root->left, x);
	}
	// neither nullptr or > or < so it must be it
	else
	{
		return true;
	}
}

void inOrderTraversal(Node* root)
{
	if (root != nullptr)
	{
		inOrderTraversal(root->left);
		
		cout << root->data << " ";

		inOrderTraversal(root->right);
	}
}

// Solution
/*********************************/
Node* inOrderSuccessor(Node* root)
{
	while (root->left != nullptr)
	{
		root = root->left;
	}
	return root;
}

Node* deleteNode(Node* root, int x)
{
	if (root == nullptr) 
		return root;

	else if (x > root->data)
	{
		root->right = deleteNode(root->right, x);
	}
	else if (x < root->data)
	{
		root->left = deleteNode(root->left, x);
	}
	// found match, time to delete it
	else
	{
		// Case 1 and 2: no children or 1 child
		// If left is nullptr then we bring the right child up the tree
		// This works whether right is nullptr or right contains nodes
		// If root->right is nullptr then we return nullptr for our delWeted node
		// if root->right exists then we just brought up the right tree
		if (root->left == nullptr)
		{
			Node* temp = root->right;
			delete root;
			return temp;
		}
		else if (root->right == nullptr)
		{
			Node* temp = root->left;
			delete root;
			return temp;
		}
		// Case 3: 2 children
		else
		{
			// find our in-order successor
			Node* succ = inOrderSuccessor(root->right);

			// transfer successor data to node we were to delete
			root->data = succ->data;

			// delete the in order successor
			// if successor has 1 child it will use our 1 child case
			root->right = deleteNode(root->right, succ->data);
		}
	}
	return root;
}
/*********************************/

int main() {

	Node* root = nullptr;
	for (int i = 0; i < 11; i++)
	{
		root = Insert(root, i);
	}

	cout << "Before delete: " << endl;
	inOrderTraversal(root);
	cout << endl;

	root = deleteNode(root, 10);

	cout << "After delete: " << endl;
	inOrderTraversal(root);
	cout << endl;



	return 0;
}
