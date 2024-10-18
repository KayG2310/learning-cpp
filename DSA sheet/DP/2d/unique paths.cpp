// basic recursion, 2^(n*m) 
class Solution {
public:
    int f(int i, int j){
        if(i==0 && j==0) return 1;
        if(i<0 || j<0) return 0;
        int left = f(i-1, j);
        int right = f(i, j-1);
        return left+right;
    }
    int uniquePaths(int m, int n) {
        return f(m-1, n-1);
    }
}; 

// memoization --> n*m, sc = n-1+m-1 + n*m 
class Solution {
public:
    int f(int i, int j, vector<vector<int>>&dp){
        if(i==0 && j==0) return 1;
        if(i<0 || j<0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int left = f(i-1, j, dp);
        int right = f(i, j-1, dp);
        return dp[i][j]=(left+right);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m, vector<int>(n,-1));
        return f(m-1, n-1, dp);
    }
}; 

// tabularization --> tc = same, sc = n*m
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m, vector<int>(n,-1));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0 && j==0) dp[0][0] = 1;
                else{
                    int left = 0, up = 0;
                    if(i>0) up = dp[i-1][j];
                    if(j>0) left = dp[i][j-1];
                    dp[i][j] = up+left;
                }
            }
        }
        return dp[m-1][n-1];
    }
};

// space optimisation, tc = same, sc = n
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int>prev(n,0);
        for(int i=0; i<m; i++){
            vector<int>temp(n,0);
            for(int j=0; j<n; j++){
                if(i==0 && j==0) temp[j] = 1;
                else{
                    int left = 0, up = 0;
                    if(i>0) up = prev[j];
                    if(j>0) left = temp[j-1];
                    temp[j] = up+left;
                }
            }
            prev = temp;

        }
        return prev[n-1];
    }
};


// combinatorics
class Solution {
public:
    int uniquePaths(int m, int n) {
        int N = n + m - 2;  // Total moves required (m-1 down + n-1 right)
        int r = m - 1;       // Number of downward moves
        double res = 1;      // Store result as double to prevent overflow

        // Calculate binomial coefficient (N choose r)
        for (int i = 1; i <= r; i++) {
            res = res * (N - r + i) / i;
        }

        return (int)res;  // Cast result to integer and return
    }
};
