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
    num *=10; 
    num += (int32) ( (*s) - "0"); 
    s++; 
  }
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


int main(){


  cout<<" test "<<test_atoi()<<endl; 
  return 0; 
}
