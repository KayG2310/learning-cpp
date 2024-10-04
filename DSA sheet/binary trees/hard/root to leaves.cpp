class Solution {
  private:
    void foo(Node* root, vector<int>&inner, vector<vector<int>>&ans){
        if(!root){
            // ans.push_back(inner);
            return;
        }
        //if(root->left==NU)
        //inner.push_back(root->data);
        if(root->left == NULL && root->right == NULL){
            ans.push_back(inner);
        }
        if(root->left!=NULL) {
            inner.push_back(root->left->data);
            foo(root->left, inner, ans);
            inner.pop_back();
        }
        if(root->right!=NULL) {
            inner.push_back(root->right->data);
            foo(root->right, inner, ans);
            inner.pop_back();
        }
    }
  public:
    vector<vector<int>> Paths(Node* root) {
        // code here
        vector<vector<int>>ans;
        vector<int>inner;
        if(root == NULL) return {};
        inner.push_back(root->data);
        foo(root, inner, ans);
        return ans;
        
    }
};
