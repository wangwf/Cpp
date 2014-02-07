#include <vector>
#include <iostream>

using namespace std;

vector<int> plusOne(vector<int> &digits){

  int i;
  for(i=digits.size()-1; i>=0; --i){
    if (digits[i] != 9){
      cout<<" .... "<<digits[i]<<" "<<++digits[i]<<endl;
      //      ++digits[i];
      return digits;
    }
    else digits[i] =0;
  }
  if (i<0) digits.insert(digits.begin(), 1);
  return digits;

}

void printVector(vector<int> &v){
  for(vector<int>::const_iterator i=v.begin(); i!=v.end(); ++i)
    cout<<*i<<" ";
  cout<<endl;
}

int main(){

  vector<int> digits{9,9,9}; //or 

  vector<int> newdigits =plusOne(digits);
  printVector(newdigits);

  digits={9,9,8};
  newdigits=plusOne(digits);
  printVector(newdigits);

  return 0;
}
