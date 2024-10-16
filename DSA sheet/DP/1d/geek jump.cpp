// memoization , tc = n, sc = 2n
class Solution {
  public:
  int f(int i, vector<int>& height, vector<int>&dp){
        if(i==1) return 0;
        if(i==2) return abs((height[1]-height[0]));
        if(dp[i] != -1) return dp[i];
        return dp[i] = min(f(i-1, height, dp)+abs(height[i-1]-height[i-2]), f(i-2, height, dp)+abs(height[i-1]-height[i-3]));
    }
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        vector<int>dp(n+1, -1);
        return f(n, height, dp);
    }
};

// tabulization tc = n, sc= n
class Solution {
  public:
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        vector<int>dp(n+1, -1);
        dp[1] = 0;
        dp[2] = abs((height[1]-height[0]));
        for(int i=3; i<=n; i++){
            dp[i] = min(dp[i-1]+abs(height[i-1]-height[i-2]), dp[i-2]+abs(height[i-1]-height[i-3]));
        }
        return dp[n];
    }
};
// tc = n, sc = 1
class Solution {
  public:
    int minimumEnergy(vector<int>& height, int n) {
        if(n==1) return 0;
        int prev1 = 0;
        int prev2 = abs((height[1]-height[0]));
        for(int i=3; i<=n; i++){
            int s = min(prev2+abs(height[i-1]-height[i-2]), prev1+abs(height[i-1]-height[i-3]));
            prev1 = prev2;
            prev2 = s;
        }
        
        return prev2;
    }
};
