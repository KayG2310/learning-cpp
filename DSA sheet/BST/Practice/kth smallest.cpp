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
    void ans(TreeNode* root, int &k, int &cnt, int &x){
        if(root == NULL) return;
        ans(root->left, k, cnt,x);
        if(++cnt == k) x= root->val;
        ans(root->right, k, cnt, x);

    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        int x;
        ans(root, k, cnt, x);
        return x;
    }
};
