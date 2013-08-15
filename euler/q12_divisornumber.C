#include <iostream>

using namespace std;

int triangleNum(const int& ith)
{

//  int num=0,i=0;
//  while (i<ith)
//    num += ++i;

  if(ith==1) return 1;
  return triangleNum(ith-1)+ith;
}

int numDivisors(const uint64_t& n)
{
  int nD=0;

  uint64_t limit=n;
  for(int i=1;i<limit; i++){
    if(n%i==0){
      limit=n/i;
      if(limit!=i)nD++;
      nD++;
    }
  }

  return nD;
}


int main(int argc, char* argv[])
{
  int i=1,nD=0;
  uint64_t triNum=0;
  int total=500;
  while(nD<=total){
    //    triNum = triangleNum(i);
    triNum += i++ ;
    nD=numDivisors(triNum);
    // if(nD>total)
    if(nD%10==0 || nD>total) cout<< triNum <<"  "<<nD<<endl;

  }
  return 1;
}
