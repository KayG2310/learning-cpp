class Solution {
public:
    void dfs(int node, vector<int>&visited, vector<int> adj[]){
        visited[node] = 1;
        // temp.push_back(node);
        for(auto &it: adj[node]){
            if(visited[it]==0){
                dfs(it, visited, adj);
            }
        }
        
    }
    int findCircleNum(vector<vector<int>>& edges) {
        int ans = 0;
        int v = edges.size();
        vector<int>visited(v);
        vector<int> adj[v];
        for(int i=0; i<v; i++){
            for(int j=0; j<v; j++){
                if(edges[i][j] == 1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        for(int i=0; i<v; i++){
            if(visited[i]==0){
                dfs(i, visited, adj);
                ans++;
            }
            
        }
        return ans;
        
    }
}; 

tc = v^2 + v+e, sc = 2v
