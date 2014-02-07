

int reverse(int x){
  int res=0;
  bool isNeg = (x<0);
  if(isNeg) x=abs(x);

  while(x){
    res = res*10 + x%10;
    x=x/10;
  }
  if(isNeg) x *=-1;
  return res;
}
  
