class Solution
{
    public:
    vector<int> topView(Node *root)
    {
        vector<int>ans2;
        map<int, int>ans;
        queue<pair<Node*, int>>q;
        q.push({root, 0});
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            Node* node = p.first;
            int x = p.second;
            // int y = p.second.second;
            if(ans.find(x) == ans.end())
                ans[x] = node->data;
            if(node->left) q.push({node->left, x-1});
            if(node->right) q.push({node->right, x+1});
        }
        // vector<vector<int>>a;
        for(auto p: ans){
            ans2.push_back(p.second);
        }
        return ans2;
    }

};
