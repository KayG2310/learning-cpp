class Solution {
  private:
    bool dfs(int node, int parent, vector<int>&visited, vector<int> adj[]){
        visited[node] = 1;
        for(auto &val: adj[node]){
            if(visited[val]==0){
                // not visited call recursion
                if(dfs(val,node, visited, adj)==true){
                    return true;
                }
            }
            else if(val != parent) return true;
        }
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int>visited(V,0);
        for(int i = 0; i<V; i++){
            if(visited[i]==0){
                if(dfs(i, -1, visited, adj)==true) return true;
            }
        }
        return false;
        
    }
};
