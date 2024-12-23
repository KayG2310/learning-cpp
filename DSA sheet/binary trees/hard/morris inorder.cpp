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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        TreeNode* cur = root; 
        // to not change the original
        while(cur != NULL){
            // 1st edge case
            if(cur->left == NULL) {
                // it means it is the node and can be pushed
                ans.push_back(cur->val);
                cur = cur->right;
            }

            // 2nd edge case 
            else{
                // left exists
                TreeNode* prev = cur->left;
                while(prev->right && prev->right != cur){
                    prev = prev->right;
                }
                // 1st case
                if(prev->right == NULL){
                    prev->right = cur; // thread to the node
                    cur = cur->left;
                }
                else{
                    // now you are traversing the thread
                    prev->right = NULL; // remove the thread
                    ans.push_back(cur->val);
                    cur = cur->right;
                }

            }

        }
        return ans;
    }
};

// tc = o(n) sc = o(1)
