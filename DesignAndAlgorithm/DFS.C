// Compute SCCs (Strongly Connected Components) in O(m+n) time
// Algorithm (given directed graph G
// (1)let G_rev = G with all arcs reversed
// (2)run DFS-loop (Depth First Search) on G_rev, its goal is compute "magical of ordering" of 
// (3) run DFS-loop on G, to discover the SCCs one-by-one. 
//   processing nodes in decreasing oder of times.
//   Here SCCs == nodes with same "leader".
// Depth-first-search 

#include <iostream>
#include <fstream>
#include <vector>
#include <list>
using namespace std; 




class vertex
{
private:
  //  vector<int> data;  //[0] is node, the rest for edge
  int data;
  int explored; 
  int ftime;
  int leader;  // strongle connected components hare a common leader; 

  std::vector<vertex*> _successors;

public: 
  void setData(int i){data=i; }
  int getData() const {return data; }
  std::vector<vertex*>& successors(){ return _successors; }

  int getExplored(){ return explored; }
  int getFtime(){ return ftime; }
  int getLeader(){return leader; }

  void setExplored(int i){ explored=i; }
  void setFtime(int x){ ftime=x; }
  void setLeader(int i){leader=i; }

};


class graph
{
private:
  vertex* node; 
  int nNodes; 
  int mEdges; 

public:
  graph(int n){
    nNodes=n; 
    mEdges=0; 
    node= new vertex[n]; 
  }

  vertex* getNode(int i){return (node+i); }

  //  int FtimeToInode(int fTime){return (node+i); }//

  void setMEdges(int i){mEdges=i; }
  int getMEdges(){return mEdges; }
  int getNNodes(){return nNodes; }
  void printNode(int i){
    cout<< node[i].getData()<<" "<<node[i].successors().size()<<" :"; 
    for(int j=0; j<node[i].successors().size(); j++) cout<<" "<<node[i].successors().at(j)->getData(); cout<<endl;
  }

  void printSLeader(){
    cout<<"result( data, explored, ordering, leader) "<<endl; 
    for(int i=0; i<this->getNNodes(); i++){
      vertex* s=this->getNode(i); 
      cout<<s->getData()<<"   "<<s->getExplored()<<"   "<<s->getFtime()<<"   "<<s->getLeader()<<endl; 
    }
  }

  void countSCC(); 

};

void graph::countSCC(){
  int num=getNNodes(); 
  vector<int> count_tmp(num); 

  for(int i=0; i<num; i++){
    int ii=getNode(i)->getLeader()-1; 
    //      cout<<" II "<<ii<<endl; 
    count_tmp[ii]++; 
  }
    std::sort(count_tmp.begin(), count_tmp.end()); 

  cout<<" maximum "; 
  for(int i=num-1; i>=num-5; i--)cout<<","<<count_tmp[i]; cout<<endl; 

 
}

int s_leader=0; //super leader 

int current_label;  //keep track of ordering
int t=0;  // reverse

void DFS(graph* G, vertex* s){

  s->setExplored(1);  
  s->setLeader(s_leader);  

  int nEdges= s->successors().size(); 
  //  cout<<" edge "<<s->getData()<<" "<<nEdges<<endl; 
  for(int j=0; j<nEdges; j++){

    vertex* v = s->successors().at(j); 
    //    cout<<"DFS  "<<s->getData()<<" "<<v->getData()<<endl; 
    if(!v->getExplored()){
      v->setExplored(1); 
      DFS(G,v);
    }
  }

  //  cout<<" edge "<<s->getData()<<" "<<current_label<<endl; 

  //  s->setFtime( current_label);   current_label --; 

  t++;  s->setFtime( t); 


}




void DFS_Loop(graph* G){
 
  // initialize all nodes unexplored
  for(int i=0; i<G->getNNodes(); i++){
    G->getNode(i)->setExplored(0);  
  }

  // to keep track of ordering
  current_label = G->getNNodes(); 
  s_leader=0; 

  //  cout<<"initial current_label "<<current_label<<" "<<G->getNNodes()-1<<endl; 

    for(int i=G->getNNodes()-1; i>=0; i--){
  //  for(int i=0; i<G->getNNodes(); i++){
      //      cout<<G->getNode(i)->getData()<<" "<<G->getNode(i)->getExplored()<<endl; 
    if(!G->getNode(i)->getExplored()){
      s_leader = G->getNode(i)->getData(); 
      //      cout<<" DFS "<<i<<" lead "<< s_leader<<endl; 
      DFS(G, G->getNode(i) ); 
    }
  }

    //-------------------------



}


