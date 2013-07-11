// C++ Code : Strongly Connected Component Algorithm (SCC)
#include<cstdio>
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<map>

#include <fstream>

using namespace std;
#define INF  1073741822
#define MAX(a,b)  ((a>b)?a:b)
#define MIN(a,b)  ((a<b)?a:b)
#define CLEAR(A,N)  (memset(A,0,(N)*sizeof(A[0])))

typedef long double LD;

//#define  num 875714
#define  num 9

vector<int> v[num],sv[num];
vector<int> topo;
int used[num],M,N;

void DFS(int s){
	int i;
	used[s]=1;
	for(i=0;i<v[s].size();i++){
	  if(used[v[s][i]]==0){
		  
			DFS(v[s][i]);
	  }
	}
	topo.push_back(s);
}

void anotherDFS(int s){
	int i;
	used[s]=1;
	for(i=0;i<sv[s].size();i++){
		if(used[sv[s][i]]==0)
			anotherDFS(sv[s][i]);
	}
}

int findSCC(int N){
	int res,i;
	CLEAR(used,N+1);
	for(i=1;i<=N;i++){
		if(used[i]==0)
			DFS(i);
	}
	CLEAR(used,N+1);
	res=0;
	for(i=topo.size()-1;i>=0;i--){
		if(used[topo[i]]==0){
			anotherDFS(topo[i]);
			res++;
		}
	}
	return res;
}


int main() {
    // 
  //  fstream myfile;  myfile.open("SCC/SCC.txt"); 
 fstream myfile;  myfile.open("tmp1.txt"); 


  int a, b,M, res; 
  if(!myfile.is_open())cout<<" Wrong file "<<endl; 
  
  while(!myfile.eof()){
       myfile>>a>>b; 
       v[a].push_back(b);
       sv[b].push_back(a);
       M++; 
              cout<<" ab "<<a<<" "<<b<<endl; 
     }
     myfile.close(); 
 
     cout<<" end of reading file "<< v[num-11].size()<<" "<<sv[num-1].size()<<" "<<v[0].size()<<endl; 
     
     res=findSCC(N);
     
     //CLEAR all vectors
   
     for(int i=1;i<=num;i++){
       v[i].clear();
       sv[i].clear();
     }
     topo.clear();
     
     cout<<"res "<<res<<endl; 

     return 0; 
}



