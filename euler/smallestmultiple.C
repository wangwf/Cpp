#include <iostream>

using namespace std;

int smallestmult(const int& n)
{

  int num=0;
  bool isDivided=true;
  while(true){
    num++;
    isDivided=true;
    for(int i=1; i<=n; i++){
      if (num%i !=0) {
	isDivided=false;
	break;
      }
    }
    if(isDivided){
      std::cout<<"n "<<n<<" num "<<num<<endl;
      break;
    }
  }
  return -1;
}

int main()
{

  smallestmult(10);
  smallestmult(20);
  return 1;
}
