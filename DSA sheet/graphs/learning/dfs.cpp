class Solution {
    private:
        void dfs(int node, vector<int> adj[], vector<int>&visited, vector<int>&ans){
            visited[node] = 1;
            ans.push_back(node);
            for(auto &it : adj[node]){
                if(visited[it]==0){
                    dfs(it, adj, visited, ans);
                }
            }
            
        }
  public:
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int>visited(V);
        vector<int>ans;
        dfs(0,adj,visited, ans);
        return ans;
    }
};
