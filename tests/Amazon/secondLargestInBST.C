//
//  Amazon phone interview,  Gene Nilson,   3-4pm, 06/11/2012
//
//  find the seoncd largest element in a binary search tree
//
//////////////////////////////////////////////////////////////////////////

//
// My answer:
//  find the rith most element.
//     If this node with no children, return its parent; 
//     otherwise,  return the largest element of its left child(ren).
//
//  below is my code implementation
#include <iostream>
using namespace std; 

// assuming is integer
struct Node{
  int   data; 

  Node* left; 
  Node* right;

  Node(int x){
    data=x; 
    left =NULL; 
    right=NULL; 
  }
  
};


void insertNode(Node*& root, const int& x){
  if(root==NULL){
    Node* tmp=new Node(x); 
    if(!tmp) return; 
    root=tmp; 
    return; 
  }
  else if(x<=root->data){
    insertNode(root->left, x); 
  }
  else{
    insertNode(root->right, x); 
  }
}

//print all elements InOrder
void printAll(Node* root){
  if(root==NULL) return; 

  printAll(root->left); 
  cout<<" "<<root->data; 
  printAll(root->right); 
}

//reverse the inOrder traversal, 
//Note: doesnot work when the maximum duplicate
void findSecond(Node* root, int& kth){

  if(root==NULL || kth<0) return; 

  findSecond(root->right,kth); 
  kth--; 
  if(kth==0){
    cout<<root->data<<endl; 
    return; 
  }
  findSecond(root->left, kth); 
}



int main(){

  //define a binary tree and fill with random generated numbers
  int nums=10; 
  Node* r=new Node(nums/2); 
  srand(time(NULL)); 
  for(int i=0; i<nums; i++){
    insertNode(r,  rand()%nums); 
  }


  cout<<"Print All"<<endl; 
  printAll(r);  cout<<endl; 


  cout<<" second largest "<<endl; 
  int kth=2;
  findSecond(r, kth); 


  return 0; 
}
