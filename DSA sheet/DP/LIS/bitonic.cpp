// striver question tc = 2n^2+n
class Solution {
  public:
    int LongestBitonicSequence(int n, vector<int> &nums) {
        // code here
        vector<int>dp1(n,1), dp2(n,1);
        for(int i=1; i<n; i++){
            // dp[i] = i;
            for(int prev = 0; prev<i; prev++){
                if(nums[i]>nums[prev] && dp1[i]<1+dp1[prev]){
                    dp1[i] = 1+dp1[prev];
                }
            }
        }
        
        for(int i=n-2; i>=0; i--){
            // dp[i] = i;
            for(int prev = n-1; prev>i; prev--){
                if(nums[i]>nums[prev] && dp2[i]<1+dp2[prev]){
                    dp2[i] = 1+dp2[prev];
                }
            }
        }
        int maxi = 0;
        for(int i=0; i<n; i++){
            maxi = max(maxi, dp1[i]+dp2[i]-1); // to remove common element
        }
        return maxi;
    }
};

// gfg question
class Solution {
  public:
    int LongestBitonicSequence(int n, vector<int> &nums) {
        // code here
        vector<int>dp1(n,1), dp2(n,1);
        for(int i=1; i<n; i++){
            // dp[i] = i;
            for(int prev = 0; prev<i; prev++){
                if(nums[i]>nums[prev] && dp1[i]<1+dp1[prev]){
                    dp1[i] = 1+dp1[prev];
                }
            }
        }
        
        for(int i=n-2; i>=0; i--){
            // dp[i] = i;
            for(int prev = n-1; prev>i; prev--){
                if(nums[i]>nums[prev] && dp2[i]<1+dp2[prev]){
                    dp2[i] = 1+dp2[prev];
                }
            }
        }
        int maxi = 0;
        for(int i=0; i<n; i++){
            if(dp1[i] !=1 && dp2[i] != 1) maxi = max(maxi, dp1[i]+dp2[i]-1); // to remove common element
        }
        return maxi;
    }
};
