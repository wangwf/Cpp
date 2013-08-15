//
// function pointer
//
#include <iostream>

class Foo{
private:
  int func_x(int m) { return m *= 5; }
  int func_y(int n) { return n *= 6; }

public:
  Foo() { do_something = &Foo::func_x; }
  int (Foo::*do_something)(int); //

  void setFunc(bool e) { do_something =e ? &Foo::func_x : &Foo::func_y; }

};

int main() {
  Foo f;
  f.setFunc(false);
  std::cout<<" "<< (f.*f.do_something)(5)<<"\n";

  return 0;
}
