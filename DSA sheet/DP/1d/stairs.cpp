class Solution {
public:
    int f(int n, vector<int>&dp){
        if(n==0) return 1;
        if(n==1) return 1;
        if(dp[n] != -1) return dp[n];
        return dp[n] = f(n-1, dp)+f(n-2, dp);
    }
    int climbStairs(int n) {
        // recursive code 
        vector<int>dp(n+1, -1);
        // return f(n, dp);

        // m-2
        // dp[0] = 1;
        // dp[1] = 1;
        // for(int i=2; i<=n; i++){
        //     dp[i] = dp[i-1]+dp[i-2];
        // }
        // return dp.back();

        // m-3
        int prev2 = 1;
        int prev = 1;
        for(int i=2; i<=n; i++){
            int s = prev2+prev;
            prev2 = prev;
            prev = s;
        }
        return prev;
    }
};
