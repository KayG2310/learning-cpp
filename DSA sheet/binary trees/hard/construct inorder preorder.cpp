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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>m;
        for(int i=0; i<inorder.size(); i++){
            m[inorder[i]] = i;
        }
        TreeNode* root = tree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, m);
        return root;
    }

    TreeNode* tree(vector<int>& preorder, int prestart, int preend, vector<int>&inorder, int instart, int inend, unordered_map<int,int>&m){
        if(prestart > preend || instart > inend) return NULL;
        TreeNode* root = new TreeNode(preorder[prestart]);
        int r = root->val;
        int inorder_index = m[r];
        int num_els_in_left = inorder_index - instart;
        root->left = tree(preorder, prestart +1, prestart+num_els_in_left, inorder, instart, inorder_index -1, m);
        root->right = tree(preorder, prestart+num_els_in_left+1, preend, inorder, inorder_index+1, inend, m);
    return root;
    }
};

// tc = n, sc = n for unordered map
