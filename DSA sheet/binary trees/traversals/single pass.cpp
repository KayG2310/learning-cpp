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
#define t TreeNode
vector<vector<int>> getTreeTraversal(t *root){
    // Write your code here.
    vector<int>po;
    vector<int>pr;
    vector<int>i;
    vector<vector<int>>m;
    stack<pair<t*, int>>st;
    st.push({root, 1});
    if(root == NULL){
        return {{}};
    }
    while(!st.empty()){
        auto it = st.top();
        st.pop();
        if(it.second == 1){
            pr.push_back(it.first->data);
            it.second++;
            st.push(it);
            if(it.first->left) st.push({it.first->left, 1});
        }
        else if(it.second == 2){
            i.push_back(it.first->data);
            it.second++;
            st.push(it);
            if(it.first->right) st.push({it.first->right, 1});
        }
        else if(it.second == 3){
            po.push_back(it.first->data);
            // st.pop();
        }
    }
    m.push_back(i);
    m.push_back(pr);
    m.push_back(po);
    return m;

}
