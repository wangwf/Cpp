/*
A tabular computation of D(n,m)

Bottom up
   computer D(i,j) for small i, j
 

*/

#include <string>

int minEditDistance(string s1, string s2){
  int m=s1.size();
  int n=s2.size();

  vector<vector<int>> D(m+1, vector<int>(n+1));
  for(int i=0; i<=m; i++)D[i][0]=i;
  for(int j=0; j<=m; j++)D[0][j]=j;

  for(int i=1; i<=m; i++){
    for(int j=1; j<=n; j++){
      int tmp=0;
      if (s1[i-1]!=s[j-1]) temp=2;
      D[i][j] = min(min( D[i-1][j]+1, D[i][j-1]+1), D[i-1][j-1]+tmp );
    }
  }
  return D[n][m];
}
