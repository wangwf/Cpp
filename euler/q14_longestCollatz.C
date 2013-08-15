#include <iostream>
#include <map>

using namespace std;

std::map<int,int> collatzMap;

void nextCollatz(uint32_t& n){

  if(n==1) return n;

  //  if(n%2==0) n /=2;
  //  else n= 3*n+1;

  //  if (n&1) n=3*n+1; // n&0x1
  //  else n /=2;
  n= n&1? 3*n+1: n/2;

}

int numCollatz(const uint32_t &n){

  int num=1;
  std::map<int,int>::iterator cm;
  uint32_t n0=n;
  while(n0!=1){
    //    cout<<" "<<n0<<endl;
    nextCollatz(n0);
    cm=collatzMap.find(n0);
    if(cm != collatzMap.end())
      return num+(*cm).second;
    num++;
  }

  collatzMap[n]=num;

  return num;
}

int maxNumCollatz(const uint32_t& limit){

  int nmax=1;
  uint32_t istart=1;
  for (uint32_t i=1; i<=limit; i++){
    int nx=numCollatz(i);
    //    if(i%1000==0)    cout<<" start  "<<i<<" num "<<nx<<endl;
    if( nx>nmax){
      cout<<" start  "<<i<<" num "<<nx<<endl;
      nmax =nx;
      istart=i;
    }
  }
  cout<<" starting: "<<istart<<" nmax "<<nmax<<endl;
  return istart;
}
int main(int argc, char* argv[]){

  uint32_t n0=13;

  cout<<" "<<numCollatz(n0)<<endl;

  n0=1e6;
  cout<<maxNumCollatz(n0)<<endl;

  return 0;
}
