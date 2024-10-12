// nodes ^ m colors
class Solution {
  public:
    bool safe(vector<int>&color, int node, vector<vector<int>>&adj, int i, int v){
        for(int k=0; k<v; k++){
            if(k != node && adj[k][node]==1 && color[k]==i){
                return false;
            }
        }
        return true;
    }
    bool f(int node, vector<int>&color, int m, int v, vector<vector<int>>&adj){
        if(node==v) return true;
        for(int i=1; i<=m; i++){
            if(safe(color, node, adj, i, v)){
                color[node] = i;
                if(f(node+1, color, m, v, adj)) return true;
                color[node] = 0;
                // backtracking
            }
        }
        return false;
    }
    bool graphColoring(int v, vector<pair<int, int>>& edges, int m) {
        vector<vector<int>>adj(v, vector<int>(v,0));
        for(auto val:edges){
            adj[val.first][val.second] = 1;
            adj[val.second][val.first] = 1;
        }
        vector<int>color(v,0);
        if(f(0, color, m, v, adj)) return true;
        return false;
    }
};
