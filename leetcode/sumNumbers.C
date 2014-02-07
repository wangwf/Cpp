/*


 */

int sum_number(TreeNode *root, int per_val, int sum)
{
  if(root == NULL) return 0; 
  pre_val *=10;
  if(root->left == NULL && root->right == NULL)
    return root->val + pre_val+ sum;

  if(root->left)
    sum = sum_number(root->left, pre_val+root->val, sum);
  if(root->right)
    sum = sum_number(root->right, pre_val+ root->val, sum);
  return sum;
}

int sumNumbers(TreeNode* root){
  return sum_number(root, 0, 0);
}
