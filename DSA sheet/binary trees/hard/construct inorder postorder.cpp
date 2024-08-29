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
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int>m;
        for(int i=0; i<inorder.size(); i++){
            m[inorder[i]] = i;
        }
        TreeNode* root = tree(postorder, postorder.size()-1, 0, inorder, 0, inorder.size()-1, m);
        return root;
    }
    TreeNode* tree(vector<int>& postorder, int poststart, int postend, vector<int>&inorder, int instart, int inend, unordered_map<int,int>&m){
        if(poststart < postend || instart > inend) return NULL;
        TreeNode* root = new TreeNode(postorder[poststart]);
        int r = root->val;
        int inorder_index = m[r];
        int num_els_in_left = inorder_index - instart;
        int num_els_in_right = inend-instart - num_els_in_left;
        root->right = tree(postorder, poststart -1, poststart-num_els_in_right, inorder, inorder_index+1, inend, m);
        root->left = tree(postorder, poststart-num_els_in_right-1, postend, inorder, instart, inorder_index-1, m);
    return root;
    }
};
