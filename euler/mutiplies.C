#include <iostream>

using namespace std;

int multiple(const int& n, const int& a, const int& b)
{
  if( a<=0 || b<=0) return 0;

  int i=n/a;  if (i && n%a==0) i--;
  int j=n/b;  if (j && n%b==0) j--;
  int c=a*b;
  int k=n/c;  if (k && n%c==0) k--;

  int sum = a*(i+1)*i/2;
  sum     += b*(j+1)*j/2;
  sum     -= (a*b)*(k+1)*k/2;

  cout<<" "<<i<<" "<<j<<" "<<k<<endl;
    return sum;
}

int multiple1(const int& n, const int& a, const int& b)
{
  int sum=0;
  for (int i=0; i<n; i++)
    if( i%a==0 || i%b==0) sum +=i;

  return sum;
}


int main()
{
  cout<<multiple(10,3,5)<<endl;
  cout<<multiple(100,3,5)<<endl;
  cout<<multiple(1000,3,5)<<endl;

  cout<<multiple1(1000,3,5)<<endl;


  return 1;
}
