#include "pch.h"
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
Numbers are stored in reverse in linked lists.
Add them together into a new reversed linked list.
*/

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* insertList(ListNode* node, int val)
{
	if (node == nullptr)
	{
		node = new ListNode(val);
		return node;
	}
	else
	{
		ListNode* temp = new ListNode(val);
		temp->next = node;
		return temp;
	}
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
	ListNode* return_List = nullptr;
	ListNode* temp1 = l1;
	ListNode* temp2 = l2;
	int carry = 0;
	vector<int> stack; // hold number to store in return_List
	int sum = 0;

	// compress all this if-else crap with ternary operator
	// append to return_list in the while loop
	while (temp1 != nullptr || temp2 != nullptr)
	{
		if (temp1 != nullptr && temp2 == nullptr)
			sum = carry + temp1->val;
		else if (temp1 == nullptr && temp2 != nullptr)
			sum = carry + temp2->val;
		else
			sum = carry + temp1->val + temp2->val;

		carry = sum / 10;

		stack.push_back(sum % 10);

		if (temp1 != nullptr) temp1 = temp1->next;
		if (temp2 != nullptr) temp2 = temp2->next;
	}

	if (carry > 0) stack.push_back(carry);

	for (int i = stack.size()-1; i >= 0; i--)
	{
		return_List = insertList(return_List, stack[i]);
	}

	return return_List;
}

int main()
{
	// List 1
	int num1[1] = { 0 };
	ListNode* list1 = nullptr;
	for (int i = 0; i < sizeof(num1) / sizeof(num1[0]); i++)
	{
		list1 = insertList(list1, num1[i]);
	}

	// List 2
	int num2[1] = { 0 };
	ListNode* list2 = nullptr;
	for (int w = 0; w < sizeof(num2) / sizeof(num2[0]); w++)
	{
		list2 = insertList(list2, num2[w]);
	}
	
	ListNode* return_List = addTwoNumbers(list1, list2);
	
	ListNode* temp = return_List;

	while (temp != nullptr)
	{
		cout << temp->val;
		temp = temp->next;
	}
	
	return 1;
}
