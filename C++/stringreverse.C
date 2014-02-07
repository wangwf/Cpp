//
// reverse a string
//
// Wenfeng.Wang@yahoo.com  05/20/2012
///////////////////////////////////////////////////////////////
#include <iostream>
#include <string>

using namespace std;; 


void reverseStr(string& s){
  int n=s.size(); 
  if(n<2) return; 
  for(int i=0; i<n/2; i++){
    //    cout<<"1 "<<s[i]<<" "<<s[n-1-i]<<endl; 
    char t=s[i]; 
    s[i]=s[n-1-i]; 
    s[n-1-i]=t; 
    //    cout<<"2 "<<s[i]<<" "<<s[n-1-i]<<endl; 
  }
}


int main(){

 string s="my name is wenfeng"; 

 cout<<" Normal order   \""<<s<<"\" "<<endl; 
 reverseStr(s);
 cout<<" Reversed order \""<<s<<"\" "<<endl; 

 return 0; 
}
