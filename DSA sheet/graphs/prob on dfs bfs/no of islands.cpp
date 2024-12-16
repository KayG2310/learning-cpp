class Solution {
  private:
    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>> &visited,
            vector<int>&r, vector<int>&c){
                visited[i][j] = 1;
                for(int ii=0; ii<4; ii++){
                    int nr = r[ii]+i;
                    int nc = c[ii]+j;
                    if(nr>=0 && nc>=0 && nr<grid.size() && nc<grid[0].size() && visited[nr][nc] ==0 && grid[nr][nc]==1){
                        dfs(nr, nc, grid, visited, r, c);
                    }
                }
            }
  public:
    
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        int islands = 0;
        vector<int>r = {-1,1, 0,0};
        vector<int>c = {0,0,-1,1};
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1 && visited[i][j]==0){
                    dfs(i, j, grid, visited, r, c);
                    islands++;
                }
            }
        }
        return islands;
    }
};
