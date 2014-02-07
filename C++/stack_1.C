/*
 * Test the stack memory
 */
#include <iostream>
using namespace std; 

int main(){

  int n=1000000; 
  int nStack0[n]; // allocate in stack;
  int *nStack=new int[n]; // pointer in stack, others in heap

  cout<<"aaaa"<<endl; 

  delete[] nStack; 
  return 0; 

}
