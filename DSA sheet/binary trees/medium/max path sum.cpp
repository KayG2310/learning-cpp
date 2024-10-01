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
    int height(TreeNode* root, int &maxsum){
        if(root == NULL) return 0;
        int lh = max(0, height(root->left, maxsum));
        int rh = max(0, height(root->right, maxsum));
        int now = root->val + lh + rh;
        maxsum = max(maxsum, now);
        return root->val+max(lh, rh);
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxsum = INT_MIN;
        int x = height(root,maxsum);
        return maxsum;
    }
};
