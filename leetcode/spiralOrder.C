
vector<int> spiralOrder(vector<vector<int>> &matrix){

  vector<int> ret;
  if(matrix.empty() || mat[0].empty()) return ret;

  int left=-1, right=matrix[0].size()-1, top=0, bottom=matrix.size()-1;
  while(left<=right && top<=bottom){
    for (int j = ++left; top<bottom && j<=right; ++j)
      ret.push_back(matrix[top][j]);

    for( int i = ++top; left<=right && i<=bottom; ++i)
      ret.push_back(matrix[i][right]);

    for(int j = --right; top<=bottom&& j>=left; --j)
      ret.push_back(matrix[bottom][j]);

    for(int i= --bottom; left <=right && i>=top; --i)
      ret.push_back(matrix[i][lef]);
  }
  return ret;

}
