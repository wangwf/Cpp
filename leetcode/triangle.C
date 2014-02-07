int triangle(vector<vector<int>> &t){
    int n = t.size();
    vector<int> p (n+1, 0);
    while(n-- > 0)
      for(int i = 0; i <= n; ++i) 
	p[i] = t[n][i] + ((p[i] < p[i+1])? p[i] : p[i+1]);
    return p[0];
  }
