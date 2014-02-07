/*
 * linked list
 */

#include <iostream>
#include <string>
using namespace std; 

struct Entry{
  string name; 
  string phoneNum; 
  Entry* nextOne; 
}; 

void PrintEntry(Entry*n){

  //  cout<<"Print out the entry "<<endl; 
  if(n==NULL){cout<<" It's empty entry"<<endl; 
    return; }
  cout<<n->name<<" "<<n->phoneNum<<endl; 
  if(n->nextOne==NULL)return; 
  PrintEntry(n->nextOne); 

}


Entry* GetNewEntry(){

  cout<<"Entry name "; 

  string s1,s2; 
 
  //    newOne->name= GetLine(); 
  //    cin>>newOne->name; 
  getline(cin,s1); 
  // string s1= getline(s1); 
    //  cin>>s1; 
  //  cout<<" s1 "<<s1<<endl;
  if(s1=="")return NULL; 

 

  cout<<"Enter Phone Number "; 
  //    newOne->phoneNum = GetLine(); 
  //  cin>>newOne->phoneNum; 
  getline(cin, s2); 
  //  string s2=getline(s2);
  // cin>>s2;
  if(s2=="")return NULL; 
 

  Entry* newOne=new Entry; 

  newOne->name=s1; 
  newOne->phoneNum =s2; 

   cout<<" "<<s1<<" "<<s2<<endl; 
   newOne->nextOne=NULL;
   return newOne; 
}

Entry* buildList(){

  Entry* list=NULL; 

  while (true){
    Entry* newOne = GetNewEntry(); 
    if(newOne==NULL)break; 
    newOne->nextOne = list; 
    list=newOne ; 
  }

  return list; 

}


int main(){
  Entry* n= buildList(); 
  PrintEntry(n); 
  
}

