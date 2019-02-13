/*
	Reverse a linked list from position m to n. Do it in one-pass.

	Note: 1 ≤ m ≤ n ≤ length of list.
*/


ListNode* reverseBetween(ListNode* head, int m, int n)
{
	ListNode* p = nullptr;
	ListNode* c = head;
	ListNode* min = nullptr;
	ListNode* end = nullptr;

	if (m > 1)
	{
		int count = 1;
		while (count < m - 1)
		{
			c = c->next;
			count++;
		}

		min = c;
		c = c->next;
		p = c;
		end = p;
		c = p->next;

		while (m < n)
		{
			ListNode* f = c->next;
			c->next = p;
			p = c;
			c = f;
			m++;
		}

		min->next = p;
		end->next = c;

		return head;
	}
	else
	{
		min = head;
		p = head;
		c = p->next;

		while (m < n)
		{
			ListNode* f = c->next;
			c->next = p;
			p = c;
			c = f;
			m++;
		}

		min->next = c;

		return p;
	}
}


int main()
{
	ListNode* head = nullptr;

	// List: 4 3 2 1 0
	for (int i = 0; i < 5; i++)
	{
		head = insert(head, i);
	}

	head = reverseBetween(head, 2, 5);

	ListNode* temp = head;
	while (temp != nullptr)
	{
		cout << temp->val << " ";
		temp = temp->next;
	}

	return 1;
}

Solution by jianchao-li on LeetCode

The basic idea is as follows:

(1) Create a new_head that points to head and use it to locate the immediate node before the m-th (notice that it is 1-indexed) node pre;

(2) Set cur to be the immediate node after pre and at each time move the immediate node after cur (named move) to be the immediate node after pre. Repeat it for n - m times.

class Solution {  
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* new_head = new ListNode(0);
        new_head -> next = head;
        ListNode* pre = new_head;
        for (int i = 0; i < m - 1; i++)
            pre = pre -> next;
        ListNode* cur = pre -> next;
        for (int i = 0; i < n - m; i++) {
            ListNode* move = cur -> next; 
            cur -> next = move -> next;
            move -> next = pre -> next;
            pre -> next = move;
        }
        return new_head -> next;
    }
};