void DFS_Loop2(graph* G, graph* Grev){
 
  // initialize all nodes unexplored
  for(int i=0; i<G->getNNodes(); i++){
    G->getNode(i)->setExplored(0);  
  }

  // to keep track of ordering
  current_label = G->getNNodes(); 
  s_leader=0; 

  int* rev=new int[G->getNNodes()]; 
  for(int i=0; i<Grev->getNNodes(); i++) rev[Grev->getNode(i)->getFtime()-1]=i; 

  //  cout<<"initial current_label "<<current_label<<" "<<G->getNNodes()-1<<endl; 

    for(int iTime=G->getNNodes()-1; iTime>=0; iTime--){
      //      if(G->getNode(i)->getFtime() == G->getNNodes()){
      int ii=rev[iTime]; 

      //            cout<<" sink index "<<ii<<" "<<iTime<<endl; 

      if(!G->getNode(ii)->getExplored()){
	s_leader = G->getNode(ii)->getData(); 
	//	cout<<" DFS "<<ii<<" leader "<< s_leader <<"  "<<endl; 
	DFS(G, G->getNode(ii) ); 
      }
      //      }
  }

    //-------------------------



}




void FindSCC(graph* G, graph* Grev){

  //  graph *Grev=reverseG(G); 
  //  DFS_Loop(Grev); 

  //  DFS_Loop(Grev);

    DFS_Loop(G);

    cout<<" Second DFS "<<endl; 
       DFS_Loop2(Grev, G); 

}



int main(){

   int num=875714; string filename="SCC/SCC.txt"; 
  //  int num=4;     string filename="tmp.txt"; 
  //  int num=9;     string filename="tmp1.txt"; 
  //     int num=5; string filename="tmp4_3.txt"; 
  //  int num=9; string filename="PQ4GraphSCC12TestCases/PQ4GraphSCC12TestCases/graph1n10000scc9453.txt"; 

  //int num =   9 ; string filename="PQ4GraphSCC12TestCases/graph0n9scc3.txt"; // 3, 3, 3, 0
  //  int num =  342156 ; string filename="PQ4GraphSCC12TestCases/graph10n342156scc315426.txt"; //21717,704,89,69  ok
//int num =  6589 ; string filename="PQ4GraphSCC12TestCases/graph11n6589scc6216.txt";
//int num =  850000 ; string filename="PQ4GraphSCC12TestCases/graph12n850000scc779032.txt";
//int num =  10000 ; string filename="PQ4GraphSCC12TestCases/graph1n10000scc9453.txt";
//int num =  100 ; string filename="PQ4GraphSCC12TestCases/graph2n100scc93.txt";
//int num =  450 ; string filename="PQ4GraphSCC12TestCases/graph3n450scc421.txt";
//int num =  4500 ; string filename="PQ4GraphSCC12TestCases/graph4n4500scc4254.txt";
//int num =  15000 ; string filename="PQ4GraphSCC12TestCases/graph5n15000scc14092.txt";
//int num =  15 ; string filename="PQ4GraphSCC12TestCases/graph6n15scc4.txt";
//int num =  900 ; string filename="PQ4GraphSCC12TestCases/graph7n900scc847.txt";
//int num =  50000 ; string filename="PQ4GraphSCC12TestCases/graph8n50000scc46790.txt";
//int num =  100000 ; string filename="PQ4GraphSCC12TestCases/graph9n100000scc93263.txt";
		      //int num =   ; string filename="PQ4GraphSCC12TestCases/results.txt";


  graph *G =new graph(num); 
  for(int i=0; i<num; i++) G->getNode(i)->setData(i+1); 

  graph *Grev =new graph(num); 
  for(int i=0; i<num; i++) Grev->getNode(i)->setData(i+1); 

  //    cout<<" Print node "<<endl;   for(int i=0; i<G->getNNodes(); i++) G->printNode(i); 

  //
  ifstream myfile; // myfile.open("SCC/SCC.txt"); 
  myfile.open(filename.c_str()); 

  int M=0, N=0; 
  if(!myfile.is_open())cout<<" Wrong File "<<endl; 
  while(myfile.good())
    {
      int a, b;
      myfile>>a>>b; 

      //      G->getNode(a)->setData(a); 
      //      cout<<" reading in "<<a<<" "<<b<<endl; 
      //      cout<<G->getNode(a-1)->getData()<<" "<<G->getNode(b-1)->getData()<<endl; 

      G->getNode(a-1)->successors().push_back( G->getNode(b-1) ); 
      Grev->getNode(b-1)->successors().push_back( Grev->getNode(a-1) ); 

      M++; N++; 
    }
    G->setMEdges(M);// ??? 
     
    myfile.close(); 
     
  cout<<" End of reading  "<< G->getNNodes()<<" "<<G->getMEdges()<<endl; 

  //  cout<<" Print node "<<endl;   for(int i=0; i<G->getNNodes(); i++) G->printNode(i); 

  //     DFS_Loop(G); 

  FindSCC(G, Grev); 


  cout<<"result( data, explored, ordering, leader) "<<endl; 
  //  Grev->printSLeader(); 


  Grev->countSCC(); 

     return 0; 
}
