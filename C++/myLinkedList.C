/*
 * Linked list
 */


#include <iostream>

class myLinkedList:
{
private:
  int data; 
  myLinkedList* next; 


public:

  // constructor
  myLinkedList()

  //destructor 
    virtual ~myLinkedList(); 

  myLinkedList* addnode(myLinkedList*); 

  myLinkedList* delete(myLinkedList*)

  myLinkedList* reverseList(); 

  bool isLoop(); 
};

//recursive way
myLinkedList* myLinkedList::reverseList(myLinkedList * ptr, myLinkedList* previous)
{
  myLinkedList* temp; 

  if(ptr->next ==NULL){
    ptr->next = previous; 
    return ptr; 
  }
  else{
    temp = reverseList(ptr, previous); 
    ptr->next = previous; 
    return temp; 
   }
}
// reversedHead = reverseList(ptr, Null); 


//on-recursive
myLinkedList* myLinkedList::reverse2(myLinkedList* ptr){
  myLinkedList *temp; 
  
  myLinkedList *previous = NULL: 
  while (ptr != NULL){
    temp = ptr->next; 
    p->next = previous; 
    previous = ptr; 
    ptr = temp; 
  }

}


//check whether the list is circular, and the cycles aren't necessarily at the start

bool MyLinkedList::isLoop(){

  myLinkedList * p1, *p2; 
  while(p1){
    p1= p1->next; 
    p2= p2->next;  if(p2) p2= p2->next; 

    if(p1==p2) cout<<" This is a loop! "<<endl; 


  }

}
