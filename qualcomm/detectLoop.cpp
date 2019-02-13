int detectloop(Node *head)
{
   Node* slow = head;
   Node* fast = head;
   
   while (slow != nullptr && fast != nullptr && fast->next != nullptr)
   {
       slow = slow->next;
       fast = fast->next->next;
       
       if (slow == fast)
       {
           return 1;
       }
   }
   
   return 0;
}