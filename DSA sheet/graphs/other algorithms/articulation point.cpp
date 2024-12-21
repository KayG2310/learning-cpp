int timer = 0;

class Solution {
  private:
    void dfs(int node, int parent, vector<int>& tin, vector<int>& low,
            vector<int>& visited, vector<int>adj[], vector<int>& mark){
        visited[node] = 1;
        tin[node] = low[node] = timer; timer++;
        int child = 0;
        for(auto it: adj[node]){
            if(it == parent) continue; // do nothing
            if(visited[it]==0){
                dfs(it, node, tin, low, visited, adj, mark);
                low[node] = min(low[node], low[it]);
                if(low[it] >= tin[node] && parent != -1) mark[node] =1;
            child++;
            }
            else{
                low[node] = min(low[node], tin[it]);
            }
        }
        if(child>1 && parent == -1) mark[node] = 1;
    }
  public:
    vector<int> articulationPoints(int n, vector<int>adj[]) {
        // Code 
        vector<int>ans;
        vector<int>visited(n,0);
        vector<int>tin(n);
        vector<int>low(n);
        vector<int>mark(n,0);
        for(int i=0; i<n; i++){
            if(visited[i] == 0){
                dfs(i, -1, tin, low, visited, adj, mark);
            }
        }
        for(int i=0; i<n; i++){
            if(mark[i]) ans.push_back(i);
        }
        if(ans.size()==0) return {-1};
        return ans;
    }
};
