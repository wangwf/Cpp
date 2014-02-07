#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool isValid(string s) {
  if(s.size()==0) return true;
  stack<char> st;
  string p="()[]{}";
  for(int i=0; i<s.size(); i++){
    cout<<"i "<<s[i]<<endl;
    if (!st.empty() &&
        ((s[i]==p[1] && st.top()==p[0]) ||
         (s[i]==p[3] && st.top()==p[2]) ||
         (s[i]==p[5] && st.top()==p[4]))){
      cout<<"tt "<<endl;
      st.pop();
    }
    else if(p.find(s[i])){
      cout<<"test"<<endl;
      st.push(s[i]);
    }
  }

  return st.empty();
}

int main(){

  string s="]";
  cout<<isValid(s)<<endl;

  return 0;
}
