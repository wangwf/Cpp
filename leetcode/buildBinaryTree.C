

struct TreeNode{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x): val(x), left(NULL), right(NULL){};
};

//build tree from preorder and inorder
TreeNode *helper(vector<int>& preorder, vector<int> &inorder, int ist, int iend, int pst){
  if(ist>iend)return NULL;
  TreeNode *root = new TreeNode(preorder[pst]);
  int mid;
  for(int i=ist; i<=iend; i++) if(root->val == inorder[i]) { mid=i;break;}

  root->right = helper(preorder, inorder, mid+1, iend, pst+1+mid-ist);
  root->left = helper(preorder, inorder, ist, mid-1, pst+1);
  return root;
}


TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder){
  if(preorder.size()==0 || preorder.size() != inorder.size()) return NULL;
  return helper(preorder, inorder, 0, preorder.size(), 0);
}

// inorder and postorder

TreeNode *helper1(vector<int>& inorder, vector<int>& postorder, int ist, int iend, int pend){
  if(ist>iend) return NULL;
  TreeNode *root=new TreeNode(postorder[pend]);
  int mid;
  for(int i=ist; i<=iend; i++) if(root->val == inorder[i]) { mid=i; break;}

  root->left = helper(inorder, postorder, ist, mid-1, pend-1 -iend + mid);
  root->right= helper(inorder, postorder, mid+1, iend, pend-1);
  return root;
}
TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder){
  if(inorder.size()==0 || inorder.size() != postorder.size()) return NULL;
  return helper(inorder, postorder, 0, inorder.size()-1, inorder.size()-1);
}
