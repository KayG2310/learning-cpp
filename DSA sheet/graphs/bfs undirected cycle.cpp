class Solution {
  private:
    bool bfs(int node, vector<vector<int>>& adj, int visited[]){
        visited[node] = 1;
        queue<vector<int>>q;
        q.push({node, -1});
        while(!q.empty()){
            int node = q.front()[0];
            int parent = q.front()[1];
            q.pop();
            for(auto &it : adj[node]){
                if(visited[it] == 0){
                    visited[it] = 1;
                    q.push({it, node});
                } 
                else if(it != parent){
                    return true;
                }
            }
        }
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>>& adj) {
        // Code here
        int v = adj.size();
        int vis[v] = {0};
        
        for(int i=0; i<v; i++){
            if(vis[i]==0){
                if(bfs(i, adj, vis)) return true;
            }
        }
        return false;
    }
}; 

tc = n+2e+n, sc = n+n
