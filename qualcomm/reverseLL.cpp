/*
Reverse a linked list
*/

// Iterative
Node* reverseLL(Node* head)
{
	Node* prev = nullptr;
	Node* cur = head;

	while (cur != nullptr)
	{
		Node* next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}

	return prev;

// Recursively
Node* reverse(Node* head)
{
	if (head->next == nullptr) return head;
	Node* newHead = reverse(head->next);
	head->next->next = head;
	head->next = NULL;

	return newHead;
}