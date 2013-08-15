#include <iostream>

using namespace std;

int sumdif(const int& n)
{
  int sum=0;

  for(int i=1; i<=n-1; i++)
    for(int j=i+1; j<=n; j++)
      if(i!=j)sum += 2*i*j;


  cout<<"sum "<<sum<<endl;
  return sum;
}


int main()
{

  sumdif(10);

  sumdif(100);

  return 1;
}
