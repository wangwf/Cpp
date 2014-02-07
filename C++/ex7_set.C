/*
 * test set constructor
 */

#include <iostream>
#include <set>

using namespace std; 

bool fncomp(int lhs, int rhs){return lhs<rhs; }

struct classcomp{
  bool operator() (const int& lhs,const int& rhs) const 
 {return lhs<rhs; }
}; 

int main(){

  set<int> first; 

  int myints[]={10,20,20,30,40,50,50,15}; 
  set<int> second(myints, myints+8); 

  set<int> third(second); 
  set<int> fourth(second.begin(), second.end()); 

  set<int,classcomp> fifth; 

  bool(*fn_pt)(int, int) =fncomp; 

  set<int, bool(*)(int, int)> sixth (fn_pt); 


  cout<<"size "<<first.size()<<" "<<second.size()<<endl; 
  
  set<int>::iterator itr; 
  for(itr=second.begin(); itr!=second.end(); itr++){
    cout<<" "<<*itr; }
  cout<<endl; 
  itr=second.find(30); 
  cout<<" find "<<*itr<<endl; 
  itr=second.find(31); 
  cout<<" find "<<*itr<<endl; 


  return 0; 
}
