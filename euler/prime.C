#include <iostream>
#include <math.h>

using namespace std;

bool isPrimeFactor(const int& n){

 int sqrtn=sqrt(n);
  for (int i=2; i<=sqrtn; i++)
    if (n%i==0) return false;

  return true;
}

int findMaxPrime(const int& ntot)
{
  int nprime=1,iprime=1;
  int i=1;
  while(iprime<=ntot){
    i++;
    if (isPrimeFactor(i)){
      nprime=i;
      iprime++;
    }
  }

  cout<<" "<<ntot<<"  is : "<<nprime<<endl;
  return nprime;
}

int main()
{

  findMaxPrime(6);

  findMaxPrime(10001);
  return 1;
}
