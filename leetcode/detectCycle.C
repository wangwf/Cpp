

struct ListNode{
  int val;
  ListNode *next;
  ListNode(int x): val(x), next(NULL){}
}


  ListNode *detectCycle(ListNode *head){
    ListNode *slow=head;
    ListNode *fast=head;
    while(slow&&fast&&fast->next){
      slow=slow->next;
      fast=fast->next->next;
      if(slow==fast){//is Cycle
	slow=head;
	while(slow !=fast){
	  slow=slow->next;
	  fast=fast->next;
	}
	return slow;
      }
    }
    retun NULL;
  }
