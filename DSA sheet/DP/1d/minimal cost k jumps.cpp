class Solution {
  public:
  int f(int i, vector<int>& height, vector<int>&dp, int k){
        if(i==1) return 0;
        if(dp[i] != -1) return dp[i];
        int mini = INT_MAX;
        
        for(int j=1; j<=k; j++){
            if(i-j>=1 && i-j<height.size()) mini = min(mini, f(i-j, height, dp, k)+abs(height[i-1]-height[i-j-1]));
        }
        
        return dp[i] = mini;
    }
    int minimizeCost(int k, vector<int>& arr) {
        // Code here
        int n = arr.size();
        vector<int>dp(n+1, -1);
        return f(n, arr, dp, k);
        
    }
}; 
// tc = O(N*K) sc = 2n 
/*
Can optimise space to k but of no use when k=n so not needed
*/
