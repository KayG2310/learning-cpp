// recursive O(h) sc = O(h)
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL) return new TreeNode(val);
        if(root->val>val) root->left =  insertIntoBST(root->left, val);
        else root->right =  insertIntoBST(root->right, val);
        return root;
    }
};

// iterative approach, tc = logn, sc = 1
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL) return new TreeNode(val);
        TreeNode* temp = root;
        while(true){
            if(temp->val < val){
                if(temp->right != NULL) temp = temp->right;
                else{
                    temp->right = new TreeNode(val);
                    return root;
                }
            }
            else{
                if(temp->left != NULL) temp = temp->left;
                else{
                    temp->left = new TreeNode(val);
                    return root;
                }
            }
        }
        return root;
    }
};
