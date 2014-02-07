  void dfs(string &s, int st, vector<int> &sp, vector<string> &res, unordered_set<string> &dict, vector<vector<bool>> &mp){
        if(st>=s.size()){
            string str=s;
            for(int i=0; i<sp.size()-1; i++){
                str.insert(sp[i]+i, " ");
            }
            res.push_back(str);
        } else{
            for(int j=0; j<mp[st].size(); j++){
                if(mp[st][j]==true){
                    sp.push_back(j+1);
                    dfs(s, j+1, sp, res, dict, mp);
                    sp.pop_back();
                }
            }
        }
        
    }
    
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        int n=s.size();
        vector<vector<bool> > mp(n, vector<bool>(n, false));
        
        for(int i=0; i<n; i++)
            for(int j=i; j<n; j++){
                if(dict.find(s.substr(i, j-i+1))!=dict.end())
                    mp[i][j]=true;
            }
        bool flag=false;
        
        for(int i=0; i<n; i++){
            if(mp[i][n-1]){
                flag=true;
                break;
            }
        }
        vector<string> res;
        if(!flag) return res;
        vector<int> sp;
        dfs(s, 0, sp, res, dict, mp);
        return res;
        
    }
