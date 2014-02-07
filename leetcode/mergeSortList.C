
struct ListNode{
  int val;
  ListNode *next;
  ListNode(int x): val(x), next(NULL){}
};

ListNode *insertSortList(ListNode *head){
  if(head==null || head->next == null) return head;

  ListNode *p =new ListNode(0);
  p->next=head;
  head=p;
  ListNode *q;

  while (p->next != NULL){
    q=head;
    bool flag=false;
    while (q !=p){
      if(q->next->val > p->next->val){
	ListNode *tmp1=p->next;
	p->next = p->next->next;
	tmp1->next=q->next;
	q->next=tmp1;
	flag=true;
	break;
      }else{q=q->next;
      }
    }
    if(!flag){p=p->next;
    }
  }
  return head->next;
}


ListNode *mergeTwoLists(ListNode *l1, ListNode *l2){
  if(!l1) return l2;
  if(!l2) return l1;
  ListNode *c1= (l1->val <= l2->val? l1:l2); //head with smaller
  ListNode *c2= (l2->val <= l2->val? l2:l1); //head with larger
  while( c1->next !=NULL && c2 !=NULL){
    if (c1->val <= c2->val && c2->val < c1->next->val){
      //insert c2 behind of c1
      ListNode* tmp = c2->next;
      c2->next =c1->next;
      c1->next =c2;
      //advance both pointers;
      c1=c1->next;
      c2=tmp;
    }
    else{
      c1=c1->next;
    }
  }
  if(c1->next == NULL) c1->next =c2;
  return (l1->val <= l2->val? l1:l2);
}

ListNode *sortList(ListNode *head){
  if(!head || !head->next) return head;

  //Advance slow pointer to middle 
  ListNode* slow=head;
  ListNode* fast=head->next;
  while(fast!=NULL && fast->next !=NULL){
    slow = slow->next;
    fast = fast->next->next;
  }
  ListNode* newHead = slow->next;
  slow->next = NULL;
  //Sort two parts
  head=sortList(head);
  newHead = sortList(newHead);
  //merge two sorted parts)
  return mergeTwoLists(head, newHead);
}
