#include <iostream>
#include <vector>
#include <list>

using namespace std;


struct node{
  int data;
  node* left;
  node* right;
};

node* findLCA(node* root, node *p, node* q){
  if(!root) return NULL;

  if(p==root || q==root)return root;

  node* l=findLCA(root->left, p, q);
  node* r=findLCA(root->left, p, q);

  if(l && r) return root;
  return l? l:r;
}

//IF its BST 
node* findLCA(node* root, int v1, int v2){
  while(root){
    if(v1< root->data && v2<root->data){
      root = root->left;
    }
    else if(v1>root->data && v2>root->data){
      root = root->right;
    }
    else return root;
  }
  return NULL;
}

//distance between two nodes
bool findNode(node* root, node* p, list<node*> path){
  if(!root) return NULL;

  path.push_back(root);
  if(root == p) return true;

  bool found=findNode(root->left, p, path);
  if(!found)
    found=findNode(root->right, p, path);

  if(!found)path.pop_back();
  return found;
}

node* findLCA2(node* root, node* p, node* q){
  if(!root) return false;
  list<node*> path1, path2;
  bool found1 = findNode(root, p, path1);
  bool found2 = findNode(root, q, path2);

  if(!found1 || !found2) return NULL;

  node* lastCommon=NULL;
  list<node*>::const_iterator it1=path1.begin();
  list<node*>::const_iterator it2=path2.begin();
  while( it1 != path1.end() && it2!= path2.end()){
    if( *it1 != *it2)break;
    lastCommon=*it1;
    it1++;
    it2++;
  }
  return lastCommon;
}


