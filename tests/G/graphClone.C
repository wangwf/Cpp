#include <vector>
#include <queue>
#include <map>

#ifndef NULL
#define NULL 0
#endif

using namespace std;

struct Node{
  int value;
  vector<Node*> neighbors;
  Node(int x):value(x){};
};

Node *dfs(Node* root, map<Node*, Node*>& visited){
  if(!root) return NULL;
  Node* rootCopy= new Node(root->value);
  visited[root] = rootCopy; //

  for(int i=0; i<root->neighbors.size(); i++){
    Node *p=root->neighbors[i];
    if( visited.find(p) ==visited.end())
      { //no copy exist
        visited[root]->neighbors.push_back(dfs(p, visited));
      } else{
      visited[root]->neighbors.push_back( visited[p]);
    }
  }
  return rootCopy;
}

Node *dfsCopy(Node* root){
  if(!root) return NULL;
  map<Node*, Node*> visited;

  Node* newRoot= dfs(root, visited);
  return newRoot;
}


Node* bfsCopy(Node* root){
  if(!root) return NULL;

  queue<Node*> Q;
  Q.push(root);

  Node* rootCopy = new Node(root->value);
  map<Node*, Node*> visited; //map node -> nodeCopy
  visited[root] = rootCopy;

  while(!Q.empty()){
    Node *p = Q.front(); Q.pop();
    for(int i=0; i<p->neighbors.size(); i++){
      Node *q = p->neighbors[i];
      if(visited.find(q) == visited.end()){
        Q.push(q);
        Node* qCopy=new Node(q->value);
        visited[p]->neighbors.push_back(qCopy);
        visited[q]=qCopy;
      }else{
        visited[p]->neighbors.push_back( visited[q]);
      }
    }
  }
  return rootCopy;
}
