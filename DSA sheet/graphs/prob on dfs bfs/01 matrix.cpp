class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        queue<vector<int>>q;
        vector<vector<int>>visited(n, vector<int>(m));
        vector<vector<int>>distance(n, vector<int>(m));
        for(int i=0; i<n; i++){
            for(int j=0; j<m ; j++){
                if(mat[i][j]==0){
                    q.push({i,j, 0});
                    visited[i][j] = 1;
                }
            }
        }
        vector<int>rows = {-1, 1, 0, 0};
        vector<int>cols = {0, 0, -1, 1};
        while(!q.empty()){
            int r = q.front()[0];
            int c = q.front()[1];
            int d = q.front()[2];
            // visited[r][c] = 1;
            distance[r][c] = d;
            q.pop();
            for(int i=0; i<4; i++){
                int nr = r+rows[i];
                int nc = c+cols[i];
                if(nr>=0 && nr<n && nc >=0 && nc < m && visited[nr][nc] == 0){
                    visited[nr][nc] = 1;
                    q.push({nr, nc, d+1});
                }
            }
            
        }
        return distance;

    }
}; 

// tc = 4nm, sc nm
