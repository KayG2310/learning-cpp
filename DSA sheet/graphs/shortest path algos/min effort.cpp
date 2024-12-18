class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        if(n==0 && m==0) return 0;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
        vector<vector<int>> effort(n, vector<int>(m, 1e9));
        effort[0][0] = 0;
        pq.push({0, 0, 0});
        vector<int>rows = {-1, 1, 0, 0};
        vector<int>cols = {0, 0, -1, 1};
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int dist = it[0];
            int r = it[1];
            int c = it[2];
            if(r==n-1 && c==m-1) return dist;
            for(int i=0; i<4; i++){
                int nr = r+rows[i];
                int nc = c+cols[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m){
                    int neweffort = max(abs(heights[nr][nc]-heights[r][c]), dist);
                    if(neweffort < effort[nr][nc]){
                        effort[nr][nc] = neweffort;
                        pq.push({neweffort, nr, nc});
                    }
                    
                }
            }
        }
        return 0;

    }
}; 
