class Solution {
  public:
    void dfs(int node, vector<int>&visited, vector<int> adj[], vector<int>&temp){
        visited[node] = 1;
        temp.push_back(node);
        for(auto &it: adj[node]){
            if(visited[it]==0){
                dfs(it, visited, adj, temp);
            }
        }
        
    }
    vector<vector<int>> connectedcomponents(int v, vector<vector<int>>& edges) {
        // code 
        vector<vector<int>>ans;
        vector<int>visited(v);
        vector<int> adj[v];
        for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        for(int i=0; i<v; i++){
            if(visited[i]==0){
                vector<int>temp;
                dfs(i, visited, adj, temp);
                sort(temp.begin(), temp.end());
                ans.push_back(temp);
            }
            
        }
        return ans;
        
    }
}; 

// tc = e+e+v + vlogv for sorting, sc = n+n+2n
