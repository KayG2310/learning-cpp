/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    bool check(TreeNode* n, TreeNode* m){
        if(n == NULL && m != NULL) return false;
        if(m == NULL && n != NULL) return false;
        if(m == NULL && n == NULL) return true;
        if(m->val != n->val) return false;

        bool l = check(n->left, m->right);
        bool r = check(n->right, m->left);

        return l&r;
    }
public:
    bool isSymmetric(TreeNode* root){
        if(root == NULL) return true;
        return check(root->left, root->right);
    }
};
