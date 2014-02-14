
#include <iostream>
#include <stdlib.h>

using namespace std;

//
// Newton's method
// x_{k+1} = 1/2 *(x_k + n/x_k)
//
int sqrt_newton(int x){
  if(x==0) return 0;
  if(x==1) return 1;

  double x0=1;
  double x1;
  while (true){
    x1=(x0 + x/x0)/2;
    if(abs(x1-x0)<1) return x1;
    x0=x1;
  }
  //  return 0;
}


// binary search

int sqrt_bst(int x){
  long long high=x;
  long long low=0;
  if(x<=0) return 0;
  if(x==1) return 1;
  while (high-low>1){
    long long mid=low + (high-low)/2;
    long long tmp=mid*mid;
    if(tmp== x)return mid;
    else if( tmp<x){low=mid;}
    else{high=mid;}
  }
  //  if(high>low) return high*high-x > x-low*low? low: high;
  return low;
} 


int main(){

  for(int i=0;i<20; i++){
    cout<<i<<"  "<<sqrt_newton(i)<<" "<<sqrt_bst(i)<<endl;}

  return 0;
}
