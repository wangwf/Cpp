/*
 *
 */

#include <iostream>
#include <string>

using namespace std; 

int occurance(const char& ch, string& s){

  int n=0; 
  for(int i=0; i<s.size(); i++){
    if(s[i]==ch) n++; 
  }

  return n; 
}

int occurance2(const char& ch, string& s){

  int found,n; 
  while( (found=s.find(ch))!=string::npos){
    s.erase(found,1); n++;   
  }; 
  
  return n; 
}


int main()
{
  string s1="This is a name tag, please wear it to class."; 

  char* ch="i"; 
  cout<<" "<<occurance(*ch,s1)<<endl; ; 

  cout<<s1<<endl; 

  cout<<" "<<occurance2(*ch,s1)<<endl; 


  return 0; 
}
