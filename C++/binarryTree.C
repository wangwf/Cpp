#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;


struct node{
  int data;
  node* left;
  node* right;
  node(int x): data(x), left(NULL), right(NULL){}
};

//number of nodes
int getNum(node* root){
  if(!root) return 0;
  return getNum(root->left) + getNum(root->right) +1;
}

//level of trees
int getDepth(node* root){
  if(!root) return 0;
  int left  = getDepth(root->left);
  int right = getDepth(root->right);
  return left>right? left+1: right+1;
}

//pre-order, inorder, post-order traversal

void preOrder(node* root){
  if(!root) return;

  //  visited(root);
  cout<<root->data<<endl;
  preOrder(root->left);
  preOrder(root->right);
}

//inorder, leftChild, root, rightChild
void inOrder(node* root){
  if(!root) return;

  inOrder(root->left);
  cout<<root->data<<endl;
  inOrder(root->right);
}

void postOrder(node* root){
  if(!root) return;
  postOrder(root->left);
  postOrder(root->right);
  cout<<root->data<<endl;
}


//level-traversal
void levelOrder(node* root){
  if(!root) return;

  queue<node*> q;
  q.push(root);
  while(!q.empty()){
    node* t=q.front(); q.pop();
    cout<<t->data<<endl; //visit
    if(t->left)  q.push(t->left);
    if(t->right) q.push(t->right);
  }
  return;
}


//flatten Binary tree to a linked list, in place
void flatbt(node* root, vector<int>& l){
  if(!root) return;
  l.push_back(root->data);
  flatbt(root->left, l);
  flatbt(root->right, l);
}
void flatten(node* root){
  if(!root) return;
  vector<int> l;
  flatbt(root, l);
  node* head =root;
  for(int i=0; i<l.size(); i++){
    head->right = new node(l[i]);
    head->left = NULL;
    head =head->right;
  }
  return;
}

//covert BT to sorted doublelinked list

void convert(node* root, node* firstNode, node* lastNode){
  node *firstLeft, *lastLeft, *firstRight, *lastRight;
  if(!root){
    firstNode=NULL;
    lastNode =NULL;
    return;
  }

  if(root->left == NULL){
    //if leftChilde is NULL, root is the first node
    firstNode=root;
  }
  else{
    convert(root->left, firstLeft, lastLeft);
    firstNode= firstLeft;
    root->left = lastLeft;
    lastLeft->right=root;
  }

  if(root->right == NULL){
    // rightChild is NULL, root is the last node;
    lastNode = root;
  }else{
    convert(root->right, firstRight, lastRight);
    lastNode = lastRight;
    root->right = firstRight;
    firstRight->left=root;
  }
  return;
}

//number of nodes in k-th level
int getNumKthLevel(node* root, int kth){
  if(!root) return 0;
  if(kth==1) return 1;
  int left = getNumKthLevel(root->left, kth-1);
  int right = getNumKthLevel(root->right, kth-1);
  return left+right;
}

//number of leaf
int getNumOfLeaf(node* root){
  if(!root)return 0;
  if(root->left == NULL && root->right==NULL) return 1;
  int left = getNumOfLeaf(root->left);
  int right = getNumOfLeaf(root->right);
  return left + right;
}


//whether two tree has same structure
bool sameTree(node* r1, node* r2){
  if( !r1 && !r2) return true;
  if( (r1==NULL) != (r2==NULL)) return false;
  bool left= sameTree(r1->left, r2->left);
  bool right=sameTree(r1->right, r2->right);
  return left&&right;
}


//balanced BT
int getBalancedBT(node *root, bool& balanced){
  if(!root || !balanced) return 0;
  int left= 1+ getBalancedBT(root->left, balanced);
  int right= 1+ getBalancedBT(root->right, balanced);
  return left>right? left:right;
}

bool isBalancedBT(node* root){
  if(!root) return true;
  bool balanced =true;
  getBalancedBT(root, balanced);
  return balanced;
}

//BT parity symmetric
node* mirror(node* root){
  if(!root) return NULL;
  node* left= mirror(root->left);
  node* right=mirror(root->right);

  root->left = right;
  root->right = left;
  return root;
}

