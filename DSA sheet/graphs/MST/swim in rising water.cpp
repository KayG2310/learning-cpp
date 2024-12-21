class Solution {

public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        minHeap.push({grid[0][0], 0, 0});
        vector<int>rows = {-1, 1, 0, 0};
        vector<int>cols = {0, 0, -1, 1};
        set<pair<int, int>> seen;
        seen.insert({0, 0});
        int maxcost = 0;
        while (!minHeap.empty()) {
            auto it = minHeap.top();
            minHeap.pop();
            int tempcost = it[0];
            int r = it[1];
            int c = it[2];
            maxcost = max(maxcost, tempcost);
            if (r == n - 1 && c == n - 1) {
                return maxcost;
            }
            for (int i=0; i<4; i++) {
                int nr = r + rows[i];
                int nc = c + cols[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n && seen.find({nr, nc}) == seen.end()) {
                    seen.insert({nr, nc});
                    minHeap.push({grid[nr][nc], nr, nc});
                }
            }
        }

        return -1;

    }
};
