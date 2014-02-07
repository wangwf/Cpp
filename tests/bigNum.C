#include <iostream>

struct Node{
  int data;
  Node* next;
};

Node* addTwoList(Node *l1, Node* l2, int residual){
  if (l1==NULL && l2==NULL) return NULL;

  Node *sum=new Node;
  sum->data = residual;

  if(l1) sum->data +=l1->data;
  if(l2) sum->data +=l2->data;

  residual = sum->data /10;
  sum->data = (sum->data)%10;

  Node* temp=addTwolist(l1->next, l2->next, residual);
  sum->next=temp;
  return sum;

}

/*
for(; i>=0 && j>=0; i--, j--, k++){
int t= num1[i] + num2[i] + carry;
sum[k] = t%10;
carry  = carry/10;
}
 */
