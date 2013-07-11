// PQ3 
// implement adjacency list and minimum cut problem

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iterator>

using namespace std; 


class Vertex
{
public:
  vector<int> v; 

  Vertex(){}; 
  Vertex(const vector<int>& vtemp){ this->v=vtemp; }
  ~Vertex(){}; 

  int  Edges(){ return v.size(); }
  void removeEdge(Vertex& vt){};     //v.erase(position);   
  void removeSelfLoop();   
}; 


class Graph: public Vertex
{
public: // change late to private
  vector< vector<int> > VV; 
  int nNodes; 
  int nEdges; 

public:
  Graph(){nNodes=0; nEdges=0; }
  void addVertex( const vector<int>& vtmp ) {    VV.push_back(vtmp);  }
  void addVertex( const Vertex& v1){ 
    VV.push_back(v1.v);
    this->nNodes++; 
    //    this->nEdges += v1.v.size();
  }

  int getNNodes(){return nNodes;}
  int getNEdges(){ 
    int temp=0; 
    for(int i=0; i<getNNodes(); i++) temp+= VV[i].size(); 
    this->nEdges= (temp-nNodes)/2; 
    return this->nEdges ;
  }
  void removeVertex(const int& );
  void mergeVertices(const int& , const int& ); 
  void checkSelfLoop(const int& ); 
  //  void mergeVertices(vector<int>& v1, vector<int>& v2); 

  void printGraph(); 
  Vertex getVertex(const int& inode); 

  //  int RContraction(); //random contraction algorithm
};

Vertex Graph::getVertex(const int& inode){

  Vertex vt; 
  for(int i=0; i<this->getNNodes(); i++){
    if(VV[i][0]==inode) vt.v=VV[i]; 
  }
  return vt; 
}

//merge v2 into v1; and remover v2 from the list; check self-loop of new v1
void Graph::mergeVertices(const int& inode1, const int& inode2){

  cout<<" merging nodes: "<<inode1<<"  "<<inode2<<endl; 
  //if(inode1==inode2)
    this->printGraph(); 

  int i1=-1, i2=-1; 
  for(int i=0; i<getNNodes(); i++){
    if(VV[i][0]==inode1) i1=i; 
    if(VV[i][0]==inode2) i2=i; 
  }
     cout<< " ith    "<<i1<<"  "<<i2<<endl; 
  if(i1<0 || i2<0)return; 
  int isConnected=0; 
  for(int j=1; j<VV[i2].size(); j++){ if(VV[i2][j]==inode1)isConnected=1;   }
  if(!isConnected) return; 

  //  cout<<" check "<<i1<<"  " ;  for(int j=0; j<VV[i1].size(); j++) cout<<" "<<VV[i1][j]; cout<<endl; 

  // put inode2's edges into node1
  for(int j=1; j<VV[i2].size(); j++){
    if(VV[i2][j]!=inode1)VV[i1].push_back(VV[i2][j]);  // no self-loop ?
  }
  int nedge2=VV[i2].size()-1; 

  //  cout<<" check "<<i1<<"  " ;  for(int j=0; j<VV[i1].size(); j++) cout<<" "<<VV[i1][j]; cout<<endl; 
 
  /// replace all other connection to inode2; 
  for(int i=0; i<VV.size(); i++){
    for(int j=1; j<VV[i].size(); j++)
      if(VV[i][j]==inode2)VV[i][j]=inode1; 
  }

  //remove self-loop
  checkSelfLoop(inode1); 

  //remove inode2
  removeVertex(inode2); 
  //  cout<<" check "<<i1<<"  " ;  for(int j=0; j<VV[i1].size(); j++) cout<<" "<<VV[i1][j]; cout<<endl; 


  // update nNodes; 
  (this->nNodes)--;  this->nEdges = this->getNEdges()- nedge2; 



}

/*
void Graph::mergeVertices( vector<int>& v1, vector<int>& v2){

  for(int j=0; j<v2.size(); j++){
    if(v2[j]!=v1[0])v1.push_back(v2[j]);  // no self-loop ?
  }
  removeVertex(v2); 
}
*/

