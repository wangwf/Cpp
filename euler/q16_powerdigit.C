// TODO, unfinished

#include <iostream>
#include <math.h>

#include <gmp.h>

using namespace std;

typedef  mpz_t int_t;

int sumofdigit(const int_t& n){

  int_t nn=n;

  int sum=0;

  while(nn>0){
    sum += nn%10;
    nn /=10;
  }

  return sum;
}

int_t getPowNum(const int& p){
  return (int_t)1<<p;
}

int main(int argc, char* argv[]){

  int p=15;
  //  int_t num=pow(2,p);

  int_t num=getPowNum(p);
  cout<<" pow of 2 is "<<num<<" sumOfDigits "<<sumofdigit(num)<<endl;

  //    int_t num1=getPowNum(1000);
  int_t num1; mpz_ui_pow_ui(num1,2,1000);
  cout<<" pow of 2 is "<<num1<<" sumOfDigits "<<sumofdigit(num1)<<endl;

  return 1;
}
