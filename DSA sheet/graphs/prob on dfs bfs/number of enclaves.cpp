class Solution {
public:
    void bfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& visited, vector<int>& r, vector<int> &c){
        visited[i][j] = 1;
        grid[i][j] = 0;
        queue<pair<int, int>>q;
        q.push({i, j});
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int in=0; in<4; in++){
                int nr = row+r[in];
                int nc = col+c[in];
                if(nr>=0 && nc>=0 && nr< grid.size() && nc<grid[0].size() && visited[nr][nc]==0 && grid[nr][nc]==1){
                    visited[nr][nc]=1;
                    q.push({nr, nc});
                    grid[nr][nc] = 0;
                }
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int>r = {-1, 1, 0, 0};
        vector<int>c = {0, 0, -1, 1};

        queue<pair<int, int>>q;
        vector<vector<int>>visited(n, vector<int>(m,0));
        for(int i=0; i<n; i++){
            if(grid[i][0]==1) bfs(i, 0, grid, visited, r, c);
            if(grid[i][m-1]==1) bfs(i, m-1, grid, visited, r,c);
        }
        for(int i=0; i<m; i++){
            if(grid[0][i]==1) bfs(0, i, grid, visited, r, c);
            if(grid[n-1][i]==1) bfs(n-1, i, grid, visited, r,c);
        }
        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1) cnt++;
            }
        }
        return cnt;
    }
};
