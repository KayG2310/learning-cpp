bool isLeaf(Node* root){
        if(root->left==NULL && root->right==NULL) return true;
        return false;
    }
    
    void leftBoundary(Node* root,vector<int> &res){
        Node* cur = root->left;
        while(cur){
            if(!isLeaf(cur)) res.push_back(cur->data);
            if(cur->left) cur = cur->left;
            else cur = cur->right;
        }
    }
    void rightBoundary(Node* root,vector<int> &res){
        Node* cur = root->right;
        stack<Node*>st;
        while(cur){
            if(!isLeaf(cur)) st.push(cur);
            if(cur->right) cur = cur->right;
            else cur = cur->left;
        }
        while(!st.empty()){
            Node* temp = st.top(); st.pop();
            res.push_back(temp->data);
        }
    }
    void leaves(Node* root,vector<int> &res){
        if(isLeaf(root)){
            res.push_back(root->data);
            return;
        }
        if(root->left) leaves(root->left,res);
        if(root->right) leaves(root->right,res);
    }

class Solution {
public:
    vector <int> boundary(Node *root)
    {
        vector<int> res;
        if(root==NULL) return res;
        if(!isLeaf(root)) res.push_back(root->data);
        leftBoundary(root,res);
        leaves(root,res);
        rightBoundary(root,res);
        return res;
    }
};