void Graph::removeVertex(const int& inode){

    cout<<" remove node "<<inode<<endl; 
  if(inode<0)return; 
  cout<<" "<<VV.size()<<endl; 
  int iRemove; 
  for(int i=0; i<VV.size(); i++){
    //    cout<<" "<<inode<<" "<<VV[i][0]<<"   "<<i<<endl; 
    if(inode==VV[i][0])iRemove=i; 
  }
  cout<<" iRemove "<<iRemove<<endl; 
  VV.erase(VV.begin()+iRemove); 
  
  cout<<" end of remove vertex "<<VV.size()<<endl; 
}

void Graph::checkSelfLoop(const int& inode){

  //erase element from back, otherwise erase operation will change vector size and delete wrong one
  int ith; 
  for(int ii=0; ii<VV.size(); ii++)     if(VV[ii][0]==inode)ith=ii; 
  for(int i=VV[ith].size()-1; i>0; i-- )
    if(VV[ith][i]==VV[ith][0])VV[ith].erase(VV[ith].begin()+i); 

}


void Graph::printGraph(){

  for(int i=0; i<getNNodes(); i++){  
    for(int j=0; j<VV[i].size();  j++)
      {
		cout<<(VV)[i][j]<<" "; 
      }
    cout<<"\n"; 
  }
 cout<<" nodes =" <<getNNodes()<<" edges "<<getNEdges()<<endl; 
}

int RContraction(Graph& myG){

  //  if(myG.getNNodes()<2) return 0; 
  if(myG.getNNodes()==2)return myG.getNEdges(); 

  //pick a random node, and random edge of this node; 
  //  srand(time(NULL)); 
  //  cout<<" "<<myG.getNNodes()<<endl; 
  int i1=rand()%myG.getNNodes(); 
  int node1=myG.VV[i1][0]; 
  //  cout<<" "<<myG.VV[i1].size()<<endl; 
  int edges=rand()%(myG.VV[i1].size()-1)+1; 
  //  cout<<" edges "<<edges<<endl; 
  //  if(edges>0){
    int i2= rand()%edges+1; 
    int node2=myG.VV[i1][i2]; 
        cout<<" random two nodes "<<node1<<" "<<node2<<endl; 
    myG.mergeVertices(node1,node2); 
    //  }

  cout<<" nnodes "<<myG.getNNodes()<<" "<<myG.getNEdges()<<endl;
  //  return 1; 
    return RContraction(myG); 

}

int main()
{

  Graph myG; 
  int inode =0; 

  ifstream fin; fin.open("kargerAdj.txt"); 
  if(!fin) std:cerr<<" Input file Wrong! \n"; 

  while(true)
    {
      string line; 
      getline(fin, line); 
      if(line.empty()) break; 
      istringstream myStream(line); 
      istream_iterator<int> begin(myStream), eof; 
      vector<int> numbers(begin, eof); 

      //            std::copy(numbers.begin(), numbers.end(), std::ostream_iterator<int>(std::cout, " "));       cout<<"\n"; 
      Vertex vt(numbers);       myG.addVertex(vt); 

      //      myG.addVertex(numbers); 

      // myG->addVertex( numbers, inode);  
      //      (myG->myVert)[inode] = v1;

      inode++; 
    }

/*  
  myG.printGraph(); 

  cout<<"===test merge \n"; 
  //  Vertex v1=myG.getVertex(1),v2=myG.getVertex(2); 
  myG.mergeVertices(1,19); 

  myG.printGraph(); 

  myG.mergeVertices(1,36); 

  myG.printGraph(); 

  myG.mergeVertices(1,15); 
  myG.printGraph(); 
 
*/

//  myG.printGraph(); myG.mergeVices(4,23); myG.printGraph(); 
  srand(time(NULL)); 

      RContraction(myG); 

  return 0; 
}
