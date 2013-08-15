//thread example

#include <iostream>
#include <thread>

int iorder=0;

void foo(){ std::cout<<"This is foo!"<<std::endl;}

void bar(int x){std::cout<<"This is bar!"<<x<<"  "<<std::endl;}

int main()
{
  std::thread first(foo); //spawn new thread that call foo()
  std::thread second(bar, 2); //spawn new thread that call bar(0)
  std::thread three(bar, 3); //spawn new thread that call bar(0)

  std::cout<<"main, foo and bar now execute concurrently..\n";

  //synchronize threads
  first.join();  //pauses until first finishedes
  second.join(); // pauses until second finishedes
  three.join(); // pauses until second finishedes

  std::cout<<"foo and bar completed. \n";


  return 0;
}
