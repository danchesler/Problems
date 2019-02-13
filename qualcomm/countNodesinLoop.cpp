int countNodesinLoop(struct Node *head)
{
    Node* s = head;
    Node* f = head;
    
    while (f && f->next)
    {
        s = s->next;
        f = f->next->next;
         
        // loop exists
        if (s == f)
        {
            // find start of loop
    		f = head;
    		while (f != s)
    		{
    			s = s->next;
    			f = f->next;
    		}
            
            // count nodes in loop
    		int count = 1;
    		Node* start = s;
    		s = s->next;
    
    		while (start != s)
    		{
    			s = s->next;
    			count++;
    		}
    
    		return count;
        }
    }
    
    return 0;
}