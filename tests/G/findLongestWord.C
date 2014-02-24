//
//A={'a', 'b', 'a', 'c',...}
//W={'cat', 'dog', '....',...}
//
//

#include <vector>
#include <string>
#include <map>
#include <list>
#include <iostream>

using namespace std;

bool findWord(const string& word, map<string, int> charBank){
  if(word.size()==0) return false;

  for(int i=0; i<word.size(); i++){
    string w=word.substr(i,1);
    if(charBank.find(w) == charBank.end()) return false;
    charBank[w]--;
  }
  return true;
}

vector<string> findLongest(vector<string> A, vector<string> W)
{
  vector<string> res;
  if(A.size()==0 || W.size()==0) return res;
  map<string, int> charBank;
  for(int i=0; i<A.size(); i++)charBank[A[i]]++;

  for(int i=0; i<W.size(); i++){
    if(!res.empty() && res[0].size()> W[i].size()) continue;
    if(!findWord(W[i], charBank)) continue;
    if(!res.empty() && W[i].size() > res[0].size()) res.clear();//if not large
    res.push_back(W[i]);
  }
  return res;
}


int main(){
  vector<string> A {"a", "b", "a", "c","t","a"};
  vector<string> W {"a","cat", "bat", "ba", "car"};
  vector<string> res = findLongest(A, W);

  for(vector<string>::iterator it=res.begin(); it!=res.end(); it++)
    cout<<*it<<" ";
  cout<<endl;
  return 0;
}
