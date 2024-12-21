class Solution {
  private:
    void dfs(int node, vector<int>& vis, stack<int>& st, vector<vector<int>> &adj){
        vis[node] = 1;
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(it, vis, st, adj);
            }
        }
        st.push(node);
    }
    void dfs2(int node, vector<int>& vis, vector<int>& temp, vector<vector<int>> &adj){
        vis[node] = 1;
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs2(it, vis, temp, adj);
            }
        }
        temp.push_back(node);
    }
  public:
    int kosaraju(vector<vector<int>> &adj) {
        // code here
        int n = adj.size();
        stack<int>st;
        vector<int>vis(n, 0);
        for(int i=0; i<n; i++){
            if(!vis[i]){
                dfs(i, vis, st, adj);
            }
        }
        // step 2: reverse the graph 
        vector<vector<int>>adj2(n);
        for(int i=0; i<n; i++){
            vis[i] = 0;
            for(auto it:adj[i]){
                adj2[it].push_back(i);
            }
        }
        vector<vector<int>>ans;
        while(!st.empty()){
            vector<int>temp;
            int node = st.top();
            st.pop();
            if(!vis[node]){
                dfs2(node, vis, temp, adj2);
                ans.push_back(temp);
            }
        }
        return ans.size();
        
    }
};
