#include <iostream>
#include <vector>

using namespace std;

bool isPalindrom(const int& n){
  if(n<0) return false;
  int num=n;

  std::vector<int> nd;
  while (num>0){
    nd.push_back(num%10);
    num/=10;
  }

  int length=nd.size();
  for(int i=0; i<length/2; i++){
    if(nd[i]!=nd[length-1-i]) return false;
  }
  return true;
}

int findMaxPal(const int& n, const int& l)
{
  int u=l*10;
  int i,j;
  bool isFound=false;
  int n0=n;
  while(!isFound && n0>0){
    n0--;
    if(isPalindrom(n)){
      for(i=u-1; i>=l;i--){
	if( n0%i==0){
	  j=n0/i;
	  if(j>=l &&j<u){
	    isFound=true;
	    cout<<" "<<i<<" "<<j<<" "<<n0<<endl;
	    return n0;
	  }
	}
      }
    }
  }

  return n0;
}

int main()
{

  int n1=9009;
  cout<<" "<<isPalindrom(n1)<<endl;

  findMaxPal(1e4,10);

  findMaxPal(1e8,100);

  return 1;

}
