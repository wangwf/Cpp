//
// find all prime numbers (0-1000); 
//
// Wenfeng.Wang@yahoo.com  05/20/2012
////////////////////////////////////////////////////////
#include <iostream> 
using namespace std; 

// time complexity O(n^2)
void prime(const int& n){
  // 0,1 not prime number
  if(n<=1) {cout<<" warning input "<<n<<endl; return; }

  cout<<" list of prime n<"<<n<<endl; 
  for(int j=2; j<=n; j++){
    int isPrime=1; 
    for(int i=2; i<j/2; i++){
      if(j%i==0) {isPrime=0; break; }
    }
    if(isPrime)cout<<j<<" "; 
  }
  cout<<endl; 
}


int main(){

  prime(1000);


  return 0; 
}
       


// test cases?
// Can I do better; 

