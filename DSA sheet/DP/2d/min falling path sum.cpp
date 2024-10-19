// recursion 3^n 
class Solution {
public:
    int f(int i, int j, vector<vector<int>>& matrix, int n){
        if(j<0 || j==n) return 1e9;
        if(i==0) return matrix[0][j];
        int s = matrix[i][j]+ f(i-1, j, matrix, n);
        int ld = matrix[i][j]+ f(i-1, j-1, matrix, n);
        int rd = matrix[i][j]+ f(i-1, j+1, matrix, n);
        return min(s, min(ld, rd));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int minPathSum = 1e9;
        for (int j = 0; j < n; j++) {
            minPathSum = min(minPathSum, f(n - 1, j, matrix, n));
        }
        return minPathSum;
        
    }
};

// tab 
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>>dp(m, vector<int>(n, 0));
        for(int j=0; j<n; j++){
            dp[0][j] = matrix[0][j];
        }
        for(int i=1; i<m; i++){
            for(int j=0; j<n; j++){
                int s=1e9, ld = 1e9, rd = 1e9;
                s = matrix[i][j]+ dp[i-1][j];
                if(j>0) ld = matrix[i][j]+ dp[i-1][j-1];
                if(j+1<n) rd = matrix[i][j]+ dp[i-1][j+1];
                dp[i][j] = min(s, min(ld, rd));
            }
        }
        int mini = 1e9;
        for(int j=0; j<n; j++){
            mini = min(mini, dp[m-1][j]);
        }
        return mini;
    }
};

// space
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        // vector<vector<int>>dp(m, vector<int>(n, 0));
        vector<int>prev(n, 0), cur(n,0);
        for(int j=0; j<n; j++){
            prev[j] = matrix[0][j];
        }
        for(int i=1; i<m; i++){
            for(int j=0; j<n; j++){
                int s=1e9, ld = 1e9, rd = 1e9;
                s = matrix[i][j]+ prev[j];
                if(j>0) ld = matrix[i][j]+prev[j-1];
                if(j+1<n) rd = matrix[i][j]+ prev[j+1];
                cur[j] = min(s, min(ld, rd));
            }
            prev = cur;
        }
        int mini = 1e9;
        for(int j=0; j<n; j++){
            mini = min(mini, prev[j]);
        }
        return mini;
    }
};
