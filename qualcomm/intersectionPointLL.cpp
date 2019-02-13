/*
Two Singly Linked Lists in a system.
The end of node of one linked list got linked into the second list
	forming a Y shaped list.
Write a program to get to the point the two linked listed merge.

*/

struct Node
{
	int data;
	Node* next;
};

/*
Algorithm:
	Traverse through first list.
		Mark nodes as visited
	Traverse through second list.
		If node in hash table we have an intersection.
		Return pointer->data

*/

int intersectPoint(Node* head1, Node* head2)
{
	unordered_map<Node*, int> visited;
	Node* temp = new Node;
	
	temp = head1;
	while (temp != nullptr)
	{
		// visit by adding node to hash table
		visited.insert(make_pair(temp, true));
		temp = temp->next;
	}

	temp = head2;
	while (temp != nullptr)
	{
		// if visited return temp->data 
		if (visited.find(temp) == visited.end()) 
		{
			// node not in map so traverse
			temp = temp->next;
		}
		else
		{
			return temp->data;
		}
	}

	return -1;

}