#include <vector>
#indlude <iostream>


using namespace std;

void printVector(vector<vector<int>> 
vector<vector<int>> subsets(vector<int> S){
  sort(S.begin(), S.end());
  vector<vector<int>> res(1);

  for(int i=0; i<S.size(); i++){
    int j=V.size();
    while(j-->0){
      res.push_back(v[j]);
      res.back().push(S[i]);
    }
  }
  return res;
}


  vector<vector<int> > subsetsWithDup(vector<int> &S){
        vector<int> path;
        vector<vector<int>> result;

        sort(S.begin(), S.end());
        sub(S, 0, path, result);
        return result;
    }

    void sub(vector<int> &s, int begin, vector<int> &path, vector<vector<int> > & result){
        result.push_back(path);

        for(int i=begin; i<s.size(); ++i){
            if(i!=begin && s[i] == s[i-1]) continue;

            path.push_back(s[i]);
            sub(s, i+1, path, result);
            path.pop_back();
        }
    }

                 int main()
