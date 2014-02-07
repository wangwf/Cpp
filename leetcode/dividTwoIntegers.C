//Divide two integers without using multiplication, division and mod operator.
#include <iostream>
#include <stdlib.h>

using namespace std;

int divide(int dividend, int divisor){
  long long a=abs((double)dividend);
  long long b=abs((double)divisor);

  long long ret=0;
  while(a>=b){
    long long c=b;
    for(int i=0; a>=c; i++, c<<=1){
    //    int i=0;    while(a>=c){  c=c<<1;
      a-=c;
      ret+=1<<i;
      cout<<" a "<<a<<" "<<b<<" "<<c<<" "<<ret<<" "<<i<<endl;
    }
  }

  int sign=(dividend^divisor)>>31? -1:1;
  return ret*sign;
}

int main(){

  cout<<divide(10,3)<<endl;

  return 0;
}
