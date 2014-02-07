//header file

class Function_pointer
{
public:

  int next(int n);
  int before( int n);
  int next_after_next( int n);

  typedef int (Function_pointer::*f)(int n);

  //  void update( int n, f pointer );
  void update(int n){ (this->*pointer)(n);};
};

// .cpp file
# include<iostream>
//# include"Header.h"
using namespace std;


int Function_pointer::next(int n)
{
  return n + 1;
}

int Function_pointer::before( int n)
{
  return n - 1;
}

int Function_pointer::next_after_next( int n)
{
  return n + 1 + 1;
}

//void Function_pointer::update( int n, f pointer )
//{  pointer(n);}

void main()
{

  Function_pointer myFunc;

  //  myFunc.update( 1, &myFunc.next); //Function_pointer::next);


  return 0;
}
