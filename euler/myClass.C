

#include <iostream>
#include <string>

using namespace std;

class myClass{
  string name; 
  double weight;
  int age; 

public:
  myClass():
    name("aa"),
    weight(0.0),
    age(0)
  { }

  //for std C++11 to prevent automatic constructor creation
  myClass(const myClass&)=delete;
  /*
  myClass(const myClass& others):
    name(others.name),
    weight(others.weight),
    age(others.age)
      {}
  //  myClass

  */

  ~myClass(){} 

};
  //  myClass()




  int main(){

    myClass a; 
    myClass b(a); 
  

	  return 0; 
  }


