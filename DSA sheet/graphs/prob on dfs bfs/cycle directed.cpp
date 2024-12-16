class Solution {
  bool dfs(int node, vector<vector<int>> &adj, int visited[], int path[]){
      visited[node] = 1;
      path[node] = 1;
      for(auto it: adj[node]){
          if(!visited[it]){
              if(dfs(it, adj, visited, path)==true) return true;
          }
          else if(path[it]==1) return true;
      }
      path[node]=0;
      return false;
  }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<vector<int>> adj) {
        // code here
        int visited[V] = {0};
        int path[V] = {0};
        for(int i=0; i<V; i++){
            if(!visited[i]){
                if(dfs(i, adj, visited, path)==true) return true;
            }
        }
        return false;
    }
};
