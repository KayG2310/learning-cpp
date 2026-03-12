class Solution {
private:
    TreeNode* first, last, middle, prev;
    void inorder(TreeNode* root){
        if(root == NULL) return;
        inorder(root->left);
        if(prev != NULL && (root->val < prev->val)){
            // first violation
            if(first == NULL){
                first = prev;
                middle = root;
            }
            else last = root;
        }
        prev = root;
        inorder(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        first = middle = last = NULL;
        prev = new TreeNode(INT_MIN);
        inorder(root);
        if(first && last) swap(first->val, last->val);
        else if(first && middle) swap(first->val, middle->val);
    }
};
