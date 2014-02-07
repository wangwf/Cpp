/*
 * Test Vector operand
 */

#include <vector>
#include <iostream>

using  namespace std; 

void TestVect(){


  vector<int> numInt; 
  numInt.push_back(7); 
  
  vector<string> words; 
  words.push_back("test"); 

  cout<< numInt.size()<<" "<<words.size()<<endl; 
  cout<< numInt.at(0)<<" "<<words.at(0)<<endl; 
}


int main(){

  TestVect(); 

}
