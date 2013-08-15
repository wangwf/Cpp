////////////////////////////////////////////////////////////////////////
// find closest element in a binary search tree
//
//  * Binary Search tree implmentation
//  * Find element from BST
//  * Find closest element from BST, two methods: non-recursive and recursive
//  * test cases
//
//   Wenfeng WANG  05/20/2012  Wenfeng.Wang@yahoo.com
////////////////////////////////////////////////////////////////////////////
#include <iostream>

using namespace std; 


struct node{
  int  data; 
  node *left; 
  node *right; 

  node(int value){ data=value; left=NULL; right=NULL; }
}; 


class BST{
  node* root; 

public:
  BST(){root=NULL;}

  node* getROOT(){return root; }
  void insert(int value); 
  void printInOrder(node* r) const; 
  void remove( int value);  // To be implemented

  bool findElem(node* p, const int& x); 

  int findClosest(const int& x); 

  int findClosest2(node* r, const int& d, int& num); 


};

void BST::insert(int d)
{
  node* tmp = new node(d); 

  if(root==NULL){ root=tmp; return;}
  
  node *curr=root; 

  while(true){
    if(curr->left==NULL&&curr->right==NULL) break; 

    if(curr->right!=NULL && curr->left != NULL)
      {
	if(tmp->data > curr->data) curr=curr->right; 
	else curr= curr->left; 
      }
    else if(curr->right != NULL && curr->left==NULL)
      {
	if(tmp->data <= curr->data) break;  
	else if (tmp->data >curr->data)
	  curr=curr->right; 
      }
    else if(curr->right==NULL&&curr->left !=NULL)
      {if(tmp->data>= curr->data) break; 
	else if (tmp->data <curr->data) curr=curr->left; 
      }

  }

    if(tmp->data<curr->data) curr->left = tmp; 
    else curr->right =tmp; 

    //    delete curr; 
    return; 
}


void BST::printInOrder(node* r) const {
  if(r!= NULL){
    if(r->left) { printInOrder(r->left);  }
    cout<<" "<<r->data<<" "; 
    if(r->right){ printInOrder(r->right);  }
  }
  else return; 
}

//find same element from BST
bool BST::findElem(node* r, const int& x){
  if(r==NULL) return false; 
  if(r->data == x) return true; 
  if(x<r->data) return findElem(r->left, x); 
  if(x>r->data) return findElem(r->right, x); 

}

//look for closest element, non-recursive method
int BST::findClosest(const int& d){

  if(root==NULL) return 0; // empty tree
  node* p=root; 

  int num= p->data; 
  int dif= abs(d - num); 


  while(p != NULL){
    int tmp= abs(d - p->data); 
    if(tmp<dif){
      dif = tmp; 
      num = p->data; 
    }

   
    if(d>=p->data && p->right!=NULL) p=p->right; 
    else if(d<p->data && p->left!=NULL) p=p->left; 
    else {p=NULL; }
  }

  //  delete p; 
  return num; 

}

//look for closest element, recursive method
int BST::findClosest2(node* r, const int& d, int&  closestNum){
  if(r==NULL)return -1; 
  int tmp=abs(d - r->data);
  if(tmp<abs(closestNum-d)){ closestNum=r->data; } //memorize the closer

  if(d>r->data && r->right !=NULL)
    return findClosest2(r->right,d,closestNum); 
  else if(d<r->data && r->left != NULL)
    return findClosest2(r->left,d,closestNum); 
  else   return r->data; 

  //  return -1; 
}


//produce random numbers for test case
int testBST(){

  BST tree; 

  cout<<"Generating new random numbers, put into BST.."<<endl;
  //  srand(time(0)); 
  for(int i=0; i<10; i++){
    int n1=rand()%100; 
    //    cout<<" "<<n1<<endl; 
    tree.insert(n1); 
    //    cout<<" insert "<<n1<<endl; 
  }
  cout<<" print inOrder "<<endl; 
  tree.printInOrder(tree.getROOT()); 
  cout<<" \n"; 

  int target=30; 

  cout.setf(std::ios::boolalpha);
  cout<<" Finding exactly target "<< target<<"?  "<<tree.findElem(tree.getROOT(),target)<<endl; 
 
  cout<<" Finding the closest element to "<<target<<endl; 
  int closest1 = tree.findClosest(target);
  cout<<" answer:  "<<closest1<<endl; 

  int closest2=tree.getROOT()->data;   
  tree.findClosest2(tree.getROOT(), target,closest2); 
  cout<<"  "<<closest1<<" "<<closest2<<endl; 

  return closest1==closest2; 

}


int main(){


  int nTest=100; 

  int nCorrect=0; 

  srand(time(NULL)); 

  for(int i=0; i<nTest; i++){
    if(testBST()) nCorrect++; 
  }

  cout<<" number of Tests "<<nTest<<"  Correct: "<<nCorrect<<"   Wrong: "<< (nTest-nCorrect)<<endl; 

  return 0; 
}
