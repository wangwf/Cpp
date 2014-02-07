

ListNode *reverse(ListNode *head){
  if(!head) return NULL;
  ListNode *pre=NULL;
  ListNode *curr=head;
  while(curr){
    ListNode *tmp=curr->next;
    curr->next =pre;
    pre=curr;
    curr=tmp;
  }

ListNode *reverse(ListNode *begin, ListNode* end){
  ListNode *last = begin->next;
  ListNode *curr = last->next;

  while(curr != end){
    last->next = curr->next;
    curr->next = begin->next;
    begin->next=curr;
    curr=last->next;
  }
  return last;

} 

 ListNode *reverseBetween(ListNode *head, int m, int n){
   if(!head) return head;

   ListNode dummy(0);
   dummy.next = head;
   ListNode *prev=&dummy;
   ListNode *curr=head;
   int i=0;
   while(curr && ++i <n){
     if(i<m)prev=curr;
     curr = curr->next;
   }
   curr=reverse(prev, curr->next);
   return dummy.next;
 }
