/*
 * namespace allows to group entitles like class, function and objects under a name.
 * This way the global scope can be divided into "sub-scopes", each one has its own name.
 * "using" keyword is used to introduce a name of namespace into the current declarative region
 */

#include <iostream>
using namespace std; 

namespace firstName {

  int x=3,y=6; 
}

namespace secondName {
  int x=7,y=10; 
}

// template
template <typename T>
T GetMax(const T& a, const T& b){
  return (a>b)?a:b; 
}

template <class T>
T GetMin(const T& a, const T& b){

  return (a>b)?b:a; 
}

int main(){

  using firstName::x; 
  using secondName::y; 
  cout<<" after using namespace x= "<<x<<" y= "<<y<<endl; 

  cout<<" under firstName "<<firstName::x<<" "<<firstName::y<<endl; 
  cout<<" under secondName "<<secondName::x<<" "<<secondName::y<<endl; 


  //template 
  cout<<" max "<<GetMax(3.1,4.8)<<" min "<<GetMin(10, 7)<<endl; 

  // throw an exception
 try
  {
    throw 20;
  }
  catch (int e)
  {
    cout << "An exception occurred. Exception Nr. " << e << endl;
  }

  return 0; 
}
