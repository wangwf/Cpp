

struct TreeNode{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x): val(x), left(NULL), right(NULL){}
};

//
/***********
preorder(node)
   if node==null then return
     visit(node)
     preorder(node.left)
     preorder(node.right(

inorder(node)                                                                                                             
   if node==null then return                                                                                               
     inorder(node.left)
     visit(node)
     inorder(node.right)

postorder(node)
    if node == null then return
    postorder(node.left)
    postorder(node.right)
    visit(node)

*************************/

vector<int> preorderTraversalIterative(TreeNode *root){
  vector<int> res;
  if(!root) return res;
  stack<TreeNode*> st;
  st.push(root);
  TreeNode* head=root;
  while(!st.empty()){
    TreeNode* top=st.top();
    st.pop();
    res.push_back(top->val);
    if(top !=NULL){
      if(top->right !=NULL)st.push(top->right);
      if(top->left!=NULL)st.push(top->left);
    }
  }
  return res;
}

vector<int> inorderTraversal(TreeNode* root){
  vector<int> res;
  if(!root) return res;
  stack<TreeNode*> st;
  //  st.push(root);
  TreeNode* current=root;
  while(!st.empty() || current){
    if(current){
      st.push(current);
      current= current->left;
    }
    else{
      current=st.top();
      st.pop();
      res.push_back(current->val);
      current=current->right;
    }
  }
}

vector<int> postorderTraversal(TreeNode *root){
  stack<TreeNode*> st;
  vector<int> res;
  if(!root) return res;

  st.push(root);
  TreeNode* head=root;
  while(!st.empty()){
    TreeNode* top=st.top();
    if((top->left==NULL&& top->right ==NULL)
       || top->right == head
       || top->left == head)
      {
      res.push_back(top->val);
      st.pop();
      head = top;
    }
    else{
      if(top->right!=NULL) st.push(top->right);
      if(top->left !=NULL) st.push(top->left);
    }
  }


}



int maxDepth(TreeNode *root){
  if(!root) return 0;
  int leftDepth = maxDepth(root->left);
  int rightDepth= maxDepth(root->right);
  return leftDepth>rightDepth? leftDepth+1: rightDepth+1;
}

int minDepth(TreeNode *root){
  if(!root) return 0; 
  int leftDepth = minDepth(root->left);
  int rightDepth = minDepth(root->right);
  if(leftDepth==0 || rightDepth ==0) return leftDepth>rightDepth? leftDepth+1: rightDepth+1;
  return leftDepth><ightDepth? leftDepth+1: rightDepth+1;
}


bool isSameTree(TreeNode *p, TreeNode *q){

  if(!p && !q) return true;
  if( !p || !q) return false;
  if( p->val != q->val) return false;
  return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}


//isBalanced

int getBalanced(TreeNode *root, bool &balanced){
  if(!root || !balanced) return 0;

  int left  = 1 + getBalanced(root->left, balanced);
  int right = 1 + getBalanced(root->right, balanced);

  if(abs(left-right)>1) balanced=false;
  return max(left, right);
}

bool isBalanced(TreeNode* root){
  bool balanced=true;
  getBalanced(root, balanced);
  return balanced;
}
