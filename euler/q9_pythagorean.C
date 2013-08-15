#include <iostream>

using namespace std;

int pythagoream(const int& n){
  int i,j,k;
  for(i=1;i<n-2;i++){
    for(j=i+1;j<n-1;j++){
      k=n-i-j;
      int delta=i*i +j*j -k*k;
      if(delta==0) return i*j*k;
    }}

  return -1;
}

//
//equation a+b+c=n, a*a + b*b=c*c
// => b=n*(n/2-a)/(n-a)
int pythagoream2(const int& n){
  int i,j,k;
  for(i=1;i<n/2;i++){
    j= n*(n/2-i)/(n-i);
    k=n-i-j;
    int delta=i*i +j*j -k*k;
    if(delta==0) return i*j*k;
  }

  return -1;
}



//equation a+b+c=n, a*a + b*b=c*c
// a= 2*m*n
// b= m*m - n*n
// c= m*m + n*n
// a+b+c = 2*m*(m+n)==N
//int pythagoream3(const int& N){}

int main(){

  int  n=1000;
  cout<<pythagoream(n)<<endl;
  cout<<pythagoream2(n)<<endl;


  return 1;
}
