
#include <iostream>
#include <string>

using namespace std;

bool isPalindrome1(int x) {
  if (x < 0) return false;
  int div = 1;
  while (x / div >= 10) {
    div *= 10;
  }        
  while (x != 0) {
    int l = x / div;
    int r = x % 10;
    if (l != r) return false;
    x = (x % div) / 10;
    div /= 100;
  }
  return true;
}

//Alternative solution

bool isPalindrome(int x, int &y) {
  if (x < 0) return false;
  if (x == 0) return true;
  if (isPalindrome(x/10, y) && (x%10 == y%10)) {
    y /= 10;
    return true;
  } else {
    return false;
  }
}
bool isPalindrome(int x) {
  return isPalindrome(x, x);
}


//
bool isAlphanumeric(char &c){
  if(c>='A' && c<= 'Z') c+= 32;
  else if(c>= '0' && c<= '9' || c>= 'a' && c<= 'z') return true;
  else return false;
  return true;
}

bool isPalindrome(string s)
{
  int n=s.length();
  int l=0, r=n - 1;
  while(l<r){
    //    if(!isAlphanumeric(s[l])) l++;
    //    else if(!isAlphanumeric(s[r])) r--;
    //    else {if (s[l++] != s[r--]) return false;}
    while(!isAlphanumeric(s[l])) l++;
    while(!isAlphanumeric(s[r])) r--;
    cout<<l<<" "<<r<<endl;
    if (l<r && l<n & r>0 && s[l++] != s[r--]) return false;

    return true;
  }
}

int main(){

  string s=".,";
  cout<<isPalindrome(s)<<endl;

  return 0;
}
