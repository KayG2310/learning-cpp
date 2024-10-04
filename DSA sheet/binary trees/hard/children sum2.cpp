// my original soln was using postorder traversal --- works for a diff question

// striver q ans -->

class Solution{
  void changeTree(TreeNode* root){
    if(root == NULL){
      return;
    }
    int child = 0;
    if(root->left){
      child += root->left->val;
    }
    if(root->right){
      child += root->right->val;
    }
    if(child<root->val){
      if(root->left) root->left->val = root->val;
      if(root->right) root->right->val = root->val;
    }
    else root->val = child;

    changeTree(root->left);
    changeTree(root->right);

    int total = 0;
    if(root->left) total += root->left->val;
    if(root->right) total += root->right->val;
    if(root->left or root->right) root->val = total;
    
  }
}
