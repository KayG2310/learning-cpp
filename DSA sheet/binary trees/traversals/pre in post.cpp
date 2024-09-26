/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
void pre(vector<int>&pr, TreeNode* root){
    if(root == NULL) return;
    pr.push_back(root->data);
    pre(pr,root->left);
    pre(pr, root->right);
}
void post(vector<int>&po, TreeNode* root){
    if(root == NULL) return;
    post(po,root->left);
    post(po, root->right);
    po.push_back(root->data);
}
void inn(vector<int>&i, TreeNode* root){
    if(root == NULL) return;
    inn(i,root->left);
    i.push_back(root->data);
    inn(i, root->right);
}
vector<vector<int>> getTreeTraversal(TreeNode *root){
    // Write your code here.
    vector<int>po;
    vector<int>pr;
    vector<int>i;
    vector<vector<int>>ans;
    inn(i,root);
    pre(pr,root);
    post(po, root);
    ans.push_back(i);
    ans.push_back(pr);
    ans.push_back(po);
    return ans;


}
