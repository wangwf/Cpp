#include <iostream>

using namespace std;


int Fibonacci(const int& nmax=100, const int& iprint=0){
  int f1=1, f2=2,fb=f2;
  int sum=0;
  cout<<" nmax "<<nmax<<endl;
  while(fb<nmax) {
    if(f2%2==0)  sum +=f2;
    //    cout<<" "<<f1<<" "<<f2<<endl;
    fb=f1+f2;
    f1=f2;
    f2=fb;
    if(iprint) cout<<" "<<fb;
  }
  cout<<" "<<endl;

  cout<<" sum "<<sum<<endl;
  return sum;
}


int main(){


  Fibonacci(10,1);

  Fibonacci(4e6,0);

  return 1;
}
