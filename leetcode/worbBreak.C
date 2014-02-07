/*
Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

  For example, given
  s = "leetcode",
  dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".

*/
bool wordBreak(string s, unordered_set<string< &dict){
  vector<bool> wordB(s.length()+1, false);
  wordB[0]=true;
  for(int i=1; i<s.length()+1; i++){
    for(int j=i-1; j>=0; j--){
      if(word[j] && dict.find(s.substr(j,i-j))!=dict.end()){
	  wordB[i]=true;
	  break;
	}
    }
  }
  return wordB[s.length()];
}



