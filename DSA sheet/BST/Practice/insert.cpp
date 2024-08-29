// recursive O(h) sc = O(h)
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // recursive approach
        if(root == NULL) return new TreeNode(val);
        // not empty
        if(root->val>val) root->left =  insertIntoBST(root->left, val);
        else root->right =  insertIntoBST(root->right, val);
        return root;
    }
};


// iterative approach, tc = logn, sc = 1
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // recursive approach
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
