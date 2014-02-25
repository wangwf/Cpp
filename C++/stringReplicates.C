#include <string>
#include <iostream>

using namespace std;

/*
a String, Stringéånæèææç，éäæççStringéåèåä
2，èåääStringåäçèåTæèF
äå：
"abcabcabc"  Ture   åäåæabcéå3æææ
"bcdbcdbcde" False  æåääæbcde
"abcdabcd"   True   åäåæabcdéå2æææ
"xyz"       False  åäåäææääStringéå
"aaaaaaaaaa"  False  éåççStringéååèåä2（èéäèçåaaéå5æ)

èæçæåæåäO(n)
*/


bool isMultiple(string s){
  int N = s.length();
  if(N<=2) return false;

  int len=0;
  int start=0;
  for(int i=1; i<N; i++){
    if(s[i] == s[start]){
      start++;
      if(start>=len) start=0;
    }else{
      len = i+1; 
      start=0;
    }
    if(len>N/2) return false;
  }
  return len >1; //!=1;
}

int main(){
  cout<<isMultiple("abcabcabc")<<endl;
  cout<<isMultiple("bcdbcdbcde")<<endl;
  cout<<isMultiple("abcdabcd")<<endl;
  cout<<isMultiple("aaaaaaaaa")<<endl;
  return 0;

}
