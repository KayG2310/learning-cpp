// brute force --> write inorder, check, tc = 2n, sc = n
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
    void ans(TreeNode* root, vector<int>&a){
        if(root == NULL) return;
        ans(root->left, a);
        a.push_back(root->val);
        ans(root->right, a);
    }
public:
    bool isValidBST(TreeNode* root) {
        vector<int>a;
        ans(root,a);
        for(int i=0; i<a.size()-1; i++){
            if(a[i]>=a[i+1]) return false;
        }
        return true;
    }
};

// better tc = n, sc = n
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
    void ans(TreeNode* root, vector<int>&a, bool &flag){
        if(root == NULL) return;
        ans(root->left, a, flag);
        if(a.size() != 0){
            if(root->val <= a.back()) flag = false;
            // root = NULL;
        }
        a.push_back(root->val);
        ans(root->right, a, flag);
    }
public:
    bool isValidBST(TreeNode* root) {
        vector<int>a;
        bool flag = true;
        ans(root,a, flag);
        return flag;
    }
};

// striver soln, optimal tc = n, sc = 1
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
    bool i(TreeNode* root, long long min, long long max){
        if(root == NULL) return true;
        if(root->val >= max || root->val <= min) return false;
        bool l = i(root->left, min, root->val);
        bool r = i(root->right, root->val, max);
        return l&&r;
    }
    bool isValidBST(TreeNode* root) {
        return i(root, LLONG_MIN, LLONG_MAX);
    }
};
