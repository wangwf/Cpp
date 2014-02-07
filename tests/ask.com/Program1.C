//
// Ask.com programming test 1
//
// Design a quick lookup to see if a phrase from a dictionary of phrases occurs inside a user query. 
// Donot care how long the initialization time takes, as long as subsequent seraches can be done efficiently. 
//
//  * 100,000 ASCII string, up to 255 chars each. 1 or more words, space separated
//  * query input from stdin
//  * soft matches
//  * optimize for time
//
//  Wenfeng Wang 06/06/2012
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**************************************************************************************************************
Problem analyzing:

  Total data size:   100,1000 (strings) * 255 bytes = 25.5Mbytes

  ASCII has 128 ( or 256) characters;  
  Total combination: pow(26, 255) is way too large  EVEN assuming only alphabeta letter used in the string.


  

   idea: using hashtable for quick lookup,  time complexity is O(1); (maybe  Trie ?)

   put all 100,1000 string into hashtable; 



***************************************************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <list>


using namespace std; 

class myHashTable{
  int length; 
  int hTableSize;  
  list<string>* value_arr; 
  string*      key_arr; 


public:

  myHashTable(int size=100000) {
    hTableSize=size; 
    value_arr=new list<string>[size]; 
    key_arr=new string[size]; 
    length=0; 
  }; 
  ~myHashTable(){
    delete[] value_arr; 
    delete[] key_arr; 
  }; 

  string getKey(string value){ // what is better key, first 3 or 4 letters?
 
    return value.substr(0,3); 
  }; 

  int getIndex(const string& arr_key){ // convert key to index (number of bucket)

    int num=0; 
    for(int i=0; i<arr_key.size()-1;i++){
      num = num*10 + (int)arr_key[i]; 
    }
   
    return num; 
  }; 

  void add(string value){
    string str_key=getKey(value); 
    int indx=getIndex(str_key); 
    key_arr[indx]=str_key; 
    value_arr[indx].push_back(value); 
    length++; 

  }; 
  void remove(string value){
    // not need for this test, no time to implement
    length--; 
  };

       
  bool lookUp(const string& inputStr){
    string str_key=getKey(inputStr); 
    int indx=getIndex(str_key); 
    
    bool isFound=false; 
    list<string>::iterator it; 
    for(it=value_arr[indx].begin(); it != value_arr[indx].end(); it++){
      if( (*it)==inputStr){
	isFound=true; 
	continue; }
    }

    return isFound; 
  }; 

}; 




int main(){

  int arr_size=100000; 
  string *arr=new string[arr_size]; 

  //setup HashTable
  myHashTable mytable(arr_size); 
  ifstream fin("input.txt"); 
  if(!fin)std::cerr<<"Input file wrong! \n"; 

  while(!fin.eof()){
    string temp; 
    fin>>temp; 
    
    mytable.add(temp); 
  }
  fin.close(); 



  //query from stdin
  string inputStr; 
  cin>>inputStr; 

  bool found=mytable.lookUp(inputStr);  

  cout<<" intput: "<<inputStr<<"   found: "<<found<<endl;   



  return 0; 
}  
  
