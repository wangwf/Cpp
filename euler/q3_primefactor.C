#include <iostream>
#include <math.h>

using namespace std;

bool isPrimeFactor(const int& n){

 unsigned int sqrtn=sqrt(n);
  for (unsigned int i=2; i<=sqrtn; i++)
    if (n%i==0) return false;

  return true;
}

template <class T>
T findMaxPrimeFactor(const T & n)
{
  T  maxp=1;
  //  int sqrtn=sqrt(n);
  //  for (T i=2; i<=n; i++){
  //    if(n%i==0){
  //      if (isPrimeFactor(i)) maxp=i;}
  //  }

  T n0=n,i=2;
  while(i<=n0){
    if(n0%i==0 && isPrimeFactor(i)){
      maxp=i;
      n0/=i;
      i=2;
    }
    else{   i++;    }
  }

  cout<<" largest Prime Factor for n "<<n<<"  is : "<<maxp<<endl;
  return maxp;
}


int main()
{

  findMaxPrimeFactor(10);

  findMaxPrimeFactor(13195);

  uint64_t n=600851475143;
  findMaxPrimeFactor(n);


  return 1;
}
