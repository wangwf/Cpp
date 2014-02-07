
int maxS=LONG_MIN;
//int max;

int maxPathSumHelper(TreeNode* root){
  if(!root) return 0;
  int left=maxPathSumHelper(root->left);
  int right=maxPathSumHelper(root->right);
  int m=root->val;
  if(left>0) m +=left;
  if(right>0) m +=right;

  maxS= max(maxS, m);
  return max(root->val, max(root->val + left, root->val + right));
}

int maxPathSum(TreeNode *root){
  
  if(!root) return 0;
  
  maxPathSumHelper(root);

  if(ret>max) max=ret;
  return maxS;
}
