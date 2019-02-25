// Given a linked list of only 0,1,2 sort it

// Answer 1
void sortList(List* head)
{
	List* i = head;
	List* j = head;

	for (int count = 0; count < 3; count++)
	{
		while (j != nullptr && i != nullptr)
		{
			if (j->data == count)
			{
				swap(i->data, j->data);
				i = i->next;
				j = j->next;
			}
			else
			{
				j = j->next;
			}
		}
		j = i;
	}
}

// Answer 2
// Can compress it by using arrays, same logic otherwise
void sortListCount(List* head)
{
	int n0 = 0, n1 = 0, n2 = 0;
	List* temp = head;

	while (temp != nullptr)
	{
		if (temp->data == 0)
			n0++;
		else if (temp->data == 1)
			n1++;
		else
			n2++;
		temp = temp->next;
	}

	temp = head;
	while (temp != nullptr)
	{
		while (n0 > 0)
		{
			temp->data = 0;
			temp = temp->next;
			n0--;
		}
		while (n1 > 0)
		{
			temp->data = 1;
			temp = temp->next;
			n1--;
		}
		while (n2 > 0)
		{
			temp->data = 2;
			temp = temp->next;
			n2--;
		}
	}
}