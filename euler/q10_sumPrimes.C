#include <iostream>
#include <math.h>

using namespace std;


bool isPrime(const int& n){

  int sqrtn=sqrt(n);

  for(int i=2;i<=sqrtn; i++)
    if(n%i==0)return false;

  return true;
}

template <class T>
T sumPrime(const T& N){

  T sum=2;
  for(T i=3; i<=N; i +=2)
    if(isPrime(i)){
      sum +=i;
      //         cout<<i<<endl;
    }
  return sum;
}

int main(){

  int N1=10;
  cout<<" sum of primes < "<<N1<<" : "<<sumPrime(N1)<<endl;

  uint64_t N2=2e6;
  cout<<" sum of primes < "<<N2<<" : "<<sumPrime(N2)<<endl;


  return 1;
}
