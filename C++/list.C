
#include <cstddef>

#include <iostream>
using namespace std;

//
struct ListNode{
  int val;
  ListNode *next;
  ListNode(int x): val(x), next(NULL){}
};

//
ListNode *reverseList(ListNode* head){
  if(!head || !head->next) return head;

  ListNode *prev = NULL;
  ListNode *curr=head;

  while(curr){
    ListNode *t= curr->next;
    curr->next = prev;
    prev = curr;
    curr=t;
  }
  return prev;
}

// reverse print a list:  recursive or using stack
void reversePrintList(ListNode* head){
  if(!head) return;
  reversePrintList(head->next);
  cout<<head->val<<" ";
}

//merge two sorted lists
ListNode *mergedTwoLists(ListNode *l1, ListNode *l2){
  ListNode *head = new ListNode(0);
  head->next = l1;
  if(!l1) head->next=l2;

  ListNode *prev=head;
  //  ListNode *curr=l1;

  while(l1 && l2){
    if(l1->val <l2->val){
      if(l1->next){
        prev=l1;
        l1=l1->next;
      }else{
        l1->next=l2;
        break;
      }
    } else{
      ListNode *tmp=l2->next;
      prev->next=l2;
      l2->next=l1;
      prev=l2;
      l2=tmp;
    }
  }

  return head->next;
}

bool isCirclar(ListNode* head){
  if(!head || !head->next) return false;
  ListNode *slow=head;
  ListNode *fast=head;

  while(fast && fast->next){
    slow = slow->next;
    fast=fast->next->next;
    if(slow == fast) return true;
  }
  return false;
}

//Two linked list intersection
// if yes, the last node must be same.
bool isIntersection(ListNode* head1, ListNode* head2){
  if(!head1 || !head2)return false;

  ListNode *end1=head1;
  while(end1->next) end1=end1->next;
  ListNode *end2=head2;
  while(end2->next) end2=end2->next;
  return end1 == end2;
}

ListNode* firstIntersection(ListNode* head1, ListNode* head2){
  if(!head1 || !head2)return NULL;
  int len1=0;
  ListNode *end1=head1;
  while(end1->next){
    len1++;
    end1 = end1->next;
  }
  int len2=0;
  ListNode *end2=head2;
  while(end2->next){
    len2++;
    end2 = end2->next;
  }
  if(end1 != end2) return NULL; //no intersection

  ListNode *p1=head1;
  ListNode *p2=head2;
  while(len1>len2){
    len1--;
    p1=p1->next;
  }
  while(len2>len1){
    len2--;
    p2=p2->next;
  }

  while(p1!= p2){
    p1=p1->next;
    p2=p2->next;
  }
  return p1;
}

// a circlar list, the first node into circle

ListNode* getFirstNodeInCirclar(ListNode* head){
  if(!head || !head->next) return NULL;

  ListNode *p1=head, *p2=head;
  bool isCirclar=false;
  while(p2 && p2->next){
    p1 = p1->next;
    p2 = p2->next->next;
    if(p1 == p2){
      isCirclar=true;
      break;
    }
  }
  if(!isCirclar) return NULL;

  p1=head;
  while(p1 != p2){
    p1=p1->next;
    p2=p2->next;
  }
  return p1;
}
