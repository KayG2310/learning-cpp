class Solution {
public:
    int f(int i, int j, vector<vector<int>>&dp, vector<vector<int>>& obs){
        if(i==0 && j==0 ) return 1;
        if(i<0 || j<0) return 0;
        if(obs[i][j]==1) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int left = f(i-1, j, dp, obs);
        int right = f(i, j-1, dp, obs);
        return dp[i][j]=(left+right);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obs) {
        
        if(obs[0][0]==1) return 0;
        vector<vector<int>>dp(obs.size(), vector<int>(obs[0].size(), -1));
        return f(obs.size()-1, obs[0].size()-1, dp, obs);
    }
};
