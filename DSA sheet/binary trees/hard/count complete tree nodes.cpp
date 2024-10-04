// traversal approach 
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
    void p(TreeNode* root, int &cnt){
        if(root == NULL) return;
        cnt++;
        p(root->left, cnt);
        p(root->right, cnt);
    }
public:
    int countNodes(TreeNode* root) {
        int cnt = 0;
        p(root, cnt);
        return cnt;
    }
};

// less than traversal log^2n sc = 1
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
    int lheight(TreeNode* root){
        // if(root == NULL) return 0;
        int height = 0;
        while(root){
            height++;
            root = root->left;
        }
        return height;
    }
    int rheight(TreeNode* root){
        // if(root == NULL) return 0;
        int height = 0;
        while(root){
            height++;
            root = root->right;
        }
        return height;
    }


public:
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        int lh = lheight(root);
        int rh = rheight(root);
        if(lh == rh) return (1<<lh) -1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};
