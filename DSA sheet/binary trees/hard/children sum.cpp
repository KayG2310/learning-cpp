class Solution{
    public:
    int isSumProperty(Node *root)
    {
        if(root == NULL || (root->left == NULL && root->right == NULL)) return 1;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            Node* n = q.front();
            int val = n->data;
            q.pop();
            int add = 0;
            if(n->left){
                q.push(n->left);
                val = val-(n->left->data);
                add++;
            }
            if(n->right){
                q.push(n->right);
                val = val-(n->right->data);
                add++;
            }
            if(add >0 && val != 0) return 0;
        }
        return 1;
    }
};
// tc = n, sc = n above is my logic 
