//
//print random node from a Binary Tree
//

#ifndef NULL
#define NULL 0
#endif

struct Node{
  int val;
  Node* left;
  Node* right;
  int nNodes; //add to keep track number of Node
};

Node* randomNode(Node* head, int k){
  if(!head || k<1 || k>head->nNodes) return NULL;

  if(k==1)return head;
  //  k--;
  int nLeft=0;
  if(head->left) nLeft=head->left->nNodes;
  if(k<=nLeft) return randomNode(head->left, k-1);
  else{
    if(head->right) return randomNode(head->right, k-nLeft);
  }
}


//If don't nNodes
Node* randomNode(Node* head, int& ){
  if(!head || k<1) return NULL;

  if(k==1) return head;
  k--;
  if(head->left) return randomNode(head->left, k);
  if(head->right) return randomNode(head->right, k);
