// range heap example
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std; 

int main(){

  int Vect[]={3,5,7,10,1}; 

  typedef vector<int> IntVect; 
  typedef IntVect::iterator it; 

  vector<int> V(Vect,Vect+5); 
  vector<int>::iterator it1; 

  make_heap(V.begin(), V.end()); 
  
  cout<<V.front()<<endl; 

  for(it1=V.begin(); it1!=V.end(); it1++)cout<<*it1<<" "; cout<<endl; 

  sort_heap(V.begin(), V.end()); 

  cout<<V.front()<<endl; 

  for(it1=V.begin(); it1!=V.end(); it1++)cout<<*it1<<" "; cout<<endl; 


 V.pop_back(); 
  pop_heap(V.begin(), V.end());

  cout<<V.front()<<endl; 

  for(it1=V.begin(); it1!=V.end(); it1++)cout<<*it1<<" "; cout<<endl; 


  sort_heap(V.begin(), V.end()); 

  cout<<V.front()<<endl; 

  for(it1=V.begin(); it1!=V.end(); it1++)cout<<*it1<<" "; cout<<endl; 

}
