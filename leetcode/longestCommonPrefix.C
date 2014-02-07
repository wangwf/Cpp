/*

 */

string longestCommonPrefix(vector<string> &strs){
  if(strs.empty()) return "";

  int rightMost = strs[0].length()-1;
  for(int i=1; i<strs.size(); i++){
    for(int j=0; j<=rightMost; j++){
      if(strs[i][j] != strs[0][j]){
	rightMost = j-1;
	break;
      }
    }
  }
  return strs[0].substr(0, rightMost+1);
}
