// #define pii pair<int, int>
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<vector<int>>q;
        int n = grid.size();
        if(grid[0][0] != 0 || grid[n-1][n-1] != 0) return -1;
        if(n==1) return 1;
        vector<int>rows = {-1, 1, 0, 0, -1, -1, 1, 1};
        vector<int>cols = {0, 0, -1, 1, -1, 1, -1, 1}; 
        // up, down, left, right, up-left, up-right, down-left, down-right
        vector<vector<int>> distance(n, vector<int>(n, 1e9));
        distance[0][0] = 1;
        q.push({1,0,0}); // dist, i, j
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int dist = it[0];
            int r = it[1];
            int c = it[2];
            for(int i=0; i<8; i++){
                int nr = r+rows[i];
                int nc = c+cols[i];
                if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==0 && dist+1<distance[nr][nc]){
                    q.push({dist+1, nr, nc});
                    if(nr==n-1 && nc == n-1) return dist+1;
                    distance[nr][nc] = 1+dist;
                }
            }
        }
        return -1;
    }
};
