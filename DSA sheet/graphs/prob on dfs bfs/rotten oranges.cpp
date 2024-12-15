class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<vector<int>>q;
        int time = 0;
        vector<vector<int>>visited(n, vector<int>(m, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    q.push({i, j, time});
                    visited[i][j] = 2;
                }
            }
        }
        vector<int>rows = {-1, 0, 1, 0}; // up left down right
        vector<int>cols = {0, -1, 0, 1}; // up left down right
        int ans = 0;
        while(!q.empty()){
            int r = q.front()[0];
            int c = q.front()[1];
            int t = q.front()[2];
            ans = max(t, ans);
            q.pop();
            for(int i=0; i<4; i++){
                int nrow = r+rows[i];
                int ncol = c+cols[i];
                if(nrow>=0 && nrow < n && ncol>=0 && ncol<m && visited[nrow][ncol] != 2 && grid[nrow][ncol] == 1){
                    q.push({nrow, ncol, t+1});
                    grid[nrow][ncol] = 2;
                    visited[nrow][ncol] = 2;
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1 && visited[i][j] != 2){
                    return -1;
                }
            }
        }
        return ans;

    }
}; 
