class Solution {
  private:
    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>> &visited,
            vector<int>&r, vector<int>&c, vector<pair<int,int>>&v, int r0, int c0){
                v.push_back({i-r0, j-c0});
                visited[i][j] = 1;
                for(int ii=0; ii<4; ii++){
                    int nr = r[ii]+i;
                    int nc = c[ii]+j;
                    if(nr>=0 && nc>=0 && nr<grid.size() && nc<grid[0].size() && visited[nr][nc] ==0 && grid[nr][nc]==1){
                        v.push_back({nr-r0, nc-c0});
                        dfs(nr, nc, grid, visited, r, c, v, r0, c0);
                    }
                }
            }
  public:
    
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        // int islands = 0;
        vector<int>r = {0, 1, 0, -1}; //right, down, left, up
        vector<int>c = {1, 0, -1, 0};
        set<vector<pair<int, int>>>st;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1 && visited[i][j]==0){
                    vector<pair<int, int>>v;
                    dfs(i, j, grid, visited, r, c, v, i, j);
                    st.insert(v);
                    
                        // islands++;
                    
                }
            }
        }
        return st.size();
    }
};
