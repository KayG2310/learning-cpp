// memoised approach, tc = n*m, sc = n*m + path length+n-1+m-1
class Solution {
public:
    int f(int i, int j, vector<vector<int>>& grid, vector<vector<int>>&dp){
        if(i==0 && j==0) return grid[0][0];
        if(i<0 || j<0) return 1e9;

        if(dp[i][j] !=-1) return dp[i][j];
        int left = grid[i][j]+ f(i-1, j, grid, dp);
        int up = grid[i][j]+ f(i, j-1, grid, dp);
        return dp[i][j] = min(left,up);
    }
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>>dp(grid.size(), vector<int>(grid[0].size(), -1));
        return f(grid.size()-1, grid[0].size()-1, grid, dp);
    }
};

// tablurisation -- removes recursive stack space
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>>dp(grid.size(), vector<int>(grid[0].size(), 0));
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(i==0 && j==0) dp[0][0] = grid[0][0];
                else{
                    int left = INT_MAX, right = INT_MAX;
                    if(i>0) left = grid[i][j]+ dp[i-1][j];
                    if (j>0) right = grid[i][j]+ dp[i][j-1];
                    dp[i][j] = min(left, right);
                }
            }
        }
        return dp[grid.size()-1][grid[0].size()-1];
    }
};

// space optimisation
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<int>prev(grid[0].size(), 0);
        for(int i=0; i<grid.size(); i++){
            vector<int>cur(grid[0].size(), 0);
            for(int j=0; j<grid[0].size(); j++){
                if(i==0 && j==0) cur[j] = grid[0][0];
                else{
                    int left = INT_MAX, right = INT_MAX;
                    if(i>0) left = grid[i][j]+ prev[j];
                    if (j>0) right = grid[i][j]+ cur[j-1];
                    cur[j] = min(left, right);
                }
            }
            prev = cur;
        }
        return prev[grid[0].size()-1];
    }
};
