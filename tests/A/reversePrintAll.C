//
/
// Q: array based hashset, There are methods: insert(), delete(), find(),
//  how to implement printAll(): print element in reversd order of insertion
//
//

//assuming storing all integers, it's easy to change type using template <class T>

#include <iostream>
#include <stack>

using namespace std;


class myHashSet{
  int* arr;
  int length;

public:
  void insert(int x);
  void delet(int x);
  int find(int x);

  int hasher(int x); //get index
  void printAll();

};

//pseudo code

//my first answer,  using a stack to store the order of insertion.

void myHashSet::printAll(){

  stack s1; //during interview, I only use 1 stack.

  int a, b, c;

  insert(a); s1.push_back( hasher(a));
  insert(b); s1.push_back( hasher(b));
  insert(c); s1.push_back( hasher(c));

  while(s1){
    int indx=s1.pop();
    s2.push_back(indx);
    cout<< arr[indx]<<" ":
  }
  cout<<endl;

}

//
// better way may using another array to store the order of insertion

struct InsertionStack{
  int* ordering; 
  int nmax; 
  order(){ ordering =new int; nmax=0; }
  add(int idx){ odering[nmax]=idx; nmax++; }
}

void myHashSet::printAll(){

  InsertionStack myInsertion; 

  int a, b, c;

  insert(a); myInsertion.add( hasher(a));
  insert(b); myInsertion.add( hasher(b));
  insert(c); myInsertion.add( hasher(c));


  for(int i= myInsertion.nmax-1; i>=0; i--){
    int indx=myInsertion.ordering[i];
    cout<< arr[indx]<<" ":
  }
  cout<<endl;

}



