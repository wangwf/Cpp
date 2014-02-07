/*
 * 16-bit
 */

#include <stdint.h>
#include <iostream>

using namespace std; 


class myClass {
  int num;  
public:
  myClass(int num1); 
  ~myClass(); 
  void numPrint(); 
}; 

myClass::myClass(int num1){
  num=num1; 
  cout<<" Constructor  num "<<num<<endl; 
}
myClass::~myClass(){
  cout<<" myClass destructor\n"; 
}

void myClass::numPrint()
{
  cout<<" num "<<num<<endl; 
  cout<<" hexadecimal "<<hex<<num<<endl; 
  cout<<"  octal      "<<oct<<num<<endl; 
  cout<<"  decimal    "<<dec<<num<<endl; 
  //  cout<<"  bin    "<<bin<<num<<endl; 

}


int main(){


  cout<<" set class \n"; 
  myClass t(17); 
  t.numPrint(); 
  cout<<" end of class \n"; 

int16_t bit16_1=13, bit16_2=16; 

 int16_t bit16_t; 

 
 cout<<" "<<bit16_1<<" "<<bit16_2<<endl; 

 bit16_t=bit16_1; 
 bit16_1=bit16_2; 
 bit16_2=bit16_t; 


  
cout<<" "<<bit16_1<<" "<<bit16_2<<endl; 

 int atemp=17; 
 cout<<"hexadecimal "<<hex<<atemp<<"  decimal "<<dec<<atemp<<" octal "<<oct<<endl; 


 printf("%d"); 

 printf(" \n"); 

 return 0; 
}
