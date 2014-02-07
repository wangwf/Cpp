//
// Giving a set of executable files (*.o), only some of them are exportable,
//   find out files are not used.
//
// Including 
//   simple graph representation
//   Breadth-First-Search  
//   check all executable
//   test case
//
// Wenfeng.Wang@yahoo.com  05/20/2012
//////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <queue>
#include <vector>

using namespace std; 

struct Node{
  string filename; 
  vector<Node*> deps; //depended files

  bool used;  //should be initialed as false; 
  bool exported; //whethe it is exportable execution

  Node(string s){
    filename=s; 
    //    deps=new vector<Node*>; 
    used=false; 
    exported=false; 
  }
}; 


void BFS(vector<Node*> G, Node* s){

  s->used = true; 
  queue<Node*> Q;
  Q.push(s); 

  while(!Q.empty()){
    Node* v = Q.front(); Q.pop(); 
    for(int i=0; i<v->deps.size(); i++){
      Node* w=v->deps[i]; 
      if(!w->used){
	w->used=true;
	Q.push(w); 
      }
      
    }
  }

}

void executableCheck(vector<Node*> G){

  int nfiles=G.size(); 
  
  for(int i=0; i<nfiles; i++){
    if(G[i]->exported)
      BFS(G, G[i]); 
  }
}


int main(){

  vector<Node*> g; 

  Node* n1=new Node("a1.o"); 
  Node* n2=new Node("a2.o"); 
  Node* n3=new Node("a3.o"); 
  Node* n4=new Node("b1.o"); 
  Node* n5=new Node("b2.o"); 
  Node* n6=new Node("c1.o"); 

  n1->deps.push_back(n1); n1->exported=true; 
  n1->deps.push_back(n2); 
  n1->deps.push_back(n4); 

  n4->deps.push_back(n4); n4->exported=true;
  n4->deps.push_back(n6);  

  g.push_back(n1); 
  g.push_back(n2); 
  g.push_back(n3); 
  g.push_back(n4); 
  g.push_back(n5); 
  g.push_back(n6); 


  executableCheck(g); 

  cout<<" output unused files:"<<endl; 

  for(int i=0; i<g.size(); i++){
    if(!g[i]->used) cout<<g[i]->filename<<endl; 
  }


  delete n1, n2, n3, n4,n5,n6; 
  return 0; 
}
