//
//Fibr
//
// it create too many threads
// in exponential time, O(long(n)
#include <thread>
#include <iostream>

//using thread
int fib_thread(const int& n){

  if(n<=1) return n;
  int fib1,fib2;

  std::thread t( [=,&fib1]{fib1=fib_thread(n-1);});
  fib2=fib_thread(n-2);
  t.join();

  return fib1+fib2;
}

//a safer way to write parral function
#include <future>
int fib_asyn(const int& n){

  if(n<=1) return n;
  int fib2;
  auto fib1 =
    std::async([=]{return fib_asyn(n-1);});
  fib2=fib_asyn(n-2);
  return fib1.get()+fib2;
}

//recursive
int fib_rec(const int& n){
  if(n<=1) return n;
  return fib_rec(n-1) + fib_rec(n-2);
}

//dynamic
int fib_dyn(const int& n){
  if(n<=1)return n;

  int* f=new int(n+1);
  f[0]=0;
  f[1]=1;
  for(int i=2;i<=n;i++){
    f[i]=f[i-1] + f[i-2];
  }
  return f[n];
}



int main()
{

  int n=11;
  std::cout<<"test thread-fibn: "<<fib_thread(n)<<std::endl;
  std::cout<<"test async-fibn: "<<fib_asyn(n)<<std::endl;
  std::cout<<"test recursive-fibn: "<<fib_rec(n)<<std::endl;
  std::cout<<"test dynamic-fibn: "<<fib_dyn(n)<<std::endl;
  return 0;
}
