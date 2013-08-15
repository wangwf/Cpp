#include <iostream>
#include <string>

class foo{
public:
  foo(){std::cout<<"foo constructor.\n";}
};
class bar: public foo{
public:
  bar(){std::cout<<"bar constructor.\n";}
};

//class parentClass{
//  string str;
//public:
//  parentClass(string str1){std::cout<<"parent class "<<str1<<std::endl;}
//};
//
//class childClass: parent("hello")
//{ public:
//  childClass(){cout<<"child class. \n";}
//};

class foo1{
public:
  foo1(int x){std::cout<<"foo constructor "<<x<<std::endl; }
};

class bar1: public foo1{
 public:
    bar1(): foo1(10) {std::cout<<"Bar constructor. \n";}
  //ar1()   {std::cout<<"Bar constructor. \n";}
};

int main(){

  bar b;
  bar1 b1;
  //  childClass c;

}
