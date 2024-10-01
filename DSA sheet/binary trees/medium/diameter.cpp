// my code tc = o(n) sc = n
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
    int height(TreeNode* root, int &diam){
        if(root == NULL) return 0;
        int lh = height(root->left, diam);
        int rh = height(root->right, diam);
        diam = max(diam, lh+rh);
        return max(lh,rh)+1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        int diam = 0;
        int x = height(root, diam);
        return diam;
    }
};
