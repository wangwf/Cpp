#include <iostream>
#include <fstream>
#include <vector>

using namespace std; 

class myHashTable{
  int length; 
  int HTableSize; 
  vector<int>* value_arr; 
  string* key_arr; 
  int hashF_c; 
  int hashFunction(const string& key); // 

public:
  myHashTable(int size=10);
  ~myHashTable(); 
  void add(int x, string key); 
  void remove(string key); 
  int lookup(const string&, const int&); 

}; 

myHashTable::myHashTable(int size){

  value_arr= new vector<int>[size]; 
  key_arr=new string[size]; 
  HTableSize=size; 

  hashF_c=100; 
}

myHashTable::~myHashTable(){
  delete[] value_arr; 
  delete[] key_arr; 
}

int myHashTable::lookup(const string& key, const int& x)
{

  //  string key = convertInt(x/c1);
  hashFunction(key); 
  int hashIndex = hashFunction(key); 

  int foundIt=0; 
  for(int i=0; i<value_arr[hashIndex].size(); i++)
    if(x==value_arr[hashIndex][i])foundIt=1;


  return foundIt; 
}

void myHashTable::add(int x, string key)
{
  int hashIndex; 
  hashIndex=hashFunction(key); 

  key_arr[hashIndex]=key; 
  value_arr[hashIndex].push_back(x); 

}

int myHashTable::hashFunction(const string& key){

  return (atoi(key.c_str()))/hashF_c; //  
}

void twoLoop(int* arr, int arr_size, int* Target){
  int found[9]={0,0,0,0,0,0,0,0,0}; 
  
  for(int i=0; i<arr_size-1; i++){
    for(int j=i+1; j<arr_size; j++){
      int sumij=arr[i]+arr[j]; 
      for(int k=0; k<9; k++)
	if( sumij==Target[k]) found[k]=1; 
    }
  }

  for(int k=0; k<9; k++)cout<<found[k]<<" ";  cout<<endl; 
}

#include <sstream>
string convertInt(int number)
{
  stringstream ss; 
  ss<<number; 
  return ss.str(); 
}
int main(){

  int arr_size=100000; 
  int *arr=new int[arr_size]; 

  int c1=100;  //must be same as HashF_c in myHashTable
  myHashTable mytable(arr_size/c1); 

  ifstream fin("HashInt.txt"); 
  if(!fin)std::cerr<<"Input file wrong! \n"; 

  int i=0; 
  while(!fin.eof()){
    int temp; 
    fin>>temp; 
    arr[i]=temp; i++;
    string key = convertInt(temp/c1);
    mytable.add(temp, key); 
  }

  fin.close(); 

  int Target[9]={231552,234756,596873,648219,726312,981237,988331,1277361,1283379}; 

  //  twoLoop(arr, arr_size, &Target[0]); 
  int found[9]={0,0,0,0,0,0,0,0,0};
  for(int k=0; k<9; k++){
    for(int i=0; i<arr_size; i++){
      int y= Target[k]- arr[i]; 
      if(y<0)continue; 
      string key=convertInt(y/c1); 
      if(mytable.lookup(key,y)) found[k]=1; 
    }
  }
  for(int k=0; k<9; k++)cout<<found[k];  cout<<endl; 

  return 0; 
}
