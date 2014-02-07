/*
* permutation 
*/

#include <iostream>
#include <string>
using namespace std; 

void permutation(string soFar, string rest)
{
    if(rest.length()==0)
cout <<soFar<<endl;
    else 
       for(int i=0; i<rest.length(); i++){
         string next=soFar+rest[i]; 
         string remaining = rest.substr(0,i)+rest.substr(i+1); 
         permutation(next,remaining);
        }; 

}

void listString(string s){

  permutation("",s); 

}

void RecSubset(string soFar, string rest){
  if(rest=="")cout<<soFar<<endl; 
  else {
    //add to the subset
    RecSubset(soFar+rest[0],rest.substr(1)); 
    //dont' in subset
    RecSubset(soFar, rest.substr(1)); 
  }
}


int main(){

string s="abc"; 	
  listString(s); 

  cout<<" test subset "<<endl; 

  RecSubset("",s); 

}
