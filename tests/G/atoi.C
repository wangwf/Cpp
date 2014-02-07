//
//


#include <iostream>
#include <assert.h>

using namespace std;

// Parse the string until the first non-numeric character.
// Return the value.
int atoi(const char *s) {
  assert(s);
  bool isNeg=false;
  if( strncmp(s, "-")){
    isNeg=true;
    s++;
  }
  int num=0;

  while( *s <="9" && *s >="0"){
    num = num*10 + (int32) ( (*s) - "0");
    s++;  }

  //  for(; str[i] != '\0'; ++i) num = num*10 + str[i] - '0';

  if(isNeg)num *= -1;
  return num;
}

// Returns true if atoi works correctly.
// Returns false otherwise
bool test_atoi() {

  bool t1=atoi("aa")==0; // 0

  bool t2= atoi("1234")==1234; //1234

  //  char* s3=”123a”;
  bool t3= atoi("123a")==123;

  //  char* s4 =”a-123”;

  bool t4= atoi(“333”)==333;
    /* “0” =0
  “-0” =0
  “-1” =-1
  “a-123” =0
  “-123a” =-123
“123  “=123
     “  123” =123 //code need to change
“ 123 “=123
“0.123” = 0
    */

     return t1&&t2&&t3;
}

int itoa(int n, char* out){
  int sign = n<0? 1:0;
  int i= 0;
  if( n == 0) out[i++] = '0';
  else if(n<0){
    out[i++] = '-';
    n = -n;
  }
  while(n>0){
    out[i++] = '0' + n%10;
    n/=10;
  }
  out[i] = '\0';
  reverse(out + sign, i - sign);
  return 0;
}


int main(){


  cout<<" test "<<test_atoi()<<endl;
  return 0;
}
