
string addBinary(string a, string b){
  string sum="";
  int la=a.size()-1;
  int lb=b.size()-1;
  int c=0;

  while(la>=0 || lb>=0 || c>0){
    int v=c;
    if(la>=0) v+=a[la]-'0';
    if(lb>=0) v+=b[lb]-'0';
    c=v/2;
    sum = string(1, ('0'+ (v&1))) +sum;
    la--;
    lb--;
  }
  return sum;
}
