/* 
* check string operation
*/
#include <iostream>
using namespace std; 

int ReturnOccurence(char* c, string* s){
 int result=0; 
 for(int i=0; i<(*s).length(); i++)
  if((*s)[i]==(*c))result++; 

 return result; 
}

int main(){

 char*c1 ="r"; 
 string s1="Merry Christmas and Happy New Year"; 
 cout<<"Occurence of "<<*c1<<" : "<<ReturnOccurence(c1,&s1)<<endl; 

 cout<<"find    "<<s1.find(c1,3)<<endl; 

 cout<<"substr  "<<s1.substr(6,7)<<endl; 
 cout<<"insert  "<<s1.insert(0,"From Wang: ")<<" : "<<s1<<endl; 
 cout<<"replace "<<s1.replace(0,4, "To ")<<" : "<<s1<<endl; 
 cout<<"erase   "<<s1.erase(0,2)<<" : "<<s1<<endl; 

 string str="abc"; 
 str +=  "def"; 
 str += 'd'; 
 str += (*c1); 

 cout<<str<<endl; 
 cout<<string("abc") + "dee"<<endl; 

 cout<<"aaa"+'bbb'<<endl; // two C-style string can't be operanded, compiler but not work
// delete c1; 
 
return 0; 
}
