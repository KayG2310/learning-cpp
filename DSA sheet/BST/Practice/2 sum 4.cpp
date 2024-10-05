// brute force, tc = n+n, sc = n
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
    void in(TreeNode* root, vector<int>&inorder){
        if(root == NULL) return;
        in(root->left, inorder);
        inorder.push_back(root->val);
        in(root->right, inorder);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int>inorder;
        in(root, inorder);
        int low = 0, high=inorder.size()-1;
        while(low<high){
            if(inorder[low]+inorder[high]==k) return true;
            else if(inorder[low]+inorder[high]>k) high--;
            else low++;
        }
        return false;

    }
};


// optimal code
// using iterator method, adding prev as well, tc
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

class BSTIterator {
public:
    stack<TreeNode*>st;
    bool reverse = true;
    void pushall(TreeNode* root){
        if(reverse == true){
            while(root != NULL){
                st.push(root);
                root = root->right;
            }
        }
        else {
            while(root != NULL){
                st.push(root);
                root = root->left;
            }
        }
     }

    BSTIterator(TreeNode* root, bool isrev) {
       
        reverse = isrev;
         pushall(root);
    }
    
    int next() {
        TreeNode* temp = st.top();
        st.pop();
        if(reverse == false) pushall(temp->right);
        else pushall(temp->left);
        return temp->val;
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(root == NULL) return false;
        BSTIterator l(root, false);
        BSTIterator r(root, true);
        int i = l.next();
        int j = r.next();
        while(i<j){
            if(i+j==k) return true;
            else if(i+j>k) j=r.next();
            else i = l.next();
        }
        return false;
    }
};