//BT parity symmetric, two-queue method
bool isSymmetric(node *root){
  if(!root) return true;
  queue<node*> leftQ, rightQ;
  leftQ.push(root->left);
  rightQ.push(root->right);

  while(!leftQ.empty() && !rightQ.empty()){
    node* l=leftQ.front(); leftQ.pop();
    node* r=rightQ.front(); rightQ.pop();
    if(!l && !r) continue;
    if(!l || !r) return false;
    if(l->data != r->data) return false;
    leftQ.push(l->left);
    leftQ.push(l->right);
    rightQ.push(r->right);
    rightQ.push(r->left);
  }
  return true;
}

//find Lowest common ancestor

node *findLCA(node* root, node *p, node* q){
  if(!root) return NULL;
  if(root== p || root==q) return root;

  node* l= findLCA(root->left, p, q);
  node* r=findLCA(root->right, p, q);
  if(l&&r) return root;
  return l? l:r;
}


//maximum distance
int getMaxDistance(node* root, int& maxLeft, int& maxRight)
{
  //maxLeft  :  max-distance left-tree
  //maxRight :  max-distance right-tree
  //maxLL, maxLR, maxRL, maxRR: depth
  if(!root){
    maxLeft=0;
    maxRight=0;
    return 0;
  }

  int maxLL, maxLR, maxRL, maxRR;
  int maxDistLeft, maxDistRight;
  if(root->left){
    maxDistLeft = getMaxDistance(root->left, maxLL, maxLR);
    maxLeft= max(maxLL, maxLR) +1;
  }else{
    maxDistLeft=0;
    maxLeft=0;
  }
  if(root->right){
    maxDistRight = getMaxDistance(root->right, maxRL, maxRR);
    maxRight = max(maxRL, maxRR) +1;
  }else{
    maxDistRight=0;
    maxRight=0;
  }

  return max (max(maxDistLeft, maxDistRight), maxLeft + maxRight);

}

//construct tree from pre-order and in-order
node* treeHelper(vector<int> &preorder, vector<int>& inorder, int ist, int iend, int pst){
  if(ist>iend) return NULL;
  node *root= new node( preorder[pst]);
  int mid;
  for(int i=ist; i<=iend; i++){
    if(inorder[i] == root->data) {mid = i; break;}
  }
  root->left  = treeHelper(preorder, inorder, ist, mid-1, pst+1);
  root->right = treeHelper(preorder, inorder, mid+1, iend, pst + mid- ist +1);
  return root;
}
node *buildtree(vector<int> &preorder, vector<int>&inorder){
  if(preorder.size()==0 || preorder.size() != inorder.size()) return NULL;
  return treeHelper(preorder, inorder, 0, preorder.size(), 0);
}

// from postorder and inorder
node* treeHelper2(vector<int> &preorder, vector<int>& inorder, int ist, int iend, int pend){
  if(ist>iend) return NULL;
  node *root= new node( preorder[pend]);
  int mid;
  for(int i=ist; i<=iend; i++){
    if(inorder[i] == root->data) {mid = i; break;}
  }
  root->left  = treeHelper(preorder, inorder, ist, mid-1, pend- (iend-mid+1) );
  root->right = treeHelper(preorder, inorder, mid+1, iend, pend -1);
  return root;
}


//
bool isCompleteBinaryTree(node* root){

  if(!root) return false;
  queue<node*> q;
  q.push(root);
  bool mustHaveNoChild=false;
  bool result=true;
  while(!q.empty()){
    node *t=q.front(); q.pop();
    if(mustHaveNoChild){
      if(t->left || t->right){
        result=false;
        break;
      }
    }else{
      if( t->left && t->right){
        q.push(t->left);
        q.push(t->right);
      }else if(t->left && !t->right){
        q.push(t->left);
        mustHaveNoChild=true;
      }else if(!t->left && t->right){
        result=false;
        break;
      }else{
        mustHaveNoChild=true;
      }
    }
  }
  return result;


}


bool isSubTree(node* t1, node* t2){
  if(t2==NULL) return true;
  if(!t1) return false;
  if(t1->val == t2->val){
    return isSubTree(t1->left, t2->left) && isSubTree(t1->right, t2->right);
  } else{
    return isSubTree(t1->left, t2) || isSubTree(t1->right, t2); 
  }
  // return false;
}

