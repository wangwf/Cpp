

#brute force O(N^3)



#Dynamic programming solution O(N^2) and O(N^2) space
string longestPalindromeDP(string s)
{

  int n = s.length();
  int longestBegin =0;
  int maxLen =1;
  int nmax=1000;
  bool table[nmax][nmax]={false};

  for(int=0; i<n; i++){
    table[i][i]=true;
  }

  for(int i=0; i<n-1; i++){
    if( s[i] == s[i+1]){
      table[i][i+1] = true;
      longestBegin=i;
      maxLen=2;
    }
  }

  for (int len=3; len<=n; len++){
    for(int i=0; i<n-len+1; i++){
      int j=i+len-1;
      if (s[i] == s[j] && table[i+1][j+1]){
	table[i][j]=true;
	longestBegin=i;
	maxLen=len;
      }
    }
  }
  return s.substr(longestBegin, maxLen);
}


string paritySystem(string s, int c1, int c2)
{
  int l=c1, r=c2;
  int n=s.length();
  while(l>=0&& r<n-1&& s[l]==s[r]){
    l--;
    r++;
  }
  return s.substr(l+1, r-1-1);
}

string longestPalindromeSimple(string s){
  int n =s.length();
  if (n==0) return "";
  if(n==1) return s;
  string longest=s.substr(0,1);
  for(int i=0; i<n-1; i++){
    string p1=paritySystem(s,i,i);
    if(p1.length()>longest.length())
      longest=p1;

    string p2=paritySystem(s, i, i+1);
    if(p2.length()>longest.length())
      longest=p2;

  }
  return longest;
}




string expandAroundCenter(string s, int c1, int c2) {
  int l = c1, r = c2;
  int n = s.length();
  while (l >= 0 && r <= n-1 && s[l] == s[r]) {
    l--;
    r++;
  }
  return s.substr(l+1, r-l-1);
}
 
string longestPalindromeSimple(string s) {
  int n = s.length();
  if (n == 0) return "";
  string longest = s.substr(0, 1);  // a single char itself is a palindrome
  for (int i = 0; i < n-1; i++) {
    string p1 = expandAroundCenter(s, i, i);
    if (p1.length() > longest.length())
      longest = p1;
 
    string p2 = expandAroundCenter(s, i, i+1);
    if (p2.length() > longest.length())
      longest = p2;
  }
  return longest;
}
