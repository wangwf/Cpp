
struct TreeNode{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x): val(x), left(NULL), right(NULL){}
};

void dfs(TreeNode *root, int level, vector<vector<int>> &ret){
  if(!root) return;
  if(level >= ret.size()) ret.push_back(vector<int>());
  ret[level].push_back(root->val);
  dfs(root->left, level+1, ret);
  dfs(root->right, level+1, ret);
}

vector<vector<int>> levelOrder(TreeNode *root){
  vector<vector<int>> ret;
  dfs(root, 0, ret);
  return ret;
}
