/*
 *  test virtual function
 */

#include <iostream>
using namespace std; 

class mammal{
private:
  int itsAge; 

public:
  mammal(); 
  ~mammal(); 

  virtual void speak() const {cout<<"Mammal sounds. \n";}; 
  void move() const {cout<<" Mammal move.\n"; }; 

}; 

mammal::mammal(){
  itsAge=1;
  cout<<"mammal constructor.\n"; 
}
mammal::~mammal(){cout<<" mammal destructor. \n"; }

class dog: public mammal
{
public:
  dog(); 
  ~dog(); 
  void speak() const {cout<<" Woof. \n"; }; 
  void move() const {cout<<" dog move. \n"; }; 
}; 

dog::dog(){cout<<" dog constructor. \n"; }
dog::~dog(){cout<<" dog destructor. \n"; }

int main(){

  // define a base class
  mammal* dog0 =new mammal; 
  dog0->speak();  
  dog0->move(); 

  // define a base class but overrided by derived class
  mammal* dog1 =new dog; 
  dog1->speak();  
  dog1->move(); 

  // define a derive class
  dog* dog2 =new dog; 
  dog2->speak();  
  dog2->move(); 

  return 0; 
}

