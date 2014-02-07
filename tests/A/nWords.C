//
// mimic 'wc' command in Linux, return number of words in a string

#include <iostream>
#include <string>

using namespace std; 


//asuuming words separated by " ", ",", ";", ".", ignor other puncations. 
bool checkEndofWord(const char& c){
  if(c==' '||c==','||c==';'||c=='.'||c=='!') return true; 
  return false; 
}


int countWords(const string& s){
  int nwords=0; 

  int length=s.size(); 
  if(length==0)return 0; 

  int i=0; 
  while(i<length){
    if(checkEndofWord(s[i])){
      nwords++; 
      cout<<s[i]<<"  "<<nwords<<endl; 
      
      if(i<length-1) {while(s[i+1]==' ')i++; } // skip blankets after puncation
      
    }
    i++; 
  }

  return nwords; 

}


int main(){

  string s1="Hello! My name is Wenfeng Wang."; 
  cout<<" nwords "<<countWords(s1)<<endl; 

  string s2="  "; //empty test
  cout<<" nwords "<<countWords(s2)<<endl; 

  string s3="Hello!    My name is Wenfeng Wang.  "; //multi-blanket test
  cout<<" nwords "<<countWords(s3)<<endl; 





  return 0; 
}
