// Wow after this wonderful explanation!! preorder approach became too easy.
// Here is the code :-
    void preorder(TreeNode* node,int vertical,int level,map<int,map<int,multiset<int>>> &nodes){
        if(node == nullptr) return;
        
        nodes[vertical][level].insert(node->val);
        preorder(node->left,vertical-1,level+1,nodes);
        preorder(node->right,vertical+1,level+1,nodes);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> nodes;
        preorder(root,0,0,nodes);
        vector<vector<int>> ans;
        
        for(auto p:nodes){
            vector<int> col;
            for(auto q:p.second){
                col.insert(col.end(),q.second.begin(),q.second.end());
            }
            ans.push_back(col);
        }
        
        
        return ans;
    }